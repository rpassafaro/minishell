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
// int main(int argc, char **argv, char** envp)
// {
// 	char *str;
// 	char** env;
// 	t_vector *vect;
// 	vect = vect_new(10, sizeof(char*));
//
// 	if (argc < 0)
// 		;
// 	if (argv)
// 		;
// 	storeenv(vect, envp);
// }
