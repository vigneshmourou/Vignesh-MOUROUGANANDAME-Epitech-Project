##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## navy
##

NAME	= my_navy

CC	= gcc -g

RM	= rm -f

SRCS	=	src/main.c \
			src/user_input.c	\
			src/connect_usr.c	\
			src/get_request.c	\
			src/signal.c	\
			src/check_boat.c	\
			src/affiche_map.c	\
			src/usage.c	\
			src/game.c	\
			src/end_game.c	\
			src/error_handling.c

LIB = 	-lprintf	\
	-lmy

OBJS	= $(SRCS:.c=.o)

CFLAGS = -W -Wall -Wextra $(DBFLAGS)

DBFLAGS	= -g -g3 -ggdb

CPPFLAGS += -I ./include/

LDLIBS	=	-L./lib/my/ $(LIB) -lm

all: $(NAME)

$(NAME):	$(OBJS)
		$(MAKE) -C lib/my
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)

clean:
	$(MAKE) clean -C lib/my
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C lib/my
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
