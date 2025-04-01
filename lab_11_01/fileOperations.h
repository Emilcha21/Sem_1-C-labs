#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <stdio.h>
FILE* openFileForReading(const char* fileName);
FILE* openFileForWriting(const char* fileName);
int countTotalLines(FILE* file);
int checkFileExists(const char* fileName);
void writeDataToFile(char** lines, int lineCount, FILE* outpFile);
void closeFile(FILE* file);
void readFileLines(FILE* file, int lineCount, char** lines);
int maxLine(FILE* file);

#endif // FILEOPERATIONS_H
