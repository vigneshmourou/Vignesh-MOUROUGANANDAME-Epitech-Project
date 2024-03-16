/*
** EPITECH PROJECT, 2024
** word len
** File description:
** count nb of word
*/

#include <stddef.h>

int count_word(char **word)
{
    int nb = 0;

    for (int i = 0; word[i] != NULL; i++)
        nb++;
    return nb;
}
