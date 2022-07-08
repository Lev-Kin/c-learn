// Предусмотреть два варианта ввода элементов массива:
// - ввод с клавиатуры;
// - ввод через генерацию случайных чисел.

// Задана квадратная матрица порядка 7. Вычислить сумму положительных
// элементов, лежащих ниже побочной диагонали.
// Программа должна выполнять ввод и вывод матрицы и
// дополнительных данных, выполнять необходимые действия и выводить
// результаты.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand()
#include <time.h>   // в этом файле содержится функция time()
#include <conio.h>  // в этом файле содержится функция getch()

int main(void);
void mas_vvod_klava(int[][7], int, int);
void mas_vvod_random(int[][7], int, int);
void mas_vyvod(int[][7], int, int);           //вывод цифр всего заданного массива
void mas_vyvod_side_down(int[][7], int, int); //вывод цифр лежащих ниже побочной диагонали
void mas_summa(int[][7], int, int);           //сумма положительных элементов, лежащих ниже побочной диагонали

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int prodolgenie = 1;
    int chislo_menu = 0;
    int array[7][7];
    int sposob_vvoda = 0;
    int m = 7, n = 7;
    do
    {
        system("cls");
        printf(" ***| Программа работы с двухмерными массивами | ***\n\n"
               " 1:Ввод массива с клавиатуры.\n");
        printf(" 2:Ввод массива через генерацию случайных чисел.\n");
        printf(" 3:Выход из программы.\n\n>");
        scanf("%d", &chislo_menu);
        switch (chislo_menu)
        {
        case 1:
            mas_vvod_klava(array, m, n);
            mas_vyvod(array, m, n);
            mas_vyvod_side_down(array, m, n);
            mas_summa(array, m, n);
            printf("\n Для продолжения-ENTER.");
            getch();
            break;

        case 2:
            mas_vvod_random(array, m, n);
            mas_vyvod(array, m, n);
            mas_vyvod_side_down(array, m, n);
            mas_summa(array, m, n);
            printf("\n Для продолжения-ENTER.");
            getch();
            break;

        case 3:
            prodolgenie = 0;
            break;

        default:
            printf("\n Неверный пункт меню. Будьте внимательны!!!\n");
            printf("\n Для продолжения-ENTER.");
            getch();
            break;
        }
    } while (prodolgenie != 0);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void mas_vvod_klava(int mas[][7], int m, int n)
{
    int i, j;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("A[%d][%d]=", i, j);
            scanf("%d", &mas[i][j]);
        }
    }
}

void mas_vvod_random(int mas[][7], int m, int n)
{
    int i, j;
    srand((unsigned)time(NULL));

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            mas[i][j] = rand() % 201 - 100;
        }
    }
}

void mas_vyvod(int mas[][7], int m, int n)
{
    int i, j;
    printf("\n Исходный массив данных:\n\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%-5d", mas[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mas_vyvod_side_down(int mas[][7], int m, int n)
{
    int i, j;
    printf(" Числа нижней побочной диагонали:\n\n");

    for (i = 1; i < m; i++)
    {
        for (j = n - i; j < n; j++)
        {
            printf("[%d][%d]=%-5d", i, j, mas[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mas_summa(int mas[][7], int m, int n) //сумма положительных элементов, лежащих ниже побочной диагонали
{
    int i, j, s = 0;
    for (i = 1; i < m; i++)
    {
        for (j = n - i; j < n; j++)
        {
            if (mas[i][j] > 0)
                s += mas[i][j];
        }
    }
    printf(" Сумма положительных чисел нижней побочной диагонали = %d\n", s);
}
