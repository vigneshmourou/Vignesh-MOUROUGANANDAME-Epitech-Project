/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** button_event
*/
#include "../include/paint_struct.h"
#include "../include/paint.h"
#include <stdlib.h>

sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *MEvent)
{
    float x = sfRectangleShape_getPosition(button->rect).x;
    float y = sfRectangleShape_getPosition(button->rect).y;
    float len = sfRectangleShape_getPosition(button->rect).x
    + sfRectangleShape_getSize(button->rect).x;
    float width = sfRectangleShape_getPosition(button->rect).y
    + sfRectangleShape_getSize(button->rect).y;

    if (MEvent->x <= len && MEvent->x >= x &&
    MEvent->y <= width && MEvent->y >= y) {
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_mouse_hover(struct button_s *button, sfRenderWindow *window)
{
    float x = sfRectangleShape_getPosition(button->rect).x;
    float y = sfRectangleShape_getPosition(button->rect).y;
    float len = sfRectangleShape_getPosition(button->rect).x
    + sfRectangleShape_getSize(button->rect).x;
    float width = sfRectangleShape_getPosition(button->rect).y
    + sfRectangleShape_getSize(button->rect).y;

    if (sfMouse_getPositionRenderWindow(window).x <= len
    && sfMouse_getPositionRenderWindow(window).x >= x
    && sfMouse_getPositionRenderWindow(window).y <= width
    && sfMouse_getPositionRenderWindow(window).y >= y)
        return sfTrue;
    return sfFalse;
}

struct s_gui_drop_menu *create_drop_menu(sfVector2f position, sfVector2f size)
{
    struct s_gui_drop_menu *menu = malloc(sizeof(drop_menu_t));

    menu->button = init_button(position, size);
    menu->button->state = NONE;
    menu->button->prev_state = NONE;
    menu->button->is_clicked = is_button_clicked;
    menu->button->is_hover = is_mouse_hover;
    menu->options = NULL;
    return menu;
}

static void go_to_end(option_t *opt, option_t *stk, drop_menu_t *dm)
{
    stk = dm->options;
    while (stk->next != NULL)
        stk = stk->next;
    stk->next = opt;
    opt->next = NULL;
}

struct s_gui_drop_menu *add_option_drop_menu(struct s_gui_drop_menu *drop_menu)
{
    option_t *option = malloc(sizeof(option_t));
    option_t *stock = malloc(sizeof(option_t));
    sfVector2f size = sfRectangleShape_getSize(drop_menu->button->rect);
    sfVector2f pos;
    int count = nb_options(drop_menu->options);

    pos.x = sfRectangleShape_getPosition(drop_menu->button->rect).x;
    pos.y = sfRectangleShape_getPosition(drop_menu->button->rect).y +
    sfRectangleShape_getSize(drop_menu->button->rect).y;
    if (drop_menu->options == NULL) {
        option->next = NULL;
        option = init_option(option, pos, size);
        drop_menu->options = option;
        return drop_menu;
    }
    pos.x += size.x * count;
    option = init_option(option, pos, size);
    go_to_end(option, stock, drop_menu);
    return drop_menu;
}
