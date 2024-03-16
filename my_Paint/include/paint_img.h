/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** paint_struct
*/

#ifndef PAINT_IMAGE_H_
    #define PAINT_IMAGE_H_
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>

static int const IMG_WIDTH_ = 1620;
static int const IMG_HEIGHT_ = 900;
static int const IMG_POSITION_X = 300;
static int const IMG_POSITION_Y = 134;
static sfVector2f const IMG_POSITION_ = {300, 134};
static sfVector2f const IMG_SIZE_ = {IMG_WIDTH_, IMG_HEIGHT_};
static int const DRAW_THICKNESS = 15;

typedef struct design_zone_s {
    sfImage *image;
    sfTexture *img_texture;
    sfSprite *img_sprite;
    int statut;
} design_zone_t;

#endif /* !PAINT_IMAGE_H_ */
