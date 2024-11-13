#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10

int main() {
    char buffer[MAX_LENGTH];

    printf("Nhap mot chuoi: ");
    fgets(buffer, MAX_LENGTH, stdin);

    printf("Chuoi vua nhap la: %s\n", buffer);

    return 0;
}