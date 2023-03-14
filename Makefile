NAME	= minishell
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
SRC		= ./src/*.c
LIBFT	= ./lib/Libft/libft.a
INCLUDE	= -I/lib/minishell.h

OBJ		= $(SRC:.c=.o)

%.o:%.c
	$(CC) $(SRC) $(CFLAGS) -c $< -o $@

all: $(NAME)
	@echo "Done!"

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -I. $(LIBFT) -I/goinfre/oakyuz/homebrew/opt/readline/include/  -L/goinfre/oakyuz/homebrew/opt/readline/lib/ -lreadline -o $(NAME)

clean:
	@rm -rf src/*.o
	@echo "Cleaned."

fclean:
	@rm -rf src/*.o
	@rm -rf a.out

re: clean fclean
