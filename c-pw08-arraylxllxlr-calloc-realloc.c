// 1. Предусмотреть два варианта ввода элементов массива: ввод с клавиатуры
//     и ввод через генерацию случайных чисел.
// 2. Решение должно использовать адресацию элементов массива через указатели.
// 3. Ввод элементов массива с клавиатуры, ввод через генерацию случайных чисел,
//     вывод элементов массива на экран и манипуляции с элементами массива
//     согласно условию, осуществить через отдельные функции.
// 4. Задачу решить с использованием простого пользовательского меню.

// Условие:
// Задана квадратная матрица порядка N. Вычислить сумму положительных
// элементов, лежащих ниже побочной диагонали.
// Программа должна выполнять ввод и вывод матрицы и
// дополнительных данных, выполнять необходимые действия и выводить
// результаты.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand() (управление динамическим выделением памяти)
#include <time.h>   // в этом файле содержится функция time()
#include <conio.h>  // в этом файле содержится функция getch()

int main(void);
int *input_array_keyboard(int *, int);
int *input_array_random(int *, int);
void output_array_primary(int *, int);         //вывод цифр всего заданного массива
void output_array_side_down(int *, int);       //вывод цифр лежащих ниже побочной диагонали
void output_array_summa_side_down(int *, int); //сумма положительных элементов, лежащих ниже побочной диагонали

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int *array;
    int n;

    int menu_number = 0;
    int go_back = 1;
    do
    {
        system("cls");
        printf(" ***| Программа работы с двухмерными массивами через указатели | ***\n\n"
               " 1:Ввод массива с клавиатуры.\n");
        printf(" 2:Ввод массива через генерацию случайных чисел.\n");
        printf(" 3:Выход из программы.\n\n>");
        scanf("%d", &menu_number);
        switch (menu_number)
        {
        case 1:
            printf("\n Задайте квадратную матрицу порядка N: ");
            do
            {
                scanf("%d", &n);
                if (n < 3 || n > 7)
                {
                    printf("\n Число в квадратной матрице должно быть не меньше 3 и не больше 7.\n");
                    printf(" Задайте квадратную матрицу порядка N: ");
                }
            } while (n < 3 || n > 7);

            array = (int *)calloc(1, sizeof(int));
            if (array)
            {
                array = input_array_keyboard(array, n);
                output_array_primary(array, n);
                output_array_side_down(array, n);
                output_array_summa_side_down(array, n);
                free(array);
            }
            else
                printf("\n Нет возможности выделить память под первый элемент матрицы.\n");

            printf("\n Для продолжения-ENTER.");
            getch();
            break;

        case 2:
            printf("\n Задайте квадратную матрицу порядка N: ");
            do
            {
                scanf("%d", &n);
                if (n < 3 || n > 7)
                {
                    printf("\n Число в квадратной матрице должно быть не меньше 3 и не больше 7.\n");
                    printf(" Задайте квадратную матрицу порядка N: ");
                }
            } while (n < 3 || n > 7);

            array = (int *)calloc(1, sizeof(int));
            if (array)
            {
                array = input_array_random(array, n);
                output_array_primary(array, n);
                output_array_side_down(array, n);
                output_array_summa_side_down(array, n);
                free(array);
            }
            else
                printf("\n Нет возможности выделить память под первый элемент матрицы.\n");

            printf("\n Для продолжения-ENTER.");
            getch();
            break;

        case 3:
            go_back = 0;
            break;

        default:
            printf("\n Неверный пункт меню. Будьте внимательны!!!\n");
            printf("\n Для продолжения-ENTER.");
            getch();
            break;
        }
    } while (go_back != 0);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

int *input_array_keyboard(int *array, int n)
{
    int i = 0;
    int j = 0;
    array = (int *)realloc(array, n * n * sizeof(int));

    printf("\n Элемент матрицы [%d][%d] = ", i, j);
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
                    printf(" Элемент матрицы [%d][%d] = ", i, j);
                    scanf("%d", array + j + (n * i));
                }
            }
        }
        return array;
    }
    else
        printf("\n Нет возможности выделить память под оставшиеся элементы матрицы.\n");
    return 0;
}

int *input_array_random(int *array, int n)
{
    int i, j;
    array = (int *)realloc(array, n * n * sizeof(int));
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
        printf("\n Нет возможности выделить память под оставшиеся элементы матрицы.\n");
    return 0;
}

void output_array_primary(int *array, int n)
{
    int i, j;

    printf("\n Исходный массив данных:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%5d", *(array + j + (n * i)));
            if ((j + 1) % n == 0)
                printf("\n");
        }
    }
}

void output_array_side_down(int *array, int n)
{
    int i, j;

    printf("\n Числа нижней побочной диагонали:\n\n");
    for (i = 1; i < n; i++)
    {
        for (j = n - i; j < n; j++)
        {
            printf("%5d", *(array + j + (n * i)));
            if ((j + 1) % n == 0)
                printf("\n");
        }
    }
}

//сумма положительных элементов, лежащих ниже побочной диагонали
void output_array_summa_side_down(int *array, int n) 
{
    int i, j;
    int sum = 0;

    for (i = 1; i < n; i++)
    {
        for (j = n - i; j < n; j++)
        {
            if (*(array + j + (n * i)) > 0)
                sum += *(array + j + (n * i));
        }
    }
    if (sum)
        printf("\n Сумма положительных чисел нижней побочной диагонали = %d\n", sum);
    else
        printf("\n На нижней побочной диагонали отсутствуют положительные числа\n");
}
