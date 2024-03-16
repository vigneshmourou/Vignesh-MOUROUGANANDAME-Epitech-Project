/*
** EPITECH PROJECT, 2023
** unit test
** File description:
** test
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"
#include "percent.h"
#include "struct.h"


void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world ");
    cr_assert_stdout_eq_str (" hello world ");
}

Test(my_printf_d, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %d", 9);
    cr_assert_stdout_eq_str(" hello world 9");
}

Test(my_printf_Od, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %04d", 9);
    cr_assert_stdout_eq_str(" hello world 0009");
}

Test(my_printf_espaced, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %5d", 9);
    cr_assert_stdout_eq_str(" hello world     9");
}

Test(my_printf_lessespaced, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %-5d", 9);
    cr_assert_stdout_eq_str(" hello world 9    ");
}

Test(my_printf_char, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %c", 'm');
    cr_assert_stdout_eq_str(" hello world m");
}

Test(my_printf_charspace, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %            c", 'm');
    cr_assert_stdout_eq_str(" hello world  m");
}

Test(my_printf_str, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %s", "caca_test");
    cr_assert_stdout_eq_str(" hello world caca_test");
}

Test(my_printf_malanged, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %+-#010d", 10);
    cr_assert_stdout_eq_str(" hello world +10       ");
}

Test(my_printf_i, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %i", 10);
    cr_assert_stdout_eq_str(" hello world 10");
}

Test(my_printf_f, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %f", 9.765);
    cr_assert_stdout_eq_str(" hello world 9.765000");
}

Test(my_printf_percent, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %%", 10);
    cr_assert_stdout_eq_str(" hello world %");
}

Test(my_printfsplus, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %+sd", "lol");
    cr_assert_stdout_eq_str(" hello world lold");
}

Test(my_printf_precision_float, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %.4f", 9.243546789765434);
    cr_assert_stdout_eq_str(" hello world 9.2435");
}

Test(my_printf_lesstr, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %-s", "mp");
    cr_assert_stdout_eq_str(" hello world mp");
}

Test(my_printf_x, simple_string, .init = redirect_all_std)
{
    my_printf(" hello world %x", 89);
    cr_assert_stdout_eq_str(" hello world 59");
}
