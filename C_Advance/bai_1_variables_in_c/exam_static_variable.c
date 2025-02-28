#include <stdint.h>

int printtt(){
    static int a = 0;
    a++; 
    printf("%d\n", a);
}

int main(){
    for(int i =0; i< 10; i++){
        printtt();
    }
}