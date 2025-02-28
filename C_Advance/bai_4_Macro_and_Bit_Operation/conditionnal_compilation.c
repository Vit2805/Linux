#include <stdint.h>

#define feature_enable

int main(){
    #ifdef feature_enable 
        printf("feature is initially enabled! \n");
    #else printf("feature is initially disabled");
    #endif


    #ifdef feature_enable 
        printf("feature is still enabled! \n");
    #else printf("feature is now disabled");
    #endif
}

//Sau tiền xử lý thì hàm main sẽ như sau: 
// int main(){
//     printf("feature is initially enabled! \n");
//     printf("feature is now disabled");
// }

#ifndef common_h
#define common_h
hello;
#endif
// Để tránh include nhiều lần, ta sử dụng ifndef để kiểm tra xem file.h đó đã được define hay chưa, nếu đã define thì sẽ bỏ qua và ngược lại.