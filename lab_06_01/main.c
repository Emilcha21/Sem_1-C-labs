#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum Programoutput {
    CORRECT_WORK,
    INCORRECT_WORK
};

enum {
    CORRECT_INPUT = 1
};

int** allocMat(int size);
void freeAllocMat(int** mat, int size);
int fillMat(int** mat, int size);
void printMat(int** mat, int size);
void transposeMat(int** mat, int size);
enum Programoutput findSolution();
void printIncorrectMessage();
void swap(int* a, int* b);

int main() {
    return findSolution();
}

int readSize(int* size) {
    return scanf("%d", size) == CORRECT_INPUT;
}

int checkSize(int size) {
    return size > 0;
}

void printIncorrectMessage() {
    printf("Incorrect input\n");
}

enum Programoutput findSolution() {
    int size = 0;
    int** mat = NULL;
    enum Programoutput workStatus = CORRECT_WORK;

    if(readSize(&size) && checkSize(size)) {
        mat = allocMat(size);
        if (mat != NULL && fillMat(mat, size)) {
            transposeMat(mat, size);
            printMat(mat, size);
            freeAllocMat(mat, size);
        }else {
            printIncorrectMessage();
            workStatus = INCORRECT_WORK;
            freeAllocMat(mat, size);
        }
    } else {
        printIncorrectMessage();
        workStatus = INCORRECT_WORK;
    }
    return workStatus;
}

int** allocMat(int size) {
    int i = 0;
    int** mat = (int**)malloc(size * sizeof(int*));
    if(mat != NULL) {
        for (i = 0; i < size; i++) {
            mat[i] = (int*)malloc(size * sizeof(int));
            if(mat[i] == NULL) {
               freeAllocMat(mat, i);
            }
        }
    } else {
        free(mat);
        mat = NULL;
    }
    return mat;
}

void freeAllocMat(int** mat, int size) {
    if(mat != NULL) {
        for (int i = 0; i < size; i++) {
            free(mat[i]);
        }
        free(mat);
    }
}

int fillMat(int** mat, int size) {
    int temp = 0;
    int checkSize = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            temp += scanf("%d", (mat[i] + j));
        }
    }
    checkSize = sqrt(temp);
    return checkSize == size;
}

void printMat(int** mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void transposeMat(int** mat, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            swap(mat[i] + j, mat[size - j - 1] + (size - i - 1));
        }
    }
}
