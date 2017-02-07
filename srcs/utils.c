#include "../headers/minishell.h"


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

int countarray(char **lst)
{
	int i;

	i = 0;
	while (lst[i])
		i++;

	return (i);
}
