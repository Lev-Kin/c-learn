
// Ввести в память машины одномерный целочисленный массив, размером
// не менее 30 элементов. Ввод осуществить с клавиатуры.
// Произвести манипуляции с массивом данных согласно условию.

//  1. С использованием конструкций cin и cout.
//  2. С использованием стандартного ввода-вывода.

// Поменять местами предпоследний элемент с самым правым минимальным.
// 1. С использованием стандартного ввода-вывода.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand()
#include <time.h>   // в этом файле содержится функция time()
#include <conio.h>  // в этом файле содержится функция getch()

int main(void);
void mas_vvod_klava(int[], int);
void mas_vvod_random(int[], int);
void mas_vyvod(int[], int);
void mas_switch(int[], int); // Поменять местами предпоследний элемент с самым правым минимальным.

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int prodolgenie = 1;
    int chislo_menu = 0;
    int array[30];
    int sposob_vvoda = 0;
    do
    {
        system("cls");
        printf(" ***| Программа работы с одномерными массивами | ***\n\n"
               " 1:Ввод массива с клавиатуры.\n");
        printf(" 2:Ввод массива через генерацию случайных чисел.\n");
        printf(" 3:Выход из программы.\n\n>");
        scanf("%d", &chislo_menu);
        switch (chislo_menu)
        {
        case 1:
            mas_vvod_klava(array, 30);
            mas_vyvod(array, 30);
            mas_switch(array, 30);
            printf(" Для продолжения-ENTER.");
            getch();
            break;
        case 2:
            mas_vvod_random(array, 30);
            mas_vyvod(array, 30);
            mas_switch(array, 30);
            printf(" Для продолжения-ENTER.");
            getch();
            break;
        case 3:
            prodolgenie = 0;
            break;
        default:
            printf(" Неверный пункт меню. Будьте внимательны!!!\n");
            printf(" Для продолжения-ENTER.");
            getch();
            break;
        }
    } while (prodolgenie != 0);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void mas_vvod_klava(int mas[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        do
        {
            printf(" Элемент массива [%d]=", i);
            scanf("%d", &mas[i]);
            if (mas[i] < 1)
                printf(" Элемент массива меньше 1. Будьте внимательны!!!\n");
        } while (mas[i] < 1);
    }
}

void mas_vvod_random(int mas[], int n)
{
    int i;
    srand((unsigned)time(NULL));

    for (i = 0; i < n; i++)
    {
        mas[i] = rand() % 100 + 1;
    }
}

void mas_vyvod(int mas[], int n)
{
    int i;
    printf("\n Исходный массив данных:\n\n");
    for (i = 0; i < n; i++)
    {
        printf(" %-5u ", mas[i]);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
}

void mas_switch(int mas[], int n)
{
    int indexMin = 0;
    printf("\n Перестановка местами предпоследнего элемента с самым правым минимальным.\n\n");
    for (int i = n - 1; i >= 0; i--)
        if (*(mas + indexMin) > *(mas + i))
            indexMin = i;

    int temp1 = *(mas + n - 2);
    *(mas + n - 2) = *(mas + indexMin);
    *(mas + indexMin) = temp1;

    for (int i = 0; i < n; i++)
    {
        printf(" %-5u ", mas[i]);
        if ((i + 1) % 5 == 0)
            printf("\n");
    }
    printf("\n");
}

/*
// 2. С использованием конструкций cin и cout.

#include <windows.h>
#include <iostream>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand()
#include <time.h>   // в этом файле содержится функция time()
#include <conio.h>  // в этом файле содержится функция getch()

using namespace std;

int main(void);
void mas_vvod_klava(int[], int);
void mas_vvod_random(int[], int);
void mas_vyvod(int[], int);
void mas_switch(int[], int); // Поменять местами предпоследний элемент с самым правым минимальным.

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool prodolgenie = true;
    int chislo_menu = 0;
    int array[30];
    int sposob_vvoda = 0;
    do
    {
        system("cls");
        cout << " ***| Программа работы с одномерными массивами | ***\n\n"
                " 1:Ввод массива с клавиатуры.\n";
        cout << " 2:Ввод массива через генерацию случайных чисел.\n";
        cout << " 3:Выход из программы.\n\n>";
        cin >> chislo_menu;
        switch (chislo_menu)
        {
        case 1:
            mas_vvod_klava(array, 30);
            mas_vyvod(array, 30);
            mas_switch(array, 30);
            cout << " Для продолжения-ENTER.";
            getch();
            break;
        case 2:
            mas_vvod_random(array, 30);
            mas_vyvod(array, 30);
            mas_switch(array, 30);
            cout << " Для продолжения-ENTER.";
            getch();
            break;
        case 3:
            prodolgenie = false;
            break;
        default:
            cout << " Неверный пункт меню. Будьте внимательны!!!\n";
            cout << " Для продолжения-ENTER.";
            getch();
            break;
        }
    } while (prodolgenie);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void mas_vvod_klava(int mas[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        do
        {
            cout << " Элемент массива [ " << i << " ] = ";
            cin >> mas[i];
            if (mas[i] < 1)
                cout << " Элемент массива меньше 1. Будьте внимательны!!!\n";
        } while (mas[i] < 1);
    }
}

void mas_vvod_random(int mas[], int n)
{
    int i;
    srand((unsigned)time(NULL));

    for (i = 0; i < n; i++)
    {
        mas[i] = rand() % 100 + 1;
    }
}

void mas_vyvod(int mas[], int n)
{
    int i;
    cout << "\n Исходный массив данных:\n\n";
    for (i = 0; i < n; i++)
    {
        cout << " | " << mas[i];
        if ((i + 1) % 30 == 0)
            cout << "\n";
    }
}

void mas_switch(int mas[], int n)
{
    int indexMin = 0;
    cout << "\n Перестановка местами предпоследнего элемента с самым правым минимальным.\n\n";
    for (int i = n - 1; i >= 0; i--)
        if (*(mas + indexMin) > *(mas + i))
            indexMin = i;

    int temp1 = *(mas + n - 2);
    *(mas + n - 2) = *(mas + indexMin);
    *(mas + indexMin) = temp1;

    for (int i = 0; i < n; i++)
    {
        cout << " | " << mas[i];
        if ((i + 1) % 30 == 0)
            cout << "\n";
    }
    cout << "\n";
}
*/
