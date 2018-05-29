##
## EPITECH PROJECT, 2017
## libmy
## File description:
## Created by antoine_dh,
##

SRC_DIR		=	src

SRC		=	$(wildcard $(SRC_DIR)/*.c)		\
			$(wildcard $(SRC_DIR)/printf/*.c)

OBJ		=	$(SRC:.c=.o)

NAME		=	libmy.a

CFLAGS		=	-W -Wall -Wextra -Iinclude

CC		=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
