/*
** EPITECH PROJECT, 2023
** percent_width
** File description:
** percent . * and functions for conversions: verifying the flags and width
*/
#include <stdlib.h>
#include "include/percent.h"
#include "include/my.h"

void my_put_spaces(int stop, char spaces)
{
    if (stop < 0)
        return;
    for (int i = 0; i != stop; i++)
        my_putchar(spaces);
    return;
}

int plus_used(char *flag)
{
    for (int i = 0; flag[i] != '\0'; i++)
        if (flag[i] == '+')
            return 1;
    return 0;
}

int spaces_handle(int nb_spaces, int uni, int placement, char *flag)
{
    if (uni == 1)
        return 2;
    if (placement == 0 && cmp_nbr(my_getnbr(flag)) < nb_spaces) {
        my_put_spaces((nb_spaces - 1) - cmp_nbr(my_getnbr(flag)), ' ');
        return 0;
    }
    return 1;
}

char *percent_nb(const char *str, char *width, int i, int *cnt_char)
{
    int a = 0;
    int power = 0;
    int elem = 0;

    for (int j = i; str[j] >= '0' && str[j] <= '9'; j++) {
        width[a] = str[j];
        a++;
        *cnt_char = *cnt_char + 1;
    }
    return width;
}
