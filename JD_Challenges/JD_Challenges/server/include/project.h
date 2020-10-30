//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#ifndef JDCHALLENGE_H
#define JDCHALLENGE_H

#include "struct.h"

void set_position(list_t *);
char **create_map(char *);
int create_server(int, char *);
int reset_fd_set(server_t *, select_t *);
int loop_server(server_t *, select_t *);
int read_function(server_t *, select_t *, int);
int client_connection(server_t *, select_t *);
int write_function(select_t *, int);
int command_management(server_t *, select_t *, char *, int);
char **my_str_to_word_array(char *, char);
char *my_word_array_to_str(char **);
int my_strlen_array(char **);

#endif //JDCHALLENGE_H
