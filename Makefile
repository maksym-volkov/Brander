NAME = lines

SRC = 	main.c \
		reading.c\
		initialization.c\
		solution.c\
		print_result.c\
		freeing_memory.c\

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $@ $(FLAGS) $^

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all