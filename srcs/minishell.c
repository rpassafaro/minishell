/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:13:39 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/16 00:55:09 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include "../libft/libft.h"
#include "../headers/vector.h"

void	nonrun(char **temp)
{
	ft_putstr("unknown command rsh: ");
	ft_putendl(temp[0]);
	freedub(temp);
}

void	dofree(char **temp)
{
	temp++;
	freedub(temp);
}

void	handlearg(int argc, char **argv)
{
	if (argc < 0)
		;
	if (argv)
		;
}

void	logicrun(int ret, char **temp, t_vector *vect)
{
	if (ret == 1 || ret == -1)
		freedub(temp);
	else if (findenvvarint(vect, "PATH") == -1 ||
	(temp[0] && !execprog(temp[0], getbins(vect), temp, vect)))
		nonrun(temp);
	else
		dofree(temp);
}

int		main(int argc, char **argv, char **envp)
{
	char		*str;
	t_vector	*vect;
	char		**temp;
	int			ret;

	handlearg(argc, argv);
	vect = vect_new(32, sizeof(char*));
	storeenv(vect, envp);
	while (1)
	{
		print_interp();
		str = read_tmp();
		temp = parseinput(str);
		checkenv(temp, vect);
		ret = runbuilt(temp, vect);
		logicrun(ret, temp, vect);
		if (ret == -1)
			break ;
	}
	exit(0);
	return (0);
}
