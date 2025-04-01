#include "book.h"
#include "fileOperations.h"
#include <stdio.h>
#include <stdlib.h>

void writeBookToFile(FILE* file, const Book* book) {
    fputs(book->name, file);
    fputs(book->author, file);
    fprintf(file, "%d\n", book->pages);
    fprintf(file, "%d\n", book->rank);
}

void writeBooksToFile(const char* fileName, Book* booksArray, int structCount) {
    FILE* fileO = openFileWMode(fileName);
    for (int i = 0; i < structCount; i++) {
        writeBookToFile(fileO, &booksArray[i]);
    }
    fclose(fileO);
}

Book* readBooksFromFile(FILE* file, int structCount) {
    Book* booksArray = (Book*)calloc(structCount, sizeof(Book));
    for (int i = 0; i < structCount; i++) {
        fgets(booksArray[i].name, LEN, file);
        fgets(booksArray[i].author, LEN, file);
        char book[LEN];
        fgets(book, LEN, file);
        booksArray[i].pages = atoi(book);
        fgets(book, LEN, file);
        booksArray[i].rank = atoi(book);
    }
    return booksArray;
}

int countLines(FILE* file) {
    rewind(file);
    int line_count = 0;
    char c;

    do {
        c = getc(file);
        if (c == '\n')
            line_count++;
    } while (c != EOF);

    rewind(file);
    c = getc(file);
    if (c != EOF && line_count == 0)
        line_count++;
    rewind(file);
    return line_count;
}

FILE* openFileRMode(const char* fileName) {
    return fopen(fileName, "r");
}

FILE* openFileWMode(const char* fileName) {
    return fopen(fileName, "w");
}

FILE* openFileAMode(const char* fileName) {
    return fopen(fileName, "a");
}
