/*
** EPITECH PROJECT, 2024
** B-MUL-200-PAR-2-1-mypaint-matthias.balon
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
