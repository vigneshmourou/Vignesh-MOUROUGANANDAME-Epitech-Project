/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** main
*/
#include "../include/paint_window.h"
#include "../include/paint.h"
#include "../include/paint_struct.h"
#include "../include/paint_cursor.h"
#include "../include/my.h"
#include <stdlib.h>

void display_sprite(window_t *window, drop_menu_t **menu, drop_menu_t **tool)
{
    sfRenderWindow_drawSprite(window->wind,
    window->design_zone->img_sprite, NULL);
    for (int i = 0; i < OVERLAY_NB_BUTTON_; i++) {
        display_side_button(window->overlay_tab[i], window->wind);
        if (window->overlay_tab[i]->prev_state == RELEASED &&
        window->overlay_tab[i]->button->state != NONE) {
            display_toolbar(window->overlay_tab, window->wind, i);
        }
    }
    display_overlay_button(menu, window->wind, window->overlay_tab[0]);
    display_overlay_button(tool, window->wind, window->overlay_tab[1]);
    sfRenderWindow_drawSprite(window->wind, window->cursor->sprite, NULL);
    sfRenderWindow_display(window->wind);
    return;
}

void update_window(window_t *window)
{
    window->design_zone->img_sprite = event_click_design(window);
    sfSprite_setPosition(window->cursor->sprite,
        (sfVector2f){sfMouse_getPosition(NULL).x,
        sfMouse_getPosition(NULL).y - 80});
    sfRenderWindow_clear(window->wind, sfBlack);
}

window_t *fill_window(void)
{
    window_t *window = malloc(sizeof(window_t));

    window->video_mode = VIDEO_MODE_;
    window->wind = sfRenderWindow_create(window->video_mode,
    NAME_WINDOW_, sfDefaultStyle, NULL);
    window->overlay_tab = init_overlay_array();
    window->design_zone = fill_design_info();
    window->cursor = fill_cursor(window);
    return window;
}

void free_funct(window_t *window)
{
    free(window->design_zone);
    free(window->overlay_tab);
    free(window->cursor);
    free(window);
}

int main(void)
{
    window_t *window = fill_window();
    drop_menu_t **menu = def_menu();
    drop_menu_t **tool = def_tool();

    my_putstr("Appuyez sur le 1er bouton à gauche pour enregistrer le file\n\
    Malheureusement, sans l'accès VIP vous ne pouvez pas ouvrir un fichier  \
    et avoir accès aux aides\n");
    my_putstr("le 2eme bouton à gauche sert à éditer: crayon, surligneur, \
    gomme, avec toutes couleurs");
    while (sfRenderWindow_isOpen(window->wind)) {
        check_button_state(window, menu, tool);
        update_window(window);
        display_sprite(window, menu, tool);
    }
    sfRenderWindow_destroy(window->wind);
    free_funct(window);
    return 0;
}
