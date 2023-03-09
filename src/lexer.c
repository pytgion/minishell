#include "../lib/minishell.h"

t_lextlist *create_lst(char **command, char type)
{
	t_lextlist *ret_val;
	int i;

	i = 0;
	ret_val = malloc(sizeof(t_lextlist));
	while (command[i])
		i++;
	ret_val->command = malloc(sizeof(char *) * (i + 1));
	ret_val->command[i] = 0;
	i = 0;
	while (command[i])
	{
		//printf("dondu\n");
		ret_val->command[i] = ft_strdup(command[i]);
		i++;
	}
	ret_val->type = type;
	ret_val->next = 0;
	return (ret_val);
}

t_lextlist *add_lst(t_lextlist *lst, char **command, char type)
{
	t_lextlist *tmp;
	int i;

	i = 0;
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(t_lextlist));
	while (command[i])
		i++;
	tmp->next->command = malloc(sizeof(char *) * (i + 1));
	tmp->next->command[i] = 0;
	i = 0;
	while (command[i])
	{
		tmp->next->command[i] = ft_strdup(command[i]);
		i++;
	}
	tmp->next->type = type;
	tmp->next->next = 0;
	return (lst);
}

t_lextlist *push_lst(t_lextlist *lst, char **command, char type)
{
	//command[*i] = 0;
	if (lst)
	{
		return (add_lst(lst, command, type));
	}
	else
		return (create_lst(command, type));
	//command = &command[*i + 1];
	//i = -1;
}

void	print_lst(t_lextlist *lst)
{
	int	x;
	while (lst)
	{
		x = 0;
		while (lst->command[x])
		{
			printf("command = %s\n", lst->command[x]);
			x++;
		}
		printf("Type = %c\n", lst->type);

		lst = lst->next;
	}
}

int init_lexer(char *line, char **env)
{
	t_lextlist *lst;
	lst = 0;
	char **spilitret;
	int i;

	spilitret = ft_split(line, ' ');
	i = 0;
	while (spilitret[i])
	{
		if (ft_strncmp(spilitret[i], "|", ft_strlen(spilitret[i])) == 0)
		{
			spilitret[i] = 0;
			lst = push_lst(lst, spilitret, PIPE);
			spilitret = &spilitret[i + 1];
			//spilitret += i + 1;
			i = -1;
		}
		else if (ft_strncmp(spilitret[i], "&&", ft_strlen(spilitret[i])) == 0)
		{
			spilitret[i] = 0;
			lst = push_lst(lst, spilitret, AND);
			spilitret = &spilitret[i + 1];
			i = -1;
		}
		else if (ft_strncmp(spilitret[i], ";", ft_strlen(spilitret[i])) == 0)
		{
			spilitret[i] = 0;
			lst = push_lst(lst, spilitret, EXE);
			spilitret = &spilitret[i + 1];
			i = -1;
		}
		//lst = push_lst(lst, spilitret[i], 0);
		//free(spilitret[i]);
		i++;
	}

	print_lst(lst);
	exec(lst, env, 0, lst);
	return (0);
}

//freelenecek

