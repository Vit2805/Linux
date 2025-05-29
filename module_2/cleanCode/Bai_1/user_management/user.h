#ifndef USER_H
#define USER_H

#define MAX_NAME 100
#define MAX_USER 100
#define MAX_BORROWED 10

// User Structer
typedef struct {
    int id;
    char name[MAX_NAME];
    char borrowedBookIds[MAX_BORROWED];
    int borrowedCount;
} User;

void addUser();
void deleteUser();
void listUser();
User* findUserById(int id);

#endif // USER_H