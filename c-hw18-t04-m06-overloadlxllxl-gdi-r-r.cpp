/*
// Задание 1:
// Разработать программу, в составе которой выполняли бы свою работу следующие
// написанные пользовательские перегруженные функции (int, double,)
// для выполнения следующих задач:
// - инициализация квадратной матрицы (ввод в память ПЭВМ);
// - вывод матрицы на экран;
// - определение максимального и минимального элемента на главной диагонали
//   матрицы;
// - сортировка элементов по возрастанию отдельно для каждой строки матрицы.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand() (управление динамическим выделением памяти)
#include <time.h>   // в этом файле содержится функция time()
#include <conio.h>  // в этом файле содержится функция getch()
#include <stdbool.h>// содержится определение логических констант true и false

int main(void);
void dash(int);
void dot(int);
void equal(int);
void eatline(void);// читать до конца строки

int* input_array_keyboard(int*, int);      // ввод массива числами с клавиатуры (53)
int* input_array_random(int*, int);        // Ввод массива числами   рандомными (53)
void output_array(int*, int);             // вывод массива                      (53)

double* input_array_keyboard(double*, int);// ввод массива числами с клавиатуры (53.86)
double* input_array_random(double*, int);  // Ввод массива числами   рандомными (53.86)
void output_array(double*, int);          // вывод массива                      (53.86)

//1. Максимальный и минимальный элемент на главной диагонали массива.
void min_max_array(int*, int);
void min_max_array(double*, int);
//2. Сортировка элементов по возрастанию отдельно для каждой строки массива.
void sort_array_line(int*, int);
void sort_array_line(double*, int);

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double* d_array = NULL;
    int* array = NULL;
    int n;
    int work_or_test = 0;
    int menu_number = 0;
    int option = 0;
    char repeat;
    bool memory = false; // проверка инициализации в память (ПЭВМ)
    bool whole;          // целое число
    bool go_back = true;

    system("cls");
    printf(" ***| Программа работы с перегрузкой функций в двумерном в массиве | ***\n\n");
    printf("  Сделайте выбор:\n");
    printf(" 1:ПУСК программы.\n"); // работа в программе согласно условия
    printf(" 2:ТЕСТ программы.\n"); // тест программы вывод на экран всех условий
    printf(" 3: __| ВЫХОД |__\n");
    do
    {
        printf("\n Выбор > ");
        scanf_s("%d", &work_or_test);
        eatline(); // удаление оставшейся части строки
        if (work_or_test != 1 && work_or_test != 2 && work_or_test != 3)
        {
            printf("\n Некорректный ввод (Действие = 3 -отмена).");
            printf("\n Пожалуйста сделайте выбор.");
        }
// ============================== пуск программы ====================================================
        else if (work_or_test == 1)
        {
            do
            {
                system("cls");
                printf(" ***| Программа работы с перегрузкой функций в двумерном в массиве | ***\n\n");
                printf(" ___________| Главное меню |_______________________________________________\n");
                printf(" 1:Инициализация квадратного массива (ввод в память ПЭВМ).\n");
                printf(" 2:Вывод массива на экран.\n");
                printf(" 3:Определение max и min элемента на главной диагонали массива.\n");
                printf(" 4:Сортировка элементов по возрастанию отдельно для каждой строки массива.\n");
                printf(" 5: | ВыхоД |\n\n>");
                scanf_s("%d", &menu_number);
                eatline();
                switch (menu_number)
                {
                case 1:
                    do
                    {
                        dash(75);
                        printf("\n ___| Инициализация квадратного массива |___\n");
                        printf("   Выберите ТИП ДАННЫХ для работы:\n");
                        printf(" 1:Целочисленный тип (int).\n");
                        printf(" 2:Вещественный  тип (double).\n");
                        printf(" 3: | Отмена |\n\n>"); // оставить как есть
                        do
                        {
                            printf("\n Выбор > ");
                            scanf_s("%d", &option);
                            eatline(); // удаление оставшейся части строки
                            if (option != 1 && option != 2 && option != 3)
                            {
                                printf("\n Некорректный ввод (Выбор = 3 -отмена).");
                                printf("\n Пожалуйста сделайте выбор.");
                            }
                            else if (option == 1) // целочисленный тип
                            {
                                free(array);
                                free(d_array);
                                dot(25);
                                printf("\n _______| Выбран целочисленный тип данных |_______\n");
                                printf("\n Задайте квадратный массив порядка N*N:");
                                printf("\n Количество (N) должно быть не меньше 3 и не больше 7.\n");
                                do
                                {
                                    printf("\n Введите количество строк и столбцов в массиве = ");
                                    scanf_s("%d", &n);
                                    eatline();
                                    if (n < 3 || n > 7)
                                        printf("\n Количество строк и столбцов должно быть не меньше 3 и не больше 7.");

                                } while (n < 3 || n > 7);
                                printf(" Задан массив [%d][%d]\n", n, n);

                                array = (int*)calloc(1, sizeof(int));
                                if (array)
                                {
                                    array = input_array_keyboard(array, n);
                                    dot(25);
                                    printf("\n Массив инициализирован в память успешно.\n");
                                    memory = true; // в памяти
                                    whole = true;  // целое число
                                }
                                else
                                    printf("\n Нет возможности выделить память под первый элемент массива.\n");

                                dash(75);
                            }

                            else if (option == 2)
                            {
                                free(array);
                                free(d_array);
                                dot(25);
                                printf("\n _______| Выбран вещественный тип данных |_______\n");
                                printf("\n Задайте квадратный массив порядка N*N:");
                                printf("\n Количество (N) должно быть не меньше 3 и не больше 7.\n");
                                do
                                {
                                    printf("\n Введите количество строк и столбцов в массиве = ");
                                    scanf_s("%d", &n);
                                    eatline();
                                    if (n < 3 || n > 7)
                                        printf("\n Количество строк и столбцов должно быть не меньше 3 и не больше 7.");

                                } while (n < 3 || n > 7);
                                printf(" Задан массив [%d][%d]\n", n, n);

                                d_array = (double*)calloc(1, sizeof(double));
                                if (d_array)
                                {
                                    d_array = input_array_keyboard(d_array, n);
                                    dot(25);
                                    printf("\n Массив инициализирован в память успешно.\n");
                                    memory = true; // в памяти
                                    whole = false; // не целое число
                                }
                                else
                                    printf("\n Нет возможности выделить память под первый элемент массива.\n");

                                dash(75);
                            }

                        } while (option != 1 && option != 2 && option != 3);

                        printf("\n R - Вернуться к выбору типа данных");
                        printf("\n Q - Выход в Главное меню.\n>");
                        repeat = getch();
                    } while (repeat == 'r' || repeat == 'R');
                    break;

                case 2:
                    dot(25);
                    if (memory)
                    {
                        printf("\n Массив находящийся в данный момент в оперативной памяти.");
                        printf("\n Исходный массив данных:\n\n");
                        if (whole)
                            output_array(array, n);
                        else
                            output_array(d_array, n);
                    }
                    else
                        printf("\n Массив не инициализирован в оперативную память.\n");

                        equal(75);
                        printf(" Для продолжения-<ENTER>");
                        getch();
                        break;

                case 3:
                    dot(25);
                    if (memory)
                    {
                        printf("\n Максимальный и минимальный элемент на главной диагонали массива.\n\n");
                        if (whole)
                            min_max_array(array, n);
                        else
                            min_max_array(d_array, n);
                    }
                    else
                        printf("\n Массив не инициализирован в оперативную память.\n");

                    equal(75);
                    printf(" Для продолжения-<ENTER>");
                    getch();
                    break;

                case 4:
                    dot(25);
                    if (memory)
                    {
                        printf("\n Сортировка элементов по возрастанию отдельно для каждой строки массива.\n\n");
                        if (whole)
                        {
                            sort_array_line(array, n);
                            output_array(array, n);
                        }
                        else
                        {
                            sort_array_line(d_array, n);
                            output_array(d_array, n);
                        }
                    }
                    else
                        printf("\n Массив не инициализирован в оперативную память.\n");

                    equal(75);
                    printf(" Для продолжения-<ENTER>");
                    getch();
                    break;

                case 5:
                    free(array);
                    free(d_array);
                    printf("\n\t................................");
                    printf("\n\t|   (^-^)/   (^-^)/   (^-^)/   |");
                    printf("\n\t''''''''''''''''''''''''''''''''\n\n\a");
                    go_back = false;
                    break;

                default:
                    printf("\n Неверный пункт меню.\n");
                    printf(" Будьте внимательны!!!\n");
                    printf(" Для продолжения-<ENTER>");
                    getch();
                    break;
                }
            } while (go_back);

        }
// ============================== тест программы ====================================================
        else if (work_or_test == 2)
        {
            n = 7;
            dash(75);
            printf("\n\t___| ТЕСТ программы |___\n\n");

            printf(" === Целочисленный тип данных (int) ===\n");
            printf(" Задан двумерный массив порядка [%d][%d]\n", n, n);
            array = (int*)calloc(1, sizeof(int));
            if (array)
            {
                array = input_array_random(array, n);
                printf("\n Исходный массив данных:\n\n");
                output_array(array, n);
                dot(25);
                printf("\n Максимальный и минимальный элемент на главной диагонали массива.\n\n");
                min_max_array(array, n);
                dot(25);
                printf("\n Сортировка элементов по возрастанию отдельно для каждой строки массива.\n\n");
                sort_array_line(array, n);
                output_array(array, n);
                free(array);
            }
            else
            {
                printf("\n Нет возможности выделить память под первый элемент массива.\n");
                dash(75);
            }
            equal(75);

            printf(" === Вещественный тип данных (double) ===\n");
            printf(" Задан двумерный массив  порядка  [%d][%d]\n", n, n);
            d_array = (double*)calloc(1, sizeof(double));
            if (d_array)
            {
                d_array = input_array_random(d_array, n);
                printf("\n Исходный массив данных:\n\n");
                output_array(d_array, n);
                dot(25);
                printf("\n Максимальный и минимальный элемент на главной диагонали массива.\n\n");
                min_max_array(d_array, n);
                dot(25);
                printf("\n Сортировка элементов по возрастанию отдельно для каждой строки массива.\n\n");
                sort_array_line(d_array, n);
                output_array(d_array, n);
                free(d_array);
                printf("\n");
                dash(75);
            }
            else
            {
                printf("\n Нет возможности выделить память под первый элемент массива.\n");
                dash(75);
            }
        }

    } while (work_or_test != 1 && work_or_test != 2 && work_or_test != 3);

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

void equal(int count)
{
    int i;
    printf("\n");
    for (i = 0; i < count; i++)
        printf("=");
    printf("\n");
}

void eatline(void)
{
    while (getchar() != '\n')
        continue;
}

//-----------------------------------------------------------------
// ручной ввод чисел
int* input_array_keyboard(int* array, int n)
{
    int i = 0;
    int j = 0;
    array = (int*)realloc(array, n * n * sizeof(int));

    printf("\n Элемент массива [%d][%d] = ", i, j);
    scanf_s("%d", array);

    if (array)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    printf(" Элемент массива [%d][%d] = ", i, j);
                    scanf_s("%d", array + j + (n * i));
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
int* input_array_random(int* array, int n)
{
    int i, j;
    array = (int*)realloc(array, n * n * sizeof(int));
    srand(time(NULL));
    if (array)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    *(array + j + (n * i)) = rand() % 201 - 100;
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
void output_array(int* array, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%6d\t", *(array + j + (n * i)));
            if ((j + 1) % n == 0)
                printf("\n");
        }
    }
}

//-----------------------------------------------------------------
// (перегрузка) ручной ввод чисел
double* input_array_keyboard(double* d_array, int n)
{
    int i = 0;
    int j = 0;
    d_array = (double*)realloc(d_array, n * n * sizeof(double));

    printf("\n Элемент массива [%d][%d] = ", i, j);
    scanf_s("%lf", d_array);

    if (d_array)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    printf(" Элемент массива [%d][%d] = ", i, j);
                    scanf_s("%lf", d_array + j + (n * i));
                }
            }
        }
        return d_array;
    }
    else
        printf("\n Нет возможности выделить память под оставшиеся элементы массива.\n");
    return 0;
}

// (перегрузка) рандомный ввод чисел
double* input_array_random(double* d_array, int n)
{
    int i, j;
    d_array = (double*)realloc(d_array, n * n * sizeof(double));
    srand(time(NULL));
    if (d_array)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    *(d_array + j + (n * i)) = 0.11 * (rand() % 201 - 100);
                }
            }
        }
        return d_array;
    }
    else
        printf("\n Нет возможности выделить память под оставшиеся элементы массива.\n");
    return 0;
}

// (перегрузка) вывод массива на экран
void output_array(double* d_array, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%10.2lf", *(d_array + j + (n * i)));
            if ((j + 1) % n == 0)
                printf("\n");
        }
    }
}

//---------------------------------------------------------------
// min and max на главной диагонали
void min_max_array(int* array, int n)
{
    int min = *array;
    int max = *array;
    int i_min = 0;
    int i_max = 0;
    int j_min = 0;
    int j_max = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)// главная диагональ массива
            {
                if (*(array + j + (n * i)) < min)
                {
                    min = *(array + j + (n * i));
                    i_min = i;
                    j_min = j;
                }
                if (*(array + j + (n * i)) > max)
                {
                    max = *(array + j + (n * i));
                    i_max = i;
                    j_max = j;
                }
            }
        }

    printf(" min [%d][%d] = %3d\n", i_min, j_min, min);
    printf(" max [%d][%d] = %3d\n", i_max, j_max, max);
}
void min_max_array(double* d_array, int n)
{
    double min = *d_array;
    double max = *d_array;
    int i_min = 0;
    int i_max = 0;
    int j_min = 0;
    int j_max = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)// главная диагональ массива
            {
                if (*(d_array + j + (n * i)) < min)
                {
                    min = *(d_array + j + (n * i));
                    i_min = i;
                    j_min = j;
                }
                if (*(d_array + j + (n * i)) > max)
                {
                    max = *(d_array + j + (n * i));
                    i_max = i;
                    j_max = j;
                }
            }
        }

    printf(" min [%d][%d] = %5.2lf\n", i_min, j_min, min);
    printf(" max [%d][%d] = %5.2lf\n", i_max, j_max, max);
}

//---------------------------------------------------------------
// сортировка отдельно для каждой строки по возрастанию
void sort_array_line(int* array, int n)
{
    int tmp;
    int i, j, ip, jp, k, flag;

    //Сортируем пузырьком, обходя все N*N элементы
    do {
        flag = 0;
            for (k = 1; k < n * n ; k++)
            {
            //Вычисляем индексы текущего элемента (для i заменить на j)
            i = k / n;
            j = k - i * n;
            //Вычисляем индексы предыдущего элемента (для i заменить на j)
            ip = (k - 1) / n;
            jp = (k - 1) - ip * n;
                //Сравниваем и задаем направление от меньшего к большему или наоборот
                if (*(array + j + (n * i)) < * (array + jp + (n * ip)))
                {
                    if (j) // по строками j по столбцам i => указатель
                    {
                        tmp = *(array + j + (n * i));
                        *(array + j + (n * i)) = *(array + jp + (n * ip));
                        *(array + jp + (n * ip)) = tmp;
                        flag = 1;
                    }
                }
            }
    } while (flag);
}

void sort_array_line(double* d_array, int n)
{
    double tmp;
    int i, j, ip, jp, k, flag;

    //Сортируем пузырьком, обходя все N*N элементы
    do {
        flag = 0;
        for (k = 1; k < n * n; k++)
        {
            //Вычисляем индексы текущего элемента (для i заменить на j)
            i = k / n;
            j = k - i * n;
            //Вычисляем индексы предыдущего элемента (для i заменить на j)
            ip = (k - 1) / n;
            jp = (k - 1) - ip * n;
            //Сравниваем и задаем направление от меньшего к большему или наоборот
            if (*(d_array + j + (n * i)) < *(d_array + jp + (n * ip)))
            {
                if (j) // по строками j по столбцам i => указатель
                {
                    tmp = *(d_array + j + (n * i));
                    *(d_array + j + (n * i)) = *(d_array + jp + (n * ip));
                    *(d_array + jp + (n * ip)) = tmp;
                    flag = 1;
                }
            }
        }
    } while (flag);
}


// Задание 2:
// Разработать программу, в составе которой выполняла бы свою работу
// рекурсивная функция нахождения наибольшего общего делителя двух целых чисел.

#include <windows.h>
#include <stdio.h>

int gcd(int, int);

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf(" ***| Программа нахождения НОД двух чисел |***\n");
    int a = 0;
    int b = 0;

    //Наибольший общий делитель существует и однозначно определён, если хотя бы одно из чисел a или b не равно нулю.
    do
    {
        do
        {
            printf("\n Введите первое целое число: \n>");
            scanf("%d", &a);
            if (a < -1)
            {
                printf("\n Ошибка !!! \n");
                printf(" Число должно быть положительным.\n Повторите ввод числа.\n");
            }
        } while (a < -1);
        do
        {
            printf("\n Введите второе целое число: \n>");
            scanf("%d", &b);
            if (b < -1)
            {
                printf("\n Ошибка !!! \n");
                printf(" Число должно быть положительным.\n Повторите ввод числа.\n");
            }
        } while (b < -1);

        if (a == 0 && b == 0)
        {
            printf("\n Ошибка !!! \n");
            printf(" Хотя бы одно из двух чисел не равно нулю.\n");
            printf(" Повторите ввод первого и второго числа.\n");
        }
        else
        {
            printf(" Условие выполнено | ОК |\n\n");
        }
    } while (a == 0 && b == 0);

    printf(" НОД двух чисел = %d\n", gcd(a, b));

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

int gcd(int a, int b)
{

    if (b == a)
    {
        return a;
    }
    // Если одно из чисел в паре равно нулю, а другое — нет, то их НОД равен модулю ненулевого числа.
    if (b == 0)
    {
        return a;
    }
    if (a == 0)
    {
        return b;
    }
    if (a > b)
    {
        return gcd(b, a % b);
    }
    else
    {
        return gcd(a, b % a);
    }
}
*/

