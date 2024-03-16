/*
** EPITECH PROJECT, 2024
** user input
** File description:
** file for handle every input of user
*/

#include "my.h"
#include <stddef.h>
#include <stdio.h>

char *my_getuser(void)
{
    char *line = NULL;
    size_t len = 0;
    int i = 0;

    i = getline(&line, &len, stdin);
    if (i < 0)
        return NULL;
    if (line[2] == '\n')
        line[2] = '\0';
    return line;
}
