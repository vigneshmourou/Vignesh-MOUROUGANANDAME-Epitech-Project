/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main navy
*/
#include "my.h"
#include "my_navy.h"
#include <stddef.h>
void free_funct(request_t *req)
{
    free(req->player->my_grid);
    free(req->player->enemy_grid);
    free(req);
}

int main(int ac, char **av)
{
    request_t *req = NULL;

    if (ac != 2 && ac != 3)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        usage();
        return 0;
    }
    req = get_request(ac, av);
    if (req == NULL)
        return (84);
    if (ac == 3 && kill(req->enemy_pid, 0) == -1) {
        write(2, "Invalid pid\n", 12);
        return (84);
    }
    process(ac, req);
    game(req);
    free_funct(req);
    return end_game(req);
}
