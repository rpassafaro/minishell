#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"
#include "vector.h"
#include <sys/types.h>
#include <sys/stat.h>

void storeenv(t_vector *vect , char **envp);
char *subof(char *str, int sub);
char **getbins(t_vector *vect);

#endif
