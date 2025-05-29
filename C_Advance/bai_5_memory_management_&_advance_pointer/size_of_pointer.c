#include <stdint.h>
#include <stdio.h>
int a = 4; //4
double b = 2; //8

int *c; //4
double *d; //8

char *e; 

int main(){
    printf("%d\n", sizeof(a)); //4
    printf("%d\n", sizeof(b)); //8
    printf("%d\n", sizeof(c)); //4
    printf("%d\n", sizeof(d)); //4
    printf("%d\n", sizeof(e)); //4
}