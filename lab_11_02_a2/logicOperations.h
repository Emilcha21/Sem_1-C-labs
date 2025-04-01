#ifndef BOOK_OPERATIONS_H
#define BOOK_OPERATIONS_H

#include "book.h"

void addBook(const char* fileName);
void showAllBooks(const char* fileName);
void deleteBookByAuthor(const char* fileName, const char* artistName);
void sortBooksByRating(const char* fileName);
void inputName(char* artistName);
int filterBooksByAuthor(Book* booksArray, int structCount, const char* artistName);
void getBookDetails(Book* book);
void switchFunc(enum Action action, const char* fileName);
void sortBooks(Book* booksArray, int structCount);

#endif // BOOK_OPERATIONS_H
