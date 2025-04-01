#include "book.h"
#include "menu.h"
#include "utils.h"
#include "logicOperations.h"
#include <stdio.h>

int calculateResult() {
    enum ProgramStatus status = CORRECT;
    char fileName[LEN] = "Books.txt";
    int action = 0;
    doProgramLogic(action, fileName);
    return status;
}

void doProgramLogic(int action, char* fileName) {
    while (action != EXIT) {
        showMenu();
        if (scanf("%d", &action) != 1) {
            enterNumberPlease();
            getchar();
            clearBuffer();
        }
        switchFunc(action, fileName);
    }
}
