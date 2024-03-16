/*
** EPITECH PROJECT, 2024
** strcom
** File description:
** comparator of 2 str
*/

#include "../../include/my.h"

int my_strcmp(char *str1, char *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return EXIT_ERROR;
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return EXIT_ERROR;
    }
    return 0;
}
