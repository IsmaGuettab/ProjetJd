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

int create_client()
{
    client_t client;
    select_t select;

    select.type = 2;
    client.address.sin_family = AF_INET;
    client.address.sin_addr.s_addr = INADDR_ANY;
    client.address.sin_port = htons(1024);
    client.addrlen = sizeof(client.address);
    if ((client.client_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return (1);
    }
    if ((client.server_fd = connect(client.client_fd, (struct sockaddr *)&client.address, client.addrlen)) < 0) {
        perror("connect");
    } else {
        select.type = 1;
    }
    if (client.client_fd > client.server_fd)
        select.max_fd = client.client_fd + 1;
    else
        select.max_fd = client.server_fd + 1;
    FD_ZERO(&select.fd_read);
    FD_ZERO(&select.fd_write);
    select.text = NULL;
    select.button = false;
    select.action = false;
    init_ncurses();
    while (select_client(&client, &select) != 1);
    return (0);
}
