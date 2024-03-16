/*
** EPITECH PROJECT, 2023
** percent_d_per.c
** File description:
** percent from conversion d to %
*/
#include <stdarg.h>
#include "include/percent.h"
#include "include/my.h"

void percent_iud(va_list ap, int *nb_print, char **flag)
{
    int nb = va_arg(ap, int);
    int size = cmp_nbr(nb);
    int *sz = &size;
    int width = my_getnbr(flag[1]);

    switch (handling(flag, 'd', nb, sz)) {
    case (1) :
        precis(flag, 'd', sz, nb);
        my_put_nbr(nb);
        my_put_spaces(width - size, ' ');
        return;
    case (2) :
        my_put_spaces(width - size, '0');
    }
    precis(flag, 'd', sz, nb);
    *nb_print += size;
    my_put_nbr(nb);
    return;
}

void percent_s(va_list ap, int *nb_print, char **flag)
{
    char *var = va_arg(ap, char *);
    int size = my_strlen(var);
    int width = my_getnbr(flag[1]);
    int placement = 0;

    for (int i = 0; flag[0][i] != '\0'; i++)
        if (flag[0][i] == '-')
            placement = 1;
    if (width > size)
        placement = spaces_handle(width - size, 0, placement, "0");
    if (placement == 1) {
        my_putstr(var);
        my_put_spaces(width - size, ' ');
        return;
    }
    *nb_print += size;
    my_putstr(var);
    return;
}

void percent_c(va_list ap, int *nb_print, char **flag)
{
    char c = (char) va_arg(ap, int);
    int size = 1;
    int *sz = &size;
    int width = my_getnbr(flag[1]);

    switch (handling(flag, 'c', c, sz)) {
    case (1) :
        my_putchar(c);
        my_put_spaces(width - size, ' ');
        return;
    case (2) :
        my_put_spaces(width - size, '0');
    }
    *nb_print += size;
    my_putchar(c);
    return;
}

void percent_per(va_list ap, int *nb_print, char **flag)
{
    char conv = '%';

    *nb_print = *nb_print + 1;
    my_putchar('%');
    return;
}
