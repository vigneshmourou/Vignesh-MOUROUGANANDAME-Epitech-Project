/*
** EPITECH PROJECT, 2023
** error_gestion.c
** File description:
** takes care of errors before the flags
*/
#include "include/struct.h"
#include "include/my.h"
#include "include/percent.h"

int verif_error2(char c, char conv, int precision, int length)
{
    int flag_char = 0;
    int width = 0;

    for (int j = 0; c != FIELD_WIDTH[j].flag && c != conv; j++) {
        if (c == FIELD_WIDTH[j].flag)
            width++;
        if ((precision > 0 || length > 0) && c == FIELD_WIDTH[j].flag) {
            return -1;
        }
    }
    for (int j = 0; c != FLAG_CHARACTERS[j].flag && c != conv; j++) {
        if (c == FLAG_CHARACTERS[j].flag)
            flag_char++;
        if ((width > 0 || precision > 0 || length > 0) &&
            (c == FLAG_CHARACTERS[j].flag))
            return -1;
    }
    if (flag_char == 0 && width == 0 && precision == 0 && length == 0)
        return 0;
    return 0;
}

int verif_error(char c, char conv)
{
    int precision = 0;
    int length = 0;

    for (int j = 0; c != LENGTH_MODIFIERS[j].flag && c != conv; j++) {
        if (c == LENGTH_MODIFIERS[j].flag)
            length++;
        if (length >= 2 || precision > 0) {
            return -1;
        }
    }
    for (int j = 0; c != PRECISION[j].flag && c != conv; j++) {
        if (c == PRECISION[j].flag)
            precision++;
        if (length > 0 && c == PRECISION[j].flag)
            return -1;
    }
    if (verif_error2(c, conv, precision, length) == -1)
        return -1;
    return 0;
}

int error_order(const char *str, int i, char conv)
{
    for (i; str[i] != conv; i++)
        if (verif_error(str[i], conv) == -1)
            return -1;
    return 0;
}

int error_no_conv(const char *str, int i)
{
    char conv;
    int j = i;

    for (int j = 0; CONVERSION[j].flag != 0 && str[i] != '\0'; j++) {
        if (str[i] == CONVERSION[j].flag) {
            conv = str[i];
            break;
        }
        if (str[i + 1] == '\0' && CONVERSION[j + 1].flag == 0)
            return -1;
        if (CONVERSION[j + 1].flag == 0) {
            i++;
            j = -1;
        }
    }
    if (error_order(str, j, conv) == -1)
        return -1;
    return conv;
}
