/*
** EPITECH PROJECT, 2023
** flags
** File description:
** do the flags e for exponentiel
*/
#include "include/my.h"
#include "include/percent.h"
#include <stdarg.h>
#include <stdlib.h>

void to_int(char *print_percent, int nb)
{
    int dec;
    char *decimal;

    decimal = malloc(sizeof(char) * cmp_nbr(nb));
    if (nb == 0)
        decimal[0] = '0';
    for (int i = 0; nb != 0; i++) {
        dec = nb % 10;
        nb = nb / 10;
        decimal[i] = dec + 48;
    }
    my_revstr(decimal);
    my_strcat(print_percent, decimal);
    return;
}

void percent_f_parcours(double vig_nb, int pre, int *nb_print, char *prc)
{
    for (int i = 1; i <= pre; i++) {
        vig_nb = vig_nb - (int)vig_nb;
        vig_nb = vig_nb * 10;
        if (i == pre && (((int)(vig_nb * 10)) % 10) >= 5) {
            to_int(prc, ((int)vig_nb + 1) % 10);
        } else
            to_int(prc, ((int)vig_nb));
        *nb_print += 1;
        if (i == pre)
            prc[i + 4] = '\0';
        if (pre == 0) {
            *nb_print -= 1;
            prc[i] = '\0';
        }
    }
    return;
}

char *second_percent_f(double vig_nb, int *nb_print, char **flag, char *prc)
{
    int entier = (int)vig_nb;
    int precision;

    precision = verif_pre(precision, flag);
    prc = malloc(sizeof(char) * (precision + cmp_nbr(entier) + 3));
    my_strcat(prc, "-");
    vig_nb = verif_point(prc, precision, vig_nb);
    *nb_print += cmp_nbr(entier) + 2;
    percent_f_parcours(vig_nb, precision, nb_print, prc);
    return prc;
}

char *converting_f(va_list ap, int *nb_print, char **flag)
{
    double vig_nb = va_arg(ap, double);
    int pre;
    char *prc;

    pre = verif_pre(pre, flag);
    if ((int)vig_nb < 0) {
        return second_percent_f(vig_nb * -1.0, nb_print, flag, prc);
    }
    prc = malloc(sizeof(char) * (pre + cmp_nbr((int)vig_nb) + 2));
    vig_nb = verif_point(prc, pre, vig_nb);
    *nb_print += cmp_nbr((int)vig_nb) + 1;
    percent_f_parcours(vig_nb, pre, nb_print, prc);
    return prc;
}

void percent_f(va_list ap, int *nb_print, char **flag)
{
    char *nb = converting_f(ap, nb_print, flag);
    int size = my_strlen(nb);
    int *sz = &size;
    int width = my_getnbr(flag[1]);

    switch (handling_str(flag, 'f', nb, sz)) {
    case (1) :
        my_putstr(nb);
        my_put_spaces(width - size, ' ');
        return;
    case (2) :
        my_put_spaces(width - size, '0');
    }
    *nb_print += size + 1;
    my_putstr(nb);
    return;
}
