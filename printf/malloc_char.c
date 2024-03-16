/*
** EPITECH PROJECT, 2023
** malloc_char.c
** File description:
** malloc for flag_characters functions
*/
#include "include/struct.h"
#include "include/percent.h"
#include "include/my.h"

int malloc_char(int i, const char *format, char conv)
{
    int	a = 0;
    int	b = 0;

    for (i; format[i] != conv; i++) {
        if (FLAG_CHARACTERS[a].flag == format[i]) {
            b++;
            a = 0;
            continue;
        }
        if (FLAG_CHARACTERS[a].flag != format[i] && format[i + 1] != '\0') {
            a++;
            i--;
        }
        if (FLAG_CHARACTERS[a].flag == 0)
            break;
    }
    return b;
}

int already_used(char *flag, char c)
{
    for (int a = 0; flag[a] != '\0'; a++) {
        if (flag[a] == c)
            return 1;
    }
    return 0;
}
