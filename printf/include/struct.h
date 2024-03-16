/*
** EPITECH PROJECT, 2023
** struct.h
** File description:
** struct
*/

#ifndef FLAGS
    #define FLAGS
    #include <stddef.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include "percent.h"
    #include "my.h"

typedef struct conv {
    char flag;
    void (*function)(va_list, int *, char **);
} conv;

typedef struct length {
    char flag;
    int (*function)(char, va_list, int *);
} length;

typedef struct number {
    char flag;
    char *(*function)(const char *, char *, int, int *);
} number;

typedef struct flag {
    char flag;
    char (*function)(char);
} flag;

static flag const FLAG_CHARACTERS[6] = {
    {'#', &percent_flag_characters},
    {'0', &percent_flag_characters},
    {'-', &percent_flag_characters},
    {'+', &percent_flag_characters},
    {' ', &percent_space},
    {0, NULL}
};

static number const FIELD_WIDTH[10] = {
    {'1', &percent_nb},
    {'2', &percent_nb},
    {'3', &percent_nb},
    {'4', &percent_nb},
    {'5', &percent_nb},
    {'6', &percent_nb},
    {'7', &percent_nb},
    {'8', &percent_nb},
    {'9', &percent_nb},
    {0, NULL}
};

static number const PRECISION[2] = {
    {'.', &percent_nb},
//      {'*', &percent_star},
    {0, NULL}
};

static length const LENGTH_MODIFIERS[6] = {
    {'h', &percent_h},
    {'l', &percent_l},
/*    {'L', &percent_L},
    {'j', &percent_j},
    {'z', &percent_z},
    {'t', &percent_t},*/
    {0, NULL}
};

static conv const CONVERSION[11] = {
    {'d', &percent_iud},
    {'i', &percent_iud},
    {'s', &percent_s},
    {'c', &percent_c},
    {'%', &percent_per},
//    {'m', &percent_m},
//    {'n', &percent_n},
    {'o', &percent_o},
    {'u', &percent_iud},
/*    {'a', &percent_a},
    {'A', &percent_upa},
    {'e', &percent_e},
    {'E', &percent_upe},*/
    {'f', &percent_f},
/*    {'F', &percent_upf},
    {'g', &percent_g},
    {'G', &percent_upg},*/
    {'x', &percent_x},
    {'X', &percent_upx},
    {0, NULL}
};

#endif
