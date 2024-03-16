/*
** EPITECH PROJECT, 2024
** create_table.c
** File description:
** create table
*/
#include <stdlib.h>
#include "../../include/hashtable.h"

hashtable_t *new_hashtable(int (*hash)(char *, int), int len)
{
    hashtable_t *hashtable = malloc(sizeof(hashtable_t));

    if (len < 1)
        return NULL;
    if (hash == NULL || len <= 0) {
        return NULL;
    }
    if (hashtable == NULL) {
        return NULL;
    }
    hashtable->hash_tab = malloc(sizeof(hashcode_t *) * len);
    if (hashtable->hash_tab == NULL) {
        free(hashtable);
        return NULL;
    }
    hashtable->len = len;
    hashtable->hash_funct = hash;
    for (int i = 0; i < len; i++)
        hashtable->hash_tab[i] = NULL;
    return hashtable;
}
