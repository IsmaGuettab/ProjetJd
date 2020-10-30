//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//

#include "../include/project.h"

int my_strlen_array(char **array)
{
    int i = 0;

    for (; array[i] && array[i] != NULL; i++);

    return i;
}
