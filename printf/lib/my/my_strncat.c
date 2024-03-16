/*
** EPITECH PROJECT, 2023
** my_strncat.c
** File description:
** my_strncat
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int max_d = my_strlen(dest);

    for (int i = 0; i != nb; ++i) {
        dest[max_d] = src[i];
        max_d ++;
    }
    return dest;
}
