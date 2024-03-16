/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** paint_tool
*/

#ifndef PAINT_MENU_H_
    #define PAINT_MENU_H_
    #include "paint_struct.h"
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>

static unsigned int const MENU_NB_BUTTON = 3;

static sfVector2f const SIZE_MENU_BUTTON = {250, 100};

static sfVector2f const SAVE_FILE_POS = {400, 20};
static sfVector2f const LOAD_FILE_BUTTON = {1000, 20};
static sfVector2f const HELP_BUTTON = {1600, 20};


typedef struct menu_s {
    sfVector2f size;
    sfVector2f position;
    char path[30];
} menu_t;

static menu_t const MENU_BUTTON_TAB[] = {
    {SIZE_MENU_BUTTON, SAVE_FILE_POS, "img/save_file_img.png"},
    {SIZE_MENU_BUTTON, LOAD_FILE_BUTTON, "img/vip_img.png"},
    {SIZE_MENU_BUTTON, HELP_BUTTON, "img/vip_img.png"},
};

#endif /* !PAINT_MENU_H_ */
