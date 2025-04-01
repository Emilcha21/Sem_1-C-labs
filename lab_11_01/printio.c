#include <stdio.h>

void printFileNotFoundMessage() {
    printf("File not found\n");
}

void printEmptyFileMessage() {
    printf("Empty file\n");
}

int getInputFilePath(char* filePath) {
    return scanf("%s", filePath) == 1;
}

void printLines(char** lines, int count) {
    for (int i = 0; i < count; i++) {
        printf("%s", lines[i]);
    }
}
