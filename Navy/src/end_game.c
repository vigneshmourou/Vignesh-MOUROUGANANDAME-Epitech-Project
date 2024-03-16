/*
** EPITECH PROJECT, 2024
** end of game
** File description:
** file for the end of the game
*/
#include "my.h"
#include "my_navy.h"

int end_game(request_t *req)
{
    display_grid(req->player);
    if (req->shift == NB_SHIFT_MAX) {
        my_putstr("Enemy won\n");
        return 1;
    } else {
        my_putstr("I won\n");
        return 0;
    }
}
