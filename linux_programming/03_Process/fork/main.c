#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    /*code*/
    pid_t child_pid;
    int a =0; 

    printf("Gia tri khoi tao cua counter: %d\n", a);

    child_pid = fork();
    if(child_pid == 0) /*Process con*/
    {
        printf("\nIm the child process, a =  %d\n", ++a);
        printf("My PID is: %d, my parent PID is: %d\n", getpid(), getppid());
    }
    else /*Process cha */
    {
        printf("\nIm the parent process, a =  %d\n", a);
        printf("My PID is: %d\n", getpid());
        while(1);
    }
    return 0;
}