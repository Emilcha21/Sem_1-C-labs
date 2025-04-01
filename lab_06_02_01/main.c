#include <stdio.h>
#include <stdlib.h>

enum {
    CORRECT_INPUT = 2
};

enum ProgramStatus {
    CORRECT_WORK,
    INCORRECT_WORK
};


enum ProgramStatus findSolution();
int readSize(int* n, int* m);
int checkInput(int n, int m);
int** allocMat(int n, int m);
int fillMat(int** mat, int n, int m);
void printMat(int** mat, int n, int m);
void transform(int** mat, int* vec, int n, int m);
void freeAllocMat(int** mat);
void freeArr(int* arr);
void swap(int* a, int* b);
void printIncorrectInput();
void changeMat(int** mat, int n, int m);
int* findFirstMax(int** mat, int n, int m);
int findSumAboveDiagMN(int** mat, int n);
int findSumAboveDiagNM(int** mat, int n, int m);


int main() {
    return findSolution();
}

enum ProgramStatus findSolution() {
    enum ProgramStatus workStatus = INCORRECT_WORK;
    int n, m;
    if (readSize(&n, &m) && checkInput(n, m)) {
        int** mat = allocMat(n, m);
        if (mat != NULL) {
            if(fillMat(mat, n, m)) {
                changeMat(mat, n, m);
                printMat(mat, n, m);
                workStatus = CORRECT_WORK;
            }
            freeAllocMat(mat);
        } else {
            printIncorrectInput();
        }
    } else {
       printIncorrectInput();
    }
    return workStatus;
}

void changeMat(int** mat, int n, int m) {
    int* max = findFirstMax(mat, n, m);
    if(max != NULL) {
        n > m ? *max = findSumAboveDiagNM(mat, n, m) : (*max = findSumAboveDiagMN(mat, n));
    }
}

int* findFirstMax(int** mat, int n, int m) {
    int max = **mat;
    int* ptr = 0;
    for (int i = 0; i < n * m; i++) {
        if(*(*(mat) + i) > max) {
            max = *(*(mat) + i);
            ptr = *mat + i;
        }
    }
    return ptr;
}

int findSumAboveDiagMN(int** mat, int n) {
    int sum = 0, rowCount = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - rowCount; j++) {
            sum += mat[i][j];
        }
        rowCount++;
    }
    return sum;
}

int findSumAboveDiagNM(int** mat, int n, int m) {
    int sum = 0, rowCount = 1;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < rowCount; j++) {
            sum += mat[i][j];
        }
        if (rowCount < m) {
            rowCount++;
        }
    }
    return sum;
}

int readSize(int* n, int* m) {
    return scanf("%d %d", n, m) == CORRECT_INPUT;
}

int checkInput(int n, int m) {
    return n >= 0 && m >= 0;
}

void transform(int** mat, int* vec, int n, int m) {
    for (int i = 0; i < n; i++)
        mat[i] = vec + i * m;
}

int** allocMat(int n, int m) {
    int** mat = NULL;
    if(n != 0 && m != 0) {
        mat = (int**)calloc(n, sizeof(int*));
    }
    if (mat != NULL) {
        int* vec = (int*)calloc(n * m, sizeof(int));
        if (vec != NULL) {
            transform(mat, vec, n, m);
        } else {
            freeAllocMat(mat);
            mat = NULL;
        }
    }
    return mat;
}

int fillMat(int** mat, int n, int m) {
    int readValues = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            readValues += scanf("%d", mat[i] + j);
        }
    }
    return n * m == readValues;
}

void printMat(int** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void printIncorrectInput() {
    printf("Incorrect input");
}

void freeAllocMat(int** mat) {
    free(*mat);
    free(mat);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
