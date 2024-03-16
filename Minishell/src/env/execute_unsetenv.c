/*
** EPITECH PROJECT, 2024
** unsetenv
** File description:
** unsetenv file
*/

#include "my.h"
#include "mini_shell.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void del_node(char *variable, t_envlk *env_lk)
{
    t_envlk *tmp = env_lk;
    t_envlk *prev = NULL;
    char **env_variable = NULL;

    while (tmp != NULL) {
        env_variable = my_split(tmp->value, '=');
        if (my_strcmp(variable, env_variable[0]) == 0) {
            prev->next = tmp->next;
            free(tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
        free(env_variable);
        env_variable = NULL;
    }
    return;
}

void execute_unsetenv(char *arg, t_envlk *env_lk, char **env)
{
    char *com = malloc(sizeof(char) * (my_strlen(arg)));
    char **command = NULL;
    char **env_variable = NULL;
    t_envlk *tmp = env_lk;

    com = my_strncat(com, arg, my_strlen(arg) - 1);
    command = my_split(com, ' ');
    if (count_word(command) != 2)
        return;
    env_variable = my_split(env_lk->value, '=');
    if (my_strcmp(command[1], env_variable[0]) == 0) {
        env_lk = env_lk->next;
        tmp->value = NULL;
        return;
    }
    del_node(command[1], env_lk);
    return;
}
