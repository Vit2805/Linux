#include <stdio.h>
#include <stdint.h>

uint64_t a = 0x0102030405060708;
uint64_t *d = &a;
uint8_t *b;
int main(){
    b = (uint8_t *)d; // ép kiểu con trỏ con trỏ trỏ đến vùng dữ liệu có 1 byte
    printf("%d\n", *b);
    b++; //p++ cộng đến vùng nhớ liền kề có kích thước 1 byte
    printf("%d\n", *b);
    b++;
    printf("%d\n", *b);
    b++;
    printf("%d\n", *b);
    b++; 

    return 0;
}