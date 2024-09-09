##
## EPITECH PROJECT, 2020
## my_rpg
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/menu.c	\
		src/lib/my_putstr.c	\
		src/lib/my_strcmp.c\
		src/check_env_var.c\
		src/init_window.c\
		src/button_manager.c\
		src/lib/my_strncmp.c

NAME	=	my_rpg

OBJ	=	$(SRC:.c=.o)

CPPFLAGS = -I./include -g

CFLAGS	=	-Wall -Wextra -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system

all:	$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re