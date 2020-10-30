//
// Created by Benjamin.
// benjamin.dupuis@epitech.eu
//


#include <stdlib.h>
#include <string.h>
#include "../include/project.h"

int    count_words(char *str, char sep)
{
    int    words = 0;
    int    i = -1;

    while (str[++i] != '\0')
        if ((str[i] != sep && str[i] != '\t') &&
            (str[i + 1] == sep || str[i + 1] == '\t' || str[i + 1] == '\0'))
            ++words;
    return (words);
}

int    my_wordlen(char *str, int *i, char sep)
{
    int    j = 0;

    while (str[++*i] != '\0')
        if (str[*i] != sep && str[*i] != '\t') {
            ++j;
            if (str[*i + 1] == sep || str[*i + 1] == '\t' ||
                str[*i + 1] == '\0')
                return (j);
        }
    return (-1);
}

char *my_wordcpy(char *array, char *str, int *i, char sep)
{
    int j = -1;

    while (str[++*i] != '\0')
        if (str[*i] != sep && str[*i] != '\t') {
            array[++j] = str[*i];
            if (str[*i + 1] == sep || str[*i + 1] == '\t' ||
                str[*i + 1] == '\0') {
                array[++j] = '\0';
                return (array);
            }
        }
    return (NULL);
}

char **my_str_to_word_array(char *str, char sep)
{
    int    words = count_words(str, sep);
    int    i = -1;
    int    j = -1;
    int    k = -1;
    char **array;

    if (str == NULL)
        return (NULL);
    if ((array = malloc(sizeof(char *) * (words + 1))) == NULL)
        return (NULL);
    while (++i < words) {
        if ((array[i] = malloc(sizeof(char) * (my_wordlen(str, &j, sep) + 1)))
            == NULL)
            return (NULL);
        array[i] = my_wordcpy(array[i], str, &k, sep);
    }
    array[i] = NULL;
    return (array);
}

int    free_array(char **array)
{
    int    i = -1;

    while (array[++i] != NULL)
        free(array[i]);
    free(array[i]);
    free(array);
    return (0);
}
