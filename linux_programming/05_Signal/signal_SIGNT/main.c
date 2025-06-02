#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void sig_handler1(int num){
    printf("Hello Tung with signal number: %d\n", num);
}

int main(){
    if(signal(SIGINT, sig_handler1)== SIG_ERR){
        fprintf(stderr, "Cannot handle SIGINT\n");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        printf("Hello\n");
        sleep(1);
    }
    
}