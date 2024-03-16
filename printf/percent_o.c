/*
** EPITECH PROJECT, 2023
** percent_o.c
** File description:
** percent octal
*/
#include <stdarg.h>
#include <stdlib.h>
#include "include/percent.h"
#include "include/my.h"

int counting_octal(int nb)
{
    int count = 0;

    while (nb != 0) {
        nb = nb / 8;
        count++;
    }
    return count;
}

unsigned int to_octal(unsigned int nb)
{
    int oct;
    unsigned int result = 0;
    char *octal;
    int power = 0;
    int elem = 0;

    octal = malloc(sizeof(int) * counting_octal(nb));
    for (int i = 0; nb != 0; i++) {
        oct = nb % 8;
        octal[i] = oct + 48;
        nb = nb / 8;
    }
    for (int j = 0; octal[j] != '\0'; j++) {
        elem = octal[j] - 48;
        result = result + (elem * my_compute_power_it(10, power));
        power++;
    }
    return result;
}

void percent_o(va_list ap, int *nb_print, char **flag)
{
    int octa = to_octal(va_arg(ap, unsigned int));
    int size = cmp_nbr(octa);
    int *sz = &size;
    int width = my_getnbr(flag[1]);

    switch (handling(flag, 'o', octa, sz)) {
    case (1) :
        precis(flag, 'o', sz, octa);
        my_put_nbr(octa);
        my_put_spaces(width - size, ' ');
        return;
    case (2) :
        my_put_spaces(width - size, '0');
    }
    precis(flag, 'o', sz, octa);
    *nb_print += size;
    my_put_nbr(octa);
    return;
}
