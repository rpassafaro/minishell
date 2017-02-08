#include "../headers/minishell.h"

void runprog(char *test, char **temp)
{
	int status;
	int pid;
	//ft_putendl(test);
	pid = fork();
	if (pid == 0){
	    int err;
	    char *env[1] = { 0 };
	    err = execve(test, temp, env);  //syscall, libc has simpler wrappers (man exec)
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

int checkloc(char *test, int size, char **temp)
{
	struct stat sb;
	if (lstat(test, &sb) == -1)
	{
		return (size);
	}
	else
		runprog(test, temp);
	return (-1);
}


int execprog(char *str, char **bins, char **temp)
{
	int size;
	char *test;

	size = countarray(bins);
	size--;
	size = checkloc(str, size, temp);
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
			runprog(test, temp);
			return 1;
		}
		else
			size--;
	}
	freedub(bins);
	return 0;
}
