// Tìm số lớn nhất trong 3 số
#include <stdio.h>

int main() {
    int a = 3, b = 6, c = 10, max;

    // Lỗi logic: Chỉ so sánh a với b
    if (a > b && a > c)
        max = a;
    else if (b > c)
        max = b;
    else 
        max = c;
    printf("So lon nhat la: %d\n", max);
    return 0;
}