#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void freeLinesArray(char** lines) {
    for (int i = 0; lines[i] != NULL; i++) {
        free(lines[i]);
    }
    free(lines);
}

int removeBlankLines(char** lines, int lineCount) {
    int newCount = 0;

    for (int i = 0; i < lineCount; i++) {
        if (strlen(lines[i]) != 1) {
            lines[newCount++] = lines[i];
        } else {
            free(lines[i]);
            lines[i] = NULL;
        }
    }
    return newCount;
}

void numberLines(char** lines, int lineCount) {
    for (int i = 0; i < lineCount; i++) {
        char *currentLine = lines[i];
        char* numberedLine = (char*)calloc(strlen(lines[i]) + 1, sizeof(char));
        sprintf(numberedLine, "%d. ", i + 1);
        strcat(numberedLine, currentLine);
        strcpy(lines[i], numberedLine);
        free(numberedLine);
    }
}

int countMaxLineLength(FILE* file) {
    rewind(file);
    int curr_len = 1, max_len = 1;
    char c;

    do {
        c = getc(file);
        curr_len++;

        if (c == '\n')
            curr_len = 1;

        if (curr_len > max_len)
            max_len = curr_len;
    }
    while (c != EOF);
    rewind(file);
    return max_len;
}
