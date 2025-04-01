#include "logicOperation.h"
#include "fileOperations.h"
#include "lineOperations.h"
#include "printio.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findSolution() {
    enum ProgramStatus status = ERROR;
    char inputFileName[MAX_SIZE];
    if (getInputFilePath(inputFileName) && checkFileExists(inputFileName)) {
        FILE* inputFile = openFileForReading(inputFileName);
        if (inputFile != NULL) {
            int totalLines = countTotalLines(inputFile);
            if (totalLines) {
                char** fileLines = allocateLinesArray(totalLines);
                readFileLines(inputFile, totalLines, fileLines);
                closeFile(inputFile);
                totalLines = removeBlankLines(fileLines, totalLines);
                numberLines(fileLines, totalLines);
                char outputFileName[MAX_SIZE];
                getInputFilePath(outputFileName);
                FILE* outputFile = openFileForWriting(outputFileName);
                if (outputFile != NULL)
                    writeDataToFile(fileLines, totalLines, outputFile);
                printLines(fileLines, totalLines);
                freeLinesArray(fileLines);
            } else
                printEmptyFileMessage();
            status = CORRECT;
        } else
            printFileNotFoundMessage();
    } else
        printFileNotFoundMessage();
    return status;
}

char** allocateLinesArray(int lineCount) {
    return (char**)calloc(lineCount, sizeof(char*));
}
