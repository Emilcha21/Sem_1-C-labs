#include <stdio.h>
#include <math.h>
#define EPS 0.000001

enum ProgramOutput {
    CORRECT_WORK,
    INCORRECT_WORK
};

enum {
    CORRECT_IN = 2
};

enum {
    FIRST = 1,
    SECOND,
    THIRD
};

enum {
    ON_ONE_LINE = 1,
    ON_TWO_LINE
};

enum Area {
    AREA_0,
    AREA_1,
    AREA_2,
    AREA_3,
    AREA_4,
    AREA_5,
    AREA_6,
    AREA_7
};

float countEquation1(float x, float y);
float countEquation2(float x, float y);
float countEquation3(float x, float y);
int sumOnLine(int l1, int l2, int l3);
enum ProgramOutput findSolution();
enum Area checkRegion(float line1, float line2, float line3);
int checkOnLine(float line);
int correctReadVal(float* x, float* y);
void printHelloMess();
void printIncorrectInput();
void printPosInf(float x, float y);

int main() {
    return findSolution();
}

void printHelloMess() {
    printf("Line equations:\ny = 2x + 2\ny = -x + 2\ny = 0.5x - 1\nEnter point coordinates:\n");
}

void printIncorrectInput() {
    printf("Incorrect input\n");
}

int correctReadVal(float* x, float* y) {
    return (scanf("%f %f", x, y) == CORRECT_IN);
}

float countEquation1(float x, float y) {
    return 2 * x + 2 - y;
}
float countEquation2(float x, float y) {
    return 0.5 * x - 1 - y;
}
float countEquation3(float x, float y) {
    return -1 * x + 2 - y;
}

enum ProgramOutput findSolution() {
    float x = 0, y = 0;
    enum ProgramOutput workStatus = CORRECT_WORK;
    if(correctReadVal(&x, &y)) {
        printPosInf(x, y);
    } else {
        printIncorrectInput();
        workStatus = INCORRECT_WORK;
    }
    return workStatus;
}

void printPosInf(float x, float y) {
    float line1 = countEquation1(x, y);
    float line2 = countEquation2(x, y);
    float line3 = countEquation3(x, y);
    int online1 = checkOnLine(line1);
    int online2 = checkOnLine(line2);
    int online3 = checkOnLine(line3);
    int pointPos = sumOnLine(online1, online2, online3);
    int region = checkRegion(line1, line2, line3);

    switch(pointPos) {
    case ON_ONE_LINE:
        printf("Point placed on line %d\n",
               online1 ? FIRST : (online2 ? SECOND : THIRD));
        break;
    case ON_TWO_LINE:
        printf("Point placed on lines %d and %d\n",
               (online1 && online2) ? FIRST : ((online1 && online3) ? FIRST : SECOND),
               (online1 && online2) ? SECOND : ((online1 && online3) ? THIRD : THIRD));
        break;
    default:
        printf("Point placed in region %d\n", region);
        break;
    }
}

int checkOnLine(float line) {
    return fabs(line) < EPS;
}

int sumOnLine(int l1, int l2, int l3) {
    return l1 + l2 + l3;
}

enum Area checkRegion(float line1, float line2, float line3) {
    enum Area area = AREA_0;
    if(0 < line1 && 0 > line2 && 0 > line3)
        area = AREA_1;
    else if(0 < line1 && 0 < line2 && 0 > line3)
        area = AREA_2;
    else if(0 < line1 && 0 < line2 && 0 < line3)
        area = AREA_3;
    else if(0 > line1 && 0 < line2 && 0 < line3)
        area = AREA_4;
    else if(0 > line1 && 0 > line2 && 0 < line3)
        area = AREA_5;
    else if(0 > line1 && 0 > line2 && 0 > line3)
        area = AREA_6;
    else if(0 < line1 && 0 > line2 && 0 < line3)
        area = AREA_7;
    return area;
}
