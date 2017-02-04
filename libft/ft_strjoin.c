/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:43:34 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/03 00:00:38 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int		count;

	count = 0;
	tmp = ft_strnew((ft_strlen(s1) + ft_strlen(s2)));
	if (!tmp)
		return (NULL);
	while (s1[0])
	{
		tmp[count] = s1[0];
		s1++;
		count++;
	}
	while (s2[0])
	{
		tmp[count] = s2[0];
		s2++;
		count++;
	}
	tmp[count] = '\0';
	return (tmp);
}
