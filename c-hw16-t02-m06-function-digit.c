// Разработать программу, в составе которой выполняли бы свою работу следующие
// написанные пользовательские функции:

// 1. Функция, которая принимает два параметра: основание степени и показатель
//     степени, и вычисляет степень числа на основе полученных данных.
// 2. Функция, которая получает в качестве параметров два целых числа и
//     возвращает сумму чисел из диапазона между ними.
// 3. Функция поиска совершенных чисел во введённом интервале. Число называется
//     совершенным, если сумма всех его делителей равна ему самому.
// 4. Функция, проверяющая,является ли переданный ей параметр алфавитно-
//     цифровым.
// 5. Функция для округления заданного числа с заданной точностью. Например,
//     передаётся в функцию 6.287 и 2, функция возвращает 6.29.
//     (не использовать встроенные функции).
// 6. Функция, которая определяет, является ли «счастливым» шестизначное
//     число.
// 7. Функция, которая принимает две даты (т.е. функция принимает шесть
//     параметров) и вычисляет разность в днях между этими датами. Для решения этой
//     задачи необходимо также написать функцию, которая определяет, является ли год
//     високосным.

#include <windows.h>
#include <stdio.h>
#include <conio.h>   // в этом файле содержится функция getch()
#include <stdbool.h> //содержится определение логических констант true и false

int main(void);
void dash(int);

