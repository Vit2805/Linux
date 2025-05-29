#ifndef BOOK_H
#define BOOK_H

//Constants
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define MAX_BOOKS 1000

//BookStatus
typedef enum {
    AVAILABLE,
    BORROWED
} BookStatus;


//Book Structures
typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    BookStatus status;
} Book;


void addBook();
void editBook();
void deleteBook();
void listAvailableBooks();
Book* findBookById(int id);
Book* findBookByAuthor(const char* author);
Book* findBookByTitle(const char* title);

#endif // BOOK_H






























