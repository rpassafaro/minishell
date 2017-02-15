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
	free (tmp);
	if (ret == 0)
	{
		vect_delete(vect, i);
		str = ft_strjoin("OLDPWD=", cwd);
		vect_insert(vect, i, &str);
	}
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
	free (tmp);
	if (ret == 0)
	{
		vect_delete(vect, i);
		str = ft_strjoin("OLDPWD=", cwd);
		vect_insert(vect, i, &str);
	}
}

void	changedirs(char *path, t_vector *vect)
{
	int ret;
	char *str;
	int i;
	char* cwd;
	char buff[PATH_MAX + 1];

	cwd = getcwd(buff, PATH_MAX + 1);
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
	vect_delete(vect, i);
	str = ft_strjoin("OLDPWD=", cwd);
	vect_insert(vect, i, &str);
	//free(cwd);
	return ;
}
