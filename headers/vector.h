/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:44:08 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/16 00:44:09 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <stdlib.h>

typedef struct	s_vector
{
	void		*data;
	size_t		capacity;
	size_t		size;
	size_t		itemsize;
}				t_vector;

t_vector		*vect_new(size_t count, size_t size);
int				vectcap(t_vector *vect);
int				vectsize(t_vector *vect);
void			increasevect(t_vector *vect);
void			*vectspot(size_t index, t_vector *vect);
void			vect_insert(t_vector *vect, size_t index, void *data);
void			col_vect(t_vector *vect);
void			decreasevect(t_vector *vect);
void			vect_delete(t_vector *vect, size_t index);
void			*ft_realloc(void *ptr, size_t size);
#endif
