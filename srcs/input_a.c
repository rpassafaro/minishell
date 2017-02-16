/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:19:24 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/16 00:19:26 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	setstruct(t_parse *thing)
{
	thing->start = 0;
	thing->end = 0;
	thing->dq = 0;
	thing->count = 0;
	thing->i = 0;
}

void	parse_a(t_parse *m_parse, char *str)
{
	while (str[m_parse->start] < 33)
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

char	**parseinput(char *str)
{
	t_parse *m_parse;

	m_parse = malloc(sizeof(t_parse));
	setstruct(m_parse);
	if (NULL == ft_strchr(str, '"'))
		return (ft_strsplit(str, ' '));
	m_parse->retstr = (char**)malloc(sizeof(char*) * (inputsize(str) + 1));
	m_parse->retstr[inputsize(str)] = 0;
	while (m_parse->count < inputsize(str))
		parse_a(m_parse, str);
	free(str);
	return (m_parse->retstr);
}

void	checkenv(char **temp, t_vector *vect)
{
	int		i;
	char	*str;

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
