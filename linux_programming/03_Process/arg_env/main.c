#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int i;

    // In ra so luong command-line truyen vao:
    printf("Number of arguments: %d\n", argc);

    // In ra noi dung cua moi command-line
    for(int i =0; i< argc; i++)
    {
        printf("argc[%d]: %s\n", i,argv[i]);
    }
}