/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** paint_struct
*/

#ifndef PAINT_STRUCT_H_
    #define PAINT_STRUCT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>

static sfVector2f const SIZE_OVERLAY = {1650, 135};
static sfVector2f const MENU_POSITION_ = {500, 100};
static sfVector2f const MENU_SIZE_ = {150, 75};
static int const MENU_NB_OPTION_ = 3;
static int const OVERLAY_NB_BUTTON_ = 7;

typedef enum button_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED,
} button_state_t;


typedef struct overlay_s {
    struct button_s *button;
    sfColor color;
    sfRectangleShape *rect;
    enum button_state prev_state;
} overlay_t;

typedef struct button_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked) (struct button_s *button, sfMouseButtonEvent *MEvent);
    sfBool (*is_hover) (struct button_s *button, sfRenderWindow *window);
    enum button_state state;
    enum button_state prev_state;
} button_t;

typedef struct s_gui_options {
    button_t *button;
    struct s_gui_options *next;
} option_t;


typedef struct s_gui_drop_menu {
    sfText *text;
    button_t *button;
    sfImage *img;
    sfTexture *texture;
    option_t *options;
} drop_menu_t;

#endif /* !PAINT_STRUCT_H_ */
