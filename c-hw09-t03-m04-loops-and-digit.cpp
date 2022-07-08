/*
// 1. Подсчитать количество целых чисел в диапазоне от 100 до 999, у которых есть две одинаковые
//     цифры

#include <windows.h>
#include <stdio.h>

int main()
{
    system("cls");

    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int result = 0, num1, num2, num3;
    for (int num = 100; num <= 999; num++)
    {
        num1 = num / 100;        //первая цифра
        num2 = num % 10;         //вторая цифра
        num3 = (num % 100) / 10; //третья цифра
        if (num1 == num2 || num2 == num3 || num1 == num3)
        {
            result++;
        }
    }
    printf("\n Количество целых чисел в диапазоне от 100 до 999\n\n"
           " у которых две одинаковые цифры --> %d\n",
           result);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 2. Подсчитать количество целых чисел в диапазоне от 100 до 999, у которых все цифры разные

#include <windows.h>
#include <stdio.h>

int main()
{
    system("cls");

    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int result = 0, num1, num2, num3;
    for (int num = 100; num <= 999; num++)
    {
        num1 = num / 100;
        num2 = num % 10;
        num3 = (num % 100) / 10;
        if (num1 != num2 && num2 != num3 && num1 != num3)
        {
            result++;
        }
    }

    printf("\n Количество целых чисел в диапазоне от 100 до 999\n\n"
           " у которых все цифры разные --> %d\n",
           result);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 3. Пользователь вводит любое целое число. Необходимо из этого целого числа удалить все цифры
//     3 и 6 и вывести обратно на экран. Если таковых цифр нет, выдать соответствующее сообщение.

#include <windows.h>
#include <stdio.h>

int main()
{
    system("cls");

    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    long long number, a = 1, out = 0;
    printf(" *** Программа удаления цифр 3 и 6 из целого числа ***\n\n");
    printf(" Введите любое целое число --> ");
    scanf("%lld", &number);
    long long number_buffer = number;

    while (number > 0)
    {
        if (number % 10 != 3 && number % 10 != 6)
        {
            out += a * (number % 10);
            a *= 10;
        }
        number /= 10;
    }

    if (out == 0)
    {
        printf("\n Введены только числа 3 и 6\n"
               " дальнейшая реализация программы невозможна.\n");
    }
    else if (out >= number_buffer)
        printf("\n Введенном числе |! %lld !|\n"
               " отсутствуют цифры 3 или 6 для удаления.\n",
               number_buffer);

    else if (out < number_buffer)
        printf("\n Цифры из введенного числа |-> %lld <-|\n"
               " были удалены.\n\n"
               " Результат следующий --> %lld .\n",
               number_buffer, out);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 4. Пользователь вводит любое целое число А. Необходимо вывести все целые числа В, для
//     которых А делится без остатка на В*В и не делится без остатка на В*В*В.

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");

    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int a, b = 1, c, d, e;
    cout << " Числа B должны выполнять условия:\n"
            " 1) для которых введенное число А делится без остатка на В * В\n"
            " 2) для которых введенное число А не делится без остатка на В * В * В.\n\n";

    cout << " Введите любое целое число А \n";
    cout << " --> ";
    cin >> a;

    for (a; a >= b * b; b++)
    {
        if (a % (b * b) == 0 && a % (b * b * b) != 0)
        {
            c = a % (b * b);
            d = a % (b * b * b);
            e = b;
        }
    }
    //Проверка
    if (c > 0 || d == 0)
        cout << "\n Условия числа B не выполнены:"
                "\n 1) Условие = "
             << c << "\n 2) Условие = " << d << "\n Числа соответствующие условиям 1 и 2 не найдены.\n";

    else
        cout << "\n Условия числа B выполнены:"
                "\n 1) Условие = "
             << c << "\n 2) Условие = " << d << "\n Числа соответствующие условиям 1 и 2 найдены = " << e << "\n";

    cout << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// 5. Пользователь вводит целое число А. Программа должна определить, что куб суммы цифр этого
//     числа равен А*А.

#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    system("cls");

    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " *** Определить, что куб суммы цифр введенного числа А равен А * А ***\n\n";
    int a, a1, sum = 0;
    cout << " Введите целое число A = ";
    cin >> a;

    if (a < 0)
        a = -a;

    a1 = a;

    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }

    if (sum * sum * sum == a1 * a1)
        cout << "\n " << (sum * sum * sum) << " равно " << (a1 * a1) << "\n Условие выполнено введенное А подходит.";
    else
        cout << "\n " << (sum * sum * sum) << " не равно " << (a1 * a1) << "\n Условие не выполнено введенное А не подходит.";

    cout << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}

// 6. Пользователь вводит целое число. Необходимо вывести все целые числа, на которое заданное
//     число делится без остатка.

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");

    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " *** Вывод всех целых чисел, на которые введенное число делится без остатка ***\n\n";
    int num;
    cout << " Введите целое число = ";
    cin >> num;

    cout << "\n Числа следующее --> ";
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            cout << i << " | ";
    }

    cout << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}
*/

// 7. Пользователь вводит два целых числа. Необходимо вывести все целые числа, на которые оба
//     введённых числа делятся без остатка.

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
    system("cls");

    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " Вывод всех целых чисел, на которые введенные числа оба делится без остатка\n\n";
    int num1, num2;
    cout << " Введите первое целое число = ";
    cin >> num1;
    cout << " Введите второе целое число = ";
    cin >> num2;

    cout << "\n Числа следующее --> ";
    for (int i = 1; i <= num1 && i <= num2; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
            cout << i << " | ";
    }

    cout << endl;

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);

    return 0;
}
