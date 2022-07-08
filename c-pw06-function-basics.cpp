/*
// 1. Написать функцию, которая возвращает истину, если переданное число простое, и
//     ложь, если не простое. Простое число – это число, которое делиться только на 1
//     и на себя (2, 5, 7, 11 и т.д.).

#include <windows.h>
#include <iostream>
#include <stdbool.h> //содержится определение логических констант true и false

using namespace std;

bool primeNumber(int n); // функция проверяет - простое ли число n

void main()
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int digit;
    do
    {
        system("cls");

        cout << " ***Эта программа проверяет число - простое оно или сложное***\n\n";
        cout << " Введите число --> ";
        cin >> digit;
        if (primeNumber(digit) == 1)
            cout << " Введенное число простое\n";
        else
            cout << " Введенное число сложное\n";
        cout << "\n\n Продолжить - нажмите 1\n";
        cout << "  | ВыхоД | - нажмите 2 и Enter.\n\n";
        cin >> digit;
    } while (digit == 1);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
}

bool primeNumber(int n)
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
*/

// 2. Напишите функцию, которая принимает радиус окружности и рисует
//       окружность из звёздочек.
//       Рекомендации: Чтобы круг не выглядел сплюснутым выводите звездочки через
//       пробел.

#include <iostream>
#include <math.h>
using namespace std;

// double можно везде заменить на int
// тогда круг станет менее читаем
// но можно задавать разные значения радиуса

double print(double x, double y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main()
{

    double r = 10; // можно 20, 30, 40 итд, иначе круг пропадет
    const double width = r;
    const double length = r * 1.5;
    cout << "\n";

    for (double y = width; y >= -width; y -= 2)
    {
        for (double x = -length; x <= length; x++)
        {
            if ((double)print(x, y) == r)
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}
