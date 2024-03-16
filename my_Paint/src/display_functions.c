/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** display_functions
*/
#include "../include/paint_struct.h"
#include "../include/paint.h"
#include <stdlib.h>

void display_option(option_t *stk, sfRenderWindow *window)
{
    while (stk != NULL) {
        sfRenderWindow_drawRectangleShape(window, stk->button->rect, NULL);
        if (stk->button->is_hover(stk->button, window)) {
            sfRenderWindow_drawRectangleShape(window, stk->button->rect, NULL);
            stk->button->state = HOVER;
        }
        stk->button->state = NONE;
        stk = stk->next;
    }
}

void display_button(option_t *option, sfRenderWindow *window, button_t *button)
{
    option_t *stock = malloc(sizeof(option_t));

    stock = option;
    if (button->state == HOVER) {
        display_option(stock, window);
    }
    return;
}

void display_toolbar(overlay_t **ov, sfRenderWindow *window, int i)
{
    if (ov[i]->rect == NULL) {
        ov[i]->rect = init_overlay_rect(ov[i]->rect, ov[i]->color);
    }
    sfRenderWindow_drawRectangleShape(window, ov[i]->rect, NULL);
    return;
}

void display_side_button(overlay_t *tab, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window, tab->button->rect, NULL);
}

static void display_check(drop_menu_t **b, int i, sfRenderWindow *win)
{
    if (b[i]->button->state == RELEASED)
        display_option(b[i]->options, win);
}

void display_overlay_button(drop_menu_t **b, sfRenderWindow *win, overlay_t *m)
{
    for (int i = 0; b[i] != NULL; i++) {
        if (m->button->state == RELEASED) {
            sfRenderWindow_drawRectangleShape(win, b[i]->button->rect, NULL);
            display_check(b, i, win);
        }
    }
}
