/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:45:25 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/01 14:45:27 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char const *dst, char *src, size_t max)
{
	size_t	i;
	size_t	temp;
	char	*d;

	temp = max;
	d = (char*)dst;
	i = 0;
	while (i < temp && src[i])
	{
		d[i] = src[i];
		i++;
	}
	if (max != 0)
		while (i < max)
		{
			d[i] = '\0';
			i++;
		}
	return (d);
}
