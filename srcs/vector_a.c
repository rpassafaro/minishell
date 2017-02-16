/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:34:56 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/16 00:34:58 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/vector.h"
#include "../headers/minishell.h"

void	*vectspot(size_t index, t_vector *vect)
{
	if (index > vect->size)
		return (NULL);
	return (vect->data + (index * vect->itemsize));
}

void	vect_insert(t_vector *vect, size_t index, void *data)
{
	size_t ref;

	if (vect->size == vect->capacity)
		increasevect(vect);
	ref = index * vect->itemsize;
	ft_memmove(vect->data + (ref + vect->itemsize), vect->data + ref,
	(vect->size * vect->itemsize) - ref);
	ft_memcpy(vect->data + ref, data, vect->itemsize);
	vect->size += 1;
}

void	decreasevect(t_vector *vect)
{
	vect->data = ft_realloc(vect->data,
		((vect->capacity * vect->itemsize) / 2));
	vect->capacity = vect->capacity / 2;
}

void	vect_delete(t_vector *vect, size_t index)
{
	size_t ref;

	ref = index * vect->itemsize;
	ft_memmove(vect->data + ref, vect->data + (ref + vect->itemsize),
	(vect->size * vect->itemsize) - ref);
	if (vect->size - 1 <= vect->capacity / 4)
		decreasevect(vect);
	vect->size -= 1;
}

void	col_vect(t_vector *vect)
{
	vect->size -= 1;
	while ((int)vect->size >= 0)
	{
		free(*(char **)vectspot(vect->size, vect));
		vect->size--;
	}
}
