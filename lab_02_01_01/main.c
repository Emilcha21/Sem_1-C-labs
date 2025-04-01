
#include <stdio.h>
#include <math.h>

// Определяем енамы(константы)
// енам не именнован, так как внутри него лежит константа, которую никакая функция в этой программе не вернет
enum {
    MIN_ITERATIONS = 2  // Минимальное количество итераций для корректной работы
};

// Определяем возможные статусы работы программы
// енам не именнован, так как внутри него лежит константы, одну из которых вернет findSolution
enum ProgramOutput {
    CORRECT_WORK,
    INCORRECT_WORK,
};

// Количество корректных значений, считанных из ввода(енам не именнован по той же причине, что и первый)
enum {
    CORRECT_IN = 3
};

// Объявляем функции
enum ProgramOutput findSolution();
int readVal(float* lBord, float* rBord, int* iterations);
int checkIncorrectData(float lBord, float rBord, int iterations);
float searchNextx(float arg, float stepCounter, float step);
float findStep(float lBord, float rBord, int iterations);
void printForTable(float lBord, float rBord, int iterations);
void printWhileTable(float lBord, float rBord, int iterations);
void printDWhileTable(float lBord, float rBord, int iterations);
void printIncorrectInput();
void printXtableArg(float arg);
void printForXtable();
void printWhileXtable();
void printDwhileXtable();
void printFxTable();
void goToNextTable();
void printFxTableFunc(float func);


// Основная функция программы(точка входа)
int main() {
    return findSolution();  // Запуск функции поиска решений
}

// Функция для вывода сообщения об ошибке ввода
void printIncorrectInput() {
    printf("Incorrect input\n");
}

// Функция для форматированного вывода значения аргумента
void printXtableArg(float arg) {
    printf("%6.3f |", arg);
}

// Функция для форматированного вывода значения функции
void printFxTableFunc(float func) {
    if(isnan(func)) {  // Проверка на "NaN"
        printf("  nan  |");
    } else {
        printf("%6.3f |", func);  // Вывод значения с заданным форматом
    }
}

// Функция для вывода заголовка таблицы для цикла for
void printForXtable() {
    printf("\n");
    printf("for:\n");
    printf("x    |");
}

// Функция для вывода заголовка таблицы для цикла while
void printWhileXtable() {
    printf("\n");
    printf("while:\n");
    printf("x    |");
}

// Функция для вывода заголовка таблицы для do-while цикла
void printDwhileXtable() {
    printf("\n");
    printf("do while:\n");
    printf("x    |");
}

// Функция для вывода заголовка для значений функции
void printFxTable() {
    printf("\n");
    printf("f(x) |");
}

// Функция для создания пустого пространства между таблицами
void goToNextTable() {
    printf("\n\n");
}

// Функция для вычисления следующего x на основе шагов
float searchNextx(float arg, float stepCounter, float step) {
    return arg + stepCounter * step;  // Вычисление следующего x
}

// Функция для чтения значений границ и количества итераций
int readVal(float* lBord, float* rBord, int* iterations) {
    return (scanf("%f %f %d", lBord, rBord, iterations) == CORRECT_IN);  // Возвращает 1, если успешно считано 3 значения
}

// Функция для проверки корректности входных данных
int checkIncorrectData(float lBord, float rBord, int iterations) {
    return (lBord < rBord && iterations >= MIN_ITERATIONS);  // Проверка на валидность
}

// Функция поиска решения, которая координирует выполнение
enum ProgramOutput findSolution() {
    float lBord = 0, rBord = 0;
    int iterations = 0;
    enum ProgramOutput workStatus = CORRECT_WORK;  // Начальное состояние работы

    // Проверка ввода и вывод соответствующих таблиц
    if(readVal(&lBord,&rBord,&iterations) && checkIncorrectData(lBord, rBord, iterations)) {
        printForTable(lBord, rBord, iterations);
        printWhileTable(lBord, rBord, iterations);
        printDWhileTable(lBord, rBord, iterations);
    } else {
        printIncorrectInput();  // Вывод сообщения об ошибке
        workStatus = INCORRECT_WORK;
    }

    return workStatus;  // Возврат статуса работы
}

// Функция для нахождения размера шага
float findStep(float lBord, float rBord, int iterations) {
    return (rBord - lBord) / (iterations - 1);  // Вычисление шага
}

// Определение значения функции
float defineFunc(float arg) {
    return tan(arg) * sqrt(arg);  // Пример функции
}

// Функция для вывода таблицы значений для цикла for
void printForTable(float lBord, float rBord, int iterations) {
    float step = findStep(lBord, rBord, iterations);  // Вычисление шага

    printForXtable();  // Заголовок таблицы x
    for(int c = 0; c < iterations; c++) {  // Цикл для вывода x
        float x = searchNextx(lBord, c, step);
        printXtableArg(x);  // Печать значения x
    }

    printFxTable();  // Заголовок таблицы для значений функции
    for(int c = 0; c < iterations; c++) {  // Цикл для вывода значений функции
        float x = searchNextx(lBord, c, step);
        float fx = defineFunc(x);
        printFxTableFunc(fx);  // Печать значения функции
    }
    goToNextTable();  // Переход к следующей таблице
}

// Функция для вывода таблицы значений для цикла while
void printWhileTable(float lBord, float rBord, int iterations) {
    float step = findStep(lBord, rBord, iterations);  // Вычисление шага

    printWhileXtable();  // Заголовок таблицы x
    int c = 0;
    while(c < iterations) {  // Цикл для вывода x
        float x = searchNextx(lBord, c, step);
        printXtableArg(x);
        c++;
    }

    printFxTable();  // Заголовок таблицы для значений функции
    c = 0;
    while(c < iterations) {  // Цикл для вывода значений функции
        float x = searchNextx(lBord, c, step);
        float fx = defineFunc(x);
        printFxTableFunc(fx);
        c++;
    }
    goToNextTable();  // Переход к следующей таблице
}

// Функция для вывода таблицы значений для do-while цикла
void printDWhileTable(float lBord, float rBord, int iterations) {
    float step = findStep(lBord, rBord, iterations);  // Вычисление шага

    printDwhileXtable();  // Заголовок таблицы x
    int c = 0;
    do {
        float x = searchNextx(lBord, c, step);  // Получаем значение x
        printXtableArg(x);  // Печатаем x
        c++;
    } while(c < iterations);  // Цикл конца

    printFxTable();  // Заголовок таблицы для значений функции
    c = 0;
    do {
        float x = searchNextx(lBord, c, step);
        float fx = defineFunc(x);  // Получаем значение функции
        printFxTableFunc(fx);  // Печатаем значение функции
        c++;
    } while(c < iterations);  // Цикл конца
    goToNextTable();  // Переход к следующей таблице
}
