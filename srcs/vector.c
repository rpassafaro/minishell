#include "../headers/vector.h"
#include "../libft/libft.h"

void *ft_realloc(void *ptr, size_t size)

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

t_vector *vect_new(size_t count, size_t size)
{
	t_vector *vect;
	size_t stat;

	vect = malloc(sizeof(t_vector));
	stat = 8;

	while (count > stat)
	{
		if (stat * 2 < stat)
			return NULL;
		stat *= 2;
	}
	vect->capacity = stat;
	vect->size = 0;
	vect->itemsize = size;
	vect->data = malloc(size * stat);
	return (vect);
}

int vectcap(t_vector *vect)
{
	return (vect->capacity);
}

int vectsize(t_vector *vect)
{
	return (vect->size);
}

void increasevect(t_vector *vect)
{
	vect->data = ft_realloc(vect->data, ((vect->capacity * vect->itemsize) * 2));
	vect->capacity = vect->capacity * 2;
}

void *vectspot(size_t index, t_vector *vect)
{
	if (index > vect->size)
		return NULL;
	return(vect->data + (index * vect->itemsize));
}

void vect_insert(t_vector *vect, size_t index, void *data)
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

void decreasevect(t_vector *vect)
{
	vect->data = ft_realloc(vect->data,
		((vect->capacity * vect->itemsize) / 2));
	vect->capacity = vect->capacity / 2;
}

void vect_delete(t_vector *vect, size_t index)
{
	size_t ref;

	ref = index * vect->itemsize;
	ft_memmove(vect->data + ref, vect->data + (ref + vect->itemsize),
	(vect->size * vect->itemsize) - ref);
	if (vect->size - 1 <= vect->capacity / 4)
		decreasevect(vect);
	vect->size -= 1;
}

void col_vect(t_vector *vect)
{
	vect->size -= 1;
	while((int)vect->size >= 0)
	{
		free(*(char **)vectspot(vect->size, vect));
		vect->size--;
	}
}
