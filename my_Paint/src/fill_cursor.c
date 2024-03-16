/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** file to fill the cursor details
*/

#include "../include/paint_window.h"
#include <stdlib.h>
#include <stdio.h>

void update_cursor(window_t *window, int statut)
{
    sfTexture_destroy(window->cursor->texture);
    sfSprite_destroy(window->cursor->sprite);
    window->cursor->statut = statut;
    window->cursor->texture = sfTexture_createFromFile(IMG[statut], NULL);
    window->cursor->sprite = sfSprite_create();
    sfSprite_setTexture(window->cursor->sprite,
    window->cursor->texture, sfTrue);
}

cursor_t *fill_cursor(window_t *window)
{
    cursor_t *cursor = malloc(sizeof(cursor_t));

    sfRenderWindow_setMouseCursorVisible(window->wind, sfFalse);
    cursor->texture = sfTexture_createFromFile(IMG[SELECT], NULL);
    cursor->sprite = sfSprite_create();
    sfSprite_setTexture(cursor->sprite, cursor->texture, sfTrue);
    cursor->statut = SELECT;
    cursor->thickness = DRAW_THICKNESS;
    return cursor;
}
