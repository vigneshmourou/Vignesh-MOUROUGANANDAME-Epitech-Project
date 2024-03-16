/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** menu_functions
*/
#include "../include/paint_struct.h"
#include "../include/paint.h"
#include <stdlib.h>


static void menu_buttons_on_none(drop_menu_t **menu, int i)
{
    for (int l = 0; menu[l] != NULL; l++) {
        if (l != i) {
            menu[l]->button->state = NONE;
            sfRectangleShape_setFillColor(menu[l]->button->rect, sfWhite);
        }
    }
    return;
}

static void init_prev_menu_state(drop_menu_t *menu)
{
    if (menu->button->state == HOVER) {
        menu->button->prev_state = HOVER;
        return;
    }
    if (menu->button->state == NONE) {
        menu->button->prev_state = NONE;
        return;
    }
    if (menu->button->state == RELEASED) {
        menu->button->prev_state = RELEASED;
        return;
    }
    if (menu->button->state == PRESSED) {
        menu->button->prev_state = PRESSED;
        return;
    }
}

static void set_menu_button_hover(drop_menu_t *menu)
{
    init_prev_menu_state(menu);
    if (menu->button->state == HOVER || menu->button->state == NONE) {
        menu->button->state = HOVER;
        sfRectangleShape_setFillColor(menu->button->rect, sfGreen);
        return;
    }
}

void is_menu_button_hover(drop_menu_t **menu, window_t *window)
{
    for (int i = 0; menu[i] != NULL; i++) {
        if (menu[i]->button->is_hover(menu[i]->button, window->wind)) {
            set_menu_button_hover(menu[i]);
            return;
        }
        if (menu[i]->button->state != RELEASED)
            sfRectangleShape_setFillColor(menu[i]->button->rect, sfWhite);
    }
}

void is_menu_button_released(drop_menu_t **menu)
{
    for (int i = 0; menu[i] != NULL; i++) {
        if (menu[i]->button->state == PRESSED) {
            menu[i]->button->state = RELEASED;
            return;
        }
    }
}

static int pressed_check(drop_menu_t **menu, int i)
{
    if (menu[i]->button->prev_state == RELEASED) {
        menu[i]->button->state = NONE;
        return 0;
    }
    return -1;
}

static int pressed_function(drop_menu_t **menu, int i, sfEvent event)
{
    if (menu[i]->button->is_clicked(menu[i]->button, &event.mouseButton)) {
        if (pressed_check(menu, i) == 0)
            return 0;
        menu[i]->button->state = PRESSED;
        menu_buttons_on_none(menu, i);
        return 0;
    }
    return -1;
}

void is_menu_button_pressed(drop_menu_t **menu, sfEvent event)
{
    for (int i = 0; menu[i] != NULL; i++) {
        if (pressed_function(menu, i, event) == 0)
            return;
    }
}

drop_menu_t **def_menu(void)
{
    drop_menu_t **menu = malloc(sizeof(drop_menu_t *) * (MENU_NB_BUTTON + 1));

    for (unsigned int i = 0; i < MENU_NB_BUTTON; i++) {
        menu[i] = init_drop_menu(MENU_BUTTON_TAB[i].position,
        MENU_BUTTON_TAB[i].size, 0);
        menu[i]->img = sfImage_createFromFile(MENU_BUTTON_TAB[i].path);
        menu[i]->texture = sfTexture_createFromImage(menu[i]->img, NULL);
        sfRectangleShape_setTexture(menu[i]->button->rect,
        menu[i]->texture, sfTrue);
    }
    menu[MENU_NB_BUTTON] = NULL;
    return menu;
}
