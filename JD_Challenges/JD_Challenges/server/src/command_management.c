//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include "../include/dico.h"
#include <string.h>
#include <stdio.h>

void key(list_t *list)
{
    if (list->on == 'c') {
        list->on = ' ';
        list->key = true;
    }
}

int command_management(server_t *server, select_t *select, char *buffer,
    int fd)
{
    list_t *list = select->list;
    char **array = NULL;

    array = my_str_to_word_array(buffer, ' ');
    for (int i = 0; dico[i].cmd_name; i++) {
        if (strcmp(array[0], dico[i].cmd_name) == 0) {
            for (; list->fd != fd; list = list->next);
            list->cmd = array[0];
            if (array[1] != NULL)
                list->cmd_support = array[1];
            else
                list->cmd_support = NULL;
            dico[i].func(server, select, list);
            key(list);
            sending_map(server, select, list);
        }
    }
    return (0);
}
