//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#include "../include/project.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <zconf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int write_function(client_t *client, select_t *select)
{
    if (select->type == 2) {
        write(client->client_fd, select->text, strlen(select->text));
        free(select->text);
        select->type = 1;
    }
    return (0);
}


int read_function(select_t *select, char *buffer)
{
    sprintf(select->map, "%s", buffer);
    erase();
    printw("%s\n", select->map);
    refresh();
    return 0;
}


