/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main of robot factory project
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/my/include/my_lib.h"
#include "../lib/rf/include/rf_lib.h"
#include "../include/body.h"

static int verif_indirect
(const op_t op_tab, char *param, int len_param, int index)
{
    for (int i = 0; param[i] != '\0'; i++) {
        if ((param[i] < '0' || param[i] > '9') && i != len_param - 1)
            return 1;
    }
    if (param[len_param - 1] != ',' &&
    (param[len_param - 1] < '0' || param[len_param - 1] > '9'))
        return 1;
    if (op_tab.type[index] != T_IND &&
    op_tab.type[index] != (T_IND | T_REG) &&
    op_tab.type[index] != (T_DIR | T_IND) &&
    op_tab.type[index] != (T_REG | T_IND | T_DIR))
        return 1;
    return 2;
}

static int verif_direct
(const op_t op_tab, char *param, int len_param, int index)
{
    if (param[0] != '%')
        return 0;
    if (len_param < 2)
        return 1;
    for (int i = 1; i < len_param - 1; i++) {
        if ((param[i] < '0' || param[i] > '9') &&
        param[1] != ':')
            return 1;
    }
    if (op_tab.type[index] != T_DIR &&
    op_tab.type[index] != (T_DIR | T_REG) &&
    op_tab.type[index] != (T_DIR | T_IND) &&
    op_tab.type[index] != (T_REG | T_IND | T_DIR))
        return 1;
    return 2;
}

static int verif_register
(const op_t op_tab, char *param, int len_param, int index)
{
    if (param[0] != 'r')
        return 0;
    if (len_param < 2 && len_param > 4)
        return 1;
    if (len_param == 4 || (len_param == 3 && param[len_param - 1] != ',')) {
        if (param[1] != '1' || (param[2] < '0' || param[2] > '6'))
            return 1;
    }
    if (len_param == 3 || (len_param == 2 && param[len_param - 1] != ',')) {
        if (param[1] < '0' || param[1] > '9')
            return 1;
    }
    if (op_tab.type[index] != T_REG &&
    op_tab.type[index] != (T_REG | T_DIR) &&
    op_tab.type[index] != (T_REG | T_IND) &&
    op_tab.type[index] != (T_REG | T_IND | T_DIR))
        return 1;
    return 2;
}

int verif_param_type(const op_t op_tab, char *param, int nb_param, int index)
{
    int len_param = my_strlen(param);
    int result = 0;

    result = verif_register(op_tab, param, len_param, nb_param);
    if (result != 0)
        return result;
    result = verif_direct(op_tab, param, len_param, nb_param);
    if (result != 0)
        return result;
    result = verif_indirect(op_tab, param, len_param, nb_param);
    if (result != 0)
        return result;
    return 1;
}

int verif_param(char **parameter, const op_t op_tab, int index)
{
    int nb_param = 0;
    int result = 0;

    for (int i = index; parameter[i] != NULL; i++) {
        nb_param ++;
        if (nb_param <= op_tab.nbr_args)
            result = verif_param_type(op_tab, parameter[i],
                                        nb_param - 1, i);
        if (result == 1)
            return 1;
    }
    if (nb_param != op_tab.nbr_args)
        return 1;
    return 0;
}

int verify_instruct(char **instruction, int index)
{
    char *instruct = NULL;

    if (instruction[index] == NULL)
        return 0;
    instruct = my_strdup(instruction[index]);
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(op_tab[i].mnemonique, instruct) == 0) {
            return verif_param(instruction, op_tab[i], index + 1);
        }
    }
    free(instruct);
    return 1;
}

int verif_line_body(char *line)
{
    char **instruction = my_split(line, ' ');
    int result = 0;

    if (instruction[1] == NULL && line[my_strlen(line) - 1] == ':')
        return 0;
    if (instruction[0][my_strlen(instruction[0]) - 1] == ':') {
        if (verify_instruct(instruction, 1) == 1)
            return 1;
    } else {
        if (verify_instruct(instruction, 0) == 1)
            return 1;
    }
    for (int i = 0; instruction[i] != NULL; i++)
        free(instruction[i]);
    free(instruction);
    return result;
}
