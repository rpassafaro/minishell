/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 23:40:17 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/15 23:41:17 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	printfirstpath(char *cwd)
{
	int i;

	i = ft_strlen(cwd);
	i--;
	while (cwd[i] != '/')
		i--;
	i++;
	while (cwd[i])
		ft_putchar(cwd[i++]);
}

void	print_interp(void)
{
	char	*cwd;
	char	buff[PATH_MAX + 1];

	cwd = getcwd(buff, PATH_MAX + 1);
	ft_putstr("[");
	printfirstpath(cwd);
	ft_putstr("]");
	ft_putstr(" ༼ つ ͠° ͟ ͟ʖ ͡° ༽つ > ");
}
