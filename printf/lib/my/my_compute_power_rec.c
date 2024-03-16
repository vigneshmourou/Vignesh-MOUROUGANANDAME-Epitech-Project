/*
** EPITECH PROJECT, 2023
** my_compute_power_rec.c
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    if (nb > 1932053504) {
        return 0;
    }
    return (my_compute_power_rec(nb, p - 1) * nb);
}
