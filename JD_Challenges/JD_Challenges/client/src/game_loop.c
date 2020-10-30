//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#include "../include/project.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reset_fd_list(client_t *client, select_t *select)
{
    if (FD_ISSET(client->client_fd, &select->fd_read))
        FD_CLR(client->client_fd, &select->fd_read);
    FD_SET(client->client_fd, &select->fd_read);
    if (FD_ISSET(client->server_fd, &select->fd_write))
        FD_CLR(client->server_fd, &select->fd_write);

    if (select->type == 1) {
        FD_SET(client->server_fd, &select->fd_read);
    } else if (select->type != 1)
        FD_SET(client->server_fd, &select->fd_write);
    return 0;
}

void fd_set_detection(client_t *client, select_t *select)
{
    char buffer[1024];

    memset(buffer, 0, 1024);
    if (FD_ISSET(client->client_fd, &select->fd_read)) {
        if (read(client->client_fd, buffer, 1024) == 0)
            exit(0);
        if (strlen(buffer) >= 2) {
            sprintf(select->map, "%s", buffer);
            read_function(select, buffer);
        }
    } else if (FD_ISSET(client->server_fd, &select->fd_write)) {
        write_function(client, select);
    }

    erase();
    printw("%s\n", select->map);
    refresh();
}

void state(client_t *client, select_t *select)
{
    static int i = 0;

    if (i < 6 && select->button == true) {
        i = 7;
    } else if (select->action == true)
        i = 5;

    if (i < 4) {
        i++;
        printw("Hey\n");
    } else if (select->action == false && select->button == false) {
        ncurses_key(client, select);
    } else if (i == 5) {
        i = 4;
        select->action = false;
    } else if (i == 6) {
        i = 8;
    } else if (i == 8) {
        i = 4;
        select->button = false;
    } else if (i == 7) {
        select->text = malloc(sizeof(char) * 7);
        sprintf(select->text, "ACTION\n");
        select->type = 2;
        i = 6;
    }
}


int select_client(client_t *client, select_t *select_s)
{
    reset_fd_list(client, select_s);
    if (select(select_s->max_fd, &select_s->fd_read, &select_s->fd_write, NULL, NULL) < 0) {
        perror("select");
        return 1;
    }
    fd_set_detection(client, select_s);
    state(client, select_s);
    return 0;
}


