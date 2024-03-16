/*
** EPITECH PROJECT, 2023
** handling_flags_characters_2.c
** File description:
** flag characters 2
*/
#include "include/my.h"
#include "include/percent.h"

int hashtag(char f, char conv, int *size, int base)
{
    if (f == '#')
        base = verif_base(conv, size);
    return base;
}

int increase(char f, char conv, int *size, int nb)
{
    int plus = 0;

    if (f == '+' && conv == 'd') {
        *size += 1;
        plus = verif_pos(nb);
    }
    return plus;
}

int less(char f, int placement)
{
    if (f == '-')
        placement = 1;
    return placement;
}

int zero(char *flag, int uni, char f, char conv)
{
    if (f == '0')
        uni = verif_otherflags(flag, conv);
    return uni;
}

int handling(char **f, char conv, int nb, int *size)
{
    int uni = 0;
    int plt = 0;
    int p = cmp_nbr(my_getnbr(f[2]));
    char *flag = reorganization(f[0]);
    int plus = 0;
    int base = 0;

    for (int i = 0; flag[i] != '\0'; i++) {
        base = hashtag(flag[i], conv, size, base);
        plus += increase(flag[i], conv, size, nb);
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
