// Разработать программу, в составе которой выполняли бы свою работу следующие написанные пользовательские функции:
// Общее условие для всех функций:
// Тип элементов массива на усмотрение разработчика.

// 1. Функция, определяющая среднее арифметическое элементов передаваемого ей
//     массива.
// 2. Функция, определяющая количество положительных, отрицательных и
//     нулевых элементов передаваемого ей массива.
// 3. Функция, определяющая минимальный и максимальный (значение и номер)
//     элементы передаваемого ей массива.
// 4. Функция, меняющая порядок следования элементов передаваемого ей
//     массива на противоположный.
// 5. Функция, возвращающая количество простых чисел в передаваемом ей
//     массиве и выводящая их на экран.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>  // в этом файле содержатся функции rand() и srand() (управление динамическим выделением памяти)
#include <time.h>    // в этом файле содержится функция time()
#include <conio.h>   // в этом файле содержится функция getch()
#include <stdbool.h> // содержится определение логических констант true и false

int main(void);
void dash(int);
void dot(int);
void eatline(void); // читать до конца строки
bool prime_n(int);  // функция проверяет - простое ли число n

double *input_array_keyboard(double *, int, int); // ввод массива числами с клавиатуры (53.86)
double *input_array_random(double *, int, int);   // Ввод массива числами   рандомными (53.86)
void output_array(double *, int, int);            // вывод массива                     (53.86)

int *input_array_keyboard(int *, int, int); // ввод массива числами с клавиатуры (53)
int *input_array_random(int *, int, int);   // Ввод массива числами   рандомными (53)
void output_array(int *, int, int);         // вывод массива                     (53)

