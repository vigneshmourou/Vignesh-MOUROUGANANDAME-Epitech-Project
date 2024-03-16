/*
** EPITECH PROJECT, 2024
** game
** File description:
** file for game
*/
#include "my.h"
#include "my_navy.h"
#include <stddef.h>

static void handle_touch_boat(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        SIG = 1;
    else if (sig == SIGUSR2)
        SIG = 2;
}

static request_t *receive_touch_boat(request_t *req, char *co)
{
    struct sigaction sig;

    sig.sa_sigaction = &handle_touch_boat;
    sig.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    pause();
    if (SIG == 1) {
        my_printf("\nresult: %s:hit\n\n", co);
        req->enemy_shift ++;
        req->player->enemy_grid[co[1] - '0' + 1][(co[0] - 'A' + 1) * 2] = 'x';
    } else if (SIG == 2) {
        my_printf("\nresult: %s:missed\n\n", co);
        req->player->enemy_grid[co[1] - '0' + 1][(co[0] - 'A' + 1) * 2] = 'o';
    }
    SIG = 0;
    return req;
}

static void handle_signal_receive(int sig, siginfo_t *info, void *context)
{
    if (sig == SIGUSR1)
        SIG += 10;
    if (sig == SIGUSR2)
        SIG += 1;
}

static void manage_signal(void)
{
    struct sigaction sig;
    int tmp = SIG;

    my_printf("waiting for enemy's attack...");
    sig.sa_sigaction = &handle_signal_receive;
    sig.sa_flags = SA_RESTART;
    tmp = SIG;
    sigaction(SIGUSR1, &sig, NULL);
    sigaction(SIGUSR2, &sig, NULL);
    while (1) {
        if (SIG % 10 != 0 && tmp + 10 == SIG) {
            SIG -= 10;
            return;
        }
        tmp = SIG;
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
    }
}

static request_t *receive_sig(request_t *req)
{
    manage_signal();
    if (req->player->my_grid[SIG % 10 + 1][SIG / 10 * 2] < '1' ||
        req->player->my_grid[SIG % 10 + 1][SIG / 10 * 2] > '8') {
        req->player->my_grid[SIG % 10 + 1][SIG / 10 * 2] = 'o';
        my_printf("\n\nresult: %c%d:missed\n\n",
                    (SIG / 10) + 'A' - 1, SIG % 10);
        kill(req->enemy_pid, SIGUSR2);
    } else {
        req->shift += 1;
        req->player->my_grid[SIG % 10 + 1][SIG / 10 * 2] = 'x';
        my_printf("\n\nresult: %c%d:hit\n\n",
                    (SIG / 10) + 'A' - 1, SIG % 10);
        kill(req->enemy_pid, SIGUSR1);
    }
    SIG = 0;
    return req;
}

int gameplay_player2(request_t *req)
{
    char *coord = NULL;
    int send_signal_return = 0;

    display_grid(req->player);
    req = receive_sig(req);
    if (req->shift == NB_SHIFT_MAX)
        return -1;
    my_printf("attack: ");
    coord = my_getuser();
    send_signal_return = send_signal(coord, req);
    while (send_signal_return == 1) {
        my_putstr("\nwrong position\n");
        my_printf("\nattack: ");
        coord = my_getuser();
        send_signal_return = send_signal(coord, req);
    }
    req = receive_touch_boat(req, coord);
    if (req->enemy_shift == NB_SHIFT_MAX)
        return -1;
}

int gameplay_player1(request_t *req)
{
    char *coord = NULL;
    int send_signal_return = 0;

    display_grid(req->player);
    my_printf("attack: ");
    coord = my_getuser();
    send_signal_return = send_signal(coord, req);
    while (send_signal_return == 1) {
        my_putstr("\nwrong position\n");
        my_printf("\nattack: ");
        coord = my_getuser();
        send_signal_return = send_signal(coord, req);
    }
    req = receive_touch_boat(req, coord);
    if (req->enemy_shift == NB_SHIFT_MAX)
        return -1;
    req = receive_sig(req);
    if (req->shift == NB_SHIFT_MAX)
        return -1;
}

void game(request_t *req)
{
    int i = 1;

    while (i != -1) {
        if (req->user == PLAYER1)
            i = gameplay_player1(req);
        if (req->user == PLAYER2)
            i = gameplay_player2(req);
    }
    return;
}
