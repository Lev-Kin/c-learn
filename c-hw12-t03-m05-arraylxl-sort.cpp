// Написать программу «справочник». Создать два одномерных массива. Один массив хранит номера ICQ, второй – телефонные номера. Реализовать меню для пользователя:
// Отсортировать по номерам ICQ
// Отсортировать по номерам телефона
// Выход

#include <windows.h>
#include <iostream>
#include <stdlib.h> // в этом файле содержатся функции rand() и srand()
#include <time.h>
#include <conio.h> // в этом файле содержится функция getch()

using namespace std;

void vrandom();   //заполнения номеров рандомно
void sortICQ();   //сортировка номеров ICQ
void sortPhone(); //сортировка номеров телефонов

int arrICQ[20];   //массив для номеров ICQ
int arrPhone[20]; //массив для номеров телефонов

void main()
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    bool vvod = true;
    int vvod_menu = 0;
    do
    {
        system("cls");

        cout << " *** Программа сортировки массивов ***\n"
                "\n 1: Отсортировать по ICQ."
                "\n 2: Отсортировать по номеру телефона."
                "\n 3: | Выход |\n\n>";
        cin >> vvod_menu;
        switch (vvod_menu)
        {
        case 1:
            vrandom();
            sortICQ();
            cout << "\n Для продолжения-ENTER.";
            getch();
            break;
        case 2:
            vrandom();
            sortPhone();
            cout << "\n Для продолжения-ENTER.";
            getch();
            break;
        case 3:
            vvod = false;
            break;
        default:
            cout << "\n Неверный пункт меню. Будьте внимательны!!!\n";
            cout << "\n Для продолжения-ENTER.";
            getch();
        }
    } while (vvod);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
}
//заполняем массив рандомно
void vrandom()
{
    srand(time(NULL));
    for (int j = 0; j < 20; j++)
    {
        // ICQ использует уникальный для каждой учётной записи номер, состоящий из 5-9 арабских цифр.
        arrICQ[j] = rand() % 100000001 + 10000;
        //Телефонный номер, состоящий из 6 арабских цифр.
        arrPhone[j] = rand() % 100001 + 100000;
    }
}
//сортируем массив номеров ICQ
void sortICQ()
{
    int min = 0;
    for (int i = 0; i < 20; i++)
    {
        min = arrICQ[i];
        for (int j = i + 1; j < 20; j++)
        {
            if (arrICQ[j] < min)
            {
                min = arrICQ[j];
                arrICQ[j] = arrICQ[i];
            }
            arrICQ[i] = min;
        }
    }
    cout << "\n ICQ номера отсортированы по-возрастанию" << endl
         << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << " " << arrICQ[i] << endl;
    }
}
//сортируем массив номеров телефона
void sortPhone()
{
    int min = 0;
    for (int i = 0; i < 20; i++)
    {
        min = arrPhone[i];
        for (int j = i + 1; j < 20; j++)
        {
            if (arrPhone[j] < min)
            {
                min = arrPhone[j];
                arrPhone[j] = arrPhone[i];
            }
            arrPhone[i] = min;
        }
    }
    cout << "\n Телефонные номера отсортированы по-возрастанию" << endl
         << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << " " << arrPhone[i] << endl;
    }
}
