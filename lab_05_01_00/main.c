//task: 3 2 1 -3 -2 0 -1 0 --> 1 2 3 -1 -2 -3 0 0

//логика: 3 2 1 -3 -2 0 -1 0 --> -3 -2 -1 0 0 1 2 3 -->
// --> 1 2 3 0 0 -3 -2 -1 --> 1 2 3 -3 -2 -1 0 0
// --> 1 2 3 -1 -2 -3 0 0

#include <stdio.h>
#include <stdlib.h>

enum Programoutput {
    CORRECT_WORK,
    INCORRECT_WORK
};

enum {
    CORRECT_INPUT = 1
};

enum Programoutput findSolution();
int readSize(int* size);
int checkSize(int size);
int fillArray(int* array, int size);
void printSortedArray(int* array, int size);
void swap(int* a, int* b);
void sortArray(int* array, int size, int (*compare)(int, int));
int groupPositive(int* array, int size);
int findFirstZero(int* array, int size);
void groupNegative(int* array, int size);
void printIncorrectMessage();
int compareSortPositive(int a, int b);
int compareSortNegative(int a, int b);

int main() {
    return findSolution();
}

int readSize(int* size) {
    return scanf("%d", size) == CORRECT_INPUT;
}

int checkSize(int size) {
    return size >= 0;
}

void printIncorrectMessage() {
    printf("Incorrect input\n");
}

enum Programoutput findSolution() {
    int size = 0;
    enum Programoutput workStatus = CORRECT_WORK;

    if(readSize(&size) && checkSize(size)) {
        int* array = (int*)malloc(size * sizeof(int));
        if (array != NULL && fillArray(array, size)) {
            sortArray(array, size, compareSortPositive);
            int firstNotPositive = groupPositive(array, size);
            if(firstNotPositive < size) {
                groupNegative(array + firstNotPositive, size - firstNotPositive);
                int firstZero = findFirstZero(array + firstNotPositive, size - firstNotPositive);
                sortArray(array + firstNotPositive, firstZero, compareSortNegative);
            }
            printSortedArray(array, size);
            free(array);
        } else {
            printIncorrectMessage();
            workStatus = INCORRECT_WORK;
            free(array);
        }
    } else {
        printIncorrectMessage();
        workStatus = INCORRECT_WORK;
    }
    return workStatus;
}

int fillArray(int* array, int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        temp += scanf("%d", (array + i));
    }
    return temp == size;
}

void printSortedArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int* array, int size, int (*compare)(int, int)) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(array[j], array[j + 1])) {
                swap(array + j, array + j + 1);
            }
        }
    }
}

int groupPositive(int* array, int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            swap(array + i, array + temp);
            temp++;
        }
    }
    return temp;
}

void groupNegative(int* array, int size) {
    int temp = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            swap(array + i, array + temp);
            temp++;
        }
    }
}

int findFirstZero(int* array, int size) {
    int index = size;
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            index = i;
            break;
        }
    }
    return index;
}

int compareSortPositive(int a, int b) {
    return a > b;
}

int compareSortNegative(int a, int b) {
    return a < b;
}
