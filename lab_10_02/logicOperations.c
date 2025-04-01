#include "logicOperations.h"
#include "printio.h"
#include "allocio.h"
#include <stdlib.h>
#include <string.h>

int inputStudent(Student* array, int index) {
    int temp = 1;
    inputStudentSurname(array, index);
    if (!inputStudentMarks(array, index)) {
        temp = 0;
    }
    assignGroup(array, index);
    computeAverageMark(array, index);
    return temp;
}

float roundToNearestTenth(float number) {
    return (int)((number * 10 + 0.5)) / 10.0;
}

void computeAverageMark(Student* array, int index) {
    float totalMarks = 0;
    for (int i = 0; i < MARKS; i++) {
        totalMarks += array[index].marks[i];
    }
    totalMarks /= MARKS;
    totalMarks = roundToNearestTenth(totalMarks);
    array[index].avgMark = totalMarks;
}

void assignGroup(Student* array, int index) {
    int lowestMark = 5;
    for (int i = 0; i < MARKS; i++) {
        if (array[index].marks[i] < lowestMark)
            lowestMark = array[index].marks[i];
    }
    switch (lowestMark) {
    case 5:
        array[index].group = 'A';
        break;
    case 4:
        array[index].group = 'B';
        break;
    case 3:
        array[index].group = 'C';
        break;
    default:
        array[index].group = 'D';
        break;
    }
}

int countFailingMarks(Student* array, int index) {
    int failingCount = 0;
    for (int j = 0; j < MARKS; j++) {
        if (array[index].marks[j] == FAIL) {
            failingCount++;
        }
    }
    return failingCount;
}

int getStudents(Student* array, int count) {
    int temp = 1;
    for (int i = 0; i < count; i++) {
        if (!inputStudent(array, i)) {
            temp = 0;
        }
    }
    return temp;
}

void removeStudent(Student** array, int* count, int index) {
    *count = countDec(array, count, index);

    if (*count > 0) {
        reallocArray(array, count);
    } else {
        free(*array);
        *array = NULL;
    }
}

// man realloc
void deleteStudents(Student** array, int* count) {
    for (int i = 0; i < *count; i++) {
        int failingCount = countFailingMarks(*array, i);
        if (failingCount > 2) {
            removeStudent(array, count, i);
            i--;
        }
    }
}

int countDec(Student** array, int* count, int index) {
    for (int i = index; i < *count - 1; i++) {
        *(*array + i) = *(*array + i + 1);
    }
    (*count)--;
    return *count;
}

int compareByGroup(const Student* a, const Student* b) {
    return a->group - b->group;
}

int compareBySurname(const Student* a, const Student* b) {
    int lengh1 = strlen(a->surname);
    int lengh2 = strlen(a->surname);
    int temp = 0;
    if(strcmp(a->surname, b->surname) > 0) {
        temp = 1;
    }
    if(strcmp(a->surname, b->surname) == 0 && lengh1 > lengh2) {
        temp = 1;
    }
    return temp;
}

int compareByAverageMark(const Student* a, const Student* b) {
    return (a->avgMark < b->avgMark) ? 1 : (a->avgMark > b->avgMark) ? -1 : 0;
}

void sortStudents(Student* array, int count, Comparator cmp) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (cmp(array + i, array + j) > 0) {
                swapStudents(array + i, array + j);
            }
        }
    }
}

void sortStudentData(Student* array, int count) {
    sortStudents(array, count, compareByGroup);
    sortStudents(array, count, compareBySurname);
    sortStudents(array, count, compareByAverageMark);
}

void displayStudents(Student* array, int count) {
    if (hasGroup(array, count, 'A')) {
        displayGroup(array, count, 'A');
    }
    if (hasGroup(array, count, 'B')) {
        displayGroup(array, count, 'B');
    }
    if (hasGroup(array, count, 'C')) {
        displayGroup(array, count, 'C');
    }
    if (hasGroup(array, count, 'D')) {
        displayGroup(array, count, 'D');
    }
}

int hasGroup(Student* array, int count, char group) {
    int temp = 0;
    for (int i = 0; i < count; i++) {
        if (array[i].group == group) {
            temp = 1;
        }
    }
    return temp;
}

void swapStudents(Student* student1, Student* student2) {
    Student temp = *student1;
    *student1 = *student2;
    *student2 = temp;
}
