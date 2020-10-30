//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#ifndef JDCHALLENGES_STRUCT_H
#define JDCHALLENGES_STRUCT_H


#include <zconf.h>
#include <netinet/in.h>
#include <stdbool.h>

typedef struct client {
    char *path;
    struct sockaddr_in address;
    int addrlen;
    int client_fd;
    int server_fd;
} client_t;

typedef struct select {
    fd_set fd_read;
    fd_set fd_write;
    int max_fd;
    int type;
    char *text;
    bool button;
    char map[500];
    bool action;
} select_t;

#endif //JDCHALLENGES_STRUCT_H
