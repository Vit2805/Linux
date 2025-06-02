#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
    printf("Run command <ls -lah> after 2 seconds\n");
    sleep(2);
    execl("/usr/bin/ls", "ls", "-l", "-h", NULL);
    return 0;
}