/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** cat string
*/
#include "../include/my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char *src)
{
    int end = 0;
    int len = my_strlen(dest) + my_strlen(src);
    char *stock = malloc(sizeof(char) * (len + 1));

    while (dest[end] != '\0')
        end++;
    for (int i = 0; dest[i] != '\0'; i++)
        stock[i] = dest[i];
    for (int i = 0; src[i] != '\0'; i++) {
        stock[end] = src[i];
        end++;
    }
    return stock;
}
