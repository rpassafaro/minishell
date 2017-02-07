#include "../headers/minishell.h"
#include <stdio.h>

int trimsome(char *str, int i)
{
	while (str[i] == ' ' && str[i])
		i++;
	return i;
}

int countthis(char *str)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '"')
			count++;
		i++;
	}
	return count;
}

int inputsize(char *str)
{
	char **temp;
	int i;
	int ret;
	int dq;

	ret = 0;
	i = 0;
	dq = 0;
	temp = my_ft_strsplit(str);
	while(temp[i])
	{
		if (ft_strchr(temp[i], '"') && countthis(temp[i]) < 2)
		{
			if (!dq)
				dq = 1;
			else if (dq)
			{
				ret++;
				dq = 0;
			}
		}
		else if (!dq)
			ret++;
		i++;
	}
	freedub(temp);
	return ret;
}

char **parseinput(char *str)
{
	str = NULL;
	// char **temp;
	// char **retstr;
	// int i;
	// int ret;
	// int dq;
	// char *fr;
	//
	// ret = 0;
	// i = 0;
	// dq = 0;
	// temp = my_ft_strsplit(str);
	// retstr = (char**)malloc(sizeof(char*) * inputsize(str) + 1);
	// retstr[inputsize(str)] = 0;
	// while(temp[i])
	// {
	// 	if (ft_strchr(temp[i], '"'))
	// 	{
	// 		while(!ft_strchr(temp[i], '"'))
	// 		{
	// 			fr = retstr[ret];
	// 			retstr[ret] = ft_strjoin(temp[i], retstr[ret]);
	// 			free(fr);
	// 			i++;
	// 		}
	// 		fr = retstr[ret];
	// 		retstr[ret] = ft_strjoin(temp[i], retstr[ret]);
	// 		free(fr);
	// 	}
	// 	else
	// 		retstr[ret] = ft_strdup(temp[i]);
	// 	i++;
	// 	ret++;
	// }
	// freedub(temp);
	// return retstr;
	return NULL;
}
