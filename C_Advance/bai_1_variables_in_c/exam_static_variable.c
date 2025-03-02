#include <stdint.h>

void gia_tri_a(){
    static int a = 0;
    a++; 
    printf("%d\n", a);
}

int main(){
    for(int i =0; i< 10; i++){
        gia_tri_a();
    }
}