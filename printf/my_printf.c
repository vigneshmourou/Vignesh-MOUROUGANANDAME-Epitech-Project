/*
** EPITECH PROJECT, 2023
** flags.c
** File description:
** Circulates through the str & looks flags if there's "%"
*/
#include "include/struct.h"
#include "include/percent.h"
#include <stdarg.h>

int nevralgic_center(const char *format, va_list ap, int *nb_print, int i)
{
    char conv;
    int count_skip = 0;
    int *cnt_char = &count_skip;
    int length = 0;
    char *flag[3];

    if (error_no_conv(format, i) == -1)
        return -1;
    else
        conv = error_no_conv(format, i);
    flag[0] = malloc(sizeof(char) * malloc_char(i, format, conv) + 1);
    flag[0] = flag_character_search(format, conv, i, cnt_char);
    flag[1] = field_width_search(format, i + *cnt_char, cnt_char);
    flag[2] = precision_search(format, i + *cnt_char, cnt_char);
    length = length_modifier_search(format, ap, i + *cnt_char, cnt_char);
    if (length == 0)
        count_skip += conversion_search(conv, ap, nb_print, flag);
    i = i + count_skip;
    return i;
}

int displaying(const char *format, int i, int *nb_print, va_list ap)
{
    int a = 0;

    if (format[i] == '%') {
        a = nevralgic_center(format, ap, nb_print, i + 1);
        if (a == -1) {
            *nb_print += 1;
            my_putchar(format[i]);
            return i;
        }
        i = a - 1;
        return i;
    }
    *nb_print += 1;
    my_putchar(format[i]);
    return i;
}

int my_printf(const char *format, ...)
{
    int nb_print = 0;
    int *nb = &nb_print;
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++)
        i = displaying(format, i, nb, ap);
    va_end(ap);
    return nb_print;
}
