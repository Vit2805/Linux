/*BT11. Viết một chương trình thực hiện tạo 2 threads. Cả hai threads này đều dùng chung một handler.
Kiểm tra nếu là thread1 đang thực hiện thì in ra thông điệp bất kì để xác định. 
Nếu là thread2 thì truyền vào dữ liệu kiểu struct human được khởi tạo từ trước, với các thông tin: Họ tên, năm sinh, sdt, quê quán. Sau đó in các thông tin này ra màn hình.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// Khai báo struct human
struct human {
    char HoVaTen[100];
    int NamSinh;
    char sdt[20];
    char QueQuan[100];
};

// Hàm xử lý dùng chung cho cả 2 threads
void *handle(void *arg) {
    if (arg == NULL) {
        // Đây là thread 1
        printf("Tôi đang ở thread1\n");
    } else {
        // Đây là thread 2
        struct human *info = (struct human *)arg;

        printf("Mời bạn nhập thông tin cá nhân: \n");
        printf("1. Họ và tên: ");
        scanf("%s", info->HoVaTen);
        printf("2. Năm sinh: ");
        scanf("%d", &info->NamSinh);
        printf("3. Số điện thoại: ");
        scanf("%s", info->sdt);
        printf("4. Quê quán: ");
        scanf("%s", info->QueQuan);

        // In thông tin đã nhập để kiểm tra
        printf("\nThông tin vừa nhập:\n");
        printf("Họ và tên: %s\n", info->HoVaTen);
        printf("Năm sinh: %d\n", info->NamSinh);
        printf("Số điện thoại: %s\n", info->sdt);
        printf("Quê quán: %s\n", info->QueQuan);
    }

    return NULL;
}

int main() {
    int ret;
    pthread_t thread_id1, thread_id2;
    struct human person; // Khởi tạo struct để lưu thông tin cho thread 2

    // Tạo thread 1 với handle và không truyền tham số
    if ((ret = pthread_create(&thread_id1, NULL, &handle, NULL)) != 0) {
        printf("pthread_create() error number: %d\n", ret);
        return -1;
    }

    // Tạo thread 2 với handle và truyền vào struct human
    if ((ret = pthread_create(&thread_id2, NULL, &handle, (void *)&person)) != 0) {
        printf("pthread_create() error number: %d\n", ret);
        return -1;
    }

    // Đợi các thread hoàn thành
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);

    printf("Các threads đã hoàn thành.\n");

    return 0;
}

