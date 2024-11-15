#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void fork_example()
{
    //child procces because return value zero
    if(fork() == 0)
    {
        printf("Hello from Child! \n");
    }
    // parent product because return value non-zero
    else
    {
        printf("Hello from Parent! \n");
    }
}
int main()
    {
        fork_example();
        return 0;
    }