//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include <stdio.h>
#include "../include/project.h"

void reset_support(server_t *server, select_t *select)
{
    if (FD_ISSET(server->fd, &select->fd_read))
        FD_CLR(server->fd, &select->fd_read);
    for (list_t *list = select->list; list->next != NULL;
         list = list->next) {
        if (list->type == 1 && FD_ISSET(list->fd, &select->fd_read))
            FD_CLR(list->fd, &select->fd_read);
        else if (list->type == 2 && FD_ISSET(list->fd, &select->fd_write))
            FD_CLR(list->fd, &select->fd_write);
        if (list->type == 1 && FD_ISSET(list->fd, &select->fd_write))
            FD_CLR(list->fd, &select->fd_write);
        else if (list->type == 2 && FD_ISSET(list->fd, &select->fd_read))
            FD_CLR(list->fd, &select->fd_read);
    }
}

int delete_support(select_t *select)
{
    list_t *list = select->list;
    if (list->to_delete == true) {
        FD_CLR(list->fd, &select->fd_read);
        FD_CLR(list->fd, &select->fd_write);
        list_t *first = list->next;
        for (; list->next != NULL; list = list->next)
            list->first = first;
        select->list = first;
        return 1;
    }
    return 0;
}

void delete_client(server_t *server, select_t *select)
{
    if (delete_support(select) == 1) {
        delete_client(server, select);
        return;
    }
    for (list_t *list = select->list; list->next != NULL; list = list->next) {
        if (list->next->to_delete == true) {
            FD_CLR(list->next->fd, &select->fd_read);
            FD_CLR(list->next->fd, &select->fd_write);
            list->next = list->next->next;

        }
    }
}

int reset_fd_set(server_t *server, select_t *select)
{
    delete_client(server, select);
    reset_support(server, select);
    FD_SET(server->fd, &select->fd_read);
    for (list_t *list = select->list; list->next != NULL;
        list = list->next) {
        if (list->type == 1)
            FD_SET(list->fd, &select->fd_read);
        else if (list->type == 2)
            FD_SET(list->fd, &select->fd_write);
    }
    return (0);
}
