/*
** EPITECH PROJECT, 2024
** delete_table.c
** File description:
** delete table
*/
#include <stdlib.h>
#include "../../include/hashtable.h"

void delete_hashtable(hashtable_t *ht)
{
    hashcode_t *node = NULL;

    if (ht == NULL || ht->hash_tab == NULL) {
        return;
    }
    for (int i = 0; i < ht->len; i++) {
        while (ht->hash_tab[i] != NULL) {
            node = ht->hash_tab[i];
            ht->hash_tab[i] = ht->hash_tab[i]->next;
            free(node->key);
            free(node->value);
            free(node);
        }
    }
    free(ht->hash_tab);
    free(ht);
    return;
}
