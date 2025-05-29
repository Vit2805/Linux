//Bài toán tính tổng từ 1 đến n
#include <stdio.h>
#include <stdint.h>

int main(){
    //Khai báo n và khởi tạo tổng sum = 0
    int n = 5;
    int sum =0;
    // Tính tổng từ 1 tới n
    for(int i = 0; i <= n; i++){
        sum += i;
    }
    //In ra giá trị của tổng
    printf("sum = %d\n", sum);
    return 0;
}