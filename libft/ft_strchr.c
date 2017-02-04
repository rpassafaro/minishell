/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:41:37 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/01 14:41:39 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int character)
{
	int	i;

	i = 0;
	while (string[0])
	{
		if (string[0] == character)
			return ((char *)string);
		else
			string += 1;
	}
	if (string[0] == character)
		return ((char *)string);
	return (NULL);
}
