/*
// Задание 1:
// Напишите программу, которая создаёт двухмерный целочисленный массив и заполняет
// его по следующему принципу: пользователь вводит число (например, 3) первый
// элемент массива принимает значение этого числа, последующий элемент массива
// принимает значение этого числа умноженного на 2 (т.е. 6 для нашего примера),
// третий элемент массива предыдущий элемент умноженный на 2 (т.е. 6*2=12 для нашего примера)
// и т.д. Созданный массив вывести на экран.
// Размер массива: количество строк и столбцов не менее 3-х и не более 7.

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << " *** Программа работы с двумерным массивом ***" << endl
         << endl;

    long long num;
    int rows, cols;
    cout << " Введите число (например 3) = ";
    cin >> num;
    do
    {
        cout << endl
             << " Введите количество строк в массиве = ";
        cin >> rows;
        if (rows < 3 || rows > 7)
        {
            cout << " Количество строк должно быть не меньше 3 и не больше 7." << endl;
        }
    } while (rows < 3 || rows > 7);
    do
    {
        cout << endl
             << " Введите количество столбцов = ";
        cin >> cols;
        if (cols < 3 || cols > 7)
        {
            cout << " Количество столбцов должно быть не меньше 3 и не больше 7." << endl;
        }
    } while (cols < 3 || cols > 7);

    long long **array = new long long *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new long long[cols];
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = num;
            num *= 2;
        }
    }

    cout << endl
         << " Вывод созданного массива на экран: " << endl
         << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << " [" << i << "][" << j << "] = " << array[i][j] << " ";
            cout << endl;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// Задание 2:
// Напишите программу, которая создаёт двухмерный целочисленный массив и заполняет
// его по следующему принципу: пользователь вводит число (например, 3) первый элемент
// массива принимает значение этого числа, последующий элемент массива принимает
// значение этого числа + 1 (т.е. 4 для нашего примера), третий элемент массива
// предыдущий элемент + 1 (т.е. 5 для нашего примера). Созданный массив вывести
// на экран. Размер массива: количество строк и столбцов не менее 3-х и не более 7.

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << " *** Программа работы с двумерным массивом ***" << endl
         << endl;

    int num;
    int rows, cols;
    cout << " Введите число (например 3) = ";
    cin >> num;
    do
    {
        cout << endl
             << " Введите количество строк в массиве = ";
        cin >> rows;
        if (rows < 3 || rows > 7)
        {
            cout << " Количество строк должно быть не меньше 3 и не больше 7." << endl;
        }
    } while (rows < 3 || rows > 7);
    do
    {
        cout << endl
             << " Введите количество столбцов = ";
        cin >> cols;
        if (cols < 3 || cols > 7)
        {
            cout << " Количество столбцов должно быть не меньше 3 и не больше 7." << endl;
        }
    } while (cols < 3 || cols > 7);

    int **array = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = num;
            num += 1;
        }
    }

    cout << endl
         << " Вывод созданного массива на экран: " << endl
         << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << " [" << i << "][" << j << "] = " << array[i][j] << " ";
            cout << endl;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
*/


// Задание 3:
// Создайте двухмерный целочисленный массив. Заполните его случайными числами и
// покажите на экран. Диапазон случайных чисел [-100, 100]. Пользователь выбирает
// количество сдвигов и положение (влево, вправо, вверх, вниз). Выполнить
// сдвиг массива и показать на экран полученный результат. Сдвиг циклический.
// Размер массива: количество строк и столбцов не менее 3-х и не более 7.
// Например, если мы имеем следующий массив
// 1 2 0 4 5 3
// 4 5 3 9 0 1
// и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
// 5 3 1 2 0 4
// 0 1 4 5 3 9

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand()
#include <time.h>   // в этом файле содержится функция time()
#include <conio.h>  // в этом файле содержится функция getch()

