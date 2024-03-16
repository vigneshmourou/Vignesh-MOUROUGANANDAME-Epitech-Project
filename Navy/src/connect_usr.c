/*
** EPITECH PROJECT, 2024
** connect_usr.c
** File description:
** dsc
*/
#include "my.h"
#include "my_navy.h"
#include <signal.h>
#include <unistd.h>

void handle_connect(int sig, siginfo_t *info, void *context)
{
    SIG = info->si_pid;
}

request_t *connect_user1(request_t *req)
{
    struct sigaction sig;

    sig.sa_sigaction = &handle_connect;
    sig.sa_flags = SA_SIGINFO;
    my_printf("my_pid: %d\n\nwaiting for enemy connection...\n\n",
                req->player->pid);
    sigaction(SIGUSR1, &sig, NULL);
    pause();
    req->enemy_pid = SIG;
    my_printf("enemy connected\n\n");
    return req;
}

request_t *connect_user2(request_t *req)
{
    my_printf("my_pid: %d\n\n", req->player->pid);
    my_putstr("successfully connected\n\n");
    kill(req->enemy_pid, SIGUSR1);
    return req;
}

request_t *process(int ac, request_t *req)
{
    if (ac == 2)
        req = connect_user1(req);
    else if (ac == 3)
        req = connect_user2(req);
    return req;
}
