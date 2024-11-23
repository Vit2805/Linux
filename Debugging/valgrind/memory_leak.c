#include <stdlib.h>
#include <stdio.h>

int main() {
    int *ptr = (int *)malloc(5 * sizeof(int));  // Cấp phát bộ nhớ cho mảng 5 phần tử
    if (ptr == NULL) {
        fprintf(stderr, "Không thể cấp phát bộ nhớ!\n");
        return 1;
    }

    ptr[0] = 10;
    ptr[1] = 20;
    ptr[2] = 30;

    // Không gọi free(ptr), dẫn đến rò rỉ bộ nhớ
    return 0;
}
