/*
** EPITECH PROJECT, 2023
** my_strncpy.c
** File description:
** copying n characters from str to str_2
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (int i = 0; i != n; ++i) {
        dest[i] = src[i];
        if (i > my_strlen(dest)) {
            dest[i] = '\0';
        }
    }
    return dest;
}
