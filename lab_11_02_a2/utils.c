#include "utils.h"
#include "book.h"
#include <stdio.h>

void swap(Book* p1, Book* p2) {
    Book temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void printIncorrectInput() {
    printf("Incorrect input. Please try again.\n");
}

void clearBuffer() {
    while (getchar() != '\n');
}
