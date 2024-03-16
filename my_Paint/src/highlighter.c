/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** file to draw pencil
*/
#include "../include/paint_window.h"
#include <stdlib.h>
#include <stdio.h>

static void verif_pixel(window_t *window, int i, int pos[])
{
    if ((pos[0] - (window->cursor->thickness / 2) + i > IMG_POSITION_X &&
    pos[1] - (window->cursor->thickness / 2) + i > IMG_POSITION_Y) &&
    (pos[0] - (window->cursor->thickness / 2) + i <
    IMG_WIDTH_ + IMG_POSITION_X &&
    pos[1] - (window->cursor->thickness / 2) + i <
    IMG_HEIGHT_ + IMG_POSITION_Y))
        sfImage_setPixel(window->design_zone->image,
                pos[0] - (window->cursor->thickness / 2) + i - IMG_POSITION_X,
                pos[1] - (window->cursor->thickness / 2) + i - IMG_POSITION_Y,
                window->cursor->color);
}

void set_highlighter(window_t *window, int pos_x, int pos_y)
{
    int pos[] = {pos_x, pos_y};

    for (int i = 0; i < window->cursor->thickness; i++) {
        for (int j = 0; j < window->cursor->thickness; j++)
            verif_pixel(window, i, pos);
    }
}
