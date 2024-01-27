// Second.c
#include <stdio.h>
#include <unistd.h>
int main()

{

    printf("\n\nHELLO WORLD printed by new process with process id=%d\n", getpid());
    printf("--------------------------------------------------\n");
    printf("\n\n");

    return 0;
}
