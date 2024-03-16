/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** function
*/

int my_compute_power_rec(int nb, int p)
{
    int result = 1;

    if (p < 0)
        return 0;
    else if (p < 1)
        return 1;
    else {
        result = nb * my_compute_power_rec(nb, p - 1);
    }
    return result;
}
