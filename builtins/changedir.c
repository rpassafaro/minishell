#include "../headers/minishell.h"

char	*findenvvar(t_vector *vect, char *str)
{
	int i;

	i = 0;
	while (i < (int)vect->size)
	{
		if (ft_strncmp(*(char **)vectspot(i, vect), subof(str,0), ft_strlen(str) - 1) == 0)
		{
			return(ft_strdup(*(char **)vectspot(i, vect)));
		}
		i++;
	}
	return (NULL);
}

void changeold(int ret, t_vector *vect, char *cwd, int i)
{
	char *str;

	if (ret == 0)
	{
		vect_delete(vect, i);
		str = ft_strjoin("OLDPWD=", cwd);
		vect_insert(vect, i, &str);
	}
}

void checkchange(int i, char *path)
{
	if (i == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
	}
}

void	goback(t_vector *vect, char *cwd)
{
	char *str;
	char *tmp;
	int ret;
	int i;

	i = findenvvarint(vect, "OLDPWD");
	str = findenvvar(vect, "OLDPWD");
	tmp = subof(str, 7);
	ft_putendl(tmp);
	free (str);
	ret = chdir(tmp);
	checkchange(ret, tmp);
	free (tmp);
	changeold(ret, vect, cwd, i);
}
void	gohome(t_vector *vect, char *cwd)
{
	char *str;
	char *tmp;
	int ret;
	int i;

	i = findenvvarint(vect, "OLDPWD");
	str = findenvvar(vect, "HOME");
	tmp = subof(str, 5);
	free (str);
	ret = chdir(tmp);
	checkchange(ret, tmp);
	free (tmp);
	changeold(ret, vect, cwd, i);
}

char *til_b(char *path, t_vector *vect)
{
	char *str;
	char *tmp;
	char *mt;

	str = findenvvar(vect, "HOME");
	tmp = subof(str, 5);
	free (str);
	if (path[0])
		mt = subof(path, 1);
	else
		mt = ft_strdup("");
	str = ft_strjoin(tmp, mt);
	free(tmp);
	free (mt);
	return (str);
}

void ft_til(t_vector *vect, char *path, char *cwd)
{
	int i;
	int ret;
	char *tmp;

	tmp = til_b(path, vect);
	ft_putendl(tmp);
	ret = chdir(tmp);
	checkchange(ret, tmp);
	free (tmp);
	if (path[0] && !path[1])
	{
		gohome(vect,cwd);
		return;
	}
	i = findenvvarint(vect, "OLDPWD");
	changeold(ret, vect, cwd, i);
}

void	changedirs(char *path, t_vector *vect)
{
	int ret;
	int i;
	char* cwd;
	char buff[PATH_MAX + 1];

	cwd = getcwd(buff, PATH_MAX + 1);
	if (path[0] == '~')
	{
		ft_til(vect, path, cwd);
		return;
	}
	if (path == NULL)
	{
		gohome(vect,cwd);
		return;
	}
	if (ft_strcmp(path,"-") == 0)
	{
		goback(vect, cwd);
		return;
	}
	i = findenvvarint(vect, "OLDPWD");
	ret = chdir(path);
	checkchange(ret, path);
	changeold(ret, vect, cwd, i);
}
