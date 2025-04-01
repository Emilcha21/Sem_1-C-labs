#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include <stdio.h>
#include "book.h"

FILE* openFileRMode(const char* fileName);
FILE* openFileWMode(const char* fileName);
FILE* openFileAMode(const char* fileName);
int countLines(FILE* file);
void writeBookToFile(FILE* file, const Book* book);
void writeBooksToFile(const char* fileName, Book* booksArray, int structCount);
Book* readBooksFromFile(FILE* file, int structCount);

#endif // FILE_OPERATIONS_H
