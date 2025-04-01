TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c11
QMAKE_CFLAGS += -Werror


SOURCES += \
        allocio.c \
        logicOperations.c \
        main.c \
        printio.c \
        student.c

HEADERS += \
    allocio.h \
    logicOperations.h \
    printio.h \
    student.h
