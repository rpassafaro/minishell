#include "../headers/minishell.h"

void runprog(char *test, char **temp, t_vector *vect)
{
	int status;
	int pid;
	int err;
	char **env;

	env = cpenv_b(vect);
	pid = fork();
	if (pid == 0){
	    err = execve(test, temp, env);
	}
	else if(pid < 0)
	{
	    printf("fork failed with error code %d\n", pid);
	    exit(-1);
	}
	signal(SIGINT, NULL);
	wait(&status);
	free (test);
}

int checkloc(char *test, int size, char **temp, t_vector *vect)
{
	struct stat sb;
	if (lstat(test, &sb) == -1)
	{
		return (size);
	}
	else
		runprog(test, temp, vect);
	return (-1);
}

int execprog(char *str, char **bins, char **temp, t_vector *vect)
{
	int size;
	char *test;

	size = countarray(bins);
	size--;
	size = checkloc(str, size, temp, vect);
	if (size == -1)
		return 1;
	while (size > -1)
	{
		test = checkbin(str, bins[size]);
		if (test != NULL)
		{
			freedub(bins);
			free(temp[0]);
			temp[0] = test;
			runprog(test, temp, vect);
			return 1;
		}
		else
			size--;
	}
	freedub(bins);
	return 0;
}
