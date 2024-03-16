/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** kill for bootstrap navy
*/

#include "my.h"
#include "mini_shell.h"
#include "command_shell.h"
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

static char *replace_tab(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
    return str;
}

int verif_command(char *com, t_envlk **env_lk, char **env)
{
    char *arg = malloc(sizeof(char) * (my_strlen(com) - 1));
    char **command = NULL;
    t_envlk *tmp = *env_lk;
    int result = 0;

    my_putstr(my_cleanstr(com, ' '));
    arg = my_strncat(arg, my_cleanstr(com, ' '), my_strlen(my_cleanstr(com, ' ')) - 1);
    command = my_split(arg, ' ');
    my_putstr(com);
    my_putchar('\n');
    my_putstr(arg);
    my_putchar('\n');
    my_putstr(command[0]);
    my_putchar('\n');
    for (int i = 0; COMMAND[i].funct != NULL; i++) {
        if (my_strcmp(command[0], COMMAND[i].com) == 0) {
            COMMAND[i].funct(replace_tab(com), *env_lk, env);
            break;
        }
        if (COMMAND[i].com == NULL)
            COMMAND[i].funct(replace_tab(com), *env_lk, env);
    }
    if ((*env_lk)->value == NULL) {
        *env_lk = (*env_lk)->next;
        free(tmp);
    }
    free(arg);
    free(command);
    return result;
}

void execute(char *arg, t_envlk *env_lk, char **env)
{
    pid_t pid = fork();
    int child = 0;
    char *command = malloc(sizeof(char) * (26 + my_strlen(arg)));
    int return_value = 0;

    if (command == NULL)
        return;
    if (pid == 0) {
        execute_command(command, arg, env_lk, env);
        free(command);
        exit(84);
    } else {
        return_value = wait(&child);
        free(command);
    }
}

int verif_exit(char *mot)
{
    if (my_strlen(mot) != 5)
        return 1;
    if (mot[0] == 'e' && mot[1] == 'x' && mot[2] == 'i' && mot[3] == 't')
        return 0;
    return 1;
}

int main(int ac, char **av, char **env)
{
    char *arg = NULL;
    size_t len = 0;
    int verif = 0;
    t_envlk *env_list = create_env_lk(env);
    int result = 0;

    while (1) {
        my_putstr("$vignesh$ > ");
        verif = getline(&arg, &len, stdin);
        if (verif == -1)
            return 0;
        if (verif_exit(arg) == 0 || verif == 0)
            return 0;
        else
            result = verif_command(arg, &env_list, env);
    }
    return result;
}
