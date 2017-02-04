#include "vector.h"
#include "./libft/libft.h"
#include <stdio.h>

char *subof(char *str, int sub)
{
	int i;
	char *ret;

	i = 0;
	ret = ft_strnew(ft_strlen(str) - sub);
	while (str[sub])
	{
		ret[i] = str[sub];
		i++;
		sub++;
	}
	return(ret);
}

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

int main(int argc, char **argv, char** envp)
{
	char *str;
	char** env;
	char **bin;
	t_vector *vect;
	vect = vect_new(10, sizeof(char*));

	if (argc < 0)
		;
	if (argv)
		;
	storeenv(vect, envp);
	bin = getbins(vect);
	int i;

	i = 0;
	while (bin[i])
	{
		printf("%s\n", bin[i]);
		i++;
	}
}
