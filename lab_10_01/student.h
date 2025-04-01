#ifndef STUDENT_H
#define STUDENT_H

enum {
    CORRECT_INPUT= 1,
    FAIL,
    MARKS = 4,
    SIZE = 100,
};

struct Student {
    char surname[SIZE];
    char group;
    int marks[MARKS];
    float avgMark;
};

int findSolution();
int getStudentCount(int* n);
void printIncorrectInput();
struct Student* allocateStudentArray(int n);
int inputStudentSurname(struct Student* arr, int k);
int getStudents(struct Student* arr, int n);
int inputStudentMarks(struct Student* arr, int k);
int inputStudent(struct Student* array, int index);
void printStudents(struct Student* arr, int n);
void assignGroup(struct Student* arr, int k);
void sortByGroup(struct Student* array, int count);
void sortByAverageMark(struct Student* array, int count);
int hasGroup(struct Student* array, int count, char group);
void swapStudents(struct Student* pa, struct Student* pb);
void sortStudentData(struct Student* arr, int n);
void sortBySurname(struct Student* array, int count);
void clearBuffer();
void displayGroup(struct Student* arr, char group, int count);
void compareSurnames(struct Student* arr, int k, int n);
unsigned stringLength(const char* str);
void printSurname(struct Student* array, int index);
void printMarks(struct Student* array, int index);
void displayStudents(struct Student* arr, int n);

#endif // STUDENT_H
