/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:20:45 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/16 00:20:48 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int		trimsome(char *str, int i)
{
	while (str[i] == ' ' && str[i])
		i++;
	return (i);
}

int		countthis(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			count++;
		i++;
	}
	return (count);
}

void	setints(int *ret, int *i, int *dq)
{
	*ret = 0;
	*i = 0;
	*dq = 0;
}

int		inputsize(char *str)
{
	char	**temp;
	int		i;
	int		ret;
	int		dq;

	setints(&ret, &i, &dq);
	temp = my_ft_strsplit(str);
	while (temp[i])
	{
		if (ft_strchr(temp[i], '"') && countthis(temp[i]) < 2)
		{
			if (!dq)
				dq = 1;
			else if (dq)
			{
				ret++;
				dq = 0;
			}
		}
		else if (!dq)
			ret++;
		i++;
	}
	freedub(temp);
	return (ret);
}
