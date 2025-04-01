#include <stdio.h>
#include <math.h>

#define EPS 0.000001

enum ProgramOutput {
    CORRECT_WORK,
    INCORRECT_WORK,
};

enum {
    CORRECT_IN = 2
};

enum LinePos {
    UNDER_LINE = - 1,
    ON_LINE,
    ABOVE_LINE
};

float countEquation(float x, float y);
int correctReadVal(float* x, float* y);
enum LinePos definePointPos(float equation);
void printByeMess(int x);
enum ProgramOutput findSolution();
void printHelloMess();

int main() {
    return findSolution();
}

void printHelloMess() {
    printf("Line equation: y = 0.5x + 1\n");
    printf("Enter point coordinates:\n");
}

void printIncorrectInput() {
    printf("Incorrect input\n");
}

enum ProgramOutput findSolution() {
    float x = 0, y = 0;
    enum ProgramOutput workStatus = CORRECT_WORK;
    float equation = countEquation(x, y);
    if(correctReadVal(&x, &y)) {
        definePointPos(equation);
        printByeMess(x);
    } else {
        printIncorrectInput();
        workStatus = INCORRECT_WORK;
    }
    return workStatus;
}

int correctReadVal(float* x, float* y) {
    return(scanf("%f %f", x, y) == CORRECT_IN);
}

float countEquation(float x, float y) {
    return 0.5 * x + 1 - y;
}

enum LinePos definePointPos(float equation) {
    enum LinePos pointPos = ON_LINE;
    if(fabs(equation) < EPS) {
        pointPos = ON_LINE;
    } else if(equation < 0) {
        pointPos = ABOVE_LINE;
    } else {
        pointPos = UNDER_LINE;
    }
    return pointPos;
}

void printByeMess(enum LinePos x) {
    switch(x) {
    case ON_LINE:
        printf("Point is on the line\n");
        break;
    case ABOVE_LINE:
        printf("Point is above the line\n");
        break;
    default:
        printf("Point is under the line\n");
        break;
    }
}
