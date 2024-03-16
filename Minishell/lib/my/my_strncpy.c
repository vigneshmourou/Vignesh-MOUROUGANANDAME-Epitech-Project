/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** function that copies n characters from a string into another
*/

char *my_strncpy(char *dest, char const *str, int n)
{
    if (n == 0) {
        return dest;
    }
    for (int i = 1; i <= n; i++) {
        if (i > my_strlen2(str)) {
            dest[i - 1] = '\0';
            return dest;
        } else {
            dest[i - 1] = str[i - 1];
        }
    }
    return dest;
}

int my_strlen2(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++){
        len++;
    }
    return len;
}
