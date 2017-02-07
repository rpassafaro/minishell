#include "../headers/minishell.h"

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
