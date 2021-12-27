NAME = push_swap

NAME_LIB = libft.a

LIST_LIB = ./libft/

LIB = -L ./libft -lft

LIST =	init_set0.c\
		init_setA.c\
		init_setB.c\
		move_b_to_a.c\
		move_mids_a_to_b.c\
		push_swap.c\
		rotations.c\
		swap_and_push.c\
		free_memory.c\

CC = gcc

OBJS = $(LIST:.c=.o)

HEADER = push_swap.h

HEADER_LIB = libft.h

CFLAGS = -Wall -Werror -Wextra

MAKE = make -C $(LIST_LIB)

all: $(NAME)

$(NAME): $(HEADER) $(OBJS) $(LIST)
		make -C $(LIST_LIB)
		$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@

clean: 
	@rm -f *.out
	@rm -f *.o
	make clean -C $(LIST_LIB)

fclean:	clean
	@rm -f $(NAME)
	make fclean -C $(LIST_LIB)

re: fclean all

.PHONY: all clean fclean re sub_libft