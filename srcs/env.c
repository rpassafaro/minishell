/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 23:45:24 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/19 23:53:13 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../headers/minishell.h"

void	storeenv(t_vector *vect, char **envp)
{
	char	**env;
	char	*thisenv;

	env = envp;
	while (*env != 0)
	{
		thisenv = *env;
		vect_insert(vect, vect->size, &thisenv);
		env++;
	}
}

void	getenvvar(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect),
		subof(str, 1), ft_strlen(str) - 1) == 0)
		{
			ft_putendl(subof(*(char **)vectspot(i, vect), ft_strlen(str)));
			return ;
		}
		i++;
	}
}

char	*dupenvvar(t_vector *vect, char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < (int)vect->size)
	{
		tmp = subof(str, 1);
		if (str[0] && str[0] == '$' &&
		ft_strncmp(*(char **)vectspot(i, vect), tmp, ft_strlen(str) - 1) == 0)
		{
			free(tmp);
			return (ft_strdup(subof(*(char **)vectspot(i, vect),
			ft_strlen(str))));
		}
		free(tmp);
		i++;
	}
	return (NULL);
}

int		findenvvarint(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), str, ft_strlen(str)) == 0)
			return (i);
		i++;
	}
	return (-1);
}
