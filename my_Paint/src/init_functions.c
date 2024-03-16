/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** init_functions
*/
#include "../include/paint_struct.h"
#include "../include/paint.h"
#include <stdlib.h>

option_t *init_option(option_t *option, sfVector2f pos, sfVector2f size)
{
    option->button = init_button(pos, size);
    option->button->is_clicked = is_button_clicked;
    option->button->is_hover = is_mouse_hover;
    option->button->state = NONE;
    return option;
}

button_t *init_button(sfVector2f position, sfVector2f size)
{
    button_t *NewButton = malloc(sizeof(button_t) * 1);

    NewButton->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(NewButton->rect, position);
    sfRectangleShape_setSize(NewButton->rect, size);
    sfRectangleShape_setFillColor(NewButton->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(NewButton->rect, 2.0);
    sfRectangleShape_setOutlineColor(NewButton->rect, sfBlack);
    return NewButton;
}

drop_menu_t *init_drop_menu(sfVector2f position, sfVector2f size, int nb_op)
{
    drop_menu_t *menu = malloc(sizeof(drop_menu_t));

    menu = create_drop_menu(position, size);
    for (int i = 0; nb_op > i; i++)
        menu = add_option_drop_menu(menu);
    return menu;
}

void init_prev_state(overlay_t *overlay)
{
    if (overlay->button->state == HOVER) {
        overlay->prev_state = HOVER;
        return;
    }
    if (overlay->button->state == NONE) {
        overlay->prev_state = NONE;
        return;
    }
    if (overlay->button->state == RELEASED) {
        overlay->prev_state = RELEASED;
        return;
    }
    if (overlay->button->state == PRESSED) {
        overlay->prev_state = PRESSED;
        return;
    }
}
