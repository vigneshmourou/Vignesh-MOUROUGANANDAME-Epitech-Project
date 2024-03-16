##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile my_hunter
##

SRC     =	my_put_nbr.c	\
			my_putchar.c	\
			my_putstr.c	\
			my_getnbr.c	\
			my_strcat.c	\
			my_strdup.c	\
			my_strlen.c	\
			my_split.c	\
			my_compute_power_rec.c	\
			my_compute_square_root.c

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

MV	=	 mv

all:	$(NAME)

$(NAME):	$(OBJ)


	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re : fclean all
