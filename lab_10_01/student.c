#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Status {
    CORRECT_WORK,
    INCORRECT_WORK
};

int findSolution() {
    enum Status progStatus = INCORRECT_WORK;
    int totalStudents = 0;
    if (getStudentCount(&totalStudents) && totalStudents > 0) {
        struct Student* studentArray = allocateStudentArray(totalStudents);
        if (studentArray != NULL) {
            if (getStudents(studentArray, totalStudents)) {
                sortStudentData(studentArray, totalStudents);
                printStudents(studentArray, totalStudents);
                progStatus = CORRECT_WORK;
            } else {
                printIncorrectInput();
            }
            free(studentArray);
        } else {
            printIncorrectInput();
        }
    } else {
        printIncorrectInput();
    }
    return progStatus;
}

int getStudentCount(int* count) {
    return scanf("%d", count) == 1;
}

void printIncorrectInput() {
    printf("Incorrect input\n");
}

struct Student* allocateStudentArray(int count) {
    return (struct Student*)calloc(count, sizeof(struct Student));
}

int inputStudentSurname(struct Student* array, int index) {
    scanf("%s", array[index].surname);
    clearBuffer();
    return 1;
}

void clearBuffer() {
    int character;
    while ((character = getchar()) != '\n' && character != EOF);
}

int inputStudentMarks(struct Student* array, int index) {
    int markCount = 0;
    for (markCount = 0; markCount < 4; markCount++) {
        if (scanf("%d", &array[index].marks[markCount]) != 1 ||
            array[index].marks[markCount] < 2 ||
            array[index].marks[markCount] > 5) {
            clearBuffer();
            return 0;
        }
    }
    clearBuffer();
    return markCount == 4;
}

void assignGroup(struct Student* array, int index) {
    int lowestMark = 5;
    for (int i = 0; i < 4; i++) {
        if (array[index].marks[i] < lowestMark)
            lowestMark = array[index].marks[i];
    }
    switch (lowestMark) {
    case 5: array[index].group = 'A';
        break;
    case 4: array[index].group = 'B';
        break;
    case 3: array[index].group = 'C';
        break;
    default: array[index].group = 'D';
        break;
    }
}

int getStudents(struct Student* array, int count) {
    int temp = 1;
    for (int i = 0; i < count; i++) {
        if (!inputStudentSurname(array, i) || !inputStudentMarks(array, i)) {
            temp = 0;
            break;
        }
        assignGroup(array, i);
    }
    return temp;
}

void sortStudentData(struct Student* array, int count) {
    sortByGroup(array, count);
    sortBySurname(array, count);
}

void sortByGroup(struct Student* array, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (array[i].group > array[j].group) {
                swapStudents(array + i, array + j);
            }
        }
    }
}

void sortBySurname(struct Student* array, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (array[i].group == array[j].group) {
                compareSurnames(array, i, j);
            }
        }
    }
}

void compareSurnames(struct Student* array, int index1, int index2) {
    int length1 = stringLength(array[index1].surname);
    int length2 = stringLength(array[index2].surname);
    int validation = strcmp(array[index1].surname, array[index2].surname);

    if(validation > 0) {
        swapStudents(array + index1, array + index2);
    }
    if(validation == 0 && length1 > length2) {
        swapStudents(array + index1, array + index2);
    }
}

void printStudents(struct Student* array, int count) {
    for (char group = 'A'; group <= 'D'; group++) {
        if (hasGroup(array, count, group)) {
            displayGroup(array, group, count);
        }
    }
}

void displayGroup(struct Student* array, char group, int count) {
    printf("%c-students:\n", group);
    for (int i = 0; i < count; i++) {
        if (array[i].group == group) {
            printSurname(array, i);
            printMarks(array, i);
        }
    }
    printf("\n");
}

int hasGroup(struct Student* array, int count, char group) {
    for (int i = 0; i < count; i++) {
        if (array[i].group == group) {
            return 1;
        }
    }
    return 0;
}

unsigned stringLength(const char* str) {
    return strlen(str);
}

void swapStudents(struct Student* student1, struct Student* student2) {
    struct Student temp = *student1;
    *student1 = *student2;
    *student2 = temp;
}

void printSurname(struct Student* array, int index) {
    printf("%s\n", array[index].surname);
}

void printMarks(struct Student* array, int index) {
    for (int i = 0; i < 4; i++) {
        printf("%d ", array[index].marks[i]);
    }
    printf("\n");
}
