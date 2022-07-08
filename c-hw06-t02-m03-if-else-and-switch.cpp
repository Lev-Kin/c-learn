/*
// 1. Зарплата менеджера составляет 200$ + процент от продаж;
//     продажи до 500$ - 3%, от 500 до 1000 – 5%, свыше 1000 – 8%. Пользователь
//     вводит с клавиатуры уровень продаж для трёх менеджеров. Определить их
//     зарплату, определить лучшего менеджера, начислить ему премию 200$, вывести
//     итоги на экран.

#include <windows.h>
#include <iostream>

using namespace std;
int main() {

    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, c;
    double sa, sb, sc;

    cout << " \n***Лучший менеджер и заработная плата.***\n\n";
    cout << " Введите уровень продаж первого  менеджера = "; cin >> a;
    cout << " Введите уровень продаж второго  менеджера = "; cin >> b;
    cout << " Введите уровень продаж третьего менеджера = "; cin >> c;

    if (a < 500)
        sa = 0.03 * a + 200;
    else
        if (a >= 500 && a <= 1000)
            sa = 0.05 * a + 200;
        else
            if (a > 1000)
                sa = 0.08 * a + 200;

    if (b < 500)
        sb = 0.03 * b + 200;
    else
        if (b >= 500 && b <= 1000)
            sb = 0.05 * b + 200;
        else
            if (b > 1000)
                sb = 0.08 * b + 200;

    if (c < 500)
        sc = 0.03 * c + 200;
    else
        if (c >= 500 && c <= 1000)
            sc = 0.05 * c + 200;
        else
            if (c > 1000)
                sc = 0.08 * c + 200;

    if (a > b && a > c)
        sa += 200;
    else
        if (b > c)
            sb += 200;
        else
            sc += 200;

    if (a > b&& a > c)
        cout << "\n Лучший уровень продаж первого  менеджера " << a << "$ и получает 200 $ премии!!!\n\n";
    else
        if (b > c)
            cout << "\n Лучший уровень продаж второго  менеджера " << b << "$ и получает 200 $ премии!!!\n\n";
        else
            cout << "\n Лучший уровень продаж третьего менеджера " << c << "$ и получает 200 $ премии!!!\n\n";

    cout << " Заработная плата первого  менеджера:" << sa << "$" << endl;
    cout << " Заработная плата второго  менеджера:" << sb << "$" << endl;
    cout << " Заработная плата третьего менеджера:" << sc << "$" << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}


// 2. Пользователь вводит с клавиатуры символ. Определить, какой это символ: буква,
//     цифра, знак препинания или другое.

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char symbol;
    cout << "***Определение что введено с клавиатуры***\n\n";
    cout << " Введите один любой символ ";
    cin >> symbol;

    if (symbol >= '0' && symbol <= '9')
    {
        cout << "\n Ввели цифру" << "\n";
    }

    else if (symbol >= 'A' && symbol <= 'Z')
    {
        cout << "\n Ввели БОЛЬШУЮ букву латиницы\n";
    }

    else if (symbol >= 'a' && symbol <= 'z')
    {
        cout << "\n Ввели малую букву латиницы\n";
    }

    else if (symbol >= 'А' && symbol <= 'Я' || symbol == 'Ё')
    {
        cout << "\n Ввели БОЛЬШУЮ букву кириллицы\n";
    }

    else if (symbol >= 'а' && symbol <= 'я' || symbol == 'ё')
    {
        cout << "\n Ввели малую букву кириллицы\n";
    }

    else
        std::cout << "\n Ввели знак\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;

}
*/

// 3. Вася работает программистом и получает 50$ за каждые 100 строк кода. За
//     каждое третье опоздание Васю штрафуют на 20$. Реализовать меню:
//     - пользователь вводит желаемый доход Васи и количество опозданий,
//       посчитать, сколько строк кода ему надо написать
//     - пользователь вводит количество строк кода, написанное Васей и желаемый
//       объем зарплаты. Посчитать, сколько раз Вася может опоздать
//     - пользователь вводит количество строк кода и количество опозданий,
//       определить, сколько денег заплатят Васе и заплатят ли вообще.

#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true)
    {
        cout << " *****| ВАСИНЫ нужды: опозданий, заработной платы, строк кода |*****\n";
        int salary;
        int line_codes;
        int be_late;
        int menu;

        cout << " ВАСЯ работает программистом и получает 50$ за каждые 100 строк кода.\n";
        cout << " За каждое третье опоздание Васю штрафуют на 20$.\n\n";
        int oneDollarTwoLCs = 2; // один доллар = две строки кода тариф
        int fine_pay = 20;       // штраф за опоздание 20$
        int fine = 3;            // За каждое третье опоздание начисляется штраф
        int fine_part;

        cout << " Введите номер пункта меню для расчета :\n\n";

        cout << "  1 - Расчет, сколько строк кода надо написать."
                "\n\tПри желаемой зарплате и количестве опозданий.\n\n";

        cout << "  2 - Расчет, сколько раз можно опоздать."
                "\n\tПри желаемой зарплате и написанных строках кода. \n\n";

        cout << "  3 - Расчет, сколько денег заплатят или не заплатят."
                "\n\tПри написанных строках кода и количестве опозданий.\n\n";

        cout << "  4 - ||ВыхоД||\n\n";

        cout << "> ";
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            cout << "\n\t1. Пункт меню выбран:\n\n";
            cout << "\tВведите желаемую зарплату: ";
            cin >> salary;
            cout << "\tВведите количество опозданий: ";
            cin >> be_late;

            line_codes = salary * oneDollarTwoLCs + ((be_late / fine) * fine_pay) * oneDollarTwoLCs;
            cout << "\n\tНеобходимо написать " << line_codes << " строк кода.\n";
        }
        break;

        case 2:
        {
            cout << "\n\t2. Пункт меню выбран:\n\n";
            cout << "\tВведите желаемую зарплату: ";
            cin >> salary;
            cout << "\tВведите количество написанных строк кода: ";
            cin >> line_codes;

            if (salary < line_codes)
            {
                fine_part = (salary + line_codes / oneDollarTwoLCs) / fine_pay;
                cout << "\n\tМожно опоздать " << fine_part / fine << " раза.\n";
            }
            else
                cout << "\n\t!Ошибка исходя из условия"
                        "\n\tзарплата должна быть меньше написанного кода."
                     << "\n";
        }
        break;

        case 3:
        {
            cout << "\n\t3. Пункт меню выбран:\n\n";
            cout << "\tВведите количество написанных строк кода: ";
            cin >> line_codes;
            cout << "\tВведите количество опозданий: ";
            cin >> be_late;

            if ((line_codes / oneDollarTwoLCs) - ((be_late / fine) * fine_pay) > 0)
            {
                cout << "\n\tЗарплата составила: " << (line_codes / oneDollarTwoLCs) - ((be_late / fine) * fine_pay) << "$.\n";
            }
            else
                cout << "\n\tНе заплатят.\n";
        }
        break;

        case 4:
        {
            cout << "\t___***|   Программа завершена   |***___\n\n";
        }
        break;

        default:
            cout << "\n\t!Ошибка ввода перезайдите.\n";
        }
        return 0;
    }

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}
