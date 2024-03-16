/*
** EPITECH PROJECT, 2024
** get_request.c
** File description:
** get request
*/
#include "my.h"
#include "my_navy.h"
#include <stddef.h>

static int verif_letter(char letter)
{
    switch (letter) {
    case 'A':
        return A;
    case 'B':
        return B;
    case 'C':
        return C;
    case 'D':
        return D;
    case 'E':
        return E;
    case 'F':
        return F;
    case 'G':
        return G;
    case 'H':
        return H;
    }
    return 0;
}

char **fill_empty_grid(void)
{
    char **map = malloc(sizeof(char *) * MAP_HIGHT + 1);

    map[0] = my_strdup(" |A B C D E F G H");
    map[1] = my_strdup("-+---------------");
    for (int i = 2; i < MAP_HIGHT; i++) {
        map[i] = malloc(sizeof(char) * MAP_LENGHT + 1);
        map[i][0] = (i - 1) + 48;
        map[i][1] = '|';
        for (int j = 2; j < MAP_LENGHT; j++) {
            map[i][j] = (j % 2 == 0) ? '.' : ' ';
        }
        map[i][MAP_LENGHT] = '\0';
    }
    map[MAP_HIGHT] = NULL;
    return map;
}

static char **place_ship(char **map, char **ship_info)
{
    if (ship_info[1][0] != ship_info[2][0] &&
        ship_info[1][1] != ship_info[2][1])
        return NULL;
    if (error_handling(ship_info) == 1)
        return NULL;
    if (ship_info[1][0] == ship_info[2][0]) {
        for (int i = (ship_info[1][1] - 48) + 1;
                i < (ship_info[2][1] - 48) + 2; i++)
            map[i][verif_letter(ship_info[1][0])] = ship_info[0][0];
    } else {
        for (int i = 0; i + ship_info[1][0] <= ship_info[2][0]; i++)
            map[ship_info[1][1] - 48][verif_letter(i + ship_info[1][0])] =
            ship_info[0][0];
    }
    return map;
}

char **fill_grid(char *path)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    char **line_info = NULL;
    char **map = fill_empty_grid();

    file = fopen(path, "r");
    if (file == NULL)
        return NULL;
    while (getline(&line, &len, file) != -1) {
        if (check_line(line) == -1)
            return NULL;
        line_info = my_split(line_info, line, ':');
        map = place_ship(map, line_info);
        if (map == NULL)
            return NULL;
    }
    return map;
}

player_t *fill_player2(char **av)
{
    player_t *player2 = malloc(sizeof(player_t));
    int pid = getpid();

    player2->pid = pid;
    player2->statut = ACTIVE;
    player2->my_grid = fill_grid(av[2]);
    if (player2->my_grid == NULL)
        return NULL;
    player2->enemy_grid = fill_empty_grid();
    return player2;
}

player_t *fill_player1(char **av)
{
    player_t *player1 = malloc(sizeof(player_t *));

    player1->pid = getpid();
    player1->statut = ACTIVE;
    player1->my_grid = fill_grid(av[1]);
    if (player1->my_grid == NULL)
        return NULL;
    player1->enemy_grid = fill_empty_grid();
    return player1;
}

request_t *get_request(int ac, char **av)
{
    request_t *req = malloc(sizeof(request_t *));

    if (ac == 2) {
        req->player = fill_player1(av);
        req->user = PLAYER1;
    } else if (ac == 3) {
        req->user = PLAYER2;
        req->player = fill_player2(av);
        req->enemy_pid = my_getnbr(av[1]);
    }
    req->shift = 0;
    req->enemy_shift = 0;
    if (req->player == NULL)
        return NULL;
    return (req);
}
