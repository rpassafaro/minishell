/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 23:34:34 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/15 23:34:37 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	extendrun(char **temp, t_vector *vect)
{
	if (temp[0] && ft_strcmp(temp[0], "setenv") == 0)
	{
		if (temp[1])
			setenv_b(temp[1], temp[2], vect);
		return (1);
	}
	if (temp[0] && ft_strcmp(temp[0], "unsetenv") == 0)
	{
		if (temp[1])
			unsetenv_b(temp[1], vect);
		return (1);
	}
	if (temp[0] && ft_strcmp(temp[0], "echo") == 0)
	{
		if (temp[1])
			echo_b(temp);
		return (1);
	}
	if (temp[0] && (ft_strcmp(temp[0], "exit") == 0
	|| ft_strcmp(temp[0], "EXIT") == 0))
		return (-1);
	return (0);
}

int	runbuilt(char **temp, t_vector *vect)
{
	if (temp[0] && ft_strcmp(temp[0], "env") == 0)
	{
		getenv_b(vect);
		return (1);
	}
	if (temp[0] && ft_strcmp(temp[0], "cd") == 0)
	{
		if (temp[1] == NULL)
			changedirs(NULL, vect);
		else if (temp[1] && temp[2] == NULL)
			changedirs(temp[1], vect);
		else
			ft_putendl("to many arguments in cd");
		return (1);
	}
	return (extendrun(temp, vect));
}
