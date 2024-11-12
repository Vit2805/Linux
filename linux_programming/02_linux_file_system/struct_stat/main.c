#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    // Tạo file
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Ghi dữ liệu vào file
    fprintf(fp, "Đây là một đoạn dữ liệu mẫu được ghi vào file test.txt\n");
    fclose(fp);

    // Lấy thông tin về file
    struct stat st;
    stat("test.txt", &st);

    // In thông tin ra màn hình
    printf("Loại file: file thường\n");
    printf("Tên file: test.txt\n");
    printf("Kích thước (byte): %ld\n", st.st_size);

    // Chuyển đổi thời gian sửa đổi cuối cùng sang định dạng dễ đọc
    char time_str[100];
    time_t rawtime = st.st_mtime;
    struct tm *timeinfo = localtime(&rawtime);
    strftime(time_str, 100, "%Y-%m-%d %H:%M:%S", timeinfo);
    printf("Thời gian sửa đổi cuối: %s\n", time_str);

    return 0;
}