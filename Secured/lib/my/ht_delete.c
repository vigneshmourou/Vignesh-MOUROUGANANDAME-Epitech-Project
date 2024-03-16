/*
** EPITECH PROJECT, 2024
** ht_delete.c
** File description:
** handle table
*/
#include "../../include/my.h"
#include "../../include/hashtable.h"
#include <stdlib.h>
#include <stddef.h>

static void free_funct(hashcode_t *tmp)
{
    free(tmp->key);
    free(tmp->value);
    free(tmp);
}

static int verif_del(hashcode_t **ht, char *key)
{
    hashcode_t *tmp = *ht;
    hashcode_t *prev = NULL;

    while (tmp != NULL && my_strcmp(tmp->key, key) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp != NULL) {
        if (prev == NULL) {
            *ht = tmp->next;
        } else {
            prev->next = tmp->next;
        }
        free_funct(tmp);
        return 0;
    }
    return 84;
}

int ht_delete(hashtable_t *ht, char *key)
{
    hashcode_t *prev = NULL;
    hashcode_t *tmp = NULL;

    if (ht == NULL)
        return 84;
    for (int i = 0; ht->len > i; i++) {
        tmp = ht->hash_tab[i];
        while (tmp != NULL &&
                my_strcmp(tmp->key, key) != 0) {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    for (int i = 0; i < ht->len; i++) {
        if (verif_del(&(ht->hash_tab[i]), key) == 0)
            return 0;
    }
    return 84;
}
