//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#ifndef JDCHALLENGE_DICO_H
#define JDCHALLENGE_DICO_H

#include "project.h"

int clear(server_t *, select_t *, list_t *);
int sending_map(server_t *, select_t *, list_t *);
int move_down(server_t *, select_t *, list_t *);
int move_right(server_t *, select_t *, list_t *);
int move_left(server_t *, select_t *, list_t *);
int move_up(server_t *, select_t *, list_t *);
int action(server_t *, select_t *, list_t *);

typedef struct dico_s {
    int (*func)();

    char *cmd_name;
    char *help;
} dico_t;

static const dico_t dico[10] = {
    {&clear,  "CLEAR\n", " :\tclear the console\n"},
    {&sending_map,  "MAP\n", " :\tsend the map\n"},
    {&move_right,  "RIGHT\n", " :\tmove to the right\n"},
    {&move_left,  "LEFT\n", " :\tmove to the left\n"},
    {&move_up,  "UP\n", " :\tmove to the top\n"},
    {&move_down,  "DOWN\n", " :\tmove to the bottom\n"},
    {&sending_map,  "NEXT\n", " :\tgo to the next map\n"},
    {&sending_map,  "VISION\n", " :\tsee friend's map\n"},
    {&action,  "ACTION\n", " :\tsee friend's map\n"},
    {NULL, NULL, NULL}
};

#endif //JDCHALLENGE_DICO_H
