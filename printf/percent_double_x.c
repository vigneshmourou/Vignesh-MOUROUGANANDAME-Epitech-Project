/*
** EPITECH PROJECT, 2023
** decimal to binary
** File description:
** convertisseur
*/
#include <stdarg.h>
#include <stdlib.h>
#include "include/percent.h"
#include "include/my.h"

int counting_hexa(int nb)
{
    int count = 0;

    while (nb != 0) {
        nb = nb / 16;
        count++;
    }
    return count;
}

char *to_hexa(unsigned int nb, int x)
{
    unsigned int hex;
    char *hexadecimal;
    int elem = 0;
    int count = 0;

    hexadecimal = malloc(sizeof(char) * counting_hexa(nb));
    for (int i = 0; nb != 0; i++) {
        hex = nb % 16;
        nb = nb / 16;
        if (hex + 48 >= 58 && hex + 48 <= 63) {
            hexadecimal[i] = hex + x;
            continue;
        }
        hexadecimal[i] = hex + 48;
    }
    my_revstr(hexadecimal);
    return hexadecimal;
}

void percent_x(va_list ap, int *nb_print, char **flag)
{
    char *hexa = to_hexa(va_arg(ap, unsigned int), 87);
    int size = my_strlen(hexa);
    int *sz = &size;
    int width = my_getnbr(flag[1]);

    switch (handling_str(flag, 'x', hexa, sz)) {
    case (1) :
        precis(flag, 'x', sz, 0);
        my_putstr(hexa);
        my_put_spaces(width - size, ' ');
        return;
    case (2) :
        if (plus_used(flag[0]) == 1)
            size--;
        my_put_spaces(width - size, '0');
    }
    precis(flag, 'x', sz, 0);
    my_putstr(hexa);
    *nb_print += size;
    return;
}

void percent_upx(va_list ap, int *nb_print, char **flag)
{
    char *hexa = to_hexa(va_arg(ap, unsigned int), 55);
    int size = my_strlen(hexa);
    int *sz = &size;
    int width = my_getnbr(flag[1]);

    switch (handling_str(flag, 'X', hexa, sz)) {
    case (1) :
        precis(flag, 'x', sz, 0);
        my_putstr(hexa);
        my_put_spaces(width - size, ' ');
        return;
    case (2) :
        if (plus_used(flag[0]) == 1)
            size--;
        my_put_spaces(width - size, '0');
    }
    precis(flag, 'x', sz, 0);
    *nb_print = *nb_print + size;
    my_putstr(hexa);
    return;
}
