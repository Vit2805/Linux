#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 10;
    int *ptr = (int*)malloc(size * sizeof(int)); // Cấp phát bộ nhớ cho mảng 10 số nguyên

    // Sử dụng mảng
    for (int i = 0; i < 10; i++) {
        ptr[i] = i;
        printf("%d \n", ptr[i]);
    }

    printf("Kich thuoc cua vung nho duoc cap phat = %zu byte\n", size * sizeof(int));

    free(ptr);
    
    return 0; // Kết thúc chương trình mà không giải phóng
}