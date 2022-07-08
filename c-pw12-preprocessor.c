
// Ввести в память машины массив размером N*M.
// Подсчитать количество ненулевых элементов заданной строки.
// Подсчет количества произвести через макрофункцию.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // rand() и srand()
#include <time.h>   // time()

#define M 5                                     // строки
#define N 5                                     // столбцы
#define CHECK(zero) ((zero) != (0) ? (1) : (0)) // проверяем есть ли в строке ноль

void dash(int);
void dot(int);
void dotdot(int);
void equal(int);
void tabs(int);
void apostrophe(int);
void underscore(int);
void eatline(void);

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    system("cls");
    equal(80);
    printf("\n");
    tabs(9);
    printf("\n");
    apostrophe(80);
    printf("\n");
    printf("\t\t    ***| Практическая №12 (препроцессор) |***\n\n");

    srand((unsigned int)time(NULL));

    int result = 0; // количество ненулевых элементов
    int line = 0;   // строка поиска не нулевых элементов

    int **array = NULL;

    // выделение памяти для двумерного массива
    array = (int **)calloc(M, sizeof(int *));
    for (int i = 0; i < M; i++)
        array[i] = (int *)calloc(N, sizeof(int));

    printf("\n\tИсходный массив данных:\n");
    for (int i = 0; i < M; ++i)
    {
        printf("\n\t");
        for (int j = 0; j < N; ++j)
        {
            array[i][j] = rand() % 10;
            printf("[%d][%d] = %d    ", i, j, array[i][j]);
        }
    }

    printf("\n\n");
    dot(26);

    do
    {
        while (1)
        {
            char ch = 0;
            printf("\n\n\tВведите номер индекса строки массива");
            printf("\n\tдля определения кол-ва ненулевых элементов:");
            printf("\n     |\n     '->");
            if (!scanf_s("%d", &line) || getchar() != '\n')
            {
                while ((ch = getchar()) != '\n' && ch != EOF)
                    ;
            }
            else
                break;
        }

        if (line >= M || line < 0)
        {
            printf("\n\tНекорректный ввод номера индекса строки массива.");
            printf("\n\tНомер индекса строки выходит за пределы массива.");
            printf("\n\tНомер индекса строки может быть от 0 до %d.", M - 1);
        }

    } while (line >= M || line < 0);

    // суммируем кол-во ненулевых элементов
    for (int i = 0; i < N; ++i)
        result += CHECK(array[line][i]);

    printf("\n");
    dash(80);
    printf("\n\n\tКоличество ненулевых элементов в %d строке = %d\n", line, result);

    //освобождаем память
    for (int i = 0; i < M; ++i)
        free(array[i]);
    free(array);

    array = NULL;

    printf("\n");
    dotdot(80);
    printf("\n");
    tabs(9);
    printf("\n");
    equal(80);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}

//============================================================================
void dash(int count)
{
    for (int i = 0; i < count; i++)
        printf("-");
}
void dot(int count)
{
    for (int i = 0; i < count; i++)
        printf("  .");
}
void dotdot(int count)
{
    for (int i = 0; i < count; i++)
        printf(".");
}
void equal(int count)
{
    for (int i = 0; i < count; i++)
        printf("=");
}
void tabs(int count)
{
    for (int i = 0; i < count; i++)
        printf("\t|");
}
void apostrophe(int count)
{
    for (int i = 0; i < count; i++)
        printf("`");
}
void underscore(int count)
{
    for (int i = 0; i < count; i++)
        printf("_");
}
void eatline(void)
{
    while (getchar() != '\n')
        continue;
}
