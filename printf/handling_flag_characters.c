/*
** EPITECH PROJECT, 2023
** handling_flag_characters.c
** File description:
** handling flag characters
*/
#include <stdlib.h>
#include "include/my.h"
#include "include/percent.h"

int verif_pos(int nb)
{
    if (nb >= 0)
        return 1;
    if (nb < 0)
        return 0;
    return 0;
}

int verif_base(char conv, int *size)
{
    switch (conv) {
    case ('o') :
        *size += 1;
        return 1;
    case ('x') :
        *size += 2;
        return 2;
    case ('X') :
        *size += 2;
        return 2;
    }
    return 0;
}

int verif_otherflags(char *flag, char conv)
{
    for (int i = 0; flag[i] != '\0'; i++)
        if (flag[i] == '-' || conv == 'c')
            return 0;
    return 1;
}

char *reorganization(char *flag)
{
    int j = 0;
    int k = 0;
    char *order = " +#0-";
    char *reorganize = malloc(sizeof(char) * my_strlen(flag) + 1);

    for (int i = 0; order[j] != '\0'; i++) {
        if (flag[i] == order[j]) {
            reorganize[k] = flag[i];
            k++;
            j++;
            i = -1;
            continue;
        }
        if (flag[i] != order[j] && flag[i + 1] == '\0') {
            j++;
            i = -1;
        }
    }
    reorganize[my_strlen(flag) + 1] = '\0';
    return reorganize;
}
