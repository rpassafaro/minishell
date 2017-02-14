#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <limits.h>
# include <sys/types.h>
#include "../libft/libft.h"
#include "vector.h"
# define ENDL '\n'
# define BUFF_SIZE 1

char	*read_tmp();
void storeenv(t_vector *vect , char **envp);
char *subof(char *str, int sub);
char **getbins(t_vector *vect);
int execprog(char *str, char **bins, char **temp);
int countarray(char **lst);
char *checkbin(char *prog, char *path);
void getenvvar(t_vector *vect, char *str);
int inputsize(char *str);
int trimsome(char *str, int i);
char		*my_word_builder(char const *str, unsigned int *index);
char			**my_ft_strsplit(char const *s);
void freedub(char **str);
char **parseinput(char *str);
void runprog(char *test, char **temp);
void getenvvar(t_vector *vect, char *str);
void getenv_b(t_vector *vect);
char* dupenvvar(t_vector *vect, char *str);
void checkenv(char **temp, t_vector *vect);
int runbuilt(char **temp, t_vector *vect);
char *findenvvar(t_vector *vect, char *str);
void changedirs(char *path, t_vector *vect);
int findenvvarint(t_vector *vect, char *str);
void setenv_b(char *key, char *val, t_vector *vect);
#endif
