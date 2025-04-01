#ifndef LOGICOPERATIONS_H
#define LOGICOPERATIONS_H

#include "student.h"
typedef int (*Comparator)(const Student*, const Student*);
int getStudents(Student* arr, int n);
int inputStudentMarks(Student* arr, int k);
int inputStudent(Student* array, int index);
int countFailingMarks(Student* array, int index);
void assignGroup(Student* arr, int k);
void sortByGroup(Student* array, int count);
void sortByAverageMark(Student* array, int count);
int hasGroup(Student* array, int count, char group);
void swapStudents(Student* pa, Student* pb);
void sortStudentData(Student* arr, int n);
void sortBySurname(Student* array, int count);
int countDec(Student** array, int* count, int index);
int compareBySurname(const Student* a, const Student* b);
int compareByAverageMark(const Student* a, const Student* b);
int compareByGroup(const Student* a, const Student* b);
unsigned stringLength(const char* str);
void displayStudents(Student* arr, int n);
void computeAverageMark(Student* arr, int k);
void deleteStudents(Student** arr, int* n);
void removeStudent(Student** array, int* count, int index);
float roundToNearestTenth(float value);

#endif // LOGICOPERATIONS_H
