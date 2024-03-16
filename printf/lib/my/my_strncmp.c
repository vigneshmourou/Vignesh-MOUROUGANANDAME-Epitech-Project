/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** my_strncmp
*/
#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int size = my_strlen(s1);

    for (int i = 0; i != n; ++i) {
        if ( s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
