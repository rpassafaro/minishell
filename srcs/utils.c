#include "../headers/minishell.h"

int countarray(char **lst)
{
	int i;

	i = 0;
	while (lst[i])
		i++;

	return (i);
}
