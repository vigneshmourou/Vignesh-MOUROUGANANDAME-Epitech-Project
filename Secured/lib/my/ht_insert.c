/*
** EPITECH PROJECT, 2024
** ht_insert.c
** File description:
** handle table
*/
#include "../../include/my.h"
#include "../../include/hashtable.h"
#include <stdlib.h>

hashcode_t *fill_hashcode(hashtable_t *ht, char *key,
                          char *value, hashcode_t *hash_tab)
{
    hash_tab->key = my_strdup(key);
    hash_tab->value = my_strdup(value);
    hash_tab->hash_num = ht->hash_funct(key, ht->len);
    hash_tab->next = ht->hash_tab[hash_tab->hash_num % ht->len];
    return hash_tab;
}

int ht_insert(hashtable_t *ht, char *key, char *value)
{
    hashcode_t *hash_tab = malloc(sizeof(hashcode_t));
    hashcode_t *tmp = NULL;

    if (ht == NULL || key == NULL || value == NULL || hash_tab == NULL) {
        free(hash_tab);
        return 84;
    }
    for (int i = 0; ht->len > i; i++) {
        tmp = ht->hash_tab[i];
        while (tmp != NULL &&
                my_strcmp(tmp->key, key) != 0)
            tmp = tmp->next;
        if (tmp != NULL) {
            tmp->value = my_strdup(value);
            return 0;
        }
    }
    hash_tab = fill_hashcode(ht, key, value, hash_tab);
    ht->hash_tab[hash_tab->hash_num % ht->len] = hash_tab;
    return 0;
}
