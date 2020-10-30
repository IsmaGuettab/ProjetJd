//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/project.h"


int is_readeable(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((32 > str[i] || str[i] > 126) && str[i] != '\r' && str[i] != '\n')
            return (1);
    }
    return (0);
}


int read_function(server_t *server, select_t *select, int fd)
{
    char buffer[1024];
    int ret = 0;
    list_t *list = select->list;


    if (fd == server->fd && client_connection(server, select) == 1)
        return (1);
    else if (fd != server->fd) {
        for (; list->fd != fd; list = list->next);
        if ((ret = read(fd, buffer, 1024)) <= 2) {
            list->to_delete = true;
            return (0);
        }
        if (is_readeable(buffer) == 0 &&
            command_management(server, select, buffer, fd) == 1)
            return (1);
        memset(buffer, 0, sizeof(buffer));
    }
    return (0);
}

int write_function(select_t *select, int fd)
{
    char buffer[5];
    list_t *list = select->list;
    for (; list->fd != fd; list = list->next);
    if (list->ret != 0) {
        sprintf(buffer, "%d\r\n", list->ret);
        write(fd, buffer, strlen(buffer));
    }
    list->type = 1;
    list->cmd = NULL;
    list->cmd_support = NULL;
    list->ret = 0;
    if (list->is_text == true) {
        write(list->fd, list->text, strlen(list->text));
        free(list->text);
        list->text = NULL;
        list->is_text = false;
    }
    return (0);
}
