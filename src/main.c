#include "minishell.h"

int	main(int argc, char **argv)
{
	if (argc > 1 && argc)
		err_msg_and_exit("minishell", "too many arguments");
}
