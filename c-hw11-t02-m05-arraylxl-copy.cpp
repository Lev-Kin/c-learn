/*
// Задание 1:
// Написать программу, копирующую последовательно элементы одного массива размером 10 элементов в 2 массива размером 5 элементов каждый.

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " *** Программа копирования массивов ***\n\n";

    cout << " Основной массив из 10 элементов:\n";
    int array_main[10];
    int array_one[5];
    int array_two[5];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        array_main[i] = rand() % 100;
        cout <<" |"<< array_main[i] << "| ";
    }

    cout << "\n\n\n Копируем основной массив в два массива: \n";
    cout << " Первый из 5 элементов \n";
    for (int i = 0; i < 5; i++)
    {
        array_one[i] = array_main[i];
        cout <<" |"<< array_one[i] << "| ";
    }

    cout << "\n\n";
    cout << " Второй из 5 элементов \n";
    for (int j = 0, i = 5; i < 10; ++j, ++i)
    {
        array_two[j] = array_main[i];
        cout<<" |" << array_two[j] << "| ";
    }
    cout << "\n\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
}
*/

// Задание 2:
// Напишите программу, которая выполняет поэлементную сумму двух массивов и результат заносит в третий массив.

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " *** Программа сложения поэлементно массивов ***\n\n";

    cout << " Суммируем поэлементно первый и второй массив: \n";
    cout << " Первый массив из 10 элементов.\n";

    int array_main[10];
    int array_one[10];
    int array_two[10];
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        array_one[i] = rand() % 100;
        cout << " |" << array_one[i] << "| ";
    }

    cout << "\n\n Второй массив из 10 элементов.\n";
    for (int i = 0; i < 10; i++)
    {
        array_two[i] = rand() % 100;
        cout << " |" << array_two[i] << "| ";
    }

    cout << "\n\n Результат после поэлементного суммирования двух массивов:\n";
    for (int i = 0; i < 10; i++)
    {
        array_main[i] = array_one[i] + array_two[i];
        cout << " |" << array_main[i] << "| ";
    }

    cout << "\n\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
}
