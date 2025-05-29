#include <stdio.h>
#include <string.h>
#include "book.h"
#include "user.h"
#include "borrow.h"

#include <stdio.h>
#include <string.h>
#include "book.h"
#include "user.h"
#include "borrow.h"

void borrowBook() {
    int userId, bookId;
    printf("Enter user ID: ");
    scanf("%d", &userId);

    printf("Enter book ID: ");
    scanf("%d", &bookId);

    User* user = findUserById(userId);
    Book* book = findBookById(bookId);

    if (!user) {
        printf("User ID not found.\n");
        return;
    }
    if (!book) {
        printf("Book ID not found.\n");
        return;
    }

    if (book->status == BORROWED) {
        printf("Book already borrowed.\n");
        return;
    }

    if (user->borrowedCount >= MAX_BORROWED) {
        printf("User has borrowed maximum number of books.\n");
        return;
    }

    book->status = BORROWED;
    user->borrowedBookIds[user->borrowedCount++] = bookId;

    printf("Book borrowed successfully.\n");
}

void returnBook() {
    int userId, bookId;
    printf("Enter user ID: ");
    scanf("%d", &userId);

    printf("Enter book ID: ");
    scanf("%d", &bookId);

    User* user = findUserById(userId);
    Book* book = findBookById(bookId);

    if (!user) {
        printf("User ID not found.\n");
        return;
    }
    if (!book) {
        printf("Book ID not found.\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < user->borrowedCount; i++) {
        if (user->borrowedBookIds[i] == bookId) {
            for (int j = i; j < user->borrowedCount - 1; j++) {
                user->borrowedBookIds[j] = user->borrowedBookIds[j + 1];
            }
            user->borrowedCount--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("User has not borrowed this book.\n");
        return;
    }

    book->status = AVAILABLE;
    printf("Book returned successfully.\n");
}
