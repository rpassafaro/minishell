/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:46:49 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/01 14:46:50 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *string, int character)
{
	int			i;
	int			f;
	const char	*temp;

	temp = string;
	i = 0;
	f = -1;
	while (temp[i])
	{
		if (temp[i] == character)
			f = i;
		i++;
	}
	if (temp[i] == character)
		f = i;
	if (f == -1)
		return (NULL);
	i = 0;
	while (i < f)
	{
		temp += 1;
		i++;
	}
	return ((char *)temp);
}
