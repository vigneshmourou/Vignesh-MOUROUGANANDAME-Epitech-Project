/*
** EPITECH PROJECT, 2024
** mini_shell.h
** File description:
** all function of minishell
*/

#ifndef MY_MINISHELL_COMMAND_
    #define MY_MINISHELL_COMMAND_
    #include "my.h"
    #include "mini_shell.h"
    #include <stddef.h>

typedef struct command {
    char *com;
    void (*funct)(char *, t_envlk *, char **);
} t_command;

static t_command const COMMAND[6] = {
    {"env", &execute_env},
    {"setenv", &execute_setenv},
    {"unsetenv", &execute_unsetenv},
    {"cd", &execute_cd},
    {NULL, &execute},
    {NULL, NULL}
};

#endif /* !MY_MINISHELL_COMMAND_ */
