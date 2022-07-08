/*
// Задание 1: В одномерном массиве, заполненном случайными числами,
//                     определить   минимальный и максимальный элементы.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf(" Нахождение max и min элементов в одномерном массиве \n"
           " заполненный случайными числами.\n\n");

    const int N = 15;
    int mas[N], i;

    srand(time(NULL));
    for (i = 0; i < N; i++)
        mas[i] = 1 + rand() % 100;

    for (i = 0; i < N; i++)
        printf(" %d |", mas[i]);

    int max = mas[0];
    int min = mas[0];
    for (int i = 0; i < 15; i++)
    {
        if (mas[i] > max)
        {
            max = mas[i];
        }
        if (mas[i] < min)
        {
            min = mas[i];
        }
    }
    printf("\n\n Минимальный элемент -> %d.\n Максимальный элемент -> %d.\n", min, max);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// Задание 2: Пользователь вводит прибыль фирмы за год (12 месяцев).
//                   Затем  пользователь вводит диапазон (например, 3 и 6 – поиск
//                   между 3-м и 6-м месяцем). Необходимо определить месяц, в
//                   котором прибыль была максимальна и месяц, в котором прибыль
//                   была минимальна с учетом выбранного диапазона.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    system("cls");
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printf(" ***Расчет min и max прибыли в заданном диапазоне ***\n\n");

    const char month[][12] = {
        "1. Январь",
        "2. Февраль",
        "3. Март",
        "4. Апрель",
        "5. Май ",
        "6. Июнь",
        "7. Июль",
        "8. Август",
        "9. Сентябрь",
        "10.Октябрь",
        "11.Ноябрь",
        "12.Декабрь",
    };
    float profit[12];

    printf(" Введите прибыль фирмы за год (12 месяцев):\n\n");
    for (int i = 0; i < 12; i++)
    {
        do
        {
            printf(" %s \t= ", month[i]);
            scanf("%f", &profit[i]);
            if (profit[i] < 0) // по модулю если делится то да
                printf("\n !Прибыль не может иметь отрицательное значение.\n\n");

        } while (profit[i] < 0);
    }

    int a, b;
    do
    {
        printf("\n Начальный диапазон месяца от 1 до 11 введите : ");
        scanf("%d", &a);
        printf("\n Конечный  диапазон месяца от 2 до 12 введите : ");
        scanf("%d", &b);
        if (a < 0 || a > 12 && b < 0 || b > 12)
            printf("\n !Диапазон нарушен должен быть от 1 до 12.\n");

        else if (b < a)
            printf("\n !Конечный диапазон не может быть меньше начального.\n");

        else if (a == b)
            printf("\n !Диапазоны не могут быть равны.\n");

    } while (a < 0 || a > 12 && b < 0 || b > 12 || a == b || b < a);
    printf("\n");

    float max = profit[a - 1];
    float min = profit[a - 1];
    for (int i = a - 1; i < b; i++) // включая месяца в заданном диапазоне
    {
        printf(" %s \t= %.2f\n", month[i], profit[i]); //вывод прибыли по месяцам в заданном диапазоне

        if (profit[i] > max)
        {
            max = profit[i];
        }
        if (profit[i] < min)
        {
            min = profit[i];
        }
    }
    printf("\n Минимальная  прибыль = %.2f.\n Максимальная прибыль = %.2f.\n", min, max);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

// srand(time(NULL));
// for (int i = 0; i < 12; i++)
// 	profit[i] = 1.01 * (rand() % 101);

// for (int i = 0; i < 12; i++)
// 	printf("%s \t= %.2f\n", month[i], profit[i]);
*/

// Задание 3: В одномерном массиве, состоящем из 30 вещественных чисел
//                    вычислить:
//                   • Сумму отрицательных элементов.
//                   • Произведение элементов, находящихся между min и max
//                     элементами.
//                   • Произведение элементов с чётными номерами.
//                   • Сумму элементов, находящихся между первым и последним
//                     отрицательными элементами.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand()
#include <time.h>   // в этом файле содержится функция time()
#include <conio.h>  // в этом файле содержится функция getch()

int main(void);
void mas_vvod_random(float[], int);
void mas_vyvod(float[], int);

