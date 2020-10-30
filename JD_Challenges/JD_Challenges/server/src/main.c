//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/project.h"


int error_management(char *str)
{
    if (strcmp(str, "-h") == 0 || strcmp(str, "--help") == 0)
        return 2;
    for (int i = 0; str[i] != 0; i++)
        if ('0' > str[i] || str[i] > '9')
            return 1;
    return 0;
}


int main(int ac, char **av)
{
    int ret = 0;

    if (ac != 2) {
        printf("USAGE: ./server map_number(01)\n");
        return (84);
    } else if ((ret = error_management(av[1])) != 0) {
        if (ret == 2) {
            printf("USAGE: ./server map_number(01)\n");
            return 0;
        }
        return (84);
    }
    if (create_server(1024, av[1]) == 1) {
        return (84);
    }
    return (0);
}