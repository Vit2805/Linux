#include <stdio.h>
#include "book.h"
#include "user.h"
#include "borrow.h"

void showMenu() {
    printf("\n=== Library Menu ===\n");
    printf("1. Add Book\n");
    printf("2. Edit Book\n");
    printf("3. Delete Book\n");
    printf("4. List Available Books\n");
    printf("5. Add User\n");
    printf("6. Delete User\n");
    printf("7. List Users\n");
    printf("8. Borrow Book\n");
    printf("9. Return Book\n");
    printf("0. Exit\n");
    printf("Choose: ");
}

int main() {
    int choice;
    while (1) {
        showMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: addBook(); break;
            case 2: editBook(); break;
            case 3: deleteBook(); break;
            case 4: listAvailableBooks(); break;
            case 5: addUser(); break;
            case 6: deleteUser(); break;
            case 7: listUser(); break;
            case 8: borrowBook(); break;
            case 9: returnBook(); break;
            case 0: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}
