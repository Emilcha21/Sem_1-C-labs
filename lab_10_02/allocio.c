#include "student.h"
#include <stdlib.h>

int reallocArray(Student** array, int* count) {
    int temp = 1;
    Student* tempArray = (Student*)realloc(*array, *count * sizeof(Student));
    if (tempArray != NULL) {
        *array = tempArray;
    } else {
        temp = 0;
    }
    return temp;
}

Student* allocateStudentArray(int count) {
    return (Student*)calloc(count, sizeof(Student));
}
