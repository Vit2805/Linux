#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(10 * sizeof(int));  // Cấp phát bộ nhớ
    arr[10] = 100;  // Lỗi truy cập ngoài vùng nhớ (ngoài phạm vi cấp phát)
    free(arr);  // Giải phóng bộ nhớ
    return 0;
}
