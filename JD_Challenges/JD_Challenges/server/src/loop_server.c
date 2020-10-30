//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include <stdio.h>
#include <stdlib.h>
#include "../include/dico.h"

void condition_next_room(select_t *select)
{
    list_t *list = select->list;
    int count = 0;
    char name[20];

    for (; list->next != NULL; list = list->next) {
        count++;
        if (list->on != 'A') {
            count *= -1;
            break;
        }
    }
    list = select->list;
    if (count > 0) {
        count = 0;
        count = atoi(select->map_name) + 1;
        sprintf(name, "0%d", count);
        sprintf(select->map_name, "%s", name);
        count = 0;
        for (; list->next != NULL; list = list->next) {
            count++;
            sprintf(name, "server/maps/%s_%d", select->map_name, count);
            list->on = ' ';
            list->map = create_map(name);
            set_position(list);
            sending_map(NULL, select, list);
        }
    }
}






int fds_detection(server_t *server, select_t *select, int fd)
{
    condition_next_room(select);
    if (FD_ISSET(fd, &select->fd_read)) {

        if (read_function(server, select, fd) == 1)
            return (1);
    } else if (FD_ISSET(fd, &select->fd_write))
        if (write_function(select, fd) == 1)
            return (1);
    return (0);
}



int loop_server(server_t *server, select_t *select_s)
{
    reset_fd_set(server, select_s);

    if (select(select_s->max_fd + 1, &select_s->fd_read, &select_s->fd_write,
        NULL, NULL) < 0) {
        perror("select");
        return (1);
    }

    for (int fd = 0; fd < select_s->max_fd + 1; fd++) {
        if (fds_detection(server, select_s, fd) == 1)
            return (1);
    }
    return (0);
}