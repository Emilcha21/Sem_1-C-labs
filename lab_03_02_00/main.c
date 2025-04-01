#include <stdio.h>
#include <math.h>

enum {
    COEFFICCIENT_2 = 2,
    COEFFICCIENT_3,
};

enum ProgramOutput {
    CORRECT_WORK,
    INCORRECT_WORK,
};

enum {
    CORRECT_IN = 3
};

double defineFunc(double arg);
double calculationIntegral(double a, double b, double n);
int readVal(double* a, double* b, double* e);
int checkIncorrectData(double a, double b, double e);
enum ProgramOutput findSolution();
double findStep(double a, double b, int n);
double findSum(double a, double b);
double searchNextX(double arg, int stepCounter, double step);
double findLastIntegral(double a, double b, double e);
void printAnsw(double a, double b, double e);

int main() {
    return findSolution();
}

void printIncorrectInput() {
    printf("Incorrect input\n");
}

double findLastIntegral(double a, double b, double e) {
    int n = 1;
    double integralFirst = calculationIntegral(a, b, n);
    double integralSecond = 0;
    double integralDifference = 0;
    do {
        n *= COEFFICCIENT_2;
        integralSecond = calculationIntegral(a, b, n);
        integralDifference = integralSecond - integralFirst;
        integralFirst = integralSecond;
    } while(fabs(integralDifference) > e);

    return integralSecond;
}

enum ProgramOutput findSolution() {
    double a = 0, b = 0, e = 0;
    enum ProgramOutput workStatus = CORRECT_WORK;
    if(readVal(&a,&b,&e) && checkIncorrectData(a, b, e)) {
        float answer = findLastIntegral(a, b, e);
        printf("%.6lf\n", answer);
    } else {
        printIncorrectInput();
        workStatus = INCORRECT_WORK;
    }
    return workStatus;
}

int readVal(double* a, double* b, double* e) {
    return (scanf("%lf %lf %lf", a, b, e) == CORRECT_IN);
}

int checkIncorrectData(double a, double b, double e) {
    return (a > 0 && b >= 0 && e > 0 );
}

double defineFunc(double arg) {
    return log(arg);
}

double calculationIntegral(double a, double b, double n) {
    double step = (b - a) / n;
    double sum = defineFunc(a) + defineFunc(b);

    for(int i = 1; i < n; i++) {
        double x = a + i * step;
        double mod = (i % COEFFICCIENT_2);
        double k = COEFFICCIENT_2 + COEFFICCIENT_2 * mod;
        sum += k * defineFunc(x);
    }
    sum *= step / COEFFICCIENT_3;

    return sum;
}
