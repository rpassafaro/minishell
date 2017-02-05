#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

void storeenv(t_vector *vect , char **envp);
char *subof(char *str, int sub);
#endif
