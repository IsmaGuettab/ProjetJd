//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#include "../include/dico.h"
#include <string.h>
#include <stdio.h>


int clear(server_t __attribute__((unused)) *server,
           select_t __attribute__((unused)) *select,
           list_t *list)
{
    if (!list->cmd_support) {
        list->type = 2;
        list->ret = 0;
        list->is_text = true;
        list->text = strdup("\e[1;1H\e[2J");
    }
    return (0);
}

