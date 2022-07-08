/*
// 1. Пользователь вводит с клавиатуры две стороны прямоугольника.
// Подсчитать площадь и периметр прямоугольника.

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double l1, l2; //длины
    cout << "Нахождение площади и периметра прямоугольника. \n";
    cout << "\n";
    cout << "Введите первую сторону прямоугольника.\n";
    cin >> l1;
    cout << "Введите вторую сторону прямоугольника.\n";
    cin >> l2;

    double S = l1 * l2;       // вычисление площади прямоугольника
    double P = 2 * (l1 + l2); // вычисление периметра прямоугольника

    cout << "\n";
    cout << "Площадь прямоугольника = " << S << "\n";
    cout << "Периметр прямоугольника = " << P << "\n";
    cout << "\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 2. Пользователь вводит с клавиатуры двухзначное число.
// Вывести на экран количество десятков и единиц этого числа.

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int l1;
    cout << "Вывод на экран количество десятков и единиц числа. \n";
    cout << "\n";
    cout << "Введите число от 1 до 100\n";
    cin >> l1;

    int d = l1 / 10; // вычисление десятков

    cout << "\n";
    cout << "Число " << l1 << " имеет - \n";
    cout << d << " десятков и " << l1 % 10 << " единиц.\n";
    cout << "\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
*/

// 3. Стоимость проезда в маршрутке – 7000 бел. руб.
// Количество сидячих мест –  20. Количество стоячих – 10.
// За день 50% поездок маршрутка полностью   наполнена,
// 30% - заполнены только сидячие места ,
// 20% - половина сидячих  мест пуста.
// Пользователь вводит расстояние одной поездки,
// стоимость бензина и расход бензина.
// Подсчитать прибыль с учетом расходов на бензин.

#include <windows.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main()
{
    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Данные получаем из условия задачи (количество пассажиров)
    double price = 7000, place_site = 20, place_stand = 10;
    // Делаем мин кол-во частей поездки две иначе условие задачи не выполняется
    double onePartTrip = place_site + place_stand;                                                     // одна часть поездки полностью заполнена
    double twoPartTrip = (place_site / 100) * 30 + (place_site / 2 - (((place_site / 2) / 100) * 20)); // вторая часть поездки
    double sumPas = onePartTrip + twoPartTrip;                                                         // Пасажиры поездки

    double dis, oil_price, oil_lesCar; // инициализация для ввода переменных
    cout << "\n";
    cout << "Подсчет прибыли с учетом расходов на бензин. \n";
    cout << "\n";
    cout << "Введите пройденное расстояния транспорта в км.\n";
    cin >> dis;
    cout << "Введите стоимость бензина за литр.\n";
    cin >> oil_price;
    cout << "Введите расход бензина транспорта литров на 100 км.\n";
    cin >> oil_lesCar;

    double lesMoney = ((oil_lesCar / 100) * dis) * oil_price;
    double plsMoney = sumPas * price;
    double profit = plsMoney - lesMoney;

    cout << "\n";
    cout << "Пассажиров за поездку " << sumPas << " человек\n";
    cout << "Прибыль составила " << profit << " денег\n";
    cout << "\n";

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}
