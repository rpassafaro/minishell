/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 12:45:57 by rpassafa          #+#    #+#             */
/*   Updated: 2016/09/25 12:46:00 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	count;
	char	*d;
	char	*s;

	d = (char*)dst;
	s = (char*)src;
	count = 0;
	while (count < n)
	{
		d[count] = s[count];
		if (d[count] == c)
			return ((void*)&d[count] + 1);
		count++;
	}
	return (NULL);
}
