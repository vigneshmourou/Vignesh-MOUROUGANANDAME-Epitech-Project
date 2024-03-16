##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC     =	my_printf.c	\
		precision_handle.c	\
		percent_d_per.c	\
		percent_double_x.c	\
		percent_flag_characters.c	\
		percent_f.c	\
		percent_width.c	\
		percent_l_h.c	\
		percent_o.c	\
		malloc_char.c	\
		error_gestion.c	\
		handling_str.c	\
		handling_flag_characters.c	\
		handling_flag_characters_2.c	\
		flags_search.c	\
		verif_pre.c	\
		gest.c	\
		lib/my/my_cmp_nbr.c\
	 	lib/my/my_compute_power_rec.c\
		lib/my/my_compute_power_it.c\
	        lib/my/my_compute_square_root.c\
		lib/my/my_find_prime_sup.c\
	        lib/my/my_getnbr.c\
	        lib/my/my_isneg.c\
	        lib/my/my_is_prime.c\
	        lib/my/my_putchar.c\
	        lib/my/my_put_nbr.c\
	        lib/my/my_putstr.c\
	        lib/my/my_revstr.c\
	        lib/my/my_showmem.c\
	        lib/my/my_showstr.c\
	        lib/my/my_sort_int_array.c\
	        lib/my/my_strcapitalize.c\
	        lib/my/my_strcat.c\
	        lib/my/my_strcmp.c\
	        lib/my/my_strcpy.c\
	        lib/my/my_str_isalpha.c\
	        lib/my/my_str_islower.c\
	        lib/my/my_str_isnum.c\
	        lib/my/my_str_isprintable.c\
	        lib/my/my_str_isupper.c\
	        lib/my/my_strlen.c\
	        lib/my/my_strlowcase.c\
	        lib/my/my_strncat.c\
	        lib/my/my_strncmp.c\
	        lib/my/my_strncpy.c\
	        lib/my/my_strstr.c\
	        lib/my/my_strupcase.c\
	        lib/my/my_swap.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) lib/

clean:
	rm -f $(OBJ)
	make clean -C lib/my/

fclean:
	rm -f $(OBJ)
	make fclean -C lib/my/
	rm -f $(NAME)

re : fclean all

unit_tests:	fclean all
	gcc -o unit_tests tests/unit_tests.c -I include/ -L lib/ -lmy --coverage -lcriterion

tests_run:	unit_tests
	./unit_tests
