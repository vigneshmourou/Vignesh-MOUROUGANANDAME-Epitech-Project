/*
** EPITECH PROJECT, 2023
** gest.c
** File description:
** gest.c
*/
#include "include/my.h"
#include "include/percent.h"

void gest(int base, char conv)
{
    if (base == 2 && conv == 'x')
        my_putstr("0x");
    if (base == 2 && conv == 'X')
        my_putstr("0X");
    if (base == 1 && conv == 'o')
        my_putstr("0");
    return;
}

void gest2(char conv, int plus)
{
    if (plus == 1 && conv == 'd')
        my_putchar('+');
    return;
}
