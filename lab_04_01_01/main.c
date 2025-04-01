#include <stdio.h>
#include <stdlib.h>

enum {
    INCORRECTFILL,
    CORRECTFILL
};

enum Programoutput {
    INCORRECTSIZE = -1,
    CORRECTWORK,
    INCORRECTWORK
};

enum {
    CORRECTIN = 1
};

int checkValues(int size);
int readValues(int* size);
enum Programoutput logicProcessing();
void printIncorrectMessage();
int* allocMassive(int size);
int fillArray(int* array, int size);
int checkCorrectness(int* lastZero);
float countAverage(int* lastZero, int* maxValue);
int* findMaximum(int* array, int size);
int* findZero(int* array, int size);
void findSolution(int* array, int size);

int main() {
    return logicProcessing();
}

void printIncorrectMessage(){
    printf("Incorrect input\n");
}

enum Programoutput logicProcessing() {
    enum Programoutput workStatus = CORRECTWORK;
    int size = 0;
    int* array = NULL;
    if(readValues(&size) && checkValues(size)) {
        array = allocMassive(size);
        if(array == NULL) {
            printIncorrectMessage();
            workStatus = INCORRECTWORK;
        }
        else if(fillArray(array, size)) {
            findSolution(array, size);
        }else{
            printIncorrectMessage();
            workStatus = INCORRECTWORK;
        }
        free(array);
    } else {
        printIncorrectMessage();
        workStatus = INCORRECTWORK;
    }
    return workStatus;
}

void findSolution(int* array, int size) {
    int* lastZero = findZero(array, size);
    int* maxValue = findMaximum(array, size);

    if(checkCorrectness(lastZero)) {
        printf("%d\n", 0);
    } else {
        float average = countAverage(lastZero, maxValue);
        printf("%.3f", average);
    }
}

int checkValues(int size) {
    return size > 0;
}

int readValues(int* size) {
    return(scanf("%d", size) == CORRECTIN);
}

int* allocMassive(int size) {
    return(int*)malloc(size * sizeof(int));
}

int fillArray(int* array, int size) {
    int temp = 0;
    for(int i = 0; i < size; i++) {
        temp += scanf("%d", (array + i));
    }
    return temp == size;
}

int *findMaximum(int* array, int size) {
    int* max = array;
    for(int i = 0; i < size; i++) {
        if(array[i] > *max) {
            max = array + i;
        }
    }
    return max;
}

int* findZero(int* array, int size) {
    int* zero = NULL;
    for(int i = 0; i < size; i++) {
        if(array[i] == 0) {
            zero = array + i;
        }
    }
    return zero;
}

int checkCorrectness(int* lastZero) {
    return(lastZero == NULL);
}

float countAverage(int* lastZero, int* maxValue) {
    float mathResult = 0;
    float sum = 0;
    float counter = 0;
    if(maxValue < lastZero) {
        for(int* i = lastZero - 1; maxValue <= i; i--) {
            sum += *i;
            counter ++;
        }
    }else{
        for(int* i = lastZero + 1; i <= maxValue; i++) {
            sum += *i;
            counter ++;
        }
    }
    mathResult = sum / counter;

    return counter > 0 ? mathResult : 0;
}
