/*
// 1. Пользователь вводит с клавиатуры целое шестизначное число. Написать
//     программу, которая определяет, является ли введённое число – счастливым.
//     Счастливым считается шестизначное число, у которого сумма первых 3 цифр
//     равна сумме вторых трёх цифр.
//     Если пользователь ввёл не шестизначное число – сообщение об ошибке.

#include <windows.h>
#include <iostream>

using namespace std;
int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int v, k, i, part1 = 0, part2 = 0;
    cout << "Введите целое шестизначное число: \n\n";
    cin >> v;
    while (100000 >= v || v > 999999)
    {
        cout << "\nНекорректный ввод числа введите еще раз!\n";
        cin >> v;
    }
    for (int i = 0; v; i++)
    {
        int k = v % 10;
        if (i < 3)
            part1 += k;
        else
            part2 += k;
        v = v / 10;
    }
    if (part1 == part2)
        cout << "\n У Вас счастливое число :-).\n";
    else
    {
        (part1 != part2);
        cout << "\n У Вас не счастливое число :-(.\n";
    }

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}


// 2. Пользователь вводит четырёхзначное число. Необходимо поменять в этом числе
//     первую и вторую цифры, а также третью и четвёртую цифры.  Если пользователь
//     вводит не четырёхзначное число – вывести сообщение об ошибке.

#include <windows.h>
#include <stdio.h>

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num;

    printf("\n Введите четырёхзначное число: ");
    scanf("%d", &num);

    if (num >= 1000 && num <= 9999)
    {
        int num_buff = 0;
        num_buff += (num % 10) * 10;
        num_buff += (num / 10 % 10);
        num_buff += (num / 100 % 10) * 1000;
        num_buff += (num / 1000) * 100;
        printf("%s%d\n", "\n Цифры после обработки следущие: ", num_buff);
    }

    else printf("\n Ошибка: Вы ввели не четырёхзначное число. \n");

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}


// 3. Пользователь вводит с клавиатуры 7 целых чисел. Напишите программу, которая
//     определяет максимальное из этих 7 чисел.

#include <windows.h>
#include <stdio.h>

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf(" ***Максимальное число из семи***\n");

    int number, Max;
    printf("%s%d%s", "\n Введите число ", 1, " --> ");
    scanf("%d", &Max);
    for (int i = 1; i < 7; i++)
    {
        printf("%s%d%s", " Введите число ", i + 1, " --> ");
        scanf("%d", &number);
        if (number > Max) Max = number;
    }
    printf("\n%s%d\n", " Максимальное число из семи введенных : ", Max);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}


// 4. Грузовой самолёт должен пролететь с грузом из пункта А в пункт С через пункт
//     В. Ёмкость бака для топлива у самолёта – 300 литров. Потребление топлива на 1
//     км в зависимости от веса груза у самолёта следующее:
// 	- до 500 кг  :    1 литров / км
// 	- до 1000 кг :   4 литров / км
// 	- до 1500 кг :   7 литров / км
// 	- до 2000 кг :   9 литров / км.
// 	- более 2000 кг – самолёт не поднимает.
//     Пользователь вводит расстояние между пунктами А и В, и расстояние между
//     пунктами В и С, а также вес груза. Программа должна рассчитать какое
//     минимальное количество топлива необходимо для дозаправки самолёту в пункте
//     В, чтобы долететь из пункта А в пункт С. В случае невозможности преодолеть
//     любое из расстояний – программа должна вывести сообщение о невозможности
//     полёта по введённому маршруту.

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int capacityMax = 300, weightMax = 2000, d1, d2, weight;

        cout << "\n Введите расстояние между A и B: "; cin >> d1;
        cout << "\n Введите расстояние между B и C: "; cin >> d2;
        cout << "\n Введите вес груза: "; cin >> weight;

        if (weight > weightMax)
        {
            cout << "\n Взлётный вес превышен! \n";
            return 0;
        }
        else
        {
            int с1 = 9, с2 = 7, с3 = 4, с4 = 1, rest = capacityMax;

            do
            {
                if (weight >= 1500) rest -= с1;
                else if (weight >= 1000) rest -= с2;
                else if (weight >= 500) rest -= с3;
                else rest -= с4;
                d1--;

                if (rest <= 0 && d1 == 0)
                {
                    cout << "\n На первый участок маршрута топлива не хватит! \n";
                    return 0;
                }
            } while (d1 > 0);

            int fuelCalculation;

            if (weight >= 1500) fuelCalculation = d2 * с1;
            else if (weight >= 1000) fuelCalculation = d2 * с2;
            else if (weight >= 500) fuelCalculation = d2 * с3;
            else fuelCalculation = d2 * с4;

            if (fuelCalculation > capacityMax)
            {
                cout << "\n На второй участок маршрута топлива не хватит! \n";
                return 0;
            }
            else if (rest > fuelCalculation) cout << "\n Дозаправка не требуется. \n";
            else cout << "\n Необходимо минимум " << fuelCalculation - rest << " литров топлива. \n";
        }

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}
*/

