/*
** EPITECH PROJECT, 2023
** flags_search.c
** File description:
** this file looks out if there's one flag or more
*/
#include "include/struct.h"
#include "include/percent.h"
#include "include/my.h"

char *flag_character_search(const char *format, char conv, int i, int *cnt)
{
    char *flags = malloc(sizeof(char) * malloc_char(i, format, conv));
    int k = 0;

    flags[0] = '%';
    for (int j = 0; FLAG_CHARACTERS[j].flag != 0 && format[i] != conv; j++) {
        if (already_used(flags, format[i]) == 1) {
            *cnt += 1;
            i++;
            continue;
        }
        if (format[i] == FLAG_CHARACTERS[j].flag){
            flags[k] = FLAG_CHARACTERS[j].function(format[i]);
            *cnt += 1;
            j = -1;
            i++;
            k++;
            continue;
        }
    }
    return flags;
}

char *field_width_search(const char *format, int i, int *cnt)
{
    char *width;
    int a = 1;

    for (int j = 0; FIELD_WIDTH[j].flag != 0; j++) {
        for (int k = i; format[k] >= '0' && format[k] <= '9'; k++)
            a++;
        width = malloc(sizeof(char) * a + 1);
        width[0] = '0';
        if (format[i] == FIELD_WIDTH[j].flag) {
            width = FIELD_WIDTH[j].function(format, width, i, cnt);
            break;
        }
    }
    width[a + 1] = '\0';
    return width;
}

char *precision_search(const char *format, int i, int *cnt)
{
    char *precision;
    int a = 1;

    for (int j = 0; PRECISION[j].flag != 0; j++) {
        for (int k = i; format[k] >= '0' && format[k] <= '9'; k++)
            a++;
        precision = malloc(sizeof(char) * a + 1);
        precision[0] = ' ';
        if (format[i] == PRECISION[j].flag) {
            precision = PRECISION[j].function(format, precision, i + 1, cnt);
            *cnt += 1;
            break;
        }
    }
    precision[a + 1] = '\0';
    return precision;
}

int length_modifier_search(const char *format, va_list ap, int i, int *cnt)
{
    int length = 0;

    for (int j = 0; LENGTH_MODIFIERS[j].flag != 0; j++) {
        if (format[i] == LENGTH_MODIFIERS[j].flag) {
            break;
        }
    }
    return 0;
}

int conversion_search(char conv, va_list ap, int *nb_print, char **flag)
{
    for (int j = 0; CONVERSION[j].flag != 0; j++) {
        if (conv == CONVERSION[j].flag) {
            CONVERSION[j].function(ap, nb_print, flag);
            break;
        }
    }
    return 1;
}
