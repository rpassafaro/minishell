/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:44:13 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/01 14:44:14 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*dest;

	i = ft_strlen(s);
	dest = ft_memalloc(i + 1);
	if (!s || !dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(s[i]);
		i++;
	}
	return (dest);
}
