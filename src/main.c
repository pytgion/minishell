#include "../lib/minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	if (argc > 1 && argc)
		err_msg_and_exit("minishell", "too many arguments");
	while (1)
	{
		
	}
}
