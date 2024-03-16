/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** paint_struct for cursor
*/

#ifndef PAINT_CURSOR_H_
    #define PAINT_CURSOR_H_
    #include "paint_img.h"
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>

enum cursor_image_e {
    SELECT = 0,
    DRAWING,
    ERASE,
    DELETE,
    HIGHLIGHT
};

static char const *const IMG[5] = {
    "img/select_img.png",
    "img/draw_img.png",
    "img/eraser_img.png",
    "img/delete_img.png",
    "img/highlight_img.png"
};

typedef struct cursor_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfColor color;
    int statut;
    void (*draw_funct)(sfImage *, int, int, int);
    int thickness;
    int old_pos_x;
    int old_pos_y;
} cursor_t;

#endif /* !PAINT_CURSOR_H_ */
