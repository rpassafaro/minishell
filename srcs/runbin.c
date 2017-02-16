/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runbin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:29:30 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/16 00:29:32 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include "../libft/libft.h"

char	**getbins(t_vector *vect)
{
	int i;

	i = vect->size - 1;
	while (i > -1)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), "PATH=", 4) == 0)
			return (ft_strsplit(subof(*(char **)vectspot(i, vect), 5), ':'));
		i--;
	}
	return (NULL);
}

char	*checkbin(char *prog, char *path)
{
	char			*test;
	char			*re;
	struct stat		sb;

	re = ft_strjoin(path, "/");
	test = ft_strjoin(re, prog);
	free(re);
	if (lstat(test, &sb) == -1)
	{
		free(test);
		return (NULL);
	}
	else
	{
		if ((sb.st_mode & S_IFMT) == S_IFREG)
			return (test);
	}
	return (NULL);
}
