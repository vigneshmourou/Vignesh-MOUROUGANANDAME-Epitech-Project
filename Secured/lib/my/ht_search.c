/*
** EPITECH PROJECT, 2024
** ht_search.c
** File description:
** handle table
*/
#include "../../include/my.h"
#include "../../include/hashtable.h"
#include <stddef.h>

char *ht_search(hashtable_t *ht, char *key)
{
    hashcode_t *tmp = NULL;

    if (ht == NULL || key == NULL)
        return NULL;
    for (int i = 0; ht->len > i; i++) {
        tmp = ht->hash_tab[i];
        while (tmp != NULL &&
                my_strcmp(tmp->key, key) != 0)
            tmp = tmp->next;
        if (tmp != NULL)
            return tmp->value;
    }
    return NULL;
}
