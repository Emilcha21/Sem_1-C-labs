#ifndef BOOKS_H
#define BOOKS_H

enum {
    LEN = 255
};

enum ProgramStatus {
    CORRECT,
    ERROR
};

enum Action {
    ADD = 1,
    LIST,
    DELETE,
    SORT,
    EXIT
};

typedef struct Book {
    char Name[LEN];
    char Author[LEN];
    int Pages;
    int Rank;
} Book;

#endif // BOOKS_H
