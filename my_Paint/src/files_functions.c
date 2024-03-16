/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** files_functions
*/
#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/paint.h"
#include "../include/paint_struct.h"

char *remove_last_char(char *str)
{
    int nb = my_strlen(str) - 1;
    char *final = malloc(sizeof(char) * nb);

    for (int i = 0; i < nb; i++) {
        final[i] = str[i];
    }
    final[nb] = '\0';
    return final;
}

void save_file(sfImage *image)
{
    char *name = NULL;
    size_t size = 0;

    my_putstr("Write the name of your file:\n");
    getline(&name, &size, stdin);
    if (name[0] == '\n' || name[0] == '\0') {
        name = my_strdup("Hoppy31.png");
        sfImage_saveToFile(image, name);
        return;
    }
    name = remove_last_char(name);
    name = my_strcat(name, ".png");
    sfImage_saveToFile(image, name);
    return;
}

void file_button(drop_menu_t *menu, window_t *win)
{
    if (menu->button->state == RELEASED &&
    menu->button->prev_state == PRESSED) {
        save_file(win->design_zone->image);
        menu->button->state = NONE;
        my_putstr("File saved !\n");
        return;
    }
    return;
}
