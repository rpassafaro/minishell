/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:36:21 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/20 18:02:58 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vector.h"
#include "../libft/libft.h"

void			*ft_realloc(void *ptr, size_t size)
{
	char *ret;

	if (!size && ptr)
	{
		if (!(ret = (char*)malloc(1)))
			return (NULL);
		ft_memdel(&ptr);
		return (ret);
	}
	ret = (char*)malloc(size);
	if (ptr)
	{
		ft_memcpy(ret, ptr, size);
		ft_memdel(&ptr);
	}
	return (ret);
}

t_vector		*vect_new(size_t count, size_t size)
{
	t_vector	*vect;
	size_t		stat;

	vect = malloc(sizeof(t_vector));
	stat = 8;
	while (count > stat)
	{
		if (stat * 2 < stat)
			return (NULL);
		stat *= 2;
	}
	vect->capacity = stat;
	vect->size = 0;
	vect->itemsize = size;
	vect->data = malloc(size * stat);
	return (vect);
}

int				vectcap(t_vector *vect)
{
	return (vect->capacity);
}

int				vectsize(t_vector *vect)
{
	return (vect->size);
}

void			increasevect(t_vector *vect)
{
	vect->data = ft_realloc(vect->data,
	((vect->capacity * vect->itemsize) * 2));
	vect->capacity = vect->capacity * 2;
}
