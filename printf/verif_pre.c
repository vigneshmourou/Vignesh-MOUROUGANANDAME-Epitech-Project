/*
** EPITECH PROJECT, 2023
** verif_pre.c
** File description:
** verif pre
*/
#include "include/my.h"
#include "include/percent.h"

int verif_pre(int pre, char **flag)
{
    if (flag[2][0] == ' ')
        pre = 6;
    else
        pre = my_getnbr(flag[2]);
    return pre;
}

double verif_point(char *prc, int pre, double vig_nb)
{
    if (pre == 1 && ((int)(vig_nb * 10) % 10) == 9 &&
        ((int)(vig_nb * 100) % 10) >= 5)
        to_int(prc, ((int)vig_nb + 1) % 10);
    else
        to_int(prc, (int)vig_nb);
    if ((int)vig_nb == vig_nb)
        vig_nb = 0.0;
    if (pre > 0) {
        prc = my_strcat(prc, ".");
    }
    return vig_nb;
}
