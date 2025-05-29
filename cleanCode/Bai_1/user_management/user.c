#include <stdio.h>
#include <string.h>
#include "user.h"

static User users[MAX_USER];
static userCount = 0;

//Add user
void addUser() {
    if (userCount >= MAX_USER) {
        printf("User limit reached. \n");
        return;
    }

    int id;
    User newUser;
    printf("Enter User ID: ");
    scanf("%d", &newUser.id);
    
    newUser.borrowedCount = 0;

    printf("Enter User Name: ");
    scanf(" %[^\n]", newUser.name);

    users[userCount++] = newUser;
    printf("User added! \n");
}

//Delete user
void deleteUser() {
    int id;
    printf("Enter User ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < MAX_USER; i++) {
        if (users[i].id == id) {
            for (int j = i; j < MAX_NAME - 1; j++) {
                users[j] = users[j+1];
            }
        }
        userCount--;
        printf("User Deleted! \n");
        return;
    }

    printf("User not found. \n");
}

//List User
void listUser() {
    printf("List user: \n");

    for(int i = 0; i < MAX_USER; i++) {
        printf("ID: %d, Name: %s, Book borrowed: %d \n", users[i].id, users[i].name, users[i].borrowedCount);
    }
}

User* findUserById(int id) { 
    for (int i = 0; i < MAX_USER; i++) {
        if (users[i].id == id) {
            return &users[i];
        }
    }
    return NULL;
}



