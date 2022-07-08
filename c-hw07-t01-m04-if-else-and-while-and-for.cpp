/*
// 1. Напишите программу, которая вычисляет сумму целых чисел от а до 500 (значение a вводится с
//     клавиатуры).

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int sum = 0;
    int a;
    cout << " ***Нахождение суммы целых чисел от а до 500***";
    cout << "\n\n Введите a = "; cin >> a;

    if (a > 500)
    {
        cout << "\n а > 500" << endl;
    }
    else
    {
        sum = (500 * 501 / 2) - ((a - 1) * a) / 2;
        cout << " \n Сумма чисел от " << a << " до 500 = " << sum << endl;
    }

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;

}


// 2. Напишите программу, которая запрашивает два целых числа x и y, после чего вычисляет и
//     выводит значение x в степени y. Встроенные функции не использовать.

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " ***Определить значение х в степени у***" << endl<< endl;

    int x, y, z = 1;

        cout << " Введите значение х = "; cin >> x;
        cout << " Введите степень   у = "; cin >> y;

    for (int i = 0; i < y; ++i)
        z *= x;

    cout <<"\n "<<x<<" в степени "<<y<<" = "<< z << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}


// 3. Найти среднее арифметическое всех целых чисел от 1 до 1000.

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " ***Среднее арифметическое всех целых чисел от 1 до 1000***" << endl;

    double m = 0;
    for (int i = 1; i <= 1000; i++)
    {
        m += i;
    }
    m /= 1000;

    cout <<"\n Будет = "<< m << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}


// 4. Найти произведение всех целых чисел от a до 20. Значение a вводится с клавиатуры:
// 1 <= a <= 20.

#include <windows.h>
#include <stdio.h>

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b = 1, i = 1;
    printf(" ***Найти произведение всех целых чисел от a до 20***\n\n");
    printf("\t  Введите число a (от 1 до 20): ");
    scanf_s("%d", &a);

    if ( a != 0 && a <= 19)
    {
        while (i <= a)
        {
            b *= i;
            i++;
        }
        printf("\n\t  %d\n", b);
    }
    else
        printf("\n\t  !Ошибка при вводе.\n");

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}
*/

// 5. Написать программу, которая выводит на экран таблицу умножения на k, где k – номер
//     варианта. Например, для 7-го варианта:
//     7 * 2 = 14
//     7 * 3 = 21

#include <windows.h>
#include <stdio.h>

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int v; //вариант который вводим в таблицу умножения
    int m; //множитель
    int p; //произведение

    printf("\n Введите вариант для таблицы умножения --> ");
    scanf_s("%d", &v);

    printf("\n Таблица умножения на %d <--\n\n", v);

    for (m = 1; m <= 9; m++)
    {
        p = v * m;
        printf(" %d x %d = %d\n", v, m, p);
    }

    printf(" \n ---| Программа завершена |---\n");

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}
