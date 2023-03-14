#include "minishell.h"

void			pwd(void)
{
	char		*pwd;
	int			ret;

	pwd = get_cwd(0, PATH_MAX);
	ft_putendl_fd(pwd, 1);
	free(pwd);
	//g_exit_status = 0;
}
