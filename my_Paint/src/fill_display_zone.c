/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** file to fill the designe zone struct
*/

#include "../include/paint_window.h"
#include "../include/paint.h"
#include <stdlib.h>
#include <stdio.h>

design_zone_t *fill_design_info(void)
{
    design_zone_t *design = malloc(sizeof(design_zone_t));

    design->image = sfImage_createFromColor(IMG_WIDTH_, IMG_HEIGHT_, sfWhite);
    design->img_texture = sfTexture_createFromImage(design->image, NULL);
    design->img_sprite = sfSprite_create();
    sfSprite_setTexture(design->img_sprite, design->img_texture, sfTrue);
    sfSprite_setPosition(design->img_sprite, IMG_POSITION_);
    return design;
}

sfSprite *event_click_design(window_t *window)
{
    int x = sfMouse_getPositionRenderWindow(window->wind).x;
    int y = sfMouse_getPositionRenderWindow(window->wind).y;

    if (x < IMG_POSITION_X || y < IMG_POSITION_Y)
        return window->design_zone->img_sprite;
    if (window->design_zone->statut == PRESSED && x >
        IMG_POSITION_X && y > IMG_POSITION_Y) {
        if (window->cursor->statut != SELECT)
            window->draw_funct(window, x, y);
        sfTexture_updateFromImage(window->design_zone->img_texture,
                                    window->design_zone->image, 0, 0);
        sfSprite_setTexture(window->design_zone->img_sprite,
                            window->design_zone->img_texture, sfTrue);
    }
    window->cursor->old_pos_x = x;
    window->cursor->old_pos_y = y;
    return window->design_zone->img_sprite;
}
