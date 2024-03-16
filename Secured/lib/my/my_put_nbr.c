/*
** EPITECH PROJECT, 2023
** put nbr
** File description:
** a
*/
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
}
