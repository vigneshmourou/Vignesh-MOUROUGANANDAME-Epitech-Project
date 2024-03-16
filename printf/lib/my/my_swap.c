/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** my_swap
*/

void my_swap(int *a, int *b)
{
    int swt;

    swt = *b;
    *b = *a;
    *a = swt;
    return;
}
