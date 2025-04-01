#include <math.h>
#include <stdio.h>

enum ProgramOutput {
    CORRECT_WORK,
    INCORRECT_WORK
};

enum {
    CORRECT_IN = 1
};

int readVal(float* e);
void printSumSequence(float e);
enum ProgramOutput findSolution();
void printIncorrectInput();
float countSumSequence(float e);
int checkIncorrectData(float e);


int main() {
    return findSolution();
}

void printIncorrectInput() {
    printf("Incorrect input\n");
}

enum ProgramOutput findSolution() {
    float e = 0;
    enum ProgramOutput workStatus = CORRECT_WORK;
    if(readVal(&e) && checkIncorrectData(e)) {
        float answer = countSumSequence(e);
        printf("%.6f\n", answer);
    } else {
        printIncorrectInput();
        workStatus = INCORRECT_WORK;
    }
    return workStatus;
}

float countSumSequence(float e) {
    float sum = 0;
    float sequenceMember = 1;
    int n = 0;

    while(fabs(sequenceMember) > e) {
        sum += sequenceMember;
        n++;
        sequenceMember *= -1;
        sequenceMember /= n;
    }
    sum += sequenceMember;
    return sum;
}

int readVal(float* e) {
    return ((scanf("%f", e) == CORRECT_IN));
}

int checkIncorrectData(float e) {
    return e > 0;
}