// 1. Cумма отрицательных элементов.
void mas_1_sum_elements_negative(float[], int);
// 2. Произведение элементов, находящихся между min и max элементами.
void mas_2_product_elements_betwееn_min_and_max(float[], int);
// 3. Произведение элементов с чётными номерами.
void mas_3_product_elements_even_number(float[], int);
// 4. Сумму элементов, находящихся между первым и последним отрицательными элементами.
void mas_4_sum_elements_between_first_and_end_negative_elements(float[], int);

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool prodolgenie = true;
    int chislo_menu = 0;
    float array[30];
    int sposob_vvoda = 0;

    do
    {
        system("cls");
        printf(" ***| Программа работы с одномерным массивом | ***\n\n"
               " 1:Произвести расчеты массива состоящего из вещественных чисел.\n");
        printf(" 2: | ВыхоД |\n\n>");
        scanf("%d", &chislo_menu);
        switch (chislo_menu)
        {
        case 1:
            mas_vvod_random(array, 30);
            mas_vyvod(array, 30);
            mas_1_sum_elements_negative(array, 30);
            mas_2_product_elements_betwееn_min_and_max(array, 30);
            mas_3_product_elements_even_number(array, 30);
            mas_4_sum_elements_between_first_and_end_negative_elements(array, 30);
            printf("\n Для продолжения-ENTER.");
            getch();
            break;
        case 2:
            prodolgenie = false;
            break;
        default:
            printf("\n Неверный пункт меню. Будьте внимательны!!!\n");
            printf("\n Для продолжения-ENTER.");
            getch();
            break;
        }
    } while (prodolgenie);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void mas_vvod_random(float mas[], int n)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < n; i++)
    {
        mas[i] = 0.11 * (rand() % 201 - 100);
    }
}

void mas_vyvod(float mas[], int n)
{
    int i;
    printf("\n Исходный массив данных:\n\n");
    for (i = 0; i < n; i++)
    {
        printf(" [%d]=%0.2f\t", i, mas[i]);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
}

void mas_1_sum_elements_negative(float mas[], int n)
{
    printf("\n 1. Найти сумму отрицательных элементов в заданном массиве.\n");
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0) //сумма отрицательных элементов массива.
            sum += mas[i];
    }
    printf("\t Сумма отрицательных элементов = %.2f\n\n", sum);
}

void mas_2_product_elements_betwееn_min_and_max(float mas[], int n)
{
    printf("\n 2. Найти произведение элементов, находящихся между min и max элементами.\n");
    int min_i = 0, max_i = 0;
    float first_min_num = 0, end_max_num = 0;
    float product = 1.0;

    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
        {
            printf("\t Первый    min элемент стоит на [%d] месте и равен %.2f\n", i, mas[i]);
            min_i = i;
            first_min_num = mas[i];
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (mas[i] > 0)
        {
            printf("\t Последний max элемент стоит на [%d] месте и равен %.2f\n", i, mas[i]);
            max_i = i;
            end_max_num = mas[i];
            break;
        }
    }
    printf("\n\t|MIN = %.2f ------------------------------ MAX = %.2f|\n", first_min_num, end_max_num);

    for (int i = min_i; i < max_i; i++) //произведение элементов массива в найденном диапазоне.
        product *= mas[i];

    printf("\t Произведение равно = %.30f\n\n", product);
}

void mas_3_product_elements_even_number(float mas[], int n)
{
    printf("\n 3. Найти произведение элементов, c четными номерами.\n");

    float product = 1.0;
    printf("\t Четные номера массива следующие:\n");
    for (int i = 0; i < n; i += 2) //произведение элементов массива с четными номерами.
    {
        product *= mas[i];

        printf("\t\t[%d]", i);
        if ((i + 1) % 3 == 0)
            printf("\n");
    }
    printf("\n\t Произведение равно = %.30f\n\n", product);
}

void mas_4_sum_elements_between_first_and_end_negative_elements(float mas[], int n)
{
    printf("\n 4. Найти сумму элементов,"
           "\n    находящихся между первым и последним отрицательными элементами.\n");

    int min_f_i = 0, min_e_i = 0;
    float first_min_num = 0, end_min_num = 0;
    float sum = 1.0;
    for (int i = 0; i < n; i++)
    {
        if (mas[i] < 0)
        {
            printf("\t Первый    отрицательный элемент стоит на [%d] месте и равен %.2f\n", i, mas[i]);
            min_f_i = i;
            first_min_num = mas[i];
            break;
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (mas[i] < 0)
        {
            printf("\t Последний отрицательный элемент стоит на [%d] месте и равен %.2f\n", i, mas[i]);
            min_e_i = i;
            end_min_num = mas[i];
            break;
        }
    }
    printf("\n\t|MIN = %.2f ------------------------------ MIN = %.2f|\n", first_min_num, end_min_num);

    for (int i = min_f_i; i < min_e_i; i++) //сумма элементов массива в найденном диапазоне.
        sum += mas[i];

    printf("\t Сумма между отрицательными элементами = %.2f\n\n", sum);
}
