#include "student.h"
#include <stdio.h>


void printStudentSurname(Student* array, int index) {
    printf("%s\n", array[index].surname);
}

void printAverageMark(Student* array, int index) {
    printf("%.2f\n", array[index].avgMark);
}

void printStudentMarks(Student* array, int index) {
    for (int i = 0; i < MARKS; i++) {
        printf("%d ", array[index].marks[i]);
    }
    printf("\n");
}

void inputStudentSurname(Student* array, int index) {
    scanf("%s", array[index].surname);
}

void printIncorrectInput() {
    printf("Incorrect input\n");
}

int getStudentCount(int* count) {
    return scanf("%d", count) == CORRECT_INPUT;
}

void displayGroup(Student* array, int count, char group) {
    printf("%c-students:\n", group);
    for (int i = 0; i < count; i++) {
        if (array[i].group == group) {
            printStudentSurname(array, i);
            printStudentMarks(array, i);
            printAverageMark(array, i);
        }
    }
    printf("\n");
}

int inputStudentMarks(Student* array, int index) {
    int markCount = 0;
    int temp = 1;
    for (markCount = 0; markCount < MARKS; markCount++) {
        if (scanf("%d", &array[index].marks[markCount]) != 1) {
            temp = 0;
            break;
        }
        if (array[index].marks[markCount] < 2 || array[index].marks[markCount] > 5) {
            temp = 0;
            break;
        }
    }
    return temp ? markCount == MARKS : 0;
}
