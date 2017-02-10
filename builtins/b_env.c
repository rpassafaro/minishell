#include "../headers/minishell.h"

void getenv_b(t_vector *vect)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		ft_putendl(*(char **)vectspot(i, vect));
		i++;
	}
}
