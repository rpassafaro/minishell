/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 12:43:20 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/01 14:35:21 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *c)
{
	int		i;
	int		sign;
	long	ans;

	i = 0;
	ans = 0;
	sign = 1;
	while (c[i] == ' ' || c[i] == '\n' || c[i] == '\t' ||
		c[i] == '\r' || c[i] == '\v' || c[i] == '\f')
		i++;
	if (c[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (c[i] == '+')
		i++;
	while (ft_isdigit(c[i]))
	{
		ans = (ans * 10) + (c[i] - 48);
		i++;
	}
	return ((int)(ans * sign));
}
