/*
** EPITECH PROJECT, 2024
** basic command
** File description:
** file to handle basic command
*/

#include "my.h"
#include "mini_shell.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char *path_char(t_envlk *env)
{
    char **ever_path = NULL;
    char *path = NULL;

    ever_path = my_split(env->value, '=');
    while (my_strcmp(ever_path[0], "PATH") != 0) {
        env = env->next;
        for (int i = 0; ever_path[i] != NULL; i++)
            free(ever_path[i]);
        free(ever_path);
        ever_path = NULL;
        ever_path = my_split(env->value, '=');
    }
    path = ever_path[1];
    free(ever_path);
    return path;
}

void execute_command(char *command, char *arg, t_envlk *env_lk, char **env)
{
    char **mot = NULL;
    char *path = path_char(env_lk);
    char *tmp = NULL;

    tmp = strtok(path, ":");
    while (tmp != NULL) {
        if (arg[0] != '.') {
            command = my_strdup(tmp);
            my_strcat(command, "/");
        }
        my_strncat(command, my_cleanstr(arg, ' '),
                    my_strlen(my_cleanstr(arg, ' ')) - 1);
        mot = my_split(command, ' ');
        execve(mot[0], mot, env);
        command[0] = '\0';
        free(mot);
        mot = NULL;
        tmp = strtok(NULL, ":");
    }
}
