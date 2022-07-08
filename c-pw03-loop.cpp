/*
// 1. Пользователь вводит две границы диапазона, вывести на экран все числа из этого диапазона.
// Предусмотреть, чтобы пользователь мог вводить границы диапазона корректно.
// вывести все четные числа из диапазона.
// вывести все нечетные числа из диапазона.
// вывести все числа, кратные семи.

#include <windows.h>
#include <iostream>

using namespace std;

int main(void)
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "*Задать границы диапазона и получить:\n";
    cout << "чётные числа, нечетные числа, кратные семи числа.*\n\n";
    cout << "Введите границы в диапазоне от 0 до 100 целочисленные значения\n\n";
    int a, b;
    if (cout << "Первая граница = ", cin >> a, cout << "Вторая граница = ", cin >> b)
        cout << "\nЗначения получины:\t___|" << a << ">>>_____<<<" << b << "|___\n";
    else
        cout << "\n\n!Ошибка одна из границ диапазона не является числом\n или не является целым числом.\n";

    while (a < 101 && b < 101 && a > -1 && b > -1)
    {
        cout << "\nЧисла диапазона:" << endl;
        for (int i = a; i <= b; i++)
        {

            cout << i << " ";
        }
        cout << endl;

        cout << "\nЧётные:" << endl;
        for (int i = a; i <= b; i++)
        {
            if ((i % 2) == 0)
                cout << i << " ";
        }
        cout << endl;

        cout << "\nНечётные:" << endl;
        for (int i = a; i <= b; i++)
        {
            if ((i % 2) != 0)
                cout << i << " ";
        }
        cout << endl;

        cout << "\nКратные семи:" << endl;
        for (int i = a; i <= b; i++)
        {
            if ((i % 7) == 0)
                cout << i << " ";
        }

        cout << "\n";
        break;
    }

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 2. Пользователь вводит число. «Перевернуть» его, записать в другую переменную и вывести на экран.

#include <windows.h>
#include <iostream>

using namespace std;

int main(void)
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a(0), b(0);
    cout << " ******Переворот числа******\n\n";
    cout << " Больше значения 123456789 вводить не допускается.\n\n";
    cout << " Введите число   ";
    cin >> a;

    while (a < 200000000)
    {
        for (; a > 0;)
        {
            b = b * 10 + a % 10;
            a = (a - a % 10) / 10;
        }
        break;
    }

    if (b)
        cout << "\n Число перевернуто   " << b << endl
             << endl;
    else
        cout << "\n Ошибка вы ввели неправильно.\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
*/

// 3. Пользователь набирает текст. Определить, сколько букв, цифр,
// пробелов и других символов он ввел. (Текст нигде не сохраняется).

#include <windows.h>
#include <string>
#include <iostream>

using namespace std;
int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int letter = 0, digit = 0, symbol = 0;
    char str[500];
    cout << "\n***Определение кол- во букв, цифр, пробелов и др символов.***" << endl;
    cout << "!Ввод кириллицы не учитывается!" << endl
         << endl;
    cout << "Введите строку:" << endl;
    cin.getline(str, 500); // ввод данных из потока
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
            letter++;
        else if (isdigit(str[i]))
            digit++;
        else
            symbol++;
    }
    cout << "\nКоличество букв в строке: " << letter << endl;
    cout << "Количество цифр в строке: " << digit << endl;
    cout << "Количество пробелов других символов в строке: " << symbol << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}
