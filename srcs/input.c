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
	char **retstr;
	int start;
	int end;
	int dq;
	int count;
	int i;

	if (NULL == ft_strchr(str,'"'))
		return(ft_strsplit(str, ' '));
	count = 0;
	dq = 0;
	start = 0;
	end = 0;
	retstr = (char**)malloc(sizeof(char*) * (inputsize(str) + 1));
	retstr[inputsize(str)] = 0;
	while(count < inputsize(str))
	{
		while(str[start] < 33)
			start++;
		end = start;
		while (str[end] > 32 || dq)
		{
			if (str[end] == '"' && dq)
			{
				dq = 0;
			}
			else if (str[end] == '"' && !dq)
			{
				dq = 1;
			}
			end++;
		}
		retstr[count] = ft_strnew(end - start);
		i = 0;
		while (start < end)
		{
			ft_putchar(str[start]);
			retstr[count][i] = str[start];
			start++;
			i++;
		}
		count++;
	}
	free(str);
	return retstr;
}

void checkenv(char **temp, t_vector *vect)
{
	int i;
	char *str;

	i = 0;
	while (temp[i])
	{
		if ((str = dupenvvar(vect, temp[i])))
		{
			free(temp[i]);
			temp[i] = str;
		}
		i++;
	}
}
