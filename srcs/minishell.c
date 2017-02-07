/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 13:13:39 by rpassafa          #+#    #+#             */
/*   Updated: 2017/02/06 22:23:03 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
#include "../libft/libft.h"
#include "../headers/vector.h"
#include <stdio.h>

char *checkbin(char *prog, char *path)
{
	char *test;
	char *re;
	struct stat sb;

	re = ft_strjoin(path, "/");
	test = ft_strjoin(re, prog);
	free(re);
	if (lstat(test, &sb) == -1)
	{
		free(test);
		return (NULL);
	}
	else
	{
		if ((sb.st_mode & S_IFMT) == S_IFREG)
			return test;
	}
	return(NULL);
}

int countarray(char **lst)
{
	int i;

	i = 0;
	while (lst[i])
		i++;

	return (i);
}

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

void getenvvar(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), subof(str,1), ft_strlen(str) - 1) == 0)
		{
			ft_putendl(subof(*(char **)vectspot(i, vect),ft_strlen(str)));
			return;
		}
		i++;
	}
}

void runprog(char *test)
{
	int status;
	int pid;
	ft_putendl(test);
	pid = fork();
	if (pid == 0){
	    int err;
	    char *env[1] = { 0 };
	    char *argv[3] = { test, 0 };
	    err = execve(test, argv, env);  //syscall, libc has simpler wrappers (man exec)
	    exit(err); //if it got here, it's an error
	}
	else if(pid < 0)
	{
	    printf("fork failed with error code %d\n", pid);
	    exit(-1);
	}

	wait(&status); //simplest one, man wait for others
	free (test);
	printf("child pid was %d, it exited with %d\n", pid, status);
}

int checkloc(char *test, int size)
{
	struct stat sb;
	if (lstat(test, &sb) == -1)
	{
		return (size);
	}
	else
		runprog(test);
		return (-1);
}


int execprog(char *str, char **bins)
{
	int size;
	char *test;

	size = countarray(bins);
	size--;
	size = checkloc(str, size);
	while (size > -1)
	{
		test = checkbin(str, bins[size]);
		if (test != NULL)
		{
			runprog(test);
			return 1;
		}
		else
			size--;
	}
	return 0;
}


int main(int argc, char **argv, char** envp)
{
	char *str;
	t_vector *vect;

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
		//ft_putendl(str);
		if(str[0] == '$')
			getenvvar(vect, str);
		else
		{
			if(!execprog(str, getbins(vect)))
			{
				ft_putstr("rsh: command not found: ");
				ft_putendl(str);
			}
		}
	}
	return 0;
}
