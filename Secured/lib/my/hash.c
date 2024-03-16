/*
** EPITECH PROJECT, 2024
** hash.c
** File description:
** hash function
*/
#include "../../include/my.h"
#include "../../include/hashtable.h"
#include <stdio.h>

int hash(char *key, int len)
{
    unsigned int hash = 5381;
    int c;

    if (len <= 0) {
        return 84;
    }
    for (int i = 0; i < my_strlen(key); i++) {
        c = key[i];
        hash = (hash * 33) ^ c * (53803 + 3648 * 23);
        }
    if (hash < 0) {
            hash = (hash * hash) * 2;
        }
    return hash & 0x7FFFFFFF;
}
