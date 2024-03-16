/*
** EPITECH PROJECT, 2023
** strcat
** File description:
** a
*/
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int len1 = my_strlen(dest);

    for (int i = 0; src[i] != '\0'; i++) {
        dest[len1 + i] = src[i];
    }
    dest[len1 + my_strlen(src)] = '\0';
    return dest;
}
