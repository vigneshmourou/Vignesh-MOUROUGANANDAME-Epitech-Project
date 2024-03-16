/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** my_strcat
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int max_d = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; ++i) {
        dest[max_d] = src[i];
        max_d ++;
    }
    return dest;
}
