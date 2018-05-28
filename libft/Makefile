NAME = libft.a

SRCS = *.c

OBJS = *.o

FLAGS = -Wall -Wextra -Werror
HEADERS = -I includes

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS) $(HEADERS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
