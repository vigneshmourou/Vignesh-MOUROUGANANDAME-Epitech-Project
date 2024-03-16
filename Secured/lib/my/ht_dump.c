/*
** EPITECH PROJECT, 2024
** ht_dump.c
** File description:
** handle table
*/
#include "../../include/my.h"
#include "../../include/hashtable.h"
#include <stddef.h>

void ht_dump(hashtable_t *ht)
{
    hashcode_t *node = NULL;
    hashcode_t *tmp = NULL;

    if (ht == NULL)
        return;
    for (int i = 0; ht->len > i; i++) {
        tmp = ht->hash_tab[i];
        my_putchar('[');
        my_put_nbr(i);
        my_putstr("]:\n");
        while (tmp != NULL) {
            my_putstr("> ");
            my_put_nbr(tmp->hash_num);
            my_putstr(" - ");
            my_putstr(tmp->value);
            my_putchar('\n');
            tmp = tmp->next;
        }
    }
    return;
}
