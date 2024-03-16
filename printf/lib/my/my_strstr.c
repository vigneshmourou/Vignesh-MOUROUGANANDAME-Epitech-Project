/*
** EPITECH PROJECT, 2023
** my_strtsr.c
** File description:
** strstr
*/

#include <stddef.h>

int static verif_simi(char const *to_find, char *str, int place, int start)
{
    while (str[place] == to_find[start]) {
        start ++;
        place ++;
        if (to_find[start] == '\0') {
            return 1;
        }
        if (str[place] == '\0') {
            return 0;
        }
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    int place = 0;
    int start = 0;
    int success = 0;

    while (str[place] != '\0') {
        if (str[place] == to_find[start]) {
            success = verif_simi(to_find, str, place, start);
        }
        if (success == 1) {
            return &(str[place]);
        }
        place ++;
    }
    return NULL;
}
