/*
** EPITECH PROJECT, 2024
** mini_shell.h
** File description:
** all function of minishell
*/

#ifndef MY_MINISHELL_
    #define MY_MINISHELL_
    #include "my.h"

////////////////      LINKED_LIST FOR ENV
typedef struct envlk {
    char *value;
    struct envlk *next;
} t_envlk;
////////////////

/////////////////     LINKED LIST FUNCTION
t_envlk *create_env_lk(char **env);
void push_to_front(t_envlk *list, char *env);
/////////////////

/////////////////      BASIC COMMAND
void execute(char *arg, t_envlk *env_lk, char **env);
void execute_command(char *command, char *arg, t_envlk *env_lk, char **env);
/////////////////

/////////////////      ENV COMMAND
void execute_env(char *arg, t_envlk *env_lk, char **env);
/////////////////

/////////////////      SETENV COMMAND
void execute_setenv(char *arg, t_envlk *env_lk, char **env);
/////////////////

/////////////////      UNSETENV COMMAND
void execute_unsetenv(char *arg, t_envlk *env_lk, char **env);
/////////////////

/////////////////      cd COMMAND
void execute_cd(char *arg, t_envlk *env_lk, char **env);
/////////////////

#endif /* !MY_MINISHELL_ */
