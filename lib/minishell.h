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


// DEFINES
# define	SYSERR	"System Error!\n"

typedef struct s_command_table {
	char	*command;

}	t_command_table;

typedef struct s_history {
	int			num;
	char		*command;
	struct s_history	*next;
	struct s_history	*pre;
}		t_history;

#endif
