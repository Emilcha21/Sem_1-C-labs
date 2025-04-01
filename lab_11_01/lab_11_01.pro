TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        condition.c \
        fileOperations.c \
        lineOperations.c \
        logicOperation.c \
        main.c \
        printio.c

HEADERS += \
    fileOperations.h \
    lineOperations.h \
    logicOperation.h \
    printio.h
