/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:13:39 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/03 21:56:52 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"
#include "../libft/libft.h"
#include "../headers/vector.h"
#include <stdio.h>

char	*read_tmp()
{
	char	*str1;
	int		bytes_read;
	char	*ret;
	t_vector *vect;
	vect = vect_new(10, sizeof(char*));

	str1 = ft_strnew(BUFF_SIZE);
	bytes_read = 0;
	ft_putstr("$> ");
	while (ft_strchr(ret, '\n') == NULL)
	{
		vect_insert(vect, vect->size, &str1);
		bzero(str1, 2);
		str1 = ft_strnew(BUFF_SIZE);
		if (bytes_read > 0)
			vect_insert(vect, vect->size, &ret);
		bytes_read += read(0, str1, BUFF_SIZE);
		if (bytes_read > 1)
			ret = ft_strjoin(ret,(const char*)str1);
		else
			ret = ft_strdup(str1);
	}
	col_vect(vect);
	return (ret);
}

int main()
{
	char *str;

	while(1)
	{
		str = read_tmp();
		printf("%s", str);
		ft_bzero(str, ft_strlen(str));
	}
	return 0;
}
