#include "../lib/minishell.h"

int	ft_strcmp(char *str, char *str2)
{
	int i;

	i = 0;
	while(*str == *str2 && str && str2)
		i++;
	return ((int)str - (int)str2);
}
