/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** function
*/

static int my_compute_power(int nb, int p)
{
    int i = 1;
    int result = 1;

    if (p < 0)
        return 0;
    if (p == 1)
        return 1;
    for (i; i <= p; i++) {
        result = result * nb;
    }
    return result;
}

static int my_compute_square_root_real(int nb, int i)
{
    if (i == 0) {
        return 0;
    } else if (my_compute_power(i, 2) == nb) {
        return i;
    } else {
        return my_compute_square_root_real(nb, i - 1);
    }
}

int my_compute_square_root(int nb)
{
    return my_compute_square_root_real(nb, nb);
}
