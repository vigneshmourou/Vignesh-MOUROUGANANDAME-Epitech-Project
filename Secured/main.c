/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main secured
*/

#include "include/hashtable.h"
#include "include/my.h"
#include <stdio.h>

int main(void)
{
    hashtable_t *ht = new_hashtable(&hash, 2);
    ht_insert(ht, "Vision", "./Documents/Tournament/Modules/Vision");
    ht_insert(ht, "Vision", "test");
    ht_delete(ht, "lol");
    ht_dump(ht);
    printf("%s", ht_search(ht, "Vision"));
    return 0;
}
