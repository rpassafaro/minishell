/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 23:38:40 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/15 23:39:02 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	printend(int x, int nflag)
{
	if (x == 1 && nflag)
		ft_putendl("%");
	else if (x == 1 && !nflag)
		ft_putchar('\n');
	else if (x == 0 && !nflag)
	{
		ft_putchar('\n');
		ft_putchar('\n');
	}
}

int		nflagfind(char *temp)
{
	int i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == 'n')
			return (1);
		i++;
	}
	return (0);
}

void	echo_b(char **temp)
{
	int i;
	int x;
	int nflag;

	x = 0;
	i = 1;
	nflag = 0;
	while (temp[i] && temp[i][0] == '-')
	{
		nflag = nflagfind(temp[i]);
		i++;
	}
	while (temp[i])
	{
		ft_putstr(temp[i]);
		i++;
		if (temp[i])
			ft_putchar(' ');
		x = 1;
	}
	printend(x, nflag);
}
