#ifndef ALLOCIO_H
#define ALLOCIO_H

struct Student* allocateStudentArray(int n);
int reallocArray(struct Student** array, int* count);

#endif
