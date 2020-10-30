##
## FOR EPITECH PROJECT
## benjamin.dupuis@epitech.eu
## File description:
## Makefile
##

NAME	=   ../jd_server

SRC		=   src/main.c						  \
			src/create_server.c				 \
			src/reset_fd_set.c				  \
			src/loop_server.c				   \
			src/fd_set_function.c			   \
			src/client_connection.c              \
			src/command_management.c			\
			src/str_to_word_array.c                  \
			src/my_strlen_array.c                  \
			src/word_array_to_str.c                  \
			src/clear.c					\
			src/sending_map.c					\
			src/actions.c					\
			src/moves.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	=   -W -Wextra -Wall -g

RM	=	rm -f

all:		$(NAME)

$(NAME):   $(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		 $(RM) $(OBJ)

fclean:		 clean
		 $(RM) $(NAME)

re:		 fclean all
