#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    int status;

    // Tạo tiến trình con
    pid = fork();

    if (pid < 0) {
        // Nếu `fork()` trả về giá trị âm, thì đã xảy ra lỗi
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        // Đây là tiến trình con
        printf("Tiến trình con (B):\n");
        printf("PID: %d\n", getpid());   // In ra PID của tiến trình con
        printf("PPID: %d\n", getppid()); // In ra PID của tiến trình cha
        exit(0); // Kết thúc tiến trình con với mã trạng thái 0
    } else {
        // Đây là tiến trình cha
        printf("Tiến trình cha (A):\n");
        printf("PID: %d\n", getpid());   // In ra PID của tiến trình cha
        printf("Con PID: %d\n", pid);    // In ra PID của tiến trình con

        // Chờ tiến trình con kết thúc và lấy trạng thái kết thúc
        if (waitpid(pid, &status, 0) > 0) {
            if (WIFEXITED(status)) {
                printf("Tiến trình con kết thúc với mã trạng thái: %d\n", WEXITSTATUS(status));
            } else {
                printf("Tiến trình con kết thúc không thành công.\n");
            }
        } else {
            perror("waitpid failed");
        }
    }

    return 0;
}
