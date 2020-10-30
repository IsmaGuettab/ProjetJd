//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#include "../include/dico.h"
#include <string.h>
#include <stdio.h>

char look_around(list_t *list)
{
    const char elements[] = "|-nC";
    char el = '?';

    if (list->map[list->pos_y+1] != NULL && strchr(elements, list->map[list->pos_y + 1][list->pos_x]) != NULL) {
        el = list->map[list->pos_y + 1][list->pos_x];
    } else if (list->pos_y != 0 && strchr(elements, list->map[list->pos_y - 1][list->pos_x]) != NULL) {
        el = list->map[list->pos_y - 1][list->pos_x];
    } else if (list->pos_x != 0 && strchr(elements, list->map[list->pos_y][list->pos_x - 1]) != NULL) {
        el = list->map[list->pos_y][list->pos_x - 1];
    } else if (list->map[list->pos_y][list->pos_x + 1] != '\0' && strchr(elements, list->map[list->pos_y][list->pos_x + 1]) != NULL)
        el = list->map[list->pos_y][list->pos_x + 1];

    return el;
}


int action(server_t __attribute__((unused)) *server,
               select_t *select,
               list_t *list)
{
    char el = look_around(list);

    if (el == '|') {
        for (int pos_y = 0; list->map[pos_y] != NULL; pos_y++)
            for (int pos_x= 0; list->map[pos_y][pos_x] != '\0'; pos_x++) {
                if (list->map[pos_y][pos_x] == '[') {
                    if ((pos_y == 0 || list->map[pos_y + 2] == NULL) || (pos_x == 0 || list->map[pos_y][pos_x + 1] == '\0' || list->map[pos_y][pos_x + 1] == ' '))
                        list->map[pos_y][pos_x] = 'A';
                    else
                        list->map[pos_y][pos_x] = ' ';
                } else if (list->map[pos_y][pos_x] == ']') {
                    if ((pos_y == 0 || list->map[pos_y + 2] == NULL) || (pos_x == 0 || list->map[pos_y][pos_x + 1] == '\0'))
                        list->map[pos_y][pos_x] = 'A';
                    else
                        list->map[pos_y][pos_x] = ' ';
                }
            }
    } else if (el == 'C') {
        for (int pos_y = 0; list->map[pos_y] != NULL; pos_y++)
            for (int pos_x= 0; list->map[pos_y][pos_x] != '\0'; pos_x++) {
                if (list->map[pos_y][pos_x] == 'C') {
                    if ((pos_y == 0 || list->map[pos_y + 2] == NULL) || (pos_x == 0 || list->map[pos_y][pos_x + 1] == '\0' || list->map[pos_y][pos_x + 1] == ' '))
                        list->map[pos_y][pos_x] = 'A';
                    else
                        list->map[pos_y][pos_x] = ' ';
                    list->key = false;
                }
            }
    } else if (el == 'n') {
        for (int pos_y = 0; list->map[pos_y] != NULL; pos_y++)
            for (int pos_x= 0; list->map[pos_y][pos_x] != '\0'; pos_x++) {
                if (list->map[pos_y][pos_x] == 'n') {
                    list->map[pos_y][pos_x] = '-';
                    list->button = true;
                }
            }
    } else if (el == '-') {
        for (list_t *cursor = select->list; cursor->next != NULL; cursor = cursor->next)
            if (cursor->button == false) {
                for (int pos_y = 0; list->map[pos_y] != NULL; pos_y++) {
                    for (int pos_x= 0; list->map[pos_y][pos_x] != '\0'; pos_x++) {
                        if (list->map[pos_y][pos_x] == '-') {
                            list->map[pos_y][pos_x] = 'n';
                            list->button = false;
                        }
                    }
                }
                return 0;
            }

        for (list_t *cursor = select->list; cursor->next && cursor->next != NULL; cursor = cursor->next) {
            for (int pos_y = 0; cursor->map[pos_y] != NULL; pos_y++)
                for (int pos_x= 0; cursor->map[pos_y][pos_x] != '\0'; pos_x++) {
                    if (cursor->map[pos_y][pos_x] == 'D') {
                        if ((pos_y == 0 || list->map[pos_y + 2] == NULL) || (pos_x == 0 || list->map[pos_y][pos_x + 1] == '\0' || list->map[pos_y][pos_x + 1] == ' '))
                            list->map[pos_y][pos_x] = 'A';
                        else
                            list->map[pos_y][pos_x] = ' ';
                    }
                }
            cursor->button = false;
        }
    }

    return 0;
}


