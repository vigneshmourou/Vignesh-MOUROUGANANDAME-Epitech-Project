/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** my string copy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0' || src[i] == '\0') {
        dest[i] = src[i];
        i ++;
        if (src[i] == '\0') {
            dest[i] = '\0';
            return dest;
        }
    }
    return dest;
}
