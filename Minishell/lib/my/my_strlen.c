/*
** EPITECH PROJECT, 2023
** my_strlen.c
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int rep = 0;

    while (str[rep] != '\0') {
        rep ++;
    }
    return (rep);
}
