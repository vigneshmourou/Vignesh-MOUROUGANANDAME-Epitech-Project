/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** paint_tool
*/

#ifndef PAINT_TOOL_H_
    #define PAINT_TOOL_H_
    #include "paint_struct.h"
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>

static unsigned int const TOOL_NB_BUTTON = 7;

static sfVector2f const BUTTON_SIZE = {100, 100};
static sfVector2f const COLOR_PALETTE_SIZE = {300, 102};

static sfVector2f const PEN_POS = {310, 20};
static sfVector2f const HIGHLIGHT_POS = {500, 20};
static sfVector2f const PLUS_POS = {700, 20};
static sfVector2f const LESS_POS = {900, 20};
static sfVector2f const ERASER_POS = {1500, 20};
static sfVector2f const CLEAR_POS = {1700, 20};

static sfVector2f const COLOR_PALETTE_POS = {1100, 20};

typedef struct tool_s {
    sfVector2f size;
    sfVector2f position;
    char path[30];
} tool_t;

static tool_t const TOOL_BUTTON_TAB[] = {
    {BUTTON_SIZE, PEN_POS, "img/draw_img.png"},
    {BUTTON_SIZE, HIGHLIGHT_POS, "img/highlight_img.png"},
    {BUTTON_SIZE, PLUS_POS, "img/plus_img.png"},
    {BUTTON_SIZE, LESS_POS, "img/less_img.png"},
    {BUTTON_SIZE, ERASER_POS, "img/eraser_img.png"},
    {BUTTON_SIZE, CLEAR_POS, "img/delete_img.png"},
    {COLOR_PALETTE_SIZE, COLOR_PALETTE_POS, "img/color_palette_img.png"}
};

#endif /* !PAINT_TOOL_H_ */
