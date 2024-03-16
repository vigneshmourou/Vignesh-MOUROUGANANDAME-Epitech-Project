/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** button_state
*/
#include <stdlib.h>
#include "../include/paint.h"
#include "../include/paint_struct.h"

static void set_hover(overlay_t *tab)
{
    init_prev_state(tab);
    if (tab->button->state == HOVER || tab->button->state == NONE) {
        tab->button->state = HOVER;
        sfRectangleShape_setFillColor(tab->button->rect, sfGreen);
        return;
    }
}

static int pressed_check(window_t *w, int i)
{
    if (w->overlay_tab[i]->prev_state == RELEASED) {
        w->overlay_tab[i]->button->state = NONE;
        return 0;
    }
    return -1;
}

static int pressed_function(window_t *w, int i, sfEvent ev)
{
    if (w->overlay_tab[i]->button->is_clicked(w->overlay_tab[i]->button,
    &ev.mouseButton)) {
        if (pressed_check(w, i) == 0)
            return 0;
        w->overlay_tab[i]->button->state = PRESSED;
        sfRectangleShape_setFillColor(w->overlay_tab[i]->button->rect, sfRed);
        buttons_on_none(w->overlay_tab, i);
        return 0;
    }
    return -1;
}

void button_pressed(sfEvent ev, window_t *w, drop_menu_t **m, drop_menu_t **t)
{
    int x = sfMouse_getPositionRenderWindow(w->wind).x;
    int y = sfMouse_getPositionRenderWindow(w->wind).y;

    for (int i = 0; i < OVERLAY_NB_BUTTON_; i++) {
        if (pressed_function(w, i, ev) == 0)
            return;
    }
    is_tool_button_pressed(t, ev);
    is_menu_button_pressed(m, ev);
    w->cursor->old_pos_x = x;
    w->cursor->old_pos_y = y;
    if (x > IMG_POSITION_X && y > IMG_POSITION_Y)
        w->design_zone->statut = PRESSED;
}

void button_released(window_t *w, drop_menu_t **m, drop_menu_t **t)
{
    int x = sfMouse_getPositionRenderWindow(w->wind).x;
    int y = sfMouse_getPositionRenderWindow(w->wind).y;

    for (int i = 0; i < OVERLAY_NB_BUTTON_; i++) {
        if (w->overlay_tab[i]->button->state == PRESSED) {
            w->overlay_tab[i]->button->state = RELEASED;
            sfRectangleShape_setFillColor(w->overlay_tab[i]->button->rect,
            sfBlue);
            return;
        }
    }
    if (w->overlay_tab[0]->button->state == RELEASED)
        is_menu_button_released(m);
    if (w->overlay_tab[1]->button->state == RELEASED)
        is_tool_button_released(t);
    if (x > IMG_POSITION_X && y > IMG_POSITION_Y)
        w->design_zone->statut = RELEASED;
}

void button_hover(overlay_t **tab, sfRenderWindow *window)
{
    for (int i = 0; i < OVERLAY_NB_BUTTON_; i++) {
        if (tab[i]->button->is_hover(tab[i]->button, window) == sfTrue) {
            set_hover(tab[i]);
            return;
        }
        if (tab[i]->button->state != RELEASED)
            sfRectangleShape_setFillColor(tab[i]->button->rect, sfWhite);
    }
    return;
}

void click_handler(sfEvent ev, window_t *w, drop_menu_t **m, drop_menu_t **t)
{
    if (ev.type == sfEvtMouseButtonPressed) {
        button_pressed(ev, w, m, t);
        return;
    } else if (ev.type == sfEvtMouseButtonReleased) {
        button_released(w, m, t);
        return;
    }
}
