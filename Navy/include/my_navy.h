/*
** EPITECH PROJECT, 2024
** my_navy.h
** File description:
** .h
*/

#ifndef _MY_NAVY_H_
    #define _MY_NAVY_H_
    #include <signal.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>

enum player {
    PLAYER1,
    PLAYER2
};

enum statut {
    ACTIVE,
    DISABLED
};

enum callback {
    WIN = 0,
    LOSE = 1,
    NONE = 0
};

enum state {
    CLIENT,
    SERVER
};

enum map {
    A = 2,
    B = 4,
    C = 6,
    D = 8,
    E = 10,
    F = 12,
    G = 14,
    H = 16
};

enum packets {
    ConnectMessage,
    FinishedGame
};

static int SIG = 0;

static int const MAP_HIGHT = 10;
static int const MAP_LENGHT = 17;

static int const NB_SHIFT_MAX = 14;

typedef struct player_s {
    int pid;
    int statut;
    char **my_grid;
    char **enemy_grid;
} player_t;

typedef struct request_s {
    int user;
    player_t *player;
    int enemy_pid;
    int shift;
    int enemy_shift;
    int victory;
} request_t;

//create player
request_t *get_request(int ac, char **av);
//signal
int *my_getbinary(int nb);
void send_request(int type, int data);
int check_line(char *str);
//connect_usr
void display_grid(player_t *player);
request_t *process(int ac, request_t *req);
request_t *connect_user1(request_t *req);
request_t *connect_user2(request_t *req);
// game
void game(request_t *req);
int gameplay_player2(request_t *req);
int gameplay_player1(request_t *req);
int verif_user_entry(char *coord);
char *my_getuser(void);
//signal
int send_signal(char *coord, request_t *req);
//
int end_game(request_t *req);
// -h
void usage(void);

int error_handling(char **info);
#endif /* !_MY_NAVY_H_ */
