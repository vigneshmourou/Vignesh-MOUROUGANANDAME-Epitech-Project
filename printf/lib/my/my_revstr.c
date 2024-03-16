/*
** EPITECH PROJECT, 2023
** my_revstr.c
** File description:
** reverse string
*/
#include "my.h"

char *my_revstr(char *str)
{
    int last;
    int first = 0;
    char switcher;

    last = my_strlen(str) - 1;
    while (first < last) {
        switcher = str[first];
        str[first] = str[last];
        str[last] = switcher;
        first ++;
        last --;
    }
    return (str);
}
