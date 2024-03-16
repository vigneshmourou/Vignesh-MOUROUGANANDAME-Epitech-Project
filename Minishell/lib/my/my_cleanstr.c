/*
** EPITECH PROJECT, 2024
** clean str
** File description:
** function to remove waste space
*/
#include "../../include/my.h"
#include <stdlib.h>

static int count_letter(char *str, char letter)
{
    int len = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if ((i == 0 && str[i] == letter) ||
            (str[i - 1] == letter && str[i] == letter) ||
            (i == my_strlen(str) - 1 && str[i] == letter))
            len --;
    }
    return len;
}

char *my_cleanstr(char *str, char letter)
{
    char *new_str = NULL;
    int len = 0;
    int index = 0;

    len = count_letter(str, letter);
    new_str = malloc(sizeof(char) * (len + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if ((i == 0 && str[i] == letter) ||
            (str[i - 1] == letter && str[i] == letter) ||
            (i == my_strlen(str) - 1 && str[i] == letter))
            continue;
        else {
            new_str[index] = str[i];
            index ++;
        }
    }
    new_str[index] = '\0';
    return new_str;
}