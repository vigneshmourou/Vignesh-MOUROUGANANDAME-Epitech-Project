/*
** EPITECH PROJECT, 2024
** cd
** File description:
** cd file
*/

#include "my.h"
#include "mini_shell.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void replace_value(char *command, t_envlk *env_lk)
{
    t_envlk *tmp = env_lk;
    char **variable = NULL;

    while (tmp != NULL) {
        variable = my_split(tmp->value, '=');
        if (my_strcmp(variable[0], "PWD") == 0) {
            tmp->value = NULL;
            free(tmp->value);
            tmp->value = my_strdup(command);
            return;
        }
        tmp = tmp->next;
    }
}

static char *search_path_env(char *variable, t_envlk *env_lk)
{
    char *path = NULL;
    char **line = NULL;
    t_envlk *tmp = env_lk;

    while (tmp != NULL) {
        line = my_split(tmp->value, '=');
        if (my_strcmp(line[0], variable) == 0) {
            path = my_strdup(line[1]);
            free(line);
            return path;
        }
        tmp = tmp->next;
    }
    free(line);
    free(path);
    return NULL;
}

static void manage_cd(char **arg, t_envlk *env_lk)
{
    char *home_path = search_path_env("HOME", env_lk);
    char *path = malloc(sizeof(char) * my_strlen(home_path) + 2);

    path[0] = '\0';
    path = my_strcat(path, home_path);
    path = my_strcat(path, "/");
    if (count_word(arg) == 1 || my_strcmp(arg[1], "~") == 0)
        chdir(path);
    else
        chdir(arg[1]);
    free(path);
    free(home_path);
    return;
}

void execute_cd(char *arg, t_envlk *env_lk, char **env)
{
    my_putchar('n');
    char *com = malloc(sizeof(char) * (my_strlen(arg)));
    char **path = NULL;
    char pwd[100];
    char *final_path = NULL;

    com = my_strncat(com, arg, my_strlen(arg) - 1);
    path = my_split(com, ' ');
    if (count_word(path) > 2)
        return;
    manage_cd(path, env_lk);
    getcwd(pwd, sizeof(pwd));
    my_putstr(pwd);
    final_path = malloc(sizeof(char) * (my_strlen(pwd) + 6));
    final_path[0] = '\0';
    final_path = my_strcat(final_path, "PWD=");
    final_path = my_strcat(final_path, pwd);
    replace_value(final_path, env_lk);
    return;
}
