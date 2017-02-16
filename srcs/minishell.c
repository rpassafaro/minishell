/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:13:39 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/15 22:38:58 by rpassafa         ###   ########.us       */
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
	t_vector *vect;

	vect = vect_new(10, sizeof(char*));
	str1 = ft_strnew(BUFF_SIZE);
	ret = ft_strnew(1);
	bytes_read = 0;
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

void nonrun(char **temp)
{
	ft_putstr("unknown command rsh: ");
	ft_putendl(temp[0]);
	freedub(temp);
}

void dofree(char **temp)
{
	temp++;
	freedub(temp);
}

void handlearg(int argc, char **argv)
{
	if (argc < 0)
		;
	if (argv)
		;
}

void logicrun(int ret, char **temp, t_vector *vect)
{
	if (ret == 1 || ret == -1)
		freedub(temp);
	else if(temp[0] && !execprog(temp[0], getbins(vect), temp, vect))
		nonrun(temp);
	else
		dofree(temp);
}

int main(int argc, char **argv, char **envp)
{
	char *str;
	t_vector *vect;
	char **temp;
	int ret;

	handlearg(argc, argv);
	vect = vect_new(32, sizeof(char*));
	storeenv(vect, envp);
	while(1)
	{
		print_interp();
		str = read_tmp();
		temp = parseinput(str);
		checkenv(temp, vect);
		ret = runbuilt(temp, vect);
		logicrun(ret, temp, vect);
		if (ret == -1)
			break;
	}
	exit(0);
	return 0;
}
