/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** paint_struct
*/

#ifndef PAINT_WINDOW_H_
    #define PAINT_WINDOW_H_
    #include "paint_struct.h"
    #include "paint_img.h"
    #include "paint_cursor.h"
    #include "paint_tool.h"
    #include "paint_menu.h"
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #define NAME_WINDOW_ "Paint"

static sfVideoMode const VIDEO_MODE_ = {1921, 1080, 32};

typedef struct window_s {
    sfRenderWindow *wind;
    sfVideoMode video_mode;
    sfEvent event;
    drop_menu_t *menu;
    overlay_t **overlay_tab;
    design_zone_t *design_zone;
    cursor_t *cursor;
    void (*draw_funct)(struct window_s *, int, int);
} window_t;

#endif /* !PAINT_WINDOW_H_ */
