#include "lineOperations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* openFileForReading(const char* fileName) {
    return fopen(fileName, "r");
}

FILE* openFileForWriting(const char* fileName) {
    return fopen(fileName, "w");
}

void closeFile(FILE* file) {
    fclose(file);
}

int checkFileExists(const char* fileName) {
    FILE *file = openFileForReading(fileName);
    int isOpen = (file != NULL);
    if (isOpen)
        fclose(file);
    return isOpen;
}

int countTotalLines(FILE* file) {
    rewind(file);
    int lineCount = 0;
    char c;
    do {
        c = getc(file);
        if (c == '\n')
            lineCount++;
    } while (c != EOF);
    rewind(file);
    c = getc(file);
    if (c != EOF && lineCount == 0)
        lineCount++;
    rewind(file);
    return lineCount;
}


void readFileLines(FILE* file, int lineCount, char** lines) {
    int maxSize = countMaxLineLength(file) + 3;
    char buffer[maxSize];
    int count = 0;
    while (count < lineCount && fgets(buffer, sizeof(buffer), file) != NULL) {
        lines[count] = (char*)calloc(strlen(buffer) + 1, sizeof(char));
        if (lines[count] == NULL) {
            fclose(file);
            break;
        }
        strcpy(lines[count], buffer);
        count++;
    }
}

void writeDataToFile(char** lines, int lineCount, FILE* outputFile) {
    for (int i = 0; i < lineCount; i++) {
        fputs(lines[i], outputFile);
    }
}
