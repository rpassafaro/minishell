#include "../headers/minishell.h"

void printfirstpath(char *cwd)
{
	int i;

	i = ft_strlen(cwd);
	i--;
	while(cwd[i] != '/')
		i--;
	i++;
	while(cwd[i])
		ft_putchar(cwd[i++]);
}

void print_interp()
{
	char* cwd;
	char buff[PATH_MAX + 1];

	cwd = getcwd(buff, PATH_MAX + 1);
	ft_putstr("[");
	printfirstpath(cwd);
	ft_putstr("]");
	ft_putstr(" ༼ つ ͠° ͟ ͟ʖ ͡° ༽つ > ");
}
