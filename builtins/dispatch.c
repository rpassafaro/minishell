#include "../headers/minishell.h"

int runbuilt(char **temp, t_vector *vect)
{
	if (temp[0] && ft_strcmp(temp[0], "env") == 0)
	{
		getenv_b(vect);
		return 1;
	}
	if (temp[0] && ft_strcmp(temp[0], "cd") == 0)
	{
		if (temp[1])
			changedirs(temp[1], vect);
		return 1;
	}
	if (temp[0] && ft_strcmp(temp[0], "setenv") == 0)
	{
		if (temp[1])
			setenv_b(temp[1], temp[2], vect);
		return 1;
	}
	if (temp[0] && ft_strcmp(temp[0], "unsetenv") == 0)
	{
		if (temp[1])
			unsetenv_b(temp[1], vect);
		return 1;
	}
	if (temp[0] && ft_strcmp(temp[0], "echo") == 0)
	{
		if (temp[1])
			echo_b(temp);
		return 1;
	}
	if (temp[0] && (ft_strcmp(temp[0], "exit") == 0 || ft_strcmp(temp[0], "EXIT") == 0))
	{
		return -1;
	}
	return 0;
}
