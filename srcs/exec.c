/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:07:51 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/20 18:00:30 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	runprog(char *test, char **temp, t_vector *vect)
{
	int		status;
	int		pid;
	int		err;
	char	**env;

	env = cpenv_b(vect);
	pid = fork();
	if (pid == 0)
		err = execve(test, temp, env);
	else if (pid < 0)
	{
		ft_putstr("fork failed with error code ");
		ft_putnbr(pid);
		ft_putchar('\n');
		exit(-1);
	}
	signal(SIGINT, NULL);
	wait(&status);
	free(test);
}

int		checkloc(char *test, int size, char **temp, t_vector *vect)
{
	struct stat sb;

	if (lstat(test, &sb) == -1)
	{
		return (size);
	}
	else
		runprog(test, temp, vect);
	return (-1);
}

int		checklocsp(char *test, char **temp, t_vector *vect)
{
	struct stat sb;

	if (lstat(test, &sb) == -1)
	{
		return (0);
	}
	else
	{
		runprog(test, temp, vect);
		return (1);
	}
}

int		execprog(char *str, char **bins, char **temp, t_vector *vect)
{
	int		size;
	char	*test;

	size = countarray(bins);
	size--;
	size = checkloc(str, size, temp, vect);
	if (size == -1)
		return (1);
	while (size > -1)
	{
		test = checkbin(str, bins[size]);
		if (test != NULL)
		{
			freedub(bins);
			free(temp[0]);
			temp[0] = test;
			runprog(test, temp, vect);
			return (1);
		}
		else
			size--;
	}
	freedub(bins);
	return (0);
}
