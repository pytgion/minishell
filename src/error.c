#include "../lib/minishell.h"

static void	print_err_msg(bool is_syserr, char *func, char *msg)
{
	if (is_syserr == true)
		ft_putstr_fd(SYSERR, STDERR_FILENO);
	else
		ft_putstr_fd("Error!\n", STDERR_FILENO);
	ft_putstr_fd(func, STDERR_FILENO);
	ft_putstr_fd(":", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(".\n", STDERR_FILENO);
}

void	err_msg_and_exit(char *func, char *msg)
{
	if (errno && ft_strncmp(msg, SYSERR, ft_strlen(msg)) == 0)
		print_err_msg(true, func, strerror(errno));
	else if (errno && !(ft_strncmp(msg, SYSERR, ft_strlen(msg)) == 0))
		print_err_msg(false, func, msg);
	else
	{
		ft_putstr_fd("Fatal error in", STDERR_FILENO);
		ft_putstr_fd(func, STDERR_FILENO);
		ft_putstr_fd(".\n", STDERR_FILENO);
	}
	//msh_destroy();
	if (errno)
		exit(errno);
	else
		exit(EXIT_FAILURE);
}
