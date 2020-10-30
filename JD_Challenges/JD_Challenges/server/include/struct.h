//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#ifndef JDCHALLENGES_STRUCT_H
#define JDCHALLENGES_STRUCT_H

#include <zconf.h>
#include <netinet/in.h>
#include <stdbool.h>

typedef struct list {
    int fd;
    int type;
    char *cmd;
    char *cmd_support;
    int ret;

    bool is_text;
    char *text;

    char **map;
    char character;

    int pos_x;
    int pos_y;
    bool action;
    char on;
    bool key;
    bool button;

    bool to_delete;
    struct list *first;
    struct list *next;
} list_t;

typedef struct server {
    char *path;
    struct sockaddr_in address;
    int addrlen;
    int fd;
    int new_fd;
} server_t;

typedef struct select {
    char *map_name;
    fd_set fd_read;
    fd_set fd_write;
    int max_fd;
    list_t *list;
} select_t;

#endif //JDCHALLENGES_STRUCT_H
