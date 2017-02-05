#ifndef VECTOR_H
# define VECTOR_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_vector
{
	void	*data;
	size_t	capacity;
	size_t	size;
	size_t	itemsize;
}			t_vector;

t_vector *vect_new(size_t count, size_t size);
int vectcap(t_vector *vect);
int vectsize(t_vector *vect);
void increasevect(t_vector *vect);
void *vectspot(size_t index, t_vector *vect);
void vect_insert(t_vector *vect, size_t index, void *data);
void col_vect(t_vector *vect);
void decreasevect(t_vector *vect);
void vect_delete(t_vector *vect, size_t index);
#endif
