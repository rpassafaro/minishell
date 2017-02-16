/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:31:04 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/16 00:32:02 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*subof(char *str, int sub)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_strnew(ft_strlen(str) - sub);
	while (str[sub])
	{
		ret[i] = str[sub];
		i++;
		sub++;
	}
	return (ret);
}

int		countarray(char **lst)
{
	int i;

	i = 0;
	while (lst[i])
		i++;
	return (i);
}

void	freedub(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
}
