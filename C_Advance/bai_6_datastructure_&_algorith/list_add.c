#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data; //Giá trị của node
    struct Node* next; //Con tro den node tiep theo 
}Node;

//Ham tao node moi 

Node *createNode(int value){
    Node *newNode = (Node*)malloc(sizeof(Node)); // Cap phat bo nho 
    newNode->data = value; 
    newNode->next = NULL;

    return newNode;
}

//Ham them node vao cuoi danh sach
//Ta sử dụng con trỏ bậc 2, trong hàm main ta truyền trực tiếp địa chỉ của biến head (&head) để thay đổi trực tiếp giá trị của head ở trong main, nếu chỉ truyền con trỏ bậc 1 và head thì sẽ chỉ thay đổi biến bản sao cục bộ ở trong hàm addNode()
void addNode(Node** head, int value){
    Node* newNode = createNode(value);

    if(*head == NULL){
        //Neu danh sach trong, node moi se la head
        *head = newNode;
    }
    else {
        // Neu danh sach khong rong, tim node cuoi va them vao
        Node *tmp = *head;
        while (tmp->next != NULL)
        {
            tmp = tmp -> next;
        }
        tmp->next = newNode;
    }
}
//Ham hien thi danh sach lien ket
//Ham nay chi truyen con tro bac 1 vao de khong lam anh huong den du lieu
void displayList(Node* head){
    Node *tmp = head;

    while(tmp != NULL){
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");
}

void freelist(Node** head){
    Node* tmp;
    while(*head != NULL){
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

int main() {
    Node* head = NULL; // Khởi tạo danh sách rỗng

    // Thêm các phần tử vào danh sách
    for (int i = 1; i <= 5; i++) {
        addNode(&head, i);
    }

    // Hiển thị danh sách liên kết
    printf("Danh sach lien ket: ");
    displayList(head);

    // Giải phóng bộ nhớ
    freelist(&head);

    return 0;
}
