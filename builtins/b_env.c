#include "../headers/minishell.h"

void	getenv_b(t_vector *vect)
{
	int i;

	i = 0;
	while (i <= (int)vect->size)
	{
		ft_putendl(*(char **)vectspot(i, vect));
		i++;
	}
}

char	**cpenv_b(t_vector *vect)
{
	int i;
	char **ret;

	ret = (char**)malloc(sizeof(char*) * vect->size + 2);
	i = 0;
	while (i <= (int)vect->size)
	{
		ret[i] = ft_strdup(*(char **)vectspot(i, vect));
		i++;
	}
	ret[i] = 0;
	return ret;
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

	data = makedata(key,val);
	if (index > -1)
	{
		ft_putendl("here");
		vect_delete(vect, index);
		vect_insert(vect, index, &data);
	}
	else
		vect_insert(vect, vect->size, &data);
}

void unsetenv_b(char *key, t_vector *vect)
{
	int index;

	index = findenvvarint(vect, key);
	if (index > -1)
		vect_delete(vect, index);
}
