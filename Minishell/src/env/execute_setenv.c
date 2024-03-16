/*
** EPITECH PROJECT, 2024
** setenv
** File description:
** setenv file
*/

#include "my.h"
#include "mini_shell.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static void replace_value(char *command, t_envlk *env_lk)
{
    t_envlk *tmp = env_lk;
    char **variable = NULL;
    char **second_variable = NULL;

    second_variable = my_split(command, '=');
    while (tmp != NULL) {
        variable = my_split(tmp->value, '=');
        if (my_strcmp(variable[0], second_variable[0]) == 0) {
            free(tmp->value);
            tmp->value = NULL;
            tmp->value = my_strdup(command);
            return;
        }
        tmp = tmp->next;
    }
    push_to_front(env_lk, command);
}

void execute_setenv(char *arg, t_envlk *env_lk, char **env)
{
    char *com = malloc(sizeof(char) * (my_strlen(arg)));
    char **command = NULL;
    char *final_command = malloc(sizeof(char) * (my_strlen(arg) + 1));

    com = my_strncat(com, arg, my_strlen(arg) - 1);
    command = my_split(com, ' ');
    if (count_word(command) > 3)
        return;
    if (count_word(command) == 1) {
        execute_env(arg, env_lk, env);
        return;
    }
    final_command = my_strcat(final_command, command[1]);
    final_command = my_strcat(final_command, "=");
    if (command[2] != NULL)
        final_command = my_strcat(final_command, command[2]);
    replace_value(final_command, env_lk);
    return;
}
