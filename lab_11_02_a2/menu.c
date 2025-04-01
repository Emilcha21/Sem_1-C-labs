#include <stdio.h>
#include "menu.h"

void showMenu() {
    printf("1. Add book\n");
    printf("2. Show all books\n");
    printf("3. Delete book by author\n");
    printf("4. Sort books by rating\n");
    printf("5. Exit\n");
    printf("Input number: ");
}

int getAction(int* action) {
    return (scanf("%d", action) != 1);
}

void enterNumberPlease() {
    printf("Input a number from 1 to 5!\n");
}
