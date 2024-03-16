/*
** EPITECH PROJECT, 2023
** handling_str.c
** File description:
** handling strings
*/
#include "include/my.h"
#include "include/percent.h"

int verif_pos_str(char *nb, char conv)
{
    if (nb[0] != '-' && conv == 'f')
        return 1;
    if (nb[0] == '-' && conv == 'f')
        return 0;
    return 0;
}

int increase_str(char f, char conv, int *size, char *nb)
{
    int plus = 0;

    if (f == '+') {
        *size += 1;
        plus = verif_pos_str(nb, conv);
    }
    return plus;
}

int handling_str(char **f, char conv, char *nb, int *size)
{
    int uni = 0;
    int plt = 0;
    int p = cmp_nbr(my_getnbr(f[2]));
    char *flag = reorganization(f[0]);
    int plus = 0;
    int base = 0;

    for (int i = 0; flag[i] != '\0'; i++) {
        base = hashtag(flag[i], conv, size, base);
        plus += increase_str(flag[i], conv, size, nb);
        plt = less(flag[i], plt);
        uni = zero(flag, uni, flag[i], conv);
    }
    if (my_getnbr(f[1]) > *size)
        plt = spaces_handle(my_getnbr(f[1]) - *size - p, uni, plt, f[2]);
    else
        plt = 0;
    gest(base, conv);
    gest2(conv, plus);
    return plt;
}
