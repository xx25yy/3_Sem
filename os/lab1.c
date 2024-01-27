#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pid, n, i;
    char *argc[] = {"hii", "hello", NULL};
    pid = fork();
    if (pid == 0)
    {
        printf("\n\nThis is child process,child_pid=%d\n", getpid());
        printf("child process is running\n");
        printf("--------------------------------------------------\n\n");
    }
    else
    {
        printf("\n\nThis is parent process,parent_pid=%d\n", getpid());
        printf("Parent process active,wait for child process to print message\n");
        printf("--------------------------------------------------\n\n");

        wait();
    }

    printf("!!!!HELLO WORLD!!!! printed by pid=%d\n\n", getpid());
    if (pid != 0)
    {

        printf("replacing parent process with new process\n\n");
        printf("--------------------------------------------------\n\n");

        execv("./ose", argc);
    }

    return 0;
}