/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:13:39 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/07 17:01:18 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include "../libft/libft.h"
#include "../headers/vector.h"
#include <stdio.h>


char	*read_tmp()
{
	char	*str1;
	int		bytes_read;
	char	*ret;
	int		dq;
	t_vector *vect;

	vect = vect_new(10, sizeof(char*));
	str1 = ft_strnew(BUFF_SIZE);
	ret = ft_strnew(1);
	bytes_read = 0;
	dq = 0;
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
	ret[bytes_read - 1] = '\0';
	return (ret);
}



int main(int argc, char **argv, char** envp)
{
	char *str;
	t_vector *vect;
	char **temp;

	if (argc < 0)
		;
	if (argv)
		;
	vect = vect_new(32, sizeof(char*));
	storeenv(vect, envp);
	while(1)
	{
		ft_putstr("$> ");
		str = read_tmp();
		if(str[0] == '$')
			getenvvar(vect, str);
		else
		{
			if(!execprog(str, getbins(vect)))
			{
				//ft_putendl(str);
				temp = parseinput(str);
				int i = 0;
				while(temp[i])
					printf("%s\n", temp[i++]);
				// ft_putnbr(inputsize(str));
				// ft_putchar('\n');
				// ft_putstr("rsh: command not found: ");
				// ft_putendl(str);
			}
		}
	}
	return 0;
}
