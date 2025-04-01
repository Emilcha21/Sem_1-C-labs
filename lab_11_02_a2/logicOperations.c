#include "logicOperations.h"
#include "fileOperations.h"
#include "utils.h"
#include "book.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void addBook(const char* fileName) {
    FILE* file = openFileAMode(fileName);
    Book book = {};
    getchar();
    getBookDetails(&book);
    writeBookToFile(file, &book);
    fclose(file);
}

void showAllBooks(const char* fileName) {
    FILE *file = openFileRMode(fileName);
    int structCount = countLines(file) / 4;

    for (int i = 0; i < structCount; i++) {
        char book[LEN];
        fgets(book, LEN, file);
        printf("Book name: %s", book);
        fgets(book, LEN, file);
        printf("Author: %s", book);
        fgets(book, LEN, file);
        printf("Pages: %d\n", atoi(book));
        fgets(book, LEN, file);
        printf("Rank: %d\n\n", atoi(book));
    }
    fclose(file);
}

void deleteBookByAuthor(const char* fileName, const char* artistName) {
    FILE *file = openFileRMode(fileName);
    int structCount = countLines(file) / 4;

    Book* booksArray = readBooksFromFile(file, structCount);
    fclose(file);

    structCount = filterBooksByAuthor(booksArray, structCount, artistName);
    writeBooksToFile(fileName, booksArray, structCount);
    free(booksArray);
}

void sortBooksByRating(const char* fileName) {
    FILE *file = openFileRMode(fileName);
    int structCount = countLines(file) / 4;

    Book* booksArray = readBooksFromFile(file, structCount);
    fclose(file);

    sortBooks(booksArray, structCount);
    writeBooksToFile(fileName, booksArray, structCount);
    free(booksArray);
}

void inputName(char* artistName) {
    printf("Enter name to be deleted: ");
    scanf("%s", artistName);
    strcat(artistName, "\n");
}

int filterBooksByAuthor(Book* booksArray, int structCount, const char* artistName) {
    int newCount = structCount;

    for (int i = 0; i < newCount; i++) {
        if (strcmp(booksArray[i].author, artistName) == 0) {
            for (int j = i; j < newCount - 1; j++) {
                booksArray[j] = booksArray[j + 1];
            }
            newCount--;
            i--;
        }
    }

    return newCount;
}

void switchFunc(enum Action action, const char* fileName) {
    switch (action) {
    case ADD:
        addBook(fileName);
        break;
    case LIST:
        showAllBooks(fileName);
        break;
    case DELETE:
        char artistName[LEN];
        inputName(artistName);
        deleteBookByAuthor(fileName, artistName);
        break;
    case SORT:
        sortBooksByRating(fileName);
        break;
    default:
        break;
    }
}

int checkData(int p) {
    return p > 0;
}

void getBookDetails(Book* book) {
    printf("Input book name: ");
    fgets(book->name, LEN, stdin);
    printf("Input author name: ");
    fgets(book->author, LEN, stdin);

    int temp = 0;
    while(temp == 0) {
        printf("Input pages: ");
        if((scanf("%d", &book->pages) == 1) && checkData(book->pages)) {
            temp = 1;
        } else {
            printIncorrectInput();
            while(getchar() != '\n');
        }
    }
    temp = 0;
    while(temp == 0) {
        printf("Input book rank: ");
        if((scanf("%d", &book->rank) == 1) && checkData(book->rank)) {
            temp = 1;
        } else {
            printIncorrectInput();
            while(getchar() != '\n');
        }
    }
}

void sortBooks(Book* booksArray, int structCount) {
    for (int i = 0; i < structCount - 1; i++) {
        for (int j = i + 1; j < structCount; j++) {
            if (booksArray[i].rank > booksArray[j].rank) {
                swap(&booksArray[i], &booksArray[j]);
            }
        }
    }
}
