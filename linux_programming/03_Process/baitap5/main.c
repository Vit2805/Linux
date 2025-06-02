#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;

    //tao tien trinh con
    pid = fork();

    if(pid < 0){
        //neu fork() tra ve gia tri am thi da xay ra loi 
        perror("fork failed");
        return 1;
    }
    else if(pid == 0){
        //day la tien trinh con
        printf("Tien trinh con:\n");
        printf("PID: %d\n", getpid()); //In ra PID cua tien trinh con 
        printf("PPID: %d\n", getppid()); ///In ra PID cua tien trinh cha
    }
    else 
    {
        //day la tien trinh cha
        printf("Tien trinh cha: \n");
        printf("PID: %d\n", getpid()); //In ra PID cua tien trinh cha
        printf("PID con: %d\n", pid); //In ra PID cua tien trinh con

    }


    return 0;
}
