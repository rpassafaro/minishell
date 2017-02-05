#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

// int main()
// {
//    pid_t pid;
//    char *const parmList[] = {"/bin/ls", "-l", NULL};
//
//    if ((pid = fork()) == -1)
// 	  perror("fork error");
//    else if (pid == 0)
//    {
// 	  execv("/bin/ls", parmList);
// 	  printf("Return not expected. Must be an execv error.n");
//    }
// }
