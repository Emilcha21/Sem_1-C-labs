#ifndef LOGICOPERATION_H
#define LOGICOPERATION_H

enum {
    MAX_SIZE = 256,
};

enum ProgramStatus {
    CORRECT,
    ERROR
};

int findSolution();
char** allocateLinesArray(int lineCount);

#endif // LOGICOPERATION_H
