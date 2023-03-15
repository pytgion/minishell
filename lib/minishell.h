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

# define PIPE		124
# define DOLLAR		36
# define EXE 		59
# define REDIRIN	60
# define REDIROUT	62
# define HDOC		72
# define APPEND		65
# define QUOTE		34

typedef struct s_lexlist {
	char		type;
	char		**command;
	int			fd[2];
	struct s_lexlist *next;
}	t_lextlist;

#endif

//promt
void	print_promt1();
void	print_promt2();

// utils

//error
void	err_msg_and_exit(char *func, char *msg);

//lexer
int	init_lexer(char *line, char **env);
int	is_meta_char(char *line);
t_lextlist *pass_to_arg(t_lextlist *lst, char **command, char type, int *i);
t_lextlist *push_lst(t_lextlist *lst, char **command, char type);
t_lextlist *add_lst(t_lextlist *lst, char **command, char type);
t_lextlist *create_lst(char **command, char type);

//exec
void	exec(t_lextlist *lst, char **env, t_lextlist *prev, t_lextlist *tmp);
