/*
// Задание 1:
// Написать программу, реализующую сортировку массива методом усовершенствованной
// сортировки пузырьковым методом. Усовершенствование состоит в том, что бы
// анализировать количество перестановок на каждом шагу, если это количество
// равно нулю, то продолжать сортировку нет смысла – массив отсортирован.

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main(void);
void input_array_keyboard(int[], int); //заполнения массива в ручную
void input_array_random(int[], int);   //заполнения массива случайными числами
void output_array_primary(int[], int); //вывод исходного массива на экран
void sort_array_output(int[], int);    //сортировка массива пузырьком и вывод на экран

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int const size=10;
    int array[size];

    bool input = true;
    int input_menu = 0;
    do
    {
        system("cls");

        cout << " *** Программа сортировки массива методом пузырька ***\n"
            "\n 1: Ввод массива с клавиатуры."
            "\n 2: Ввод массива случайными числами."
            "\n 3: | Выход |\n\n>";
        cin >> input_menu;
        switch (input_menu)
        {
        case 1:
            input_array_keyboard(array,size);
            output_array_primary(array, size);
            sort_array_output(array, size);
            cout << "\n Для продолжения-ENTER.";
            getch();
            break;
        case 2:
            input_array_random(array, size);
            output_array_primary(array, size);
            sort_array_output(array, size);
            cout << "\n Для продолжения-ENTER.";
            getch();
            break;
        case 3:
            input = false;
            break;
        default:
            cout << "\n Неверный пункт меню. Будьте внимательны!!!\n";
            cout << "\n Для продолжения-ENTER.";
            getch();
        }
    } while (input);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void input_array_keyboard(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " Элемент массива ["<<i<<"] = ";
        cin >> array[i];
    }
}
void input_array_random(int array[], int size)
{
    int i;
    srand(time(NULL));

    for (i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }

}
void output_array_primary(int array[], int size)
{
    cout << "\n Исходный массив данных:\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << " | " << array[i];
    }
    cout << "\n";
}
void sort_array_output(int array[], int  size) //сортировка массива пузырьком
{
    int temp;
    int count=0;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];  // меняем элементы местами
                array[j] = array[j + 1];
                array[j + 1] = temp;
                count++;
            }
        }
        //если замен не было, то выходим из цикла
        if (count == 0)
        {
            cout << "\n Сортировка массива не требуется массив отсортирован. \n";
            break;
        }

    }
    if (count != 0) //вывод отсортированного массива на экран
        {
        cout << "\n Сортировка массива выполнена:\n\n";
        for (int i = 0; i < size; i++)
        {
            cout << " | " << array[i];
        }
        cout << "\n";
        }
}
*/

// Задание 2:
// Есть стопка оладий различного радиуса. Единственная операция проводимая
// с ними - между любыми двумя суем лопатку и меняем порядок оладий над лопаткой
// на обратный. Необходимо за минимальное количество операций таких отсортировать
// сзк вверх по убыванию радиуса.

