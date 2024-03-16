/*
** EPITECH PROJECT, 2023
** percent_l_h.c
** File description:
** l ll h hh
*/
#include <stdarg.h>
#include "include/percent.h"
#include "include/my.h"

int double_l(va_list ap)
{
    long long length = va_arg(ap, int);

    return length;
}

int percent_l(char c, va_list ap, int *nb_char_flag)
{
    long length;

    if (c == 'l') {
        length = double_l(ap);
        *nb_char_flag += 2;
        return length;
    }
    *nb_char_flag = *nb_char_flag + 1;
    length = va_arg(ap, int);
    return length;
}

int double_h(va_list ap)
{
    unsigned short length = va_arg(ap, int);

    return length;
}

int percent_h(char c, va_list ap, int *nb_char_flag)
{
    short length;

    if (c == 'l') {
        double_h(ap);
        *nb_char_flag += 2;
        return length;
    }
    *nb_char_flag = *nb_char_flag + 1;
    length = va_arg(ap, int);
    return length;
}
/*
int main(void)
{
    int a = 425;
    int d = 0;
    int *b = &d;

    printf("%d\n", a);
    a = percent_l('v', b, a);
    printf("%\n", a); //h: modulo 256 de -128 à 127.
    percent_h('c', b, a);
    printf("%hd\n", a); //hh: modulo 65536 de -32768 à 32767.
    return 0;
}
// Fonctionne à priori.
// A tester en temps réel avec les flags et my_printf.
*/
