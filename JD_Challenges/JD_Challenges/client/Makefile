##
##	Created by Benjamin.
##	benjamin.dupuis@epitech.eu
##


NAME		=	../jd_client

SRC			=	src/main.c							\
				src/create_client.c					\
				src/game_loop.c					\
				src/read_and_write.c					\
				src/ncurses.c

INCLUDE		=	-Iinclude

CFLAGS		=	-W -Wall -Wextra $(INCLUDE)

LIBFLAGS	=	-lncurses

OBJ			=	$(SRC:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LIBFLAGS)

clean:
				rm -f $(OBJ)
				rm -f *~

fclean:			clean
				rm -f $(NAME)

re:				fclean all



