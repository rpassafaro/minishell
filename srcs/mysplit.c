/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 00:25:31 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/20 18:03:15 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char			*my_word_builder(char const *str, unsigned int *index)
{
	unsigned	i;
	unsigned	start;
	unsigned	end;
	char		*word;

	i = *index;
	while (str[i] <= 32)
		i++;
	start = i;
	while (str[i] > 32 && str[i] != '\0')
		i++;
	end = i;
	*index = i;
	word = ft_strnew(end - start);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**my_ft_strsplit(char const *s)
{
	unsigned	i;
	unsigned	j;
	unsigned	words;
	char		**rtn;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] > 32 && (s[i + 1] <= 32 || s[i + 1] == '\0'))
			words++;
		i++;
	}
	i = 0;
	j = 0;
	rtn = (char**)malloc(sizeof(char*) * (words + 1));
	if (!rtn)
		return (NULL);
	while (i < words)
	{
		rtn[i] = my_word_builder(s, &j);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
