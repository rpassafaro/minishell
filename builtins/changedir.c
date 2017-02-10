#include "../headers/minishell.h"

char *findenvvar(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), subof(str,0), ft_strlen(str) - 1) == 0)
		{
			return(*(char **)vectspot(i, vect));
		}
		i++;
	}
	return (NULL);
}

int findenvvarint(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), subof(str,0), ft_strlen(str) - 1) == 0)
		{
			return i;
		}
		i++;
	}
	return (-1);
}

void changedirs(char *path, t_vector *vect)
{
	int ret;
	char *opwd;

	ret = chdir (path);
	opwd = findenvvar(vect, "OLDPWD");
	vect_delete(vect, ret);
}
