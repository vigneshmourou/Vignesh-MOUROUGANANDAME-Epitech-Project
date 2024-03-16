/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** check_functions
*/
#include <stdlib.h>
#include <stdio.h>
#include "../include/paint.h"
#include "../include/paint_struct.h"

void check_button_state(window_t *win, drop_menu_t **menu, drop_menu_t **tool)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(win->wind, &event)) {
        click_handler(event, win, menu, tool);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(win->wind);
        if (event.type == sfEvtKeyPressed &&
            event.key.code == sfKeyEscape)
            sfRenderWindow_close(win->wind);
    }
    file_button(menu[0], win);
    check_cursor(tool, win);
    button_hover(win->overlay_tab, win->wind);
    is_tool_button_hover(tool, win);
    is_menu_button_hover(menu, win);
    return;
}

void buttons_on_none(overlay_t **tab, int i)
{
    for (int l = 0; l < OVERLAY_NB_BUTTON_; l++) {
        if (l != i) {
            tab[l]->button->state = NONE;
            tab[l]->rect = NULL;
            sfRectangleShape_destroy(tab[l]->rect);
            sfRectangleShape_setFillColor(tab[l]->button->rect, sfWhite);
        }
    }
    return;
}
