#include <stdio.h>
#include <string.h>
#include "book.h"

//Libary
static Book books[MAX_BOOKS];
static int bookCount = 0;


//Addbook 
void addBook() {
    if (bookCount >= MAX_BOOKS) { 
        printf("Libary is full! \n");
        return;
    }

    Book newBook;
    
    printf("Enter book ID: ");
    scanf("%d", &newBook.id);

    printf("Enter title: ");
    scanf(" %[^\n]", newBook.title);

    printf("Enter author: ");
    scanf(" %[^\n]", newBook.author);

    newBook.status = AVAILABLE;
    books[bookCount++] = newBook;
}

//Editbook
void editBook() {
    int id; 
    printf("Enter book ID to edit: ");
    scanf("%d", &id);

    Book* book = findBookById(id);
    if(book == NULL) {
        printf("Book not found. \n");
        return;
    }

    printf("Enter new title: ");
    scanf(" %[^\n]", book->title);

    printf("Enter new author: ");
    scanf(" %[^\n]", book->author);

    printf("Book updated! \n");

}

//Delete book
void deleteBook() {
    int id;
    printf("Enter book ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < bookCount; i++) { 
        if (books[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                books[j] = books[j + 1];
            }
        }
        bookCount--;
        printf("Book deleted. \n");
        return;
    }

    printf("Book not found. \n");
}

void listAvailableBooks() {
    printf("Available books: ");
    for (int i = 0; i < bookCount; i++) {
        if (books[i].status == AVAILABLE) {
            printf("ID: %d | Title: %s | Author: %s \n", books[i].id, books[i].title, books[i].author);
        }
    }
}

Book* findBookById(int id) { 
    for(int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            return &books[i];
        }
    }
    return NULL;
}

Book* findBookByTitle(const char *title) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return &books[i];
        }
    }
    return NULL;
}

Book* findBookByAuthor(const char *author) {
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(books[i].author, author) == 0) {
            return &books[i];
        }
    }
    return NULL;
}
