//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include <string.h>
#include <stdio.h>
#include "../include/dico.h"

int sending_map(server_t __attribute__((unused)) *server,
                select_t __attribute__((unused)) *select,
                list_t *list)
{
    if (!list->cmd_support) {
        list->type = 2;
        list->ret = 0;
        list->is_text = true;
        list->text = strdup(my_word_array_to_str(list->map));
    }
    return (0);
}
