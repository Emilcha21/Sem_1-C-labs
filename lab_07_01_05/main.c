#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// змейка диагональная (слева-сверху). Допускается реализация только для квадратной матрицы при наличии всех необходимых проверок.
//      Пример:
//      Ввод:

//       3 3
//       1 2 3
//       4 5 6
//       7 8 9


//       Вывод:

//       1 2 6
//       3 5 7
//       4 8 9

enum {
    NOT_CHANGED,
    CHANGED,
    CORRECT_INPUT,
    TEN
};

enum ProgramStatus {
    CORRECT_WORK,
    INCORRECT_WORK
};


enum ProgramStatus findSolution();
int readSize(int* n, int* m);
int checkInput(int n, int m);
int** allocMat(int n, int m);
int fillMat(int** mat, int n);
void printMat(int** mat, int n, int m);
void transform(int** mat, int* vec, int n, int m);
void freeAllocMat(int** mat);
void freeArr(int* arr);
void swap(int* a, int* b);
void getIndex(int diagAmount, int* n, int* m, int arrows);
int* getElem(int** mat, int index, int arrows);
void sortMat(int** mat, int arrows);
void printIncorrectInput();

int main() {
    return findSolution();
}

enum ProgramStatus findSolution() {
    enum ProgramStatus workStatus = INCORRECT_WORK;
    int n = 0, m = 0;
    if (readSize(&n, &m) && checkInput(n, m)) {
        int** mat = allocMat(n, m);
        if (mat != NULL) {
            if(fillMat(mat, n)) {
                sortMat(mat, n);
                printMat(mat, n, m);
                workStatus = CORRECT_WORK;
            } else {
                printIncorrectInput();
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

void getIndex(int diagAmount, int* n, int* m, int arrows) {
    int isChanged = NOT_CHANGED;
    int currentIndex = *n * TEN + *m;
    int currentDiagAmount = *n + *m;
    for (int i = 0; i <= diagAmount && i < arrows; i++) {
        if (isChanged){
            break;
        }
        for (int j = 0; j <= diagAmount && j < arrows; j++) {
            if (diagAmount == (i + j)) {
                if ((diagAmount % 2 == 1) && (diagAmount != currentDiagAmount || (i * TEN + j) > currentIndex)) {
                    *n = i;
                    *m = j;
                    isChanged = CHANGED;
                    break;
                } else if (diagAmount != currentDiagAmount || (i * TEN + j) < currentIndex) {
                    *n = i;
                    *m = j;
                }
            }
        }
    }
}

int* getElem(int** mat, int index, int arrows) {
    int diagAmount = 2 * arrows - 1;
    int* pointer = *mat;
    int n = 0, m = 0, count = 0;
    for (int i = 0; i < diagAmount; i++) {
        for (int j = 0; j <= i && j < diagAmount - i; j++) {
            getIndex(i, &n, &m, arrows);
            if (count == index) {
                pointer = *(mat + n) + m;
            }
            count++;
        }
    }
    return pointer;
}

void sortMat(int** mat, int n) {
    for (int i = 0; i < n * n - 1; i++) {
        for (int j = i + 1; j < n * n; j++) {
            int* first = getElem(mat, i, n);
            int* second = getElem(mat, j, n);
            if(*first > *second){
                swap(first, second);
            }
        }
    }
}

int readSize(int* n, int* m) {
    return scanf("%d %d", n, m) == CORRECT_INPUT;
}

int checkInput(int n, int m) {
    return (n > 0 && m > 0) && n == m;
}

void transform(int** mat, int* vec, int n, int m) {
    for (int i = 0; i < n; i++) {
        mat[i] = vec + i * m;
    }
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

int fillMat(int** mat, int n) {
    int temp = 0;
    int* vec = *mat;
    for (int i = 0; i < n * n; i++) {
        if(scanf("%d", vec + i)) {
            temp++;
        } else {
            break;
        }
    }
    int sqrtTemp = sqrt(temp);
    return sqrtTemp == n;
}

void printMat(int** mat, int n, int m) {
    printf("\n");
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
