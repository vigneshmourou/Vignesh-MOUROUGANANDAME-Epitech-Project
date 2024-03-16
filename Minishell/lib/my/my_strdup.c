/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** strdup
*/
#include "../../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *dest = NULL;

    dest = malloc(sizeof(char) * my_strlen(src) + 1);
    dest[0] = '\0';
    my_strcat(dest, src);
    return dest;
}
