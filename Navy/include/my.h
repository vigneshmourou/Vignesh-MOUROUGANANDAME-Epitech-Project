/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h library
*/

#ifndef MY_H_
    #define MY_H_
    #define EXIT_ERROR 84

int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
int my_getnbr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char **my_split(char **dest, char *str, char sep);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_printf(const char *format, ...);
#endif /* !MY_H_ */
