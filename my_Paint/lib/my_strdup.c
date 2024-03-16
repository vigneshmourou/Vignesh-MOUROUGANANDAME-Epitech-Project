/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** string duplicate
*/
#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(char *src)
{
    char *stock = NULL;
    int count = my_strlen(src);

    stock = malloc(sizeof(char) * (count + 1));
    for (int i = 0; i < count; i++)
        stock[i] = src[i];
    stock[count] = '\0';
    return stock;
}
