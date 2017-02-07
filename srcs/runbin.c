#include "../headers/minishell.h"
#include "../libft/libft.h"
#include <stdio.h>


char **getbins(t_vector *vect)
{
	int i;

	i = vect->size;
	while (i > -1)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), "PATH=",4) == 0)
			return(ft_strsplit(subof(*(char **)vectspot(i, vect), 5), ':'));
		i--;
	}
	return (NULL);
}

char *checkbin(char *prog, char *path)
{
	char *test;
	char *re;
	struct stat sb;

	re = ft_strjoin(path, "/");
	test = ft_strjoin(re, prog);
	free(re);
	if (lstat(test, &sb) == -1)
	{
		free(test);
		return (NULL);
	}
	else
	{
		if ((sb.st_mode & S_IFMT) == S_IFREG)
			return test;
	}
	return(NULL);
}
// int main(int argc, char **argv, char** envp)
// {
// 	char *str;
// 	char** env;
// 	char **bin;
// 	t_vector *vect;
// 	vect = vect_new(10, sizeof(char*));
//
// 	if (argc < 0)
// 		;
// 	if (argv)
// 		;
// 	storeenv(vect, envp);
// 	bin = getbins(vect);
// 	int i;
//
// 	i = 0;
// 	while (bin[i])
// 	{
// 		printf("%s\n", bin[i]);
// 		i++;
// 	}
// }
