//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#ifndef JDCHALLENGES_PROJECT_H
#define JDCHALLENGES_PROJECT_H

#include "struct.h"
#include <ncurses.h>

void init_ncurses();
int ncurses_key(client_t *, select_t *);
int write_function(client_t *, select_t *);
int read_function(select_t *, char *);
int select_client(client_t *, select_t *);
int create_client();
int main();


#endif //JDCHALLENGES_PROJECT_H
