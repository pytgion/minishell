#include "../lib/minishell.h"

void	exec(t_lextlist *lst, char **env, t_lextlist *prev, t_lextlist *tmp)
{

	if (tmp->type == PIPE)
	{
		pipe(tmp->fd);
	}
	if (!fork())
	{
		if (prev && prev->type == PIPE)
		{
			close(prev->fd[1]);
			dup2(prev->fd[0], 0);
			close(prev->fd[0]);
		}
		if (tmp->type == PIPE)
		{
			close(tmp->fd[0]);
			dup2(tmp->fd[1], 1);
			close(tmp->fd[1]);
		}
		/*
		else if (tmp->type == EXE && prev && prev->type == PIPE)
		{
			dup2(0, prev->fd[0]);
			close(prev->fd[0]);
		}
		*/
		execve(tmp->command[0], &tmp->command[1], env);
		exit(1);
	}
	//wait(NULL);
	//waitpid(pid, status, NULL); forktan pid çek
	if (prev && prev->type == PIPE)
	{
		close(prev->fd[0]);
	}
	if (tmp->type == PIPE)
	{
		close(tmp->fd[1]);
	}
	prev = tmp;

	if (tmp && tmp->next)
		exec(lst, env, prev, tmp->next);
}
