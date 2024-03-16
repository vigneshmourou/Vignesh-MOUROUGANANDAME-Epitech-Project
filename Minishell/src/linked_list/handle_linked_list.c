/*
** EPITECH PROJECT, 2024
** linked list
** File description:
** handle linked list for the MINISHELL project
*/

#include "my.h"
#include "mini_shell.h"
#include <stddef.h>
#include <stdlib.h>

void push_to_front(t_envlk *list, char *env)
{
    t_envlk *node = malloc(sizeof(t_envlk));

    while (list->next != NULL) {
        list = list->next;
    }
    node->value = my_strdup(env);
    node->next = NULL;
    list->next = malloc(sizeof(t_envlk));
    list->next = node;
    return;
}

t_envlk *create_env_lk(char **env)
{
    t_envlk *env_lk = malloc(sizeof(t_envlk));

    env_lk->value = my_strdup(env[0]);
    env_lk->next = NULL;
    for (int i = 1; env[i] != NULL; i++)
        push_to_front(env_lk, env[i]);
    return env_lk;
}
