/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** cursor_functions
*/
#include <stdlib.h>
#include "../include/paint.h"
#include "../include/paint_struct.h"

static void modif_thickness(drop_menu_t *less, drop_menu_t *pl, window_t *win)
{
    if (less->button->state == RELEASED &&
    less->button->prev_state == PRESSED) {
        if (win->cursor->thickness >= 10) {
            win->cursor->thickness -= 5;
        }
        return;
    }
    if (pl->button->state == RELEASED && pl->button->prev_state == PRESSED){
        win->cursor->thickness += 5;
        return;
    }
}

static void cursor_on_eraze(drop_menu_t *erazer, window_t *wind)
{
    if (erazer->button->state == RELEASED) {
        update_cursor(wind, ERASE);
        wind->draw_funct = &set_erase;
        return;
    }
    return;
}

static void cursor_on_draw(drop_menu_t *pen, window_t *wind)
{
    if (pen->button->state == RELEASED) {
        update_cursor(wind, DRAWING);
        wind->draw_funct = &set_drawing;
        return;
    }
    return;
}

static void cursor_on_color(drop_menu_t *color_palette, window_t *wind)
{
    int x = sfMouse_getPositionRenderWindow(wind->wind).x;
    int y = sfMouse_getPositionRenderWindow(wind->wind).y;

    if (color_palette->button->state == RELEASED &&
    color_palette->button->prev_state == PRESSED) {
        wind->cursor->color = sfImage_getPixel(color_palette->img,
        x - 1100, y - 20);
    }
    return;
}

static void cursor_on_highlight(drop_menu_t *highlight, window_t *wind)
{
    if (highlight->button->state == RELEASED) {
        update_cursor(wind, HIGHLIGHT);
        wind->draw_funct = &set_highlighter;
        return;
    }
    return;
}

void clear_img(drop_menu_t *clear, window_t *wind)
{
    sfImage *NewImg;

    if (clear->button->state == RELEASED) {
        sfImage_destroy(wind->design_zone->image);
        NewImg = sfImage_createFromColor(IMG_WIDTH_, IMG_HEIGHT_, sfWhite);
        sfTexture_updateFromImage(wind->design_zone->img_texture,
        NewImg, 0, 0);
        wind->design_zone->img_sprite = sfSprite_create();
        sfSprite_setTexture(wind->design_zone->img_sprite,
        wind->design_zone->img_texture, sfTrue);
        sfSprite_setPosition(wind->design_zone->img_sprite, IMG_POSITION_);
        wind->design_zone->image = NewImg;
        return;
    }
    return;
}

void check_cursor(drop_menu_t **tool, window_t *window)
{
    modif_thickness(tool[3], tool[2], window);
    cursor_on_draw(tool[0], window);
    cursor_on_eraze(tool[4], window);
    cursor_on_color(tool[6], window);
    cursor_on_highlight(tool[1], window);
    clear_img(tool[5], window);
}
