##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Projet Secured
##

SRC	=	lib//my/create_table.c	\
		lib//my/delete_table.c	\
		lib/my/hash.c	\
		lib/my/ht_delete.c	\
		lib/my/ht_dump.c	\
		lib/my/ht_insert.c	\
		lib/my/ht_search.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_strcat.c	\
		lib/my/my_strdup.c	\
		lib/my/my_strlen.c	\
		lib/my/my_strcomp.c	\
		lib/my/my_split.c	\
		lib/my/my_compute_power_rec.c	\
		lib/my/my_compute_square_root.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libhashtable.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	make clean
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
