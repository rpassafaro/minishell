#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
#include "../libft/libft.h"
#include "vector.h"
# define ENDL '\n'
# define BUFF_SIZE 1

char	*read_tmp();
void storeenv(t_vector *vect , char **envp);
char *subof(char *str, int sub);
char **getbins(t_vector *vect);
int execprog(char *str, char **bins);
int countarray(char **lst);
#endif
