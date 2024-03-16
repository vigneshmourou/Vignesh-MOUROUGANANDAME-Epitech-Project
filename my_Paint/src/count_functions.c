/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** count_functions
*/
#include "../include/paint_struct.h"
#include "../include/paint.h"
#include <stdlib.h>

int nb_options(option_t *option)
{
    option_t *stock = malloc(sizeof(option_t));
    int count = 1;

    stock = option;
    while (stock->next != NULL) {
        count++;
        stock = stock->next;
    }
    return count;
}