// Задание 3 : Написать игру «Быки и коровы».Программа "загадывает" четырёхзначное число
// и играющий должен угадать его.После ввода пользователем числа программа сообщает,
// сколько цифр числа угадано(быки)
// и сколько цифр угадано и стоит на нужном месте(коровы).
// После отгадывания числа на экран необходимо вывести количество сделанных
// пользователем попыток.В программе желательно использовать рекурсию.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand()
#include <time.h>   // в этом файле содержится функция time()
#include <conio.h>  // в этом файле содержится функция getch()

#define ND 4 // количество цифр в числе (число из цифр number of digits)

int main(void);
void dash(int);
void dot(int);

int *comp_rand_num(int *);
int *comp_rand_num_cheat(int *);
int *digits(int);
void check(int *, int *, int *, int *, int *, int);
void game(int *, int *, int *);

int *pc = new int[ND]; // число компьютера (комбинация)
int *pl = new int[ND]; // число игрока     (комбинация)
int *tm = new int[ND]; // массив флагов    (заполнения нулями)
int count_try = 1;     // попытки

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char repeat; // повтор игры или теста
    int replay;  // количество переигровок попыток
    int menu_number = 0;
    bool go_back = true;
    do
    {
        system("cls");
        printf(" ***| ИГРА БЫКИ И КОРОВЫ |***\n\n");
        printf(" 1:Начать игру.\n");
        printf(" 2:Тест игры.\n");
        printf(" 3:Выход из ИГРЫ.\n\n>");
        scanf("%d", &menu_number);
        switch (menu_number)
        {
        case 1:
            do
            {
                dash(45);
                printf("\n _____________/ ИГРА \\______________\n\n");

                printf(" Программа "
                       "загадывает"
                       " четырёхзначное число\n");
                printf(" и играющий должен угадать его.\n");
                printf(" После ввода числа вы узнаете:\n");
                printf(" Быки   - сколько цифр угадано.\n");
                printf(" Коровы - сколько угаданных цифр\n");
                printf("          находятся на своем месте.\n\n");

                int *pc_unzip = comp_rand_num(pc);
                printf(" После ввода числа нажимайте <Enter>\n");
                game(pc_unzip, &replay, tm);
                printf(" Количество попыток \\ %d / \n", replay);

                dot(15);
                printf("\n Y - Повторить ИГРУ.");
                printf("\n Q - Выход из ИГРЫ.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 2:
            do
            {
                dash(45);
                printf("\n ___________/ ТЕСТ ИГРЫ \\____________\n\n");

                printf(" Программа "
                       "загадывает"
                       " четырёхзначное число\n");
                printf(" и играющий должен угадать его.\n");
                printf(" После ввода числа вы узнаете:\n");
                printf(" Быки   - сколько угадано цифр.\n");
                printf(" Коровы - сколько угаданных цифр\n");
                printf("          находятся на своем месте.\n\n");

                printf(" Число загаданное компьютером = ");
                int *pc_unzip = comp_rand_num_cheat(pc);
                printf(" После ввода числа нажимайте <Enter>\n");
                game(pc_unzip, &replay, tm);
                printf(" Количество попыток \\ %d / \n", replay);

                dot(15);
                printf("\n Y - Повторить ТЕСТ.");
                printf("\n Q - Выход из ТЕСТА.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 3:
            delete[] pc;
            delete[] pl;
            delete[] tm;
            printf("\n        (__)       __");
            printf("\n        |Oo|      |Oo|");
            printf("\n   /|'''(oo)      (oo)'''|\\");
            printf("\n  / |_____|        0_____| \\");
            printf("\n *   I   I          I   I   *");
            printf("\n ````````````````````````````");
            printf("\n      Спасибо за игру\n\n");
            go_back = false;
            break;

        default:
            printf("\n Неверный ввод. Будьте внимательны!!!\n");
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

// компьютер "задумывает" число
int *comp_rand_num(int *pc)
{
    srand(time(NULL));
    for (int i = 0; i < ND; i++)
        *(pc + i) = rand() % 10;
    return pc;
}

// просмотр числа которое компьютер задумал
int *comp_rand_num_cheat(int *pc)
{
    srand(time(NULL));
    for (int i = 0; i < ND; i++)
    {
        *(pc + i) = rand() % 10;
        printf("%d", *(pc + i));
    }
    printf("\n");
    return pc;
}

// число игрока разбиваем на цифры
int *digits(int pl_num)
{
    for (int i = 3; i >= 0; i--)
    {
        *(pl + i) = pl_num % 10;
        if (pl_num != 0)
            pl_num /= 10;
        else
            pl_num == 0;
    }
    return pl;
}

// рекурсия в игре
void game(int *pc_unzip, int *count, int *tm)
{
    *count = count_try; // передать количество попыток
    int pl_num = 0;     // число вводимое игроком
    int bull;
    int cow;

    printf(">");
    scanf("%d", &pl_num);

    int *pl_unzip = digits(pl_num); // передать распакованное число
    check(pc_unzip, pl_unzip, tm, &bull, &cow, ND);
    printf(" ''''_| Быки '%d' || ---- || '%d' Коровы |_\n", bull, cow);
    count_try++; // счетчик попыток

    if (bull == ND && cow == ND)
    {
        printf("\n Поздравлю!\n Число отгадано!!!\n");
        count_try = 1; // сбрасываем счетчик попыток
    }
    else
        game(pc_unzip, count, tm);
}

// проверка числа по цифрам
void check(int *pc_unzip, int *pl_unzip, int *tm, int *bull, int *cow, int nd)
{
    int i, j;
    // сбрасываем все влаги и заполняем массив нулями
    for (i = 0; i < nd; i++)
        *(tm + i) = 0;

    *bull = 0;              // кол-во быков считаем (при повторном входе обнуляем)
    for (i = 0; i < 5; i++) // проверим, сколько цифр угадано
        for (j = 0; j < nd; j++)
            if ((*(pc_unzip + i) == *(pl_unzip + j)) && !(*(tm + i)))
            {
                (*bull)++;
                *(tm + i) = 1;
                //*(tm + i) == 1, если i-я цифра
                // компьютера совпала с одной из цифр игрока.
                // запретим сравнивать эту цифру игрока
                // с еще не проверенными цифрами компьютера
            }

    *cow = 0;                // кол-во коров считаем (при повторном входе обнуляем)
    for (i = 0; i < nd; i++) // проверим, сколько на своих местах
        if (*(pc_unzip + i) == *(pl_unzip + i))
            (*cow)++;
}
