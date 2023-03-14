NAME	= minishell
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
#src		= ./src/*.c
#SRC		= $(wildcard ./src/*.c)
SRC	= $(shell find src -name "*.c")
LIBFT	= ./lib/Libft/libft.a
INCLUDE	= -I/lib/minishell.h -I./lib

OBJ		= $(SRC:.c=.o)

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)
	@echo "Done!"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I. $(LIBFT) -I/goinfre/oakyuz/homebrew/opt/readline/include/  -L/goinfre/oakyuz/homebrew/opt/readline/lib/ -lreadline -o $(NAME)

clean:
	@rm -rf src/*.o
	@echo "Cleaned."

fclean:
	@find . -name "*.o" -delete
	@rm -rf a.out

re: clean fclean all
