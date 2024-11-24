/*BT12: Viết một chương trình thực hiện tạo 3 threads.
Thread 1: Thực hiện việc nhập dữ liệu sinh viên từ bàn phím, bao gồm thông tin: Họ tên, ngày sinh, quê quán.
Thread2: Mỗi lần nhập xong dữ liệu một sinh viên, thread này sẽ ghi thông tin sinh viên đó vào file (mỗi thông tin sinh viên nằm trên 1 dòng) thongtinsinhvien.txt.
Thread3: Đọc dữ liệu vừa ghi được và in ra màn hình sau đó thông báo cho thread 1 tiếp tục nhập thêm sinh viên.
Sử dụng mutex và condition variable để giải quyết bài toán.
*/
//hello 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

// Struc luu thong tin sinh vien 
typedef struct 
{
    char hovaten[50];
    char ngaysinh[50];
    char quequan[50];
}SinhVien;

// Cac dieu kien va mutex

pthread_mutex_t mutex;
pthread_cond_t cond_input, cond_write;

// Bien toan cuc luu tru thong tin sinh vien 

SinhVien sinhvien;
int data_ready =0;

//thread 1: nhap du lieu sinh vien tu ban phim 
void *nhap_du_lieu(void *arg){
    while(1){
        pthread_mutex_lock(&mutex);

        //Nhap du lieu sinh vien
        printf("Nhap thong tin sinh vien: \n");
        printf("Ho va ten: ");
        fgets(sinhvien.hovaten, sizeof(sinhvien.hovaten), stdin);
        sinhvien.hovaten[strcspn(sinhvien.hovaten, "\n")] = 0;

        printf("Ngay sinh (dd/mm/yyyy): ");
        fgets(sinhvien.ngaysinh, sizeof(sinhvien.ngaysinh), stdin);
        sinhvien.ngaysinh[strcspn(sinhvien.ngaysinh, "\n")] = 0;

        printf("Que quan: ");
        fgets(sinhvien.quequan, sizeof(sinhvien.quequan), stdin);
        sinhvien.quequan[strcspn(sinhvien.quequan, "\n") ] =0;

        // Danh dau du lieu da san sang de ghi 
        data_ready = 1; 

        //thong bao cho thread2 bat dau lam viec

        pthread_cond_signal(&cond_input);
        pthread_mutex_unlock(&mutex);

        // doi thread 3 thong bao de tiep tuc nhap them sinh vien
        pthread_mutex_lock(&mutex);
        while(data_ready != 0){
            pthread_cond_wait(&cond_write, &mutex);
        }
        pthread_mutex_unlock(&mutex);
    }
    
    return NULL;
}
// Thread 2: ghi du lieu vao file
void *ghi_du_lieu(void *arg){
    FILE *file;

    while (1)
    {
        pthread_mutex_lock(&mutex);

        // DOi cho den khi du lieu sinh vien san sang
        while(data_ready == 0){
            pthread_cond_wait(&cond_input, &mutex);
        }

        //Ghi du lieu vao file
        file = fopen("thongtinsinhvien.txt", "a");
        if(file == NULL){
            printf("Khong the mo file de ghi du lieu! \n");
            pthread_cond_wait(&cond_input, &mutex);
            continue;
        }
        fprintf(file, "%s\n%s\n%s\n\n", sinhvien.hovaten, sinhvien.ngaysinh, sinhvien.quequan);
        fclose(file);

        //danh dau du lieu da duoc ghi xong, san sang cho thread 3 doc
        data_ready = 2;

        //thong bao cho thread3 bat dau doc du lieu
        pthread_cond_signal(&cond_input);
        pthread_mutex_unlock(&mutex);

    }
    return 0;
    

}
void *doc_du_lieu(void *arg){
    FILE *file;
    char buffer[256];

    while(1){
        pthread_mutex_lock(&mutex);

        //doi du lieu da duoc ghi xong vao file 

        while(data_ready != 2){
            pthread_cond_wait(&cond_input, &mutex);
        }

        //doc du lieu tu file ra man hinh

        file = fopen("thongtinsinhvien.txt", "r");
        if(file == NULL){
            printf("Khong the mo file!\n");
            pthread_mutex_unlock(&mutex);
            continue;
        }
        printf("\n--- Thong tin sinh vien vua nhap ---\n");
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("%s", buffer);
        }
        printf("\n------------------------------------\n");
        fclose(file);

        //danh dau da hoan thanh doc va cho phep nhap sinh vien moi 

        data_ready = 0;

        //thong bao thread 1 co the nhap sinh vien moi 
        pthread_cond_signal(&cond_write);
        pthread_mutex_unlock(&mutex);
    }
    return 0;
    
}

int main(){
    pthread_t thread1, thread2, thread3;


    //khoi tao mutex va conditional variable 

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_input, NULL);
    pthread_cond_init(&cond_write, NULL);

    //khoi tao thread
    pthread_create(&thread1, NULL, nhap_du_lieu, NULL);
    pthread_create(&thread2, NULL, ghi_du_lieu, NULL);
    pthread_create(&thread3, NULL, doc_du_lieu, NULL);

    //cho cac thread ket thuc
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    //huy bo mutex va conditionnal variable 
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_input);
    pthread_cond_destroy(&cond_write);
    

}
