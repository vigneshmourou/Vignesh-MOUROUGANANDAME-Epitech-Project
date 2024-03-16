/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** init_button
*/
#include "../include/paint_struct.h"
#include "../include/paint.h"
#include <stdlib.h>

overlay_t *init_overlay(float mult)
{
    int next = 125 * mult;
    overlay_t *ov = malloc(sizeof(overlay_t));
    sfVector2f pos = {0, 134 + next};
    sfVector2f s = {300, 125};

    ov->button = init_button(pos, s);
    ov->button->state = NONE;
    ov->button->is_clicked = is_button_clicked;
    ov->button->is_hover = is_mouse_hover;
    ov->prev_state = NONE;
    return ov;
}

sfRectangleShape *init_overlay_rect(sfRectangleShape *rect, sfColor color)
{
    sfVector2f position = {302, 0};
    sfVector2f size = {1650, 135};

    rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(rect, position);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setOutlineThickness(rect, 2.0);
    sfRectangleShape_setOutlineColor(rect, sfBlack);
    return rect;
}

overlay_t **init_overlay_array(void)
{
    overlay_t **tab = malloc(sizeof(overlay_t *) * (OVERLAY_NB_BUTTON_ + 1));

    for (int i = 0; i < OVERLAY_NB_BUTTON_; i++) {
        tab[i] = malloc(sizeof(overlay_t));
        tab[i] = init_overlay(i);
    }
    tab[0]->color = sfBlue;
    tab[1]->color = sfRed;
    tab[2]->color = sfCyan;
    tab[3]->color = sfGreen;
    tab[4]->color = sfYellow;
    tab[5]->color = sfWhite;
    tab[6]->color = sfMagenta;
    for (int j = 0; j < OVERLAY_NB_BUTTON_; j++)
        tab[j]->rect = NULL;
    tab[OVERLAY_NB_BUTTON_] = NULL;
    return tab;
}
