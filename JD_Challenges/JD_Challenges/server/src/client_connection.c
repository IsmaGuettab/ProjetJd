//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/dico.h"

void set_position(list_t *list)
{
    for (int line = 0; list->map[line] != NULL; line++)
        for (int col = 0; list->map[line][col] != '\0'; col++)
            if (list->map[line][col] == 'o' || list->map[line][col] == 'k' || list->map[line][col] == '?') {
                list->pos_x = col;
                list->pos_y = line;
            }
}

void set_character(select_t *select, list_t *list)
{
    char player[3];
    int count = 0;
    char *name = malloc(sizeof(char) * 12);
    char *name1 = malloc(sizeof(char) * 12);

    for (list_t *cursor = select->list; cursor->fd != -1; cursor = cursor->next) {
        if (cursor->character != '?')
            player[count] = cursor->character;
        count++;
    }

    if (strchr(player, 'o') == NULL)
        count = 1;
    else if (strchr(player, 'k') == NULL)
        count = 2;
    else if (strchr(player, '?') == NULL)
        count = 3;


    if (count == 1)
        list->character = 'o';
    else if (count == 2)
        list->character = 'k';
    else if (count == 3)
        list->character = '?';

    sprintf(name, "%s_%d", select->map_name, count);
    sprintf(name1, "server/maps/%s", name);
    list->map = create_map(name1);
    free(name);
    free(name1);
    set_position(list);
}


void connected_client(list_t *list)
{
    list->next->cmd = NULL;
    list->next->cmd_support = NULL;
    list->next->ret = 0;
    list->is_text = false;
    list->text = NULL;
    list->pos_x = 0;
    list->pos_y = 0;
    list->action = false;
    list->key = false;
    list->button = false;
    list->on = ' ';
    list->character = '?';
    list->to_delete = false;
    list->next->next = NULL;
    list->next->first = list->first;
}

void set_connected_client(server_t *server, select_t *select)
{
    list_t *list = select->list;

    if (server->new_fd > select->max_fd)
        select->max_fd = server->new_fd + 1;
    for (; list->next != NULL; list = list->next);
    list->fd = server->new_fd;
    list->type = 1;
    list->next = malloc(sizeof(list_t));
    list->next->fd = -1;
    list->next->type = -1;
    list->next->to_delete = false;
    connected_client(list);
    set_character(select, list);
    sending_map(server, select, list);
}

int client_connection(server_t * server, select_t *select)
{
    if ((server->new_fd = accept(server->fd,
                                 (struct sockaddr *)&server->address,
                                 (socklen_t *)&server->addrlen)) < 0) {
        perror("accept");
        return (1);
    } else {
        //write(server->new_fd, "220", 5);
        set_connected_client(server, select);
    }
    return (0);
}
