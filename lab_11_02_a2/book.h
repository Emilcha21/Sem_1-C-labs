#ifndef BOOK_H
#define BOOK_H

enum Action {
    ADD = 1,
    LIST,
    DELETE,
    SORT,
    EXIT,
    LEN = 255
};

typedef struct {
    char name[LEN];
    char author[LEN];
    int pages;
    int rank;
} Book;

enum ProgramStatus {
    CORRECT,
    INCORRECT
};

int calculateResult();
void doProgramLogic(int action, char fileName[LEN]);

#endif // BOOK_H
