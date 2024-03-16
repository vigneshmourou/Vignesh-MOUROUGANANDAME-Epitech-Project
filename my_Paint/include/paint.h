/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** paint
*/
#include "paint_struct.h"
#include "paint_window.h"

#ifndef PAINT_H_
    #define PAINT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>

// button event functions
sfBool is_button_clicked(button_t *button, sfMouseButtonEvent *MEvent);
sfBool is_mouse_hover(struct button_s *button, sfRenderWindow *window);
drop_menu_t *create_drop_menu(sfVector2f position, sfVector2f size);
drop_menu_t *add_option_drop_menu(struct s_gui_drop_menu *drop_menu);
void buttons_on_none(overlay_t **tab, int i);

// init functions
option_t *init_option(option_t *option, sfVector2f pos, sfVector2f size);
drop_menu_t *init_drop_menu(sfVector2f pos, sfVector2f size, int nb_opt);
button_t *init_button(sfVector2f position, sfVector2f size);
overlay_t *init_overlay(float mult);
overlay_t **init_overlay_array(void);
void init_prev_state(overlay_t *overlay);
sfRectangleShape *init_overlay_rect(sfRectangleShape *rect, sfColor color);

// display functions
void display_button(option_t *option, sfRenderWindow *win, button_t *button);
void display_toolbar(overlay_t **overlay, sfRenderWindow *window, int i);
void display_side_button(overlay_t *tab, sfRenderWindow *window);

// check functions
void check_button_state(window_t *window, drop_menu_t **menu,
    drop_menu_t **tool);
void check_overlay_state(overlay_t *tab, sfRenderWindow *window);

// count functions
int nb_options(option_t *option);

// init design zone
design_zone_t *fill_design_info(void);

// display design zone
void display_design(window_t *window);
sfSprite *event_click_design(window_t *window);
void display_option(option_t *stk, sfRenderWindow *window);
void display_overlay_button(drop_menu_t **buttons, sfRenderWindow *window,
    overlay_t *menu);

// button state
void click_handler(sfEvent event, window_t *window, drop_menu_t **menu,
    drop_menu_t **tool);
void button_pressed(sfEvent event, window_t *window, drop_menu_t **menu,
    drop_menu_t **tool);
void button_hover(overlay_t **tab, sfRenderWindow *window);
void button_released(window_t *window, drop_menu_t **menu, drop_menu_t **tool);

// menu function
drop_menu_t **def_menu(void);
void is_menu_button_released(drop_menu_t **menu);
void is_menu_button_pressed(drop_menu_t **menu, sfEvent event);
void is_menu_button_hover(drop_menu_t **menu, window_t *window);


// cursor
cursor_t *fill_cursor(window_t *wind);
void update_cursor(window_t *window, int statut);
void check_cursor(drop_menu_t **tool, window_t *window);

// pencil
void set_drawing(window_t *window, int pos_x, int pos_y);
void set_erase(window_t *window, int pos_x, int pos_y);
void set_highlighter(window_t *window, int pos_x, int pos_y);


// tool function
drop_menu_t **def_tool(void);
void is_tool_button_released(drop_menu_t **tool);
void is_tool_button_pressed(drop_menu_t **tool, sfEvent event);
void is_tool_button_hover(drop_menu_t **tool, window_t *window);

// files functions
void save_file(sfImage *image);
void file_button(drop_menu_t *menu, window_t *win);

#endif /* !PAINT_H_ */
