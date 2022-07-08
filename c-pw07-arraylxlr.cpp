// Ввести в память машины одномерный целочисленный массив, размером
// не менее 10 элементов. Ввод осуществить с клавиатуры.
// Произвести манипуляции с массивом данных согласно условию.
// Вывести на экран исходный массив и данные, полученные согласно заданию.

// Решение должно использовать адресацию элементов массива через указатели.
// Ввод элементов массива с клавиатуры, вывод элементов массива на экран и
// манипуляции с элементами массива согласно условию, осуществить через отдельные функции.
// Задачу решить с использованием простого пользовательского меню.

// Условие:
// Поменять местами предпоследний элемент с самым правым минимальным.

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
    int array[10];
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
            mas_vvod_klava(array, 10);
            mas_vyvod(array, 10);
            mas_switch(array, 10);
            cout << " Для продолжения-ENTER.";
            getch();
            break;
        case 2:
            mas_vvod_random(array, 10);
            mas_vyvod(array, 10);
            mas_switch(array, 10);
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
        if ((i + 1) % 10 == 0)
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
        if ((i + 1) % 10 == 0)
            cout << "\n";
    }
    cout << "\n";
}
