/*
** EPITECH PROJECT, 2024
** env
** File description:
** env file
*/

#include "my.h"
#include "mini_shell.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void execute_env(char *arg, t_envlk *env_lk, char **env)
{
    while (env_lk != NULL) {
        my_putstr(env_lk->value);
        my_putchar('\n');
        env_lk = env_lk->next;
    }
    return;
}
