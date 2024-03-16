/*
** EPITECH PROJECT, 2024
** check_boat.c
** File description:
** dsc
*/
#include "my.h"
#include "my_navy.h"

int check_line(char *str)
{
    if (str[0] < 48 || str[0] >= 57 || str[1] != ':')
        return (-1);
    if (str[2] < 65 || str[2] > 72 || str[5] < 65 || str[5] > 72)
        return (-1);
    if (str[3] < 48 || str[3] >= 57 || str[4] != ':')
        return (-1);
    if (str[6] < 48 || str[6] >= 57)
        return (-1);
}

int verif_user_entry(char *coord)
{
    if (my_strlen(coord) != 2) {
        return (-1);
    }
    if (coord[0] < 'A' || coord[0] > 'H') {
        return (-1);
    }
    if (coord[1] < '1' || coord[1] > '8') {
        return (-1);
    }
    return 0;
}
