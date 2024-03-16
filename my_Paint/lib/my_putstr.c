/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** my_putstr
*/
#include "../include/my.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return;
}
