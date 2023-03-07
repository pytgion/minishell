#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <sys/wait.h> //wait for process to change state
# include <sys/stat.h> //get file status
# include <dirent.h> //directory shit
# include <stdlib.h>
# include <signal.h>
# include "Libft/libft.h"


// DEFINES
# define	SYSERR	"System Error!\n"

typedef struct s_command_table {
	char	*command;

}	t_command_table;

typedef struct s_lexlist {
	char		type;
	char		*command;
	struct s_lexlist *next;
}	t_lextlist;

#endif

//promt
void	print_promt1();
void	print_promt2();

// utils
int	ft_strcmp(char *str, char *str2);

//error
void	err_msg_and_exit(char *func, char *msg);
