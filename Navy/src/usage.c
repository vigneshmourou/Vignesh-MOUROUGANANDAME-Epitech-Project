/*
** EPITECH PROJECT, 2024
** usage.c
** File description:
** usage navy
*/
#include "my.h"
#include "my_navy.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     first_player_pid: only for the 2nd player.");
    my_putstr(" pid of the first player.\n");
    my_putstr("     navy_positions: file representing the");
    my_putstr(" positions of the ships.\n");
}
