/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changedir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 23:30:38 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/15 23:31:21 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*findenvvar(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect),
		subof(str, 0), ft_strlen(str) - 1) == 0)
		{
			return (ft_strdup(*(char **)vectspot(i, vect)));
		}
		i++;
	}
	return (NULL);
}

void	changeold(int ret, t_vector *vect, char *cwd, int i)
{
	char *str;

	if (ret == 0)
	{
		vect_delete(vect, i);
		str = ft_strjoin("OLDPWD=", cwd);
		vect_insert(vect, i, &str);
	}
}

void	checkchange(int i, char *path)
{
	if (i == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
	}
}
