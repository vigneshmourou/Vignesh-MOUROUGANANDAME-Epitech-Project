/*
** EPITECH PROJECT, 2024
** signal.c
** File description:
** dsc
*/
#include "my.h"
#include "my_navy.h"
#include <signal.h>

int send_signal(char *coord, request_t *req)
{
    if (coord == NULL)
        return 1;
    if (verif_user_entry(coord) == (-1))
        return 1;
    for (int i = 0; i < coord[0] - 'A' + 1; i++) {
        kill(req->enemy_pid, SIGUSR1);
        usleep(100);
    }
    for (int i = 0; i < coord[1] - '0'; i++) {
        kill(req->enemy_pid, SIGUSR2);
        usleep(100);
    }
    kill(req->enemy_pid, SIGUSR1);
    return 0;
}
