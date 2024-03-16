##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## navy
##

NAME	= mysh

CC	= gcc -g

RM	= rm -f

SRCS	=	src/main.c \
		src/basic/execute_basic.c	\
		src/env/execute_env.c	\
		src/env/execute_setenv.c	\
		src/env/execute_unsetenv.c	\
		src/cd/execute_cd.c	\
		src/linked_list/handle_linked_list.c

LIB = 	-lmy

OBJS	= $(SRCS:.c=.o)

CFLAGS = -W -Wall -Wextra $(DBFLAGS)

DBFLAGS	= -g -ggdb

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
