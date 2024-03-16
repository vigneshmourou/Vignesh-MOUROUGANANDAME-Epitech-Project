/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** tool_functions
*/
#include "../include/paint_struct.h"
#include "../include/paint.h"
#include <stdlib.h>

static void tool_buttons_on_none(drop_menu_t **tool, int i)
{
    for (int l = 0; tool[l] != NULL; l++) {
        if (l != i) {
            tool[l]->button->state = NONE;
            sfRectangleShape_setFillColor(tool[l]->button->rect, sfWhite);
        }
    }
    return;
}

static void init_prev_tool_state(drop_menu_t *tool)
{
    if (tool->button->state == HOVER) {
        tool->button->prev_state = HOVER;
        return;
    }
    if (tool->button->state == NONE) {
        tool->button->prev_state = NONE;
        return;
    }
    if (tool->button->state == RELEASED) {
        tool->button->prev_state = RELEASED;
        return;
    }
    if (tool->button->state == PRESSED) {
        tool->button->prev_state = PRESSED;
        return;
    }
}

static void set_tool_button_hover(drop_menu_t *tool, int i)
{
    init_prev_tool_state(tool);
    if (i == TOOL_NB_BUTTON - 1)
        return;
    if (tool->button->state == HOVER || tool->button->state == NONE) {
        tool->button->state = HOVER;
        sfRectangleShape_setFillColor(tool->button->rect, sfGreen);
        return;
    }
}

void is_tool_button_hover(drop_menu_t **tool, window_t *window)
{
    for (int i = 0; tool[i] != NULL; i++) {
        if (tool[i]->button->is_hover(tool[i]->button, window->wind)) {
            set_tool_button_hover(tool[i], i);
            return;
        }
        if (tool[i]->button->state != RELEASED)
            sfRectangleShape_setFillColor(tool[i]->button->rect, sfWhite);
    }
}

void is_tool_button_released(drop_menu_t **tool)
{
    for (int i = 0; tool[i] != NULL; i++) {
        if (tool[i]->button->state == PRESSED) {
            tool[i]->button->state = RELEASED;
            return;
        }
    }
}

static int pressed_check(drop_menu_t **tool, int i)
{
    if (tool[i]->button->prev_state == RELEASED) {
        tool[i]->button->state = NONE;
        return 0;
    }
    return -1;
}

static int pressed_function(drop_menu_t **tool, int i, sfEvent event)
{
    if (tool[i]->button->is_clicked(tool[i]->button, &event.mouseButton)) {
        if (pressed_check(tool, i) == 0)
            return 0;
        tool[i]->button->state = PRESSED;
        tool_buttons_on_none(tool, i);
        return 0;
    }
    return -1;
}

void is_tool_button_pressed(drop_menu_t **tool, sfEvent event)
{
    for (int i = 0; tool[i] != NULL; i++) {
        if (pressed_function(tool, i, event) == 0)
            return;
    }
}

drop_menu_t **def_tool(void)
{
    drop_menu_t **tool = malloc(sizeof(drop_menu_t *) * (TOOL_NB_BUTTON + 1));

    for (unsigned int i = 0; i < TOOL_NB_BUTTON; i++) {
        tool[i] = init_drop_menu(TOOL_BUTTON_TAB[i].position,
        TOOL_BUTTON_TAB[i].size, 0);
        tool[i]->img = sfImage_createFromFile(TOOL_BUTTON_TAB[i].path);
        tool[i]->texture = sfTexture_createFromImage(tool[i]->img, NULL);
        sfRectangleShape_setTexture(tool[i]->button->rect,
        tool[i]->texture, sfFalse);
    }
    tool[TOOL_NB_BUTTON] = NULL;
    return tool;
}
