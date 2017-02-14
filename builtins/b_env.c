#include "../headers/minishell.h"

void	getenv_b(t_vector *vect)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		ft_putendl(*(char **)vectspot(i, vect));
		i++;
	}
}

char	*makedata(char *key, char *val)
{
	char *tmp;

	tmp = ft_strjoin(key,"=");
	return(ft_strjoin(tmp,val));
}

void setenv_b(char *key, char *val, t_vector *vect)
{
	int index;
	char *data;

	index = findenvvarint(vect, key);
	if (index > -1)
	{
		vect_delete(vect, index);
		data = makedata(key,val);
		vect_insert(vect, index, &data);
	}
	else
	{
		data = makedata(key,val);
		vect_insert(vect, vect->size, &data);
	}
	//free(key);
	//free(val);
	//ft_putnbr(index);
	//ft_putendl(*(char **)vectspot(index, vect));
}