// 1. Функция, определяющая среднее арифметическое элементов передаваемого ей массива.
void mean_array(double *, int, int);
// 2. Функция, определяющая количество положительных, отрицательных и нулевых
//    элементов передаваемого ей массива.
void plus_mines_zero_array(double *, int, int);
// 3. Функция, определяющая минимальный и максимальный (значение и номер) элементы
//    передаваемого ей массива.
void min_max_array(double *, int, int);
// 4. Функция, меняющая порядок следования элементов передаваемого ей
//    массива на противоположный.
void reverse_array(double *, int, int);
// 5. Функция, возвращающая количество простых чисел в передаваемом ей
//    массиве и выводящая их на экран.
int prime_n_array(int *, int, int);

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double *array = NULL;
    int *p_n_array = NULL;
    int n;
    int m;
    char repeat;
    int option = 0;
    int menu_number = 0;
    bool go_back = true;
    do
    {
        system("cls");
        printf(" ***| Программа работы с функциями в массиве | ***\n\n");
        printf(" ___________| Главное меню |_____________________________________________\n");
        printf("   Выберите ФУНКЦИЮ для работы:\n");
        printf(" 1:Определяющая среднее арифметическое элементов передаваемого ей массива.\n");
        printf(" 2:Определяющая количество положительных, отрицательных и нулевых\n"
               "   элементов передаваемого ей массива.\n");
        printf(" 3:Определяющая минимальный и максимальный (значение и номер) элементы\n"
               "   передаваемого ей массива. \n");
        printf(" 4:Функция, изменяющая порядок следования элементов передаваемого ей\n"
               "   массива на противоположный.\n");
        printf(" 5:Функция, возвращающая количество простых чисел в передаваемом ей\n"
               "   массиве и выводящая их на экран.\n");
        printf(" 6: | ВыхоД |\n\n>");
        scanf_s("%d", &menu_number);
        eatline();
        switch (menu_number)
        {
        case 1:
            do
            {
                dash(75);
                printf("\n _______| Выбран 1 пункт меню |_______\n");
                printf("\n   Выберите действие:\n");
                printf(" 1:Задать массив для работы с функцией.\n");
                printf(" 2:Тест работы функции в заданном массиве.\n");
                printf(" 3: | Отмена |\n");
                do
                {
                    printf("\n Действие >");
                    scanf_s("%d", &option);
                    eatline();       // удаление оставшейся части строки
                    if (option == 3) // отмена
                        dash(75);
                    else
                    {
                        if (option != 1 && option != 2)
                        {
                            printf("\n Некорректный ввод (Действие = 3 -отмена).");
                            printf("\n Пожалуйста сделайте выбор.");
                        }
                        else if (option == 1) // задать массив с клавиатуры
                        {
                            printf("\n ___| Выбрано 1 действие |___\n");
                            printf("\n Задайте двумерный массив порядка N*M:");
                            printf("\n Количество строк (N) и столбцов (M) должно быть не меньше 3 и не больше 7.\n");
                            do
                            {
                                printf("\n Введите количество строк в массиве = ");
                                scanf_s("%d", &n);
                                eatline();
                                if (n < 3 || n > 7)
                                    printf("\n Количество строк должно быть не меньше 3 и не больше 7.");

                            } while (n < 3 || n > 7);
                            printf(" [%d][]\n", n);
                            do
                            {
                                printf("\n Введите количество столбцов в массиве = ");
                                scanf_s("%d", &m);
                                eatline();
                                if (m < 3 || m > 7)
                                    printf("\n Количество столбцов должно быть не меньше 3 и не больше 7.");
                            } while (m < 3 || m > 7);
                            printf(" [%d][%d]\n", n, m);

                            array = (double *)calloc(1, sizeof(double));
                            if (array)
                            {
                                array = input_array_keyboard(array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                mean_array(array, n, m);
                                free(array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                        else if (option == 2) //тест функции
                        {
                            n = 7;
                            m = 7;
                            printf("\n ___| Выбрано 2 действие |___\n");
                            printf("\n Задан двумерный массив порядка [%d][%d]", n, m);

                            array = (double *)calloc(1, sizeof(double));
                            if (array)
                            {
                                array = input_array_random(array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                mean_array(array, n, m);
                                free(array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                    }
                } while (option != 1 && option != 2 && option != 3);
                printf("\n Y - Повторить пункт 1.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 2:
            do
            {
                dash(75);
                printf("\n _______| Выбран 2 пункт меню |_______\n");
                printf("\n   Выберите действие:\n");
                printf(" 1:Задать массив для работы с функцией.\n");
                printf(" 2:Тест работы функции в заданном массиве.\n");
                printf(" 3: | Отмена |\n");
                do
                {
                    printf("\n Действие >");
                    scanf_s("%d", &option);
                    eatline();       // удаление оставшейся части строки
                    if (option == 3) // отмена
                        dash(75);
                    else
                    {
                        if (option != 1 && option != 2)
                        {
                            printf("\n Некорректный ввод (Действие = 3 -отмена).");
                            printf("\n Пожалуйста сделайте выбор.");
                        }
                        else if (option == 1) // задать массив с клавиатуры
                        {
                            printf("\n ___| Выбрано 1 действие |___\n");
                            printf("\n Задайте двумерный массив порядка N*M:");
                            printf("\n Количество строк (N) и столбцов (M) должно быть не меньше 3 и не больше 7.\n");
                            do
                            {
                                printf("\n Введите количество строк в массиве = ");
                                scanf_s("%d", &n);
                                eatline();
                                if (n < 3 || n > 7)
                                    printf("\n Количество строк должно быть не меньше 3 и не больше 7.");

                            } while (n < 3 || n > 7);
                            printf(" [%d][]\n", n);
                            do
                            {
                                printf("\n Введите количество столбцов в массиве = ");
                                scanf_s("%d", &m);
                                eatline();
                                if (m < 3 || m > 7)
                                    printf("\n Количество столбцов должно быть не меньше 3 и не больше 7.");
                            } while (m < 3 || m > 7);
                            printf(" [%d][%d]\n", n, m);

                            array = (double *)calloc(1, sizeof(double));
                            if (array)
                            {
                                array = input_array_keyboard(array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                plus_mines_zero_array(array, n, m);
                                free(array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                        else if (option == 2) //тест функции
                        {
                            n = 7;
                            m = 7;
                            printf("\n ___| Выбрано 2 действие |___\n");
                            printf("\n Задан двумерный массив порядка [%d][%d]", n, m);

                            array = (double *)calloc(1, sizeof(double));
                            if (array)
                            {
                                array = input_array_random(array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                plus_mines_zero_array(array, n, m);
                                free(array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                    }
                } while (option != 1 && option != 2 && option != 3);
                printf("\n Y - Повторить пункт 2.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 3:
            do
            {
                dash(75);
                printf("\n _______| Выбран 3 пункт меню |_______\n");
                printf("\n   Выберите действие:\n");
                printf(" 1:Задать массив для работы с функцией.\n");
                printf(" 2:Тест работы функции в заданном массиве.\n");
                printf(" 3: | Отмена |\n");
                do
                {
                    printf("\n Действие >");
                    scanf_s("%d", &option);
                    eatline();       // удаление оставшейся части строки
                    if (option == 3) // отмена
                        dash(75);
                    else
                    {
                        if (option != 1 && option != 2)
                        {
                            printf("\n Некорректный ввод (Действие = 3 -отмена).");
                            printf("\n Пожалуйста сделайте выбор.");
                        }
                        else if (option == 1) // задать массив с клавиатуры
                        {
                            printf("\n ___| Выбрано 1 действие |___\n");
                            printf("\n Задайте двумерный массив порядка N*M:");
                            printf("\n Количество строк (N) и столбцов (M) должно быть не меньше 3 и не больше 7.\n");
                            do
                            {
                                printf("\n Введите количество строк в массиве = ");
                                scanf_s("%d", &n);
                                eatline();
                                if (n < 3 || n > 7)
                                    printf("\n Количество строк должно быть не меньше 3 и не больше 7.");

                            } while (n < 3 || n > 7);
                            printf(" [%d][]\n", n);
                            do
                            {
                                printf("\n Введите количество столбцов в массиве = ");
                                scanf_s("%d", &m);
                                eatline();
                                if (m < 3 || m > 7)
                                    printf("\n Количество столбцов должно быть не меньше 3 и не больше 7.");
                            } while (m < 3 || m > 7);
                            printf(" [%d][%d]\n", n, m);

                            array = (double *)calloc(1, sizeof(double));
                            if (array)
                            {
                                array = input_array_keyboard(array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                min_max_array(array, n, m);
                                free(array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                        else if (option == 2) //тест функции
                        {
                            n = 7;
                            m = 7;
                            printf("\n ___| Выбрано 2 действие |___\n ");
                            printf("\n Задан двумерный массив порядка [%d][%d]", n, m);

                            array = (double *)calloc(1, sizeof(double));
                            if (array)
                            {
                                array = input_array_random(array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                min_max_array(array, n, m);
                                free(array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                    }
                } while (option != 1 && option != 2 && option != 3);
                printf("\n Y - Повторить пункт 3.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 4:
            do
            {
                dash(75);
                printf("\n _______| Выбран 4 пункт меню |_______\n");
                printf("\n   Выберите действие:\n");
                printf(" 1:Задать массив для работы с функцией.\n");
                printf(" 2:Тест работы функции в заданном массиве.\n");
                printf(" 3: | Отмена |\n");
                do
                {
                    printf("\n Действие >");
                    scanf_s("%d", &option);
                    eatline();       // удаление оставшейся части строки
                    if (option == 3) // отмена
                        dash(75);
                    else
                    {
                        if (option != 1 && option != 2)
                        {
                            printf("\n Некорректный ввод (Действие = 3 -отмена).");
                            printf("\n Пожалуйста сделайте выбор.");
                        }
                        else if (option == 1) // задать массив с клавиатуры
                        {
                            printf("\n ___| Выбрано 1 действие |___\n");
                            printf("\n Задайте двумерный массив порядка N*M:");
                            printf("\n Количество строк (N) и столбцов (M) должно быть не меньше 3 и не больше 7.\n");
                            do
                            {
                                printf("\n Введите количество строк в массиве = ");
                                scanf_s("%d", &n);
                                eatline();
                                if (n < 3 || n > 7)
                                    printf("\n Количество строк должно быть не меньше 3 и не больше 7.");

                            } while (n < 3 || n > 7);
                            printf(" [%d][]\n", n);
                            do
                            {
                                printf("\n Введите количество столбцов в массиве = ");
                                scanf_s("%d", &m);
                                eatline();
                                if (m < 3 || m > 7)
                                    printf("\n Количество столбцов должно быть не меньше 3 и не больше 7.");
                            } while (m < 3 || m > 7);
                            printf(" [%d][%d]\n", n, m);

                            array = (double *)calloc(1, sizeof(double));
                            if (array)
                            {
                                array = input_array_keyboard(array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                reverse_array(array, n, m);
                                free(array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                        else if (option == 2) //тест функции
                        {
                            n = 7;
                            m = 7;
                            printf("\n ___| Выбрано 2 действие |___\n ");
                            printf("\n Задан двумерный массив порядка [%d][%d]", n, m);

                            array = (double *)calloc(1, sizeof(double));
                            if (array)
                            {
                                array = input_array_random(array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                reverse_array(array, n, m);
                                free(array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                    }
                } while (option != 1 && option != 2 && option != 3);
                printf("\n Y - Повторить пункт 4.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 5:
            do
            {
                dash(75);
                printf("\n _______| Выбран 5 пункт меню |_______\n");
                printf("\n   Выберите действие:\n");
                printf(" 1:Задать массив для работы с функцией.\n");
                printf(" 2:Тест работы функции в заданном массиве.\n");
                printf(" 3: | Отмена |\n");
                do
                {
                    printf("\n Действие >");
                    scanf_s("%d", &option);
                    eatline();       // удаление оставшейся части строки
                    if (option == 3) // отмена
                        dash(75);
                    else
                    {
                        if (option != 1 && option != 2)
                        {
                            printf("\n Некорректный ввод (Действие = 3 -отмена).");
                            printf("\n Пожалуйста сделайте выбор.");
                        }
                        else if (option == 1) // задать массив с клавиатуры
                        {
                            printf("\n ___| Выбрано 1 действие |___\n");
                            printf("\n Задайте двумерный массив порядка N*M:");
                            printf("\n Количество строк (N) и столбцов (M) должно быть не меньше 3 и не больше 7.\n");
                            do
                            {
                                printf("\n Введите количество строк в массиве = ");
                                scanf_s("%d", &n);
                                eatline();
                                if (n < 3 || n > 7)
                                    printf("\n Количество строк должно быть не меньше 3 и не больше 7.");

                            } while (n < 3 || n > 7);
                            printf(" [%d][]\n", n);
                            do
                            {
                                printf("\n Введите количество столбцов в массиве = ");
                                scanf_s("%d", &m);
                                eatline();
                                if (m < 3 || m > 7)
                                    printf("\n Количество столбцов должно быть не меньше 3 и не больше 7.");
                            } while (m < 3 || m > 7);
                            printf(" [%d][%d]\n", n, m);

                            p_n_array = (int *)calloc(1, sizeof(int));
                            if (p_n_array)
                            {
                                p_n_array = input_array_keyboard(p_n_array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(p_n_array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                int count = prime_n_array(p_n_array, n, m);
                                printf("\n\n Кол-во простых чисел в массиве = %d\n", count);
                                printf(" Оставлены простые числа в массиве\n");
                                printf(" Все остальные заменены '0'\n\n");
                                output_array(p_n_array, n, m);
                                printf("\n");
                                free(p_n_array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                        else if (option == 2) //тест функции
                        {
                            n = 7;
                            m = 7;
                            printf("\n ___| Выбрано 2 действие |___\n ");
                            printf("\n Задан двумерный массив порядка [%d][%d]", n, m);

                            p_n_array = (int *)calloc(1, sizeof(int));
                            if (p_n_array)
                            {
                                p_n_array = input_array_random(p_n_array, n, m);
                                printf("\n Исходный массив данных:\n\n");
                                output_array(p_n_array, n, m);
                                dot(25);
                                printf("\n Результат работы ФУНКЦИИ:\n");
                                int count = prime_n_array(p_n_array, n, m);
                                printf("\n\n Кол-во простых чисел в массиве = %d\n", count);
                                printf(" Оставлены простые числа в массиве\n");
                                printf(" Все остальные заменены '0'\n\n");
                                output_array(p_n_array, n, m);
                                printf("\n");
                                free(p_n_array);
                            }
                            else
                                printf("\n Нет возможности выделить память под первый элемент массива.\n");

                            dash(75);
                        }
                    }
                } while (option != 1 && option != 2 && option != 3);
                printf("\n Y - Повторить пункт 5.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 6:
            printf("\n\t..................");
            printf("\n\t|  До свидание   |");
            printf("\n\t|  Заходите еще  |");
            printf("\n\t|     (^-^)/     |");
            printf("\n\t''''''''''''''''''\n\n\a");
            go_back = false;
            break;

        default:
            printf("\n Неверный пункт меню. Будьте внимательны!!!\n");
            printf(" Для продолжения-ENTER.\n");
            getch();
            break;
        }
    } while (go_back);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        printf("-");
}

void dot(int count)
{
    int i;
    printf("\n");
    for (i = 0; i < count; i++)
        printf(" . ");
    printf("\n");
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

bool prime_n(int n)
{
    if (n > 1)
    {
        // в цикле перебираем числа от 2 до n - 1
        for (int i = 2; i < n; i++)
            if (n % i == 0) // если n делится без остатка на i - возвращаем false (число не простое)
                return false;
        // если программа дошла до данного оператора, то возвращаем true (число простое) - проверка пройдена
        return true;
    }
    else
        return false;
}

// ручной ввод чисел
double *input_array_keyboard(double *array, int n, int m)
{
    int i = 0;
    int j = 0;
    array = (double *)realloc(array, n * m * sizeof(double));

    printf("\n Элемент массива [%d][%d] = ", i, j);
    scanf_s("%lf", array);
    if (array)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    printf(" Элемент массива [%d][%d] = ", i, j);
                    scanf_s("%lf", array + j + (m * i));
                }
            }
        }
        return array;
    }
    else
        printf("\n Нет возможности выделить память под оставшиеся элементы массива.\n");
    return 0;
}

// рандомный ввод чисел
double *input_array_random(double *array, int n, int m)
{
    int i, j;
    array = (double *)realloc(array, n * m * sizeof(double));
    srand(time(NULL));
    if (array)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    *(array + j + (m * i)) = 0.11 * (rand() % 201 - 100);
                }
            }
        }
        return array;
    }
    else
        printf("\n Нет возможности выделить память под оставшиеся элементы массива.\n");
    return 0;
}

// вывод массива на экран
void output_array(double *array, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%10.2lf", *(array + j + (m * i)));
            if ((j + 1) % m == 0)
                printf("\n");
        }
    }
}

// (перегрузка) ручной ввод чисел
int *input_array_keyboard(int *p_n_array, int n, int m)
{
    int i = 0;
    int j = 0;
    p_n_array = (int *)realloc(p_n_array, n * m * sizeof(int));

    printf("\n Элемент массива [%d][%d] = ", i, j);
    scanf_s("%d", p_n_array);

    if (p_n_array)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    printf(" Элемент массива [%d][%d] = ", i, j);
                    scanf_s("%d", p_n_array + j + (m * i));
                }
            }
        }
        return p_n_array;
    }
    else
        printf("\n Нет возможности выделить память под оставшиеся элементы массива.\n");
    return 0;
}

// (перегрузка) рандомный ввод чисел
int *input_array_random(int *p_n_array, int n, int m)
{
    int i, j;
    p_n_array = (int *)realloc(p_n_array, n * m * sizeof(int));
    srand(time(NULL));
    if (p_n_array)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    *(p_n_array + j + (m * i)) = rand() % 201 - 100;
                }
            }
        }
        return p_n_array;
    }
    else
        printf("\n Нет возможности выделить память под оставшиеся элементы массива.\n");
    return 0;
}

// (перегрузка) вывод массива на экран
void output_array(int *p_n_array, int n, int m)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%6d\t", *(p_n_array + j + (m * i)));
            if ((j + 1) % m == 0)
                printf("\n");
        }
    }
}

// среднее значение чисел в массиве
void mean_array(double *array, int n, int m)
{
    double sum = 0;
    double mid = 0;
    int a = n * m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum = sum + (*(array + j + (m * i)));
    mid = sum / a;
    printf(" Среднее арифметическое элементов = %.2lf \n\n", mid);
}

// кол-во положительных, отрицательных, нулевых элементов массива
void plus_mines_zero_array(double *array, int n, int m)
{
    int plus = 0;
    int mines = 0;
    int zero = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (*(array + j + (m * i)) > 0)
                plus++;
            if (*(array + j + (m * i)) < 0)
                mines++;
            if (*(array + j + (m * i)) == 0)
                zero++;
        }
    printf(" Количество элементов:\n");
    printf(" Положительных = %d\n", plus);
    printf(" Отрицательных = %d\n", mines);
    printf("       Нулевых = %d\n\n", zero);
}

// min и max элементы в массиве
void min_max_array(double *array, int n, int m)
{
    double min = *array;
    double max = *array;
    int i_min = 0;
    int i_max = 0;
    int j_min = 0;
    int j_max = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (*(array + j + (m * i)) < min)
            {
                min = *(array + j + (m * i));
                i_min = i;
                j_min = j;
            }
            if (*(array + j + (m * i)) > max)
            {
                max = *(array + j + (m * i));
                i_max = i;
                j_max = j;
            }
        }

    printf(" min [%d][%d] = %.2lf\n", i_min, j_min, min);
    printf(" max [%d][%d] = %.2lf\n\n", i_max, j_max, max);
}

// противоположный массив
void reverse_array(double *array, int n, int m)
{
    int i, j;
    printf(" Обработанный массив данных:\n\n");
    for (i = n - 1; i >= 0; i--)
    {
        for (j = m - 1; j >= 0; j--)
        {
            printf("%10.2lf", *(array + j + (m * i)));
            if (j % m == 0)
                printf("\n");
        }
    }
    printf("\n");

    double tmp;
    int i, j, ip, jp, k, flag;
    //Сортируем пузырьком, обходя все N*M элементы
    do
    {
        flag = 0;
        for (k = 1; k < n * m; k++)
        {
            //Вычисляем индексы текущего элемента
            j = k / n;
            i = k - j * n;
            //Вычисляем индексы предыдущего элемента
            jp = (k - 1) / n;
            ip = (k - 1) - jp * n;
            if (*(array + j + (m * i)) > *(array + jp + (m * ip)))
            {
                tmp = *(array + j + (m * i));
                *(array + j + (m * i)) = *(array + jp + (m * ip));
                *(array + jp + (m * ip)) = tmp;
                flag = 1;
            }
        }
    } while (flag);
    output_array(array, n, m);
}

// простые числа в массиве
int prime_n_array(int *p_n_array, int n, int m)
{
    int count = 0;
    printf(" Простые числа в массиве:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (prime_n(*(p_n_array + j + (m * i))))
            {
                count++;
                printf(" %d |", *(p_n_array + j + (m * i)));
            }
            else
                *(p_n_array + j + (m * i)) = 0;
        }
    return count;
}
