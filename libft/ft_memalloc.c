/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:36:16 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/01 14:36:18 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*ptr;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	if (size == 0)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
