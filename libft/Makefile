NAME = libft.a

LIST =	ft_isdigit.c\
		ft_atoi.c\
		ft_strlen.c\

OBJS = $(LIST:.c=.o)

FLAGS = -Wall -Werror -Wextra


all : $(NAME)

$(NAME) : $(OBJS) libft.h
	ar rcs $(NAME) $?

clean: 
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re