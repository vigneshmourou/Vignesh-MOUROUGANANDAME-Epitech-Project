##
## EPITECH PROJECT, 2024
## B-MUL-200-PAR-2-1-mypaint-matthias.balon
## File description:
## Makefile
##

SRC =	src/button_event.c	\
	src/check_functions.c	\
	src/display_functions.c	\
	src/init_functions.c	\
	src/count_functions.c	\
	src/button_state.c	\
	src/main.c				\
	src/fill_display_zone.c	\
	src/init_interface.c	\
	src/tool_functions.c	\
	src/cursor_functions.c	\
	src/menu_functions.c	\
	src/fill_cursor.c	\
	src/pencil.c	\
	src/erase.c	\
	src/highlighter.c	\
	src/files_functions.c	\
	lib/my_strlen.c	\
	lib/my_putstr.c	\
	lib/my_strdup.c	\
	lib/my_strcat.c	\

OBJ =	$(SRC:.c=.o)

NAME = my_paint

CFLAGS = -Wextra -Wall

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

all: $(NAME)

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
