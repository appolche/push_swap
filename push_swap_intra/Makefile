NAME = push_swap
SRC =  push_swap.c\
		error_handling.c\
		string_processing.c frame_processing.c\
		sort_stack.c\
		do_rotate.c do_reverse_rotate.c do_swap.c do_push.c\
		list_tools.c utils.c
OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra -g
HEADER	= push_swap.h

all: ${NAME}

$(NAME): $(OBJS) $(HEADER)
	gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re