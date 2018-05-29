##
## EPITECH PROJECT, 2017
## liblist
## File description:
## Created by antoine_dh,
##

INCLUDE		=	include

SRC_DIR		=	src

SRC		=	$(wildcard $(SRC_DIR)/*.c)

OBJ		=	$(SRC:.c=.o)

NAME		=	liblist.a

CFLAGS		=	-Wall -Wextra -I $(INCLUDE)

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
