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
