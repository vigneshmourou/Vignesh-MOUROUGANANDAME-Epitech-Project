/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** my_strupcase
*/
#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; i != my_strlen(str); ++i) {
        if (str[i] > 96 && str[i] < 123) {
            str[i] = str[i] - 32;
        }
    }
    return str;
}
