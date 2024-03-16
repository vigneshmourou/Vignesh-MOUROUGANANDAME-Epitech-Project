/*
** EPITECH PROJECT, 2023
** percent.h
** File description:
** stock prototypes functions
*/

#ifndef PERCENT
    #define PERCENT
    #include <stdarg.h>

void my_put_spaces(int stop, char spaces);
int spaces_handle(int nb_spaces, int uni, int placement, char *flag);
int handling(char **f, char conv, int nb, int *size);
int handling_str(char **f, char conv, char *nb, int *size);
int zero(char *flag, int uni, char f, char conv);
int less(char f, int placement);
int increase(char f, char conv, int *size, int nb);
int hashtag(char f, char conv, int *size, int base);
int verif_pre(int pre, char **flag);
double verif_point(char *prc, int pre, double vig_nb);
int precis(char **flag, char conv, int *size, int nb);
int put_precision(char **flag, char conv, int *size, int a);
int increase_str(char f, char conv, int *size, char *nb);
char percent_space(char c);
char percent_flag_characters(char c);
void my_put_spaces(int stop, char spaces);
char *reorganization(char *flag);
int verif_otherflags(char *flag, char conv);
int verif_base(char conv, int *size);
int verif_pos(int nb);
int verif_pos_str(char *nb, char conv);
int verif_error2(char c, char conv, int precision, int length);
int verif_error(char c, char conv);
int error_order(const char *str, int i, char conv);
int error_no_conv(const char *str, int i);
int displaying(const char *format, int i, int *nb_print, va_list ap);
void gest(int base, char conv);
void gest2(char conv, int plus);
void to_int(char *print_percent, int nb);
void percent_f_parcours(double vig_nb, int pre, int *nb_print, char *prc);
char *second_percent_f(double vig_nb, int *nb_print, char **flag, char *prc);
char *converting_f(va_list ap, int *nb_print, char **flag);
char *flag_character_search(const char *format, char conv, int i, int *cnt);
char *field_width_search(const char *format, int i, int *cnt);
char *precision_search(const char *format, int i, int *cnt);
int length_modifier_search(const char *format, va_list ap, int i, int *cnt);
int conversion_search(char conv, va_list ap, int *nb_print, char **f);
int my_printf(const char *format, ...);
void percent_f(va_list ap, int *nb_print, char **flag);
void percent_iud(va_list ap, int *nb_print, char **flag);
void percent_s(va_list ap, int *nb_print, char **flag);
void percent_c(va_list ap, int *nb_print, char **flag);
void percent_per(va_list ap, int *nb_print, char **flag);
void my_put_spaces(int stop, char spaces);
char *percent_nb(const char *str, char *width, int i, int *cnt_char);
void percent_x(va_list ap, int *nb_print, char **flag);
void percent_upx(va_list ap, int *nb_print, char **flag);
char *to_hexa(unsigned int nb, int x);
int counting_hexa(int nb);
void percent_o(va_list ap, int *nb_print, char **flag);
unsigned int to_octal(unsigned int nb);
void verif_plus_tag(int plus, int tag, int *size);
int plus_used(char *flag);
int counting_octal(int nb);
int percent_h(char c, va_list ap, int *nb_char_flag);
int double_h(va_list ap);
int percent_l(char c, va_list ap, int *nb_char_flag);
int double_l(va_list ap);
int malloc_char(int i, const char *format, char conv);
int already_used(char *flag, char c);

#endif
