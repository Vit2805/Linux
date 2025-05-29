#include <stdio.h>

//Khai bao function voi keyword Inline
inline int foo(int a, int b){
    a = a+ b;
}

int main(){
    int x = 20, y = 1;

    //Inline function call
    foo(x, y);

    printf("%d\n", x);
    return 0;
} 