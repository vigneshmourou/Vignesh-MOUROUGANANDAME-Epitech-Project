/*
** EPITECH PROJECT, 2023
** my_cmp_nbr.c
** File description:
** cmp nbr
*/

int cmp_nbr(int nb)
{
    int count = 1;

    if (nb < 0) {
        count ++;
        nb = nb * -1;
    }
    while (nb >= 10) {
        nb = nb / 10;
        count ++;
    }
    return count;
}
