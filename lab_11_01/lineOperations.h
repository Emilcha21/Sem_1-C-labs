#ifndef LINEOPERATIONS_H
#define LINEOPERATIONS_H

#include <stdio.h>
int removeBlankLines(char** lines, int lineCount);
void freeLinesArray(char** lines);
void numberLines(char** lines, int lineCount);
int countMaxLineLength(FILE* file);

#endif // LINEOPERATIONS_H