#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main(void);
void input_array_keyboard(int[], int); //заполнения массива в ручную
void input_array_random(int[], int);   //заполнения массива случайными числами
void output_array_primary(int[], int); //вывод исходного массива на экран
void sort_array_output(int[], int);    //сортировка массива max элемента переворот и вывод на экран
void output_array_final(int[], int);   //вывод окочательного массива на экран

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int const n = 10;
    int array[n];
    int size = sizeof(array) / sizeof(int);

    bool input = true;
    int input_menu = 0;
    do
    {
        system("cls");

        cout << " *** Программа сортировки оладий ***\n"
                "\n 1: Ввод радиуса оладий с клавиатуры."
                "\n 2: Ввод радиуса оладий случайными числами."
                "\n 3: | ВыхоД |\n\n>";
        cin >> input_menu;
        switch (input_menu)
        {
        case 1:
            input_array_keyboard(array, size);
            sort_array_output(array, size);
            output_array_final(array, size);
            cout << "\n Для продолжения-ENTER.";
            getch();
            break;
        case 2:
            input_array_random(array, size);
            output_array_primary(array, size);
            sort_array_output(array, size);
            output_array_final(array, size);
            cout << "\n Для продолжения-ENTER.";
            getch();
            break;
        case 3:
            input = false;
            break;
        default:
            cout << "\n Неверный пункт меню. Будьте внимательны!!!\n";
            cout << "\n Для продолжения-ENTER.";
            getch();
        }
    } while (input);

    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void input_array_keyboard(int array[], int size)
{
    cout << "\n Ввод исходной стопки оладий: \n\n";
    for (int i = 0; i < size; i++)
    {
        do
        {
            cout << "  Позиция " << i << "-ая радиус оладьи = ";
            cin >> array[i];

            if (array[i] <= 0)
                cout << " \n  Oладья не может иметь отрицательный радиус!\n";
        } while (array[i] <= 0);
    }
}
void output_array_primary(int array[], int size)
{
    cout << "\n Исходная стопка оладий:\n\n";
    for (int i = 0; i < size; i++)
    {
        cout << "  Позиция " << i << "-ая радиус оладьи = " << array[i] << "\n";
    }
}
void input_array_random(int array[], int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = 1 + rand() % 10;
    }
}
void sort_array_output(int array[], int size) //сортировка оладий
{
    int temp;
    int max;
    int max_array_element;

    for (int i = size - 1; i >= 0; i--)
    {
        max = array[i];
        max_array_element = i;
        for (int j1 = i; j1 >= 0; j1--) //нахождение самой большой оладьи
        {
            if (array[j1] > max)
            {
                max = array[j1];
                max_array_element = j1;
            }
        }
        cout << " |_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|\n";
        cout << "\n " << size - i << "-ое нахождение следующей большой оладьи в стопке.";
        cout << "\n Большая оладья на позиции " << max_array_element << " = " << max << " радиус.\n";
        cout << "\n Найденную " << size - i << "-ую большую оладью отправляем на самый ВЕРХ стопке.";
        cout << "\n Для этого вставляем лопатку и переворачиваем.\n";
        cout << "\n\t________------------|||||| \n\n";

        //переворачиваем часть стопки оладьев, чтобы максимальная оказалась наверху
        for (int flip_over = 0; flip_over <= max_array_element / 2; flip_over++)
        {
            if (max_array_element == 0) //является ли верхняя оладья максимальной
            {
                break;
            }

            temp = array[flip_over];
            array[flip_over] = array[max_array_element - flip_over];
            array[max_array_element - flip_over] = temp;
        }

        for (int output = 0; output < size; output++) //вывод на экран результат переворота 1
        {
            cout << "  Позиция " << output << "-ая радиус оладьи = " << array[output]
                 << " (стопка " << size - i << ".1)\n";
        }
        cout << " |_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|\n";
        cout << "\n Найденную " << size - i << "-ую большую оладью отправляем на самый НИЗ стопке.";
        cout << "\n Для этого вставляем лопатку и переворачиваем.\n";
        cout << "\n\t________------------|||||| \n\n";

        for (int j2 = 0; j2 <= i / 2; j2++) //переворачиваем часть стопки оладьев, чтобы максимальная оказалась внизу
        {
            temp = array[j2];
            array[j2] = array[i - j2];
            array[i - j2] = temp;
        }

        for (int output = 0; output < size; output++) //вывод на экран результат переворота 2
        {
            cout << "  Позиция " << output << "-ая радиус оладьи = " << array[output]
                 << " (стопка " << size - i << ".2)\n";
        }
    }
}
void output_array_final(int array[], int size) //вывод исходного массива на экран
{
    cout << "\n\n\n ------------------------------------------------\n";
    cout << "\n Окончательная стопка оладий:\n\n";
    //выводим отсортированный массив
    for (int i = 0; i < size; i++)
    {
        cout << "  Позиция " << i << "-ая = " << array[i] << " радиус оладьи."
             << "\n";
    }
    cout << " |_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_|\n";
}
