/*
// 1. Написать программу, которая определяет,
// каким днем (Рабочий день, Суббота, Воскресенье)
// является введенный номер дня недели.

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main(void)
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int day; // объявляем переменную для ввода
    cout << "Введите номер дня недели:\n";
    cin >> day;
    switch (day)
    {
    case 1:
        cout << "Рабочий день\n";
        break;
    case 2:
        cout << "Рабочий день\n";
        break;
    case 3:
        cout << "Рабочий день\n";
        break;
    case 4:
        cout << "Рабочий день\n";
        break;
    case 5:
        cout << "Рабочий день\n";
        break;
    case 6:
        cout << "Суббота\n";
        break;
    case 7:
        cout << "Воскресенье\n";
        break;
    default:
        cout << "Нет такого"
             << " дня недели" << '\n';
    }
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
*/

// 2. Пользователь вводит два числа. Определить,
// равны ли эти числа, и если нет, вывести их на экран порядке возрастания.

#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdio.h>

using namespace std;

int main(void)
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b;
    cout << " *************Определения равенства чисел************* \n";
    cout << " *Если числа не равны выводятся в порядке возрастания* \n";
    cout << "\n";
    cout << " Введите два целочисленных числа \n";
    cout << "\n Первое число -> ";
    cin >> a;
    cout << " Второе число -> ";
    cin >> b;

    if (a != b)
    {
        cout << "\n Числа " << a << " и " << b << " не равны.\n";
        if (a < b)
            cout << " Вывод в порядке возрастания " << a << "  " << b << endl;
        else
            cout << " Вывод в порядке возрастания " << b << "  " << a << endl;
    }
    else if (a == b)
    {
        cout << "\n Числа " << a << " и " << b << " равны.\n";
    }

    return 0;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
