/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:47:05 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/07 01:32:21 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*word_builder(char const *str, char c, unsigned int *index)
{
	unsigned	i;
	unsigned	start;
	unsigned	end;
	char		*word;

	i = *index;
	while (str[i] == c)
		i++;
	start = i;
	while (str[i] != c && str[i] != '\0')
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

char			**ft_strsplit(char const *s, char c)
{
	unsigned	i;
	unsigned	j;
	unsigned	words;
	char		**rtn;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
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
		rtn[i] = word_builder(s, c, &j);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