// 5. Пользователь вводит две даты (день, месяц, год в виде целых чисел). Необходимо
//     определить и вывести количество дней между этими двумя датами. Для расчётов
//     учитывать високосные года, а также корректное число дней в месяцах (март – 31,
//     сентябрь – 30, февраль не високосного года – 28 и т.д.).

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b, c, d, e, f, x, y = 0;
    int leap, ly;
    int m1 = 31, m2 = 28, m3 = 31, m4 = 30, m5 = 31, m6 = 30, m7 = 31, m8 = 31, m9 = 30, m10 = 31, m11 = 30, m12 = 31;

    cout << " \n***Подсчет кол-во дней между датами.***\n\n";

    cout << " Введите начальную дату ДД.MM.ГГГГ через пробел: ";
    cin >> a >> b >> c;
    cout << " \n Введите конечную дату ДД.MM.ГГГГ через пробел: ";
    cin >> d >> e >> f;

    //высчитываем сколько было високосных лет в заданном интервале
    leap = c;
    ly = 0;
    while (leap <= f)
    {
        if (leap % 4 == 0 && leap % 100 != 0 || leap % 400 == 0)
        {
            ly = ly + 1;
        }
        leap++;
    }
    cout << "\n Високосных лет = " << ly << endl;

    //высчитываем сколько прошло дней в году до начальной даты
    if (b == 1)
    {
        x = a;
    }
    else if (b == 2)
    {
        x = m1 + a;
    }
    else if (b == 3)
    {
        x = m1 + m2 + a;
    }
    else if (b == 4)
    {
        x = m1 + m2 + m3 + a;
    }
    else if (b == 5)
    {
        x = m1 + m2 + m3 + m4 + a;
    }
    else if (b == 6)
    {
        x = m1 + m2 + m3 + m4 + m5 + a;
    }
    else if (b == 7)
    {
        x = m1 + m2 + m3 + m4 + m5 + m6 + a;
    }
    else if (b == 8)
    {
        x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + a;
    }
    else if (b == 9)
    {
        x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + a;
    }
    else if (b == 10)
    {
        x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + a;
    }
    else if (b == 11)
    {
        x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + a;
    }
    else if (b == 12)
    {
        x = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + a;
    }

    //высчитываем сколько прошло дней в году до конечной даты
    if (e == 1)
    {
        y = d;
    }
    else if (e == 2)
    {
        y = m1 + d;
    }
    else if (e == 3)
    {
        y = m1 + m2 + d;
    }
    else if (e == 4)
    {
        y = m1 + m2 + m3 + d;
    }
    else if (e == 5)
    {
        y = m1 + m2 + m3 + m4 + d;
    }
    else if (e == 6)
    {
        y = m1 + m2 + m3 + m4 + m5 + d;
    }
    else if (e == 7)
    {
        y = m1 + m2 + m3 + m4 + m5 + m6 + d;
    }
    else if (e == 8)
    {
        y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + d;
    }
    else if (e == 9)
    {
        y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + d;
    }
    else if (e == 10)
    {
        y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + d;
    }
    else if (e == 11)
    {
        y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + d;
    }
    else if (e == 12)
    {
        y = m1 + m2 + m3 + m4 + m5 + m6 + m7 + m8 + m9 + m10 + m11 + d;
    }

    //если начальная дата високосный год больше 29 февраля то отнимаем 1 от кол-во високосных лет
    if ((c % 4 == 0 && leap % 100 != 0 || leap % 400 == 0) && b > 2)
    {
        ly = ly - 1;
    }

    //если конечная дата до 29 февраля то отнимаем 1 от високосных лет
    if ((f % 4 == 0 && leap % 100 != 0 || leap % 400 == 0) && d <= 29 && e < 3)
    {
        ly = ly - 1;
    }

    if (c == f)
    {
        cout << "\n Количество дней между датами : " << (y - x) + ly << endl
             << endl;
    }
    else
        cout << "\n Количество дней между датами : " << (f - c) * 365 + ((y - x) + ly) << endl
             << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}
