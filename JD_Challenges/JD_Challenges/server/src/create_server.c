//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/project.h"


char **create_map(char *filename)
{
    int cols = 0;
    int lines = 0;
    int nums = 0;
    char **map;
    FILE *content;
    if ((content = fopen(filename, "r")) == NULL) {
        if ((content = fopen("server/maps/SUCCESS", "r")) == NULL)
            return NULL;

    }

    map = malloc(sizeof(char *) * (49 + 1));
    map[49] = NULL;
    for (int i = 0; i != 49; i++) {
        map[i] = NULL;
    }
    map[0] = malloc(sizeof(char) * (49 + 1));
    for (int i = 0; i != 49; i++) {
        map[0][i] = 0;
    }
    while(1) {
        nums = fgetc(content);

        if(feof(content) || nums == '\0')
            break ;
        if (nums == '\n') {
            lines += 1;
            cols = 0;
            map[lines] = malloc(sizeof(char *) * (49 + 1));
            for (int i = 0; i != 49; i++) {
                map[lines][i] = 0;
            }
        } else {
            map[lines][cols] = nums;
            cols += 1;
        }
    }
    fclose(content);

    return map;
}


void set_list_fd(server_t *server, select_t *select, char *filename)
{
    list_t *list = malloc(sizeof(list_t));

    select->max_fd = server->fd;
    list->fd = -1;
    list->type = 1;
    list->cmd = NULL;
    list->cmd_support = NULL;
    list->ret = 0;
    list->is_text = false;
    list->text = NULL;
    list->pos_x = 0;
    list->pos_y = 0;
    list->action = false;
    list->key = false;
    list->button = false;
    list->on = ' ';
    list->map = NULL;
    list->character = '?';
    list->to_delete = false;
    list->next = NULL;
    list->first = list;
    select->list = list;
    select->map_name = malloc(sizeof(char) * 12);
    select->map_name = strcpy(select->map_name, filename);
}

int set_server(server_t server, char *filename)
{
    int ret = 0;
    select_t select;

    set_list_fd(&server, &select, filename);
    if (bind(server.fd, (struct sockaddr *)&server.address,
        sizeof(server.address)) < 0) {
        perror("bind failed");
        return (1);
    }
    if (listen(server.fd, 3) < 0) {
        perror("listen");
        return (1);
    }
    FD_ZERO(&select.fd_read);
    FD_ZERO(&select.fd_write);
    while ((ret = loop_server(&server, &select)) == 0);
    if (ret == 1)
        return (1);
    return (0);
}

int create_server(int port, char *filename)
{
    server_t server;
    int opt = 1;
    char cwd[PATH_MAX];

    if ((server.fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return (1);
    }
    if (setsockopt(server.fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
        &opt, sizeof(opt))) {
        perror("setsockopt");
        return (1);
    }
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        server.path = cwd;
    server.address.sin_family = AF_INET;
    server.address.sin_addr.s_addr = INADDR_ANY;
    server.address.sin_port = htons(port);
    server.addrlen = sizeof(server.address);
    return (set_server(server, filename));
}