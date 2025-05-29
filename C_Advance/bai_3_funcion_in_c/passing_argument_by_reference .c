#include <stdint.h>
#include <stdio.h>

int Sum(int a, int b);

int swap(int *a, int *b);
int main(){
    int x = 19, y = 5;
    printf("%d, %d\n", x, y);
    swap(&x, &y); //Truyền địa chỉ của biến x và biến y vào trong hàm swap(), trong hàm swap int *a = &x -> địa chỉ của x được gán cho con trỏ a
    printf("%d, %d\n", x, y);
}

int swap(int *a, int *b){
    int tmp; 
    tmp = *a;
    *a = *b;
    *b = tmp;
}

