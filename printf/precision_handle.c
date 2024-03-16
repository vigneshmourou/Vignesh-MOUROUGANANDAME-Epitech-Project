/*
** EPITECH PROJECT, 2023
** precision_handle.c
** File description:
** precision
*/
#include "include/my.h"
#include "include/percent.h"

void verif_plus_tag(int plus, int tag, int *size)
{
    if (tag == 2)
        *size += 2;
    if (plus == 1 || tag == 1)
        *size += 1;
    return;
}

int precis(char **flag, char conv, int *size, int nb)
{
    int a = 0;
    int plus = 0;
    int tag = 0;

    for (int i = 0; flag[0][i] != '\0'; i++) {
        if (flag[0][i] == '+' && nb >= 0 && conv != 'o') {
            *size = *size - 1;
            plus = 1;
        }
        if (flag[0][i] == '#' && conv == 'x') {
            *size = *size - 2;
            tag = 2;
        }
    }
    if (flag[2][0] != ' ' && my_getnbr(flag[2]) > 0
        && *size < my_getnbr(flag[2]))
        put_precision(flag, conv, size, a);
    verif_plus_tag(plus, tag, size);
    return a;
}

int put_precision(char **flag, char conv, int *size, int a)
{
    int sz = *size;

    for (int i = 0; i != my_getnbr(flag[2]) - sz; i++) {
        if (conv == 'f') {
            *size += 1;
            a++;
        }
        if (conv == 'o' || conv == 'd' || conv == 'x') {
            *size += 1;
            my_putchar('0');
        }
    }
    return a;
}
