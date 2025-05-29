#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
    /*code*/
    pid_t child_pid;  /*Luu trong stack frame cua main() */
    int status, rv; 

    

    child_pid = fork();
    if(child_pid == 0) /*Process con*/
    {
        printf("Im the child process, my PID = %d\n", getpid());
        while(1);
        printf("Child process terminate after 5 seconds\n");
        sleep(5);
        exit(0);
        
    }
    else /*Process cha */
    {
        rv = wait(&status);
        if(rv == -1){
            printf("wait() unsuccessful\n");
        } 

        printf("Iam the parrent process, PID child process: %d\n", rv);

        if(WIFEXITED(status)){
            printf("Normally termination, status = %d\n", WEXITSTATUS(status));

        } else if(WIFSIGNALED(status)){
            printf("Killed by signal, value = %d\n", WTERMSIG(status));
        }
    }
    return 0;
}