int main(void);
void dash(int);
void input_array_random(int[][7], int, int);      //ввод случайных чисел от -100 до 100
void input_array_change_menu(int[][7], int, int); //ввод кол-ва сдвигов и направление
void output_array_primary(int[][7], int, int);    //вывод созданного массива
void output_array_changed(int[][7], int, int);    //вывод измененного массива

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int array[7][7];
    int n;
    int m;

    int menu_number = 0;
    bool go_back = true;
    do
    {
        system("cls");
        printf(" ***| Программа работы со сдвигом чисел в двумерном массиве |***\n\n");
        printf(" _____________| Главное меню |____________\n");
        printf(" 1:Ручной ввод кол-во строк и столбцов массива.\n");
        printf(" 2:Заданное кол-во строк и столбцов массива.\n");
        printf(" 3: | ВыхоД |\n\n>");
        scanf("%d", &menu_number);
        switch (menu_number)
        {
        case 1:
            printf("\n Задайте количество строк: ");
            do
            {
                scanf("%d", &n);
                if (n < 3 || n > 7)
                {
                    printf("\n Число строк должно быть не меньше 3 и не больше 7.\n");
                    printf(" Задайте количество строк: ");
                }
            } while (n < 3 || n > 7);
            printf("\n Задайте количество столбцов: ");
            do
            {
                scanf("%d", &m);
                if (m < 3 || m > 7)
                {
                    printf("\n Число в столбцов должно быть не меньше 3 и не больше 7.\n");
                    printf(" Задайте количество столбцов: ");
                }
            } while (m < 3 || m > 7);

            input_array_random(array, n, m);
            output_array_primary(array, n, m);
            input_array_change_menu(array, n, m);
            break;

        case 2:
            n = 7;
            m = 7;

            input_array_random(array, n, m);
            output_array_primary(array, n, m);
            input_array_change_menu(array, n, m);
            break;

        case 3:
            go_back = false;
            break;

        default:
            printf("\n Неверный пункт меню. Будьте внимательны!!!\n");
            printf("\n Для продолжения-ENTER.");
            getch();
            break;
        }
    } while (go_back);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void input_array_random(int array[][7], int n, int m)
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            array[i][j] = rand() % 201 - 100;
        }
    }
}

void output_array_primary(int array[][7], int n, int m)
{
    int i, j;
    printf("\n Исходный массив данных:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%5d", array[i][j]);
            if ((j + 1) % m == 0)
                printf("\n");
        }
    }
}

void input_array_change_menu(int array[][7], int n, int m)
{
    int shift; //количество сдвигов
    printf("\n Задайте сдвиг массива на --> ");
    do
    {
        scanf("%d", &shift);
        if (shift < 0)
        {
            printf("\n Сдвиг массива не может быть отрицательным.\n");
            printf(" Задайте сдвиг массива на --> ");
        }
    } while (shift < 0);

    int menu_number = 0;
    bool go_back = true;
    int i, j, k;
    do
    {
        printf("\n ---| Сдвиг массива = %d  |---\n", shift);
        printf(" ___| Меню выбора сдвига |___\n");
        printf(" 1:Влево.\n");
        printf(" 2:Вправо.\n");
        printf(" 3:Вверх.\n");
        printf(" 4:Вниз.\n");
        printf(" 5: | Выход в Главное меню |\n\n>");
        scanf("%d", &menu_number);
        switch (menu_number)
        {
        case 1:
            printf("\n Сдвиг ВЛЕВО на %d.", shift);
            for (k = 0; k < shift; k++)
            {
                for (i = 0; i < n; i++)
                {
                    int tmp = array[i][0];
                    for (j = 0; j < m - 1; j++)
                        array[i][j] = array[i][j + 1];
                    array[i][m - 1] = tmp;
                }
            }
            output_array_changed(array, n, m);
            printf("\n Для продолжения-ENTER.\n");
            getch();
            dash(35);
            break;

        case 2:
            printf("\n Сдвиг ВПРАВО на %d.", shift);
            for (k = 0; k < shift; k++)
            {
                for (i = 0; i < n; i++)
                {
                    int tmp = array[i][m - 1];
                    for (j = m - 1; j > 0; j--)
                        array[i][j] = array[i][j - 1];
                    array[i][0] = tmp;
                }
            }
            output_array_changed(array, n, m);
            printf("\n Для продолжения-ENTER.\n");
            getch();
            dash(35);
            break;

        case 3:
            printf("\n Сдвиг ВВЕРХ на %d.", shift);
            for (k = 0; k < shift; k++)
            {
                for (j = 0; j < m; j++)
                {
                    int tmp = array[0][j];
                    for (i = 0; i < n - 1; i++)
                        array[i][j] = array[i + 1][j];
                    array[n - 1][j] = tmp;
                }
            }
            output_array_changed(array, n, m);
            printf("\n Для продолжения-ENTER.\n");
            getch();
            dash(35);
            break;

        case 4:
            printf("\n Сдвиг ВНИЗ на %d.", shift);
            for (k = 0; k < shift; k++)
            {
                for (j = 0; j < m; j++)
                {
                    int tmp = array[n - 1][j];
                    for (i = n - 1; i > 0; i--)
                        array[i][j] = array[i - 1][j];
                    array[0][j] = tmp;
                }
            }
            output_array_changed(array, n, m);
            printf("\n Для продолжения-ENTER.\n");
            getch();
            dash(35);
            break;

        case 5:
            go_back = false;
            break;

        default:
            printf("\n Неверный пункт меню. Будьте внимательны!!!\n");
            printf("\n Для продолжения-ENTER.\n");
            getch();
            break;
        }
    } while (go_back);
}

void output_array_changed(int array[][7], int n, int m)
{
    int i, j;
    printf("\n Измененный массив данных:\n\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%5d", array[i][j]);
            if ((j + 1) % m == 0)
                printf("\n");
        }
    }
}

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        printf("-");
}
