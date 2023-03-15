#include "../lib/minishell.h"

static int is_quote(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\"')
		{
			while (line[i] != '\"')
			{
				if (line[i + 1] == '\0')
					return (1);
				i++;
			}
		}
		if (line[i] == '\'')
		{
			while (line[i] != '\'')
			{
				if (line[i + 1] == '\0')
					return (1);
			}
		}
		i++;
	}
	return (0);
}

t_lextlist	*pass_to_arg(t_lextlist *lst, char **command, char type, int *i)
{

	command[*i] = 0;
	lst = push_lst(lst, command, type);
	*i += 1;
	command = &command[*i];
	//?printf("\n\nBUT THE COMMAND IS %s\n\n AND INDEX IS %d", command[0], *i);
	*i = -1;
	return (lst);
}

int	is_meta_char(char *line)
{
	int		d;

	d = ft_strlen(line);
	if (!line)
		return (-1);
	if (is_quote(line))
		return (QUOTE);
	if (ft_strchr(line, '|'))
		return (PIPE);
	if (ft_strchr(line, '$'))
		return (DOLLAR);
	if (ft_strchr(line, ';'))
		return (EXE);
	if (ft_strchr(line, '<'))
		return (REDIRIN);
	if (ft_strchr(line, '>'))
		return (REDIROUT);
	if (!ft_strncmp(line, "<<", d))
		return (HDOC);
	if (!ft_strncmp(line, ">>", d))
		return (APPEND);
	return (0);
	}
