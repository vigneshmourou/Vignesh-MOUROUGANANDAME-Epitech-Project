/*
** EPITECH PROJECT, 2024
** affiche_map.c
** File description:
** dsc
*/
#include "my.h"
#include "my_navy.h"
#include <stddef.h>

void display_grid(player_t *player)
{
    my_printf("my navy:\n");
    for (int i = 0; player->my_grid[i] != NULL; i++)
        my_printf("%s\n", player->my_grid[i]);
    my_printf("\nenemy navy:\n");
    for (int i = 0; player->enemy_grid[i] != NULL; i++)
        my_printf("%s\n", player->enemy_grid[i]);
    my_putchar('\n');
    return;
}
