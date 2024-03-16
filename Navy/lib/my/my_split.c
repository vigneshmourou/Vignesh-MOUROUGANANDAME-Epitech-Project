/*
** EPITECH PROJECT, 2023
** my_str_to_world_array
** File description:
** transform str to world array
*/
#include "../../include/my.h"
#include <stdlib.h>

int nb_word(char *str, char sep)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep || str[i] == '\t')
            nb++;
    }
    nb += 2;
    return nb;
}

void malloc_world(char **dest, char *str, char sep)
{
    int letter = 0;
    int mot = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        letter ++;
        if (str[i] == sep || str[i] == '\t') {
            dest[mot] = malloc(sizeof(char) * letter + 1);
            mot++;
            letter = 0;
        }
    }
    dest[mot] = malloc(sizeof(char) * letter + 1);
}

void fill_world(char **dest, char *str, char sep)
{
    int letter = 0;
    int mot = 0;
    int test = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep || str[i] == '\t') {
            dest[mot][letter] = '\0';
            mot++;
            letter = 0;
            continue;
        }
        dest[mot][letter] = str[i];
        letter++;
    }
    if (dest[mot][letter - 1] == '\n')
        dest[mot][letter - 1] = '\0';
    dest[mot][letter] = '\0';
    dest[mot + 1] = NULL;
}

char **my_split(char **dest, char *str, char sep)
{
    dest = malloc(sizeof(char *) * nb_word(str, sep) + 1);
    malloc_world(dest, str, sep);
    fill_world(dest, str, sep);
    return dest;
}
