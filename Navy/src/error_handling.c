/*
** EPITECH PROJECT, 2024
** error handling
** File description:
** file for error handling of file
*/
#include "my.h"
#include "my_navy.h"

int verif_letter(char **info)
{
    if (info[0][0] < '2' || info[0][0] > '5')
        return 1;
    if (info[1][0] < 'A' || info[1][0] > 'H')
        return 1;
    if (info[1][1] < '1' || info[1][1] > '8')
        return 1;
    if (info[2][0] < 'A' || info[2][0] > 'H')
        return 1;
    if (info[2][1] < '1' || info[2][1] > '8')
        return 1;
    return 0;
}

int verif_count(char **info)
{
    int len = 0;

    for (int i = 0; info[i] != NULL; i++)
        len++;
    if (len != 3)
        return 1;
    if (my_strlen(info[0]) != 1)
        return 1;
    if (my_strlen(info[1]) != 2 || my_strlen(info[2]) != 2)
        return 1;
    return 0;
}

int verif_shift(char **info)
{
    if ((info[1][1] - '0') - (info[2][1] - '0') == (info[0][0] - '0'))
        return 1;
    return 0;
}

int error_handling(char **info)
{
    if (verif_count(info) == 1)
        return 1;
    if (verif_letter(info) == 1)
        return 1;
    if (verif_shift(info) == 1)
        return 1;
    return 0;
}
