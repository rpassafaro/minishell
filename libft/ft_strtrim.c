/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:47:57 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/01 14:47:58 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		findspace(char *s)
{
	int	i;

	i = 0;
	while (s[i] <= ' ' && s[i])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s)
{
	unsigned	i;
	unsigned	start;
	unsigned	end;
	char		*new;

	i = findspace((char*)s);
	start = i;
	while (s[i])
		i++;
	while (s[i] <= ' ' && i > start)
		i--;
	end = i;
	new = ft_strnew(end - start + 1);
	i = 0;
	if (!new)
		return (NULL);
	while (start <= end)
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