// 1. Функция, которая принимает два параметра: основание степени и показатель
//    степени, и вычисляет степень числа на основе полученных данных.
int n_in_exp(int, int);
// 2. Функция, которая получает в качестве параметров два целых числа и
//    возвращает сумму чисел из диапазона между ними.
int a_sum_b(int, int);
// 3. Функция поиска совершенных чисел во введённом интервале.
void a_perfect_b(long long, long long);
// 4. Функция, проверяющая, является ли переданный ей параметр алфавитно-цифровым.
void abc123_print(char);
bool abc123_or_not(char);
// 5. Функция для округления заданного числа с заданной точностью.
double n_dot_cut(double, int);
// 6. Функция, которая определяет, является ли «счастливым» шестизначное число.
void lucky_v(int);
// 7. Функция, которая принимает две даты (т.е. функция принимает шесть
//    параметров) и вычисляет разность в днях между этими датами.
int count_day(int, int, int, int, int, int);

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char repeat;
    char replay;
    int work_n_cut = 0;
    int menu_number = 0;
    bool go_back = true;
    do
    {
        system("cls");
        printf(" ***| Программа работы с функциями | ***\n\n");
        printf(" ___________| Главное меню |______________________________________\n");
        printf("   Выберите ФУКЦИЮ для работы:\n");
        printf(" 1:Которая принимает два параметра: основание степени и показатель\n"
               "   степени, и вычисляет степень числа на основе полученных данных.\n");
        printf(" 2:Которая получает в качестве параметров два целых числа и\n"
               "   возвращает сумму чисел из диапазона между ними.\n");
        printf(" 3:Поиска совершенных чисел во введённом интервале. \n");
        printf(" 4:Проверяющая, является ли переданный ей параметр\n"
               "   алфавитно-цифровым.\n");
        printf(" 5:Для округления заданного числа с заданной точностью.\n");
        printf(" 6:Которая определяет, является ли «счастливым»\n"
               "   шестизначное число.\n");
        printf(" 7:Которая принимает две даты и вычисляет разность\n"
               "   в днях между этими датами.\n");
        printf(" 8: | ВыхоД |\n\n>");

        scanf("%d", &menu_number);
        switch (menu_number)
        {
        case 1:
            do
            {
                dash(65);
                printf("\n Вы находитесь в 1 пункте меню.\n");
                int n, exp, result;
                printf("\n Введите   число --> ");
                scanf("%d", &n);
                printf(" Введите степень --> ");
                scanf("%d", &exp);
                result = n_in_exp(n, exp);
                printf("\n %d в степени %d = %d\n", n, exp, result);
                printf("\n Y - Продолжить.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 2:
            do
            {
                dash(65);
                printf("\n Вы находитесь в 2 пункте меню.\n");
                int a, b, result;
                printf("\n Введите первое число --> ");
                scanf("%d", &a);
                printf(" Введите второе число --> ");
                scanf("%d", &b);
                result = a_sum_b(a, b);
                printf(" Сумма между %d и %d = %d\n", a, b, result);
                printf("\n Y - Продолжить.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 3:
            do
            {
                dash(65);
                printf("\n Вы находитесь в 3 пункте меню.\n");
                long long a, b;
                printf("\n Задайте интервал поиска: ");
                printf("\n Начальное число --> ");
                scanf("%lld", &a);
                printf(" Конечное число  --> ");
                scanf("%lld", &b); // до 9000, можно больше работает (ждать долго).
                printf("\n В интервале от [%lld] до [%lld]\n", a, b);
                printf(" Найдены совершенные числа:\n");
                a_perfect_b(a, b); // 6, 28, 496, 8128 (дальше долго обрабатывает 33550336 и тд)
                printf("\n Y - Продолжить.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 4:
            do
            {
                dash(65);
                printf("\n Вы находитесь в 4 пункте меню.\n");
                while (getchar() != '\n')
                    ;
                char symbol;
                int result;
                printf("\n Определяем параметр: \n");
                printf(" Введите один любой символ --> ");
                scanf("%c", &symbol);
                abc123_print(symbol);
                result = abc123_or_not(symbol);
                //алфавитно-цифровые символы A-z, a-z, 0-9, А-я, а-я.
                if (abc123_or_not(symbol) == 1)
                    printf(" '%c' является алфавитно цифровым.\n", symbol);
                else
                    printf(" '%c' НЕ является алфавитно цифровым.\n", symbol);
                printf("\n Y - Продолжить.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 5:
            do
            {
                dash(65);
                printf("\n Вы находитесь в 5 пункте меню.\n");
                double n;
                int n_cut;
                printf("\n Введите вещественное число = ");
                scanf("%lf", &n);
                do
                {
                    printf(" Округления не более 6 знаков после точки:\n");
                    printf(" Введите количество знаков = ");
                    scanf("%d", &n_cut);
                    while (getchar() != '\n')
                        ;
                    if (n_cut == 0)
                        printf("\n Число не округлялась.\n");
                    else
                    {
                        if (n_cut > 6 || n_cut < -1)
                        {
                            printf("\n Условие не выполнено. Вы вели больше 6 знаков или меньше 0. | !!! |");
                            printf("\n Повторите - ENTER. ");
                            replay = getchar();
                        }
                        else
                            printf("\n Вы вели %d для округления условие выполнено. | OK |", n_cut);
                        printf("\n");
                        work_n_cut = 1;
                    }
                } while (n_cut > 6 || n_cut < -1);

                if (work_n_cut == 1)
                {
                    switch (n_cut)
                    {
                    case 1:
                        printf("\n Число округлено на %d знак после точки = %.1lf\n", n_cut, n_dot_cut(n, n_cut));
                        break;
                    case 2:
                        printf("\n Число округлено на %d знака после точки = %.2lf\n", n_cut, n_dot_cut(n, n_cut));
                        break;
                    case 3:
                        printf("\n Число округлено на %d знака после точки = %.3lf\n", n_cut, n_dot_cut(n, n_cut));
                        break;
                    case 4:
                        printf("\n Число округлено на %d знака после точки = %.4lf\n", n_cut, n_dot_cut(n, n_cut));
                        break;
                    case 5:
                        printf("\n Число округлено на %d знаков после точки = %.5lf\n", n_cut, n_dot_cut(n, n_cut));
                        break;
                    case 6:
                        printf("\n Число округлено на %d знаков после точки = %.6lf\n", n_cut, n_dot_cut(n, n_cut));
                        break;
                    }
                }
                printf("\n Y - Продолжить.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 6:
            do
            {
                dash(65);
                printf("\n Вы находитесь в 6 пункте меню.\n");
                int v;
                printf(" Введите целое шестизначное число: \n\n>");
                scanf("%d", &v);
                while (100000 >= v || v > 999999)
                {
                    printf("\n Некорректный ввод числа введите еще раз!\n>");
                    scanf("%d", &v);
                }
                lucky_v(v);
                printf("\n Y - Продолжить.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 7:
            do
            {
                dash(65);
                printf("\n Вы находитесь в 7 пункте меню.\n");
                int a, b, c, d, e, f, x, y = 0;
                printf("\n Введите начальную дату ДД.MM.ГГГГ через пробел: ");
                scanf("%d %d %d", &a, &b, &c);
                printf(" Введите конечную  дату ДД.MM.ГГГГ через пробел: ");
                scanf("%d %d %d", &d, &e, &f);
                printf("\n Количество дней между датами : %d\n", count_day(a, b, c, d, e, f));
                printf("\n Y - Продолжить.");
                printf("\n Q - Выход в Главное меню.\n>");
                repeat = getch();
            } while (repeat == 'y' || repeat == 'Y');
            break;

        case 8:
            printf("\n ___|  Всего хорошего  |___");
            printf("\n ___|      (^-^)/      |___\n\n\a");
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

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        printf("-");
}

int n_in_exp(int n, int exp)
{
    int result = n;
    if (exp == 0)
        return 1;
    if (exp == 1)
        return n;

    for (int i = 0; i < exp - 1; i++)
        result *= n;

    return result;
}

int a_sum_b(int a, int b)
{
    int sum = 0;
    if (a == b)
        return 0;
    if (a < b)
    {
        sum = (b * (b + 1) - a * (a - 1)) / 2;
    }
    else
    {
        sum = (a * (a + 1) - b * (b - 1)) / 2;
    }
    return sum;
}

void a_perfect_b(long long a, long long b)
{
    for (int i = a; i < b; i++)
    {
        long long result = 0;
        for (int j = 1; j < i; j++)
        {
            if ((i % j) == 0)
                result += j;
        }
        if (result == i && result)
            printf(" | %lld | ", result);
    }
    printf("\n");
}

void abc123_print(char symbol)
{
    if (symbol >= '0' && symbol <= '9')
        printf("\n Ввели цифру");
    else if (symbol >= 'A' && symbol <= 'Z')
        printf("\n Ввели БОЛЬШУЮ букву латиницы");
    else if (symbol >= 'a' && symbol <= 'z')
        printf("\n Ввели малую букву латиницы");
    else if (symbol >= 'А' && symbol <= 'Я' || symbol == 'Ё')
        printf("\n Ввели БОЛЬШУЮ букву кириллицы");
    else if (symbol >= 'а' && symbol <= 'я' || symbol == 'ё')
        printf("\n Ввели малую букву кириллицы");
    else
        printf("\n Ввели знак");
}

bool abc123_or_not(char symbol)
{
    if (symbol >= '0' && symbol <= '9')
        return true;
    else if (symbol >= 'A' && symbol <= 'Z')
        return true;
    else if (symbol >= 'a' && symbol <= 'z')
        return true;
    else if (symbol >= 'А' && symbol <= 'Я' || symbol == 'Ё')
        return true;
    else if (symbol >= 'а' && symbol <= 'я' || symbol == 'ё')
        return true;
    else
        return false;
}

double n_dot_cut(double n, int n_cut)
{
    double temp1, resolt5;
    int transfer = 1;
    int temp2, n_end;
    for (int i = 1; i <= n_cut; i++)
    {
        transfer *= 10; //перенос запятой до указанной точности
    }

    temp2 = n * transfer * 10; //берем число на порядок больше
    n_end = temp2 % 10;        //определяем последнюю цифру
    temp1 = temp2 / 10;        //приводим число к указанной точности
    temp1 = (int)temp1;        //отбрасываем ненужные цифры

    if (n_end >= 5)
        temp1++; //проверяем по правилам округления

    resolt5 = temp1 / transfer; //возвращаем на место запятую

    return resolt5;
}

void lucky_v(int v)
{
    int i, part1 = 0, part2 = 0;
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
        printf("\n У Вас счастливое число :-).\n");
    else if (part1 != part2)
        printf("\n У Вас не счастливое число :-(.\n");
}

int count_day(int a, int b, int c, int d, int e, int f)
{
    int x = 0, y = 0;
    int leap, ly;
    int m1 = 31, m2 = 28, m3 = 31, m4 = 30, m5 = 31, m6 = 30, m7 = 31, m8 = 31, m9 = 30, m10 = 31, m11 = 30, m12 = 31;

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
    printf("\n Високосных лет = %d", ly);

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
        return (y - x) + ly + 1; // включая последнюю дату
    else
        return (f - c) * 365 + ((y - x) + ly + 1); // включая последнюю дату

    /*
    Начальная дата 01 12 2019
    Конечная  дата 01 03 2020

    Декабрь(31) + Январь(31) + Февраль(29) + Март(1) = 92 Дня
    */
}
