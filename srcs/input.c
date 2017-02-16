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

void setints(int *ret, int *i, int *dq)
{
	*ret = 0;
	*i = 0;
	*dq = 0;
}
int inputsize(char *str)
{
	char **temp;
	int i;
	int ret;
	int dq;

	setints(&ret, &i, &dq);
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

void setstruct(t_parse *thing)
{
	thing->start = 0;
	thing->end = 0;
	thing->dq = 0;
	thing->count = 0;
	thing->i = 0;
}

void parse_a(t_parse *m_parse, char *str)
{
	while(str[m_parse->start] < 33)
		m_parse->start++;
	m_parse->end = m_parse->start;
	while (str[m_parse->end] > 32 || m_parse->dq)
	{
		if (str[m_parse->end] == '"' && m_parse->dq)
			m_parse->dq = 0;
		else if (str[m_parse->end] == '"' && !m_parse->dq)
			m_parse->dq = 1;
		m_parse->end++;
	}
	m_parse->retstr[m_parse->count] = ft_strnew(m_parse->end - m_parse->start);
	m_parse->i = 0;
	if (str[m_parse->start] == '"' && str[ft_strlen(str) - 1] == '"')
	{
		m_parse->start++;
		m_parse->end--;
	}
	while (m_parse->start < m_parse->end)
	{
		m_parse->retstr[m_parse->count][m_parse->i] = str[m_parse->start];
		m_parse->start++;
		m_parse->i++;
	}
	m_parse->count++;
}

char **parseinput(char *str)
{
	t_parse *m_parse;

	m_parse = malloc(sizeof(t_parse));
	setstruct(m_parse);
	if (NULL == ft_strchr(str,'"'))
		return(ft_strsplit(str, ' '));
	m_parse->retstr = (char**)malloc(sizeof(char*) * (inputsize(str) + 1));
	m_parse->retstr[inputsize(str)] = 0;
	while(m_parse->count < inputsize(str))
		parse_a(m_parse, str);
	free(str);
	return m_parse->retstr;
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
