//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_word_array_to_str(char **array)
{
    char *str = malloc(sizeof(char) * 500);
    str = strcpy(str, array[0]);
    strcat(str, "\n");

    for (int i = 1; array[i + 1] && array[i+1] != NULL; i++) {
        strcat(str, array[i]);
        strcat(str, "\n");
    }

    return str;
}