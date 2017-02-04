/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:47:43 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/01 14:47:44 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ft_strnew(len);
	if (!tmp)
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		tmp[i] = s[start];
		start++;
		i++;
	}
	return (tmp);
}
