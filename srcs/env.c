#include <stdio.h>
#include "../headers/minishell.h"

void storeenv(t_vector *vect , char **envp)
{
	char** env;

	env = envp;
	while (*env != 0)
	{
		char* thisEnv = *env;
		vect_insert(vect, vect->size, &thisEnv);
		env++;
	}
	vect->size -= 1;
}

void getenvvar(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), subof(str,1), ft_strlen(str) - 1) == 0)
		{
			ft_putendl(subof(*(char **)vectspot(i, vect),ft_strlen(str)));
			return;
		}
		i++;
	}
}

char* dupenvvar(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), subof(str,1), ft_strlen(str) - 1) == 0)
		{
			return(ft_strdup(subof(*(char **)vectspot(i, vect),ft_strlen(str))));
		}
		i++;
	}
	return NULL;
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
