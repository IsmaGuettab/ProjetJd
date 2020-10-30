//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include "../include/dico.h"
#include <stdio.h>

int move_down(server_t __attribute__((unused)) *server,
              select_t __attribute__((unused)) *select,
              list_t *list)
{
    char on;

    if (list->map[list->pos_y + 1] == NULL)
        return 0;



    if (list->map[list->pos_y + 1][list->pos_x] == 'A' || list->map[list->pos_y + 1][list->pos_x] == ' ' || list->map[list->pos_y + 1][list->pos_x] == 'c')
    {
        on = list->on;
        list->on = list->map[list->pos_y + 1][list->pos_x];
        list->map[list->pos_y + 1][list->pos_x] = list->character;
        list->map[list->pos_y][list->pos_x] = on;
        list->pos_y++;
    }
    return 0;
}

int move_up(server_t __attribute__((unused)) *server,
            select_t __attribute__((unused)) *select,
            list_t *list)
{
    char on;

    if (list->pos_y == 0)
        return 0;

    if (list->map[list->pos_y - 1][list->pos_x] == 'A' || list->map[list->pos_y - 1][list->pos_x] == ' '  || list->map[list->pos_y - 1][list->pos_x] == 'c')
    {
        on = list->on;
        list->on = list->map[list->pos_y - 1][list->pos_x];
        list->map[list->pos_y - 1][list->pos_x] = list->character;
        list->map[list->pos_y][list->pos_x] = on;
        list->pos_y--;
    }
    return 0;
}

int move_right(server_t __attribute__((unused)) *server,
               select_t __attribute__((unused)) *select,
               list_t *list)
{
    char on;

    if (list->map[list->pos_y][list->pos_x + 1] == '\0')
        return 0;

    if (list->map[list->pos_y][list->pos_x + 1] == 'A' || list->map[list->pos_y][list->pos_x + 1] == ' '  || list->map[list->pos_y][list->pos_x + 1] == 'c')
    {
        on = list->on;
        list->on = list->map[list->pos_y][list->pos_x + 1];
        list->map[list->pos_y][list->pos_x + 1] = list->character;
        list->map[list->pos_y][list->pos_x] = on;
        list->pos_x++;
    }
    return 0;
}


int move_left(server_t __attribute__((unused)) *server,
              select_t __attribute__((unused)) *select,
              list_t *list)
{
    char on;

    if (list->pos_x == 0)
        return 0;

    if (list->map[list->pos_y][list->pos_x - 1] == 'A' || list->map[list->pos_y][list->pos_x - 1] == ' '  || list->map[list->pos_y][list->pos_x - 1] == 'c')
    {
        on = list->on;
        list->on = list->map[list->pos_y][list->pos_x - 1];
        list->map[list->pos_y][list->pos_x - 1] = list->character;
        list->map[list->pos_y][list->pos_x] = on;
        list->pos_x--;
    }
    return 0;
}
