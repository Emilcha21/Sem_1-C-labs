#ifndef PRINTIO_H
#define PRINTIO_H

void printFileNotFoundMessage();
void printEmptyFileMessage();
int getInputFilePath(char* filePath);
void printLines(char** lines, int count);

#endif // PRINTIO_H
