/*
** EPITECH PROJECT, 2023
** my_compute_power_it.c
** File description:
** my_compute_power_it
*/

int my_compute_power_it(int nb, int p)
{
    int nb_origin = nb;

    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    while ( p != 1 ) {
        nb = nb * nb_origin;
        p --;
    }
    if (nb >= 1932053504){
        return 0;
    }
    return nb;
}
