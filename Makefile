##
## EPITECH PROJECT, 2017
## my_rpg
## File description:
## Created by antoine_dh,
##

SRCDIR	=	./src

SRC	=   	$(wildcard $(SRCDIR)/*.c)			\
		$(wildcard $(SRCDIR)/game/*.c)			\
		$(wildcard $(SRCDIR)/game/map/*.c)		\
		$(wildcard $(SRCDIR)/game/events/*.c)		\
		$(wildcard $(SRCDIR)/game/quests/*.c)		\
		$(wildcard $(SRCDIR)/game/projectiles/*.c)	\
		$(wildcard $(SRCDIR)/gui/*.c)			\
		$(wildcard $(SRCDIR)/gui/toolbar/*.c)		\
		$(wildcard $(SRCDIR)/gui/inventory/*.c)		\
		$(wildcard $(SRCDIR)/gui/stats/*.c)		\
		$(wildcard $(SRCDIR)/engine/*.c)		\
		$(wildcard $(SRCDIR)/engine/drawing/*.c)	\
		$(wildcard $(SRCDIR)/engine/lua/*.c)		\
		$(wildcard $(SRCDIR)/engine/math/*.c)		\
		$(wildcard $(SRCDIR)/engine/obj/*.c)		\
		$(wildcard $(SRCDIR)/engine/obj/animation/*.c)	\
		$(wildcard $(SRCDIR)/engine/physics/*.c)	\

OBJ	=	$(SRC:.c=.o)

NAME	=	rpg

CFLAGS	=	-I./include -W -Wall -Wextra

LDFLAGS	=	-lc_graph_prog -lGL -lGLU -Llib/my -lmy -Llib/list	\
		-llist -lm

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	make -C lib/list
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

debug: CFLAGS += -g
debug: re

clean:
	make clean -C lib/my
	make clean -C lib/list
	rm -f $(OBJ)

fclean:	clean
	make fclean -C lib/my
	make fclean -C lib/list
	rm -f $(NAME)

re:	fclean all
