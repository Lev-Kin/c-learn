/*
// 1. Пользуясь двумя указателями на массив целых чисел, скопировать один массив в
//     другой. Использовать в программе арифметику указателей для продвижения по
//     массиву, а также оператор разыменования.

#include <windows.h>
#include <iostream>
#include <stdlib.h> // rand() и srand()
#include <time.h>   // time()

#define N 10 // массив
using namespace std;

int main(void);
void dash(int);
void dot(int);
void equal(int);

int* input_array_random(int*, int);            // заполнение массива целыми числами
int* exchange_pointer(int*, int*, int*, int*);  // oбмен указателями
void output_array(int*, int);                  // вывод массива на экран

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    system("cls");
    dash(75);
    cout << endl;
    cout << " 1. Пользуясь двумя указателями на массив целых чисел, скопировать один" << endl <<
         "    массив в другой." << endl << endl;
    dash(75);
    cout << endl;

    int* array_A = new int[N];
    int* array_B = new int[N];
    int* ptr_A = nullptr;
    int* ptr_B = nullptr;

    input_array_random(array_A, N);
    cout << " Исходные массивы данных:" << endl;
    cout << " Массив A:" << endl;
    output_array(array_A, N);
    cout << " Массив В:" << endl;
    output_array(array_B, N);

    dot(25);
    cout << endl;
    cout << " Копируем Массив А в Массив B:" << endl;
    cout << " Массив A:" << endl;
    output_array(array_A, N);
    cout << " Массив В:" << endl;
    exchange_pointer(ptr_A, ptr_B, array_A, array_B);
    output_array(array_B, N);

    delete[] array_A;
    delete[] array_B;
    ptr_A = nullptr;
    ptr_B = nullptr;

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        cout << "-";
}

void dot(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout << " . ";
    cout << endl;
}

void equal(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout <<"=";
    cout << endl;
}

int* input_array_random(int* array_A, int n)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        array_A[i] = rand() % 201 - 100;
    }
    return array_A;
}

void output_array(int* array, int n)
{
    for (int i = 0; i < N; i++)
    {
        cout << " | " << array[i];
        if ((i + 1) % N == 0)
            cout << endl;
    }
}

int* exchange_pointer(int* ptr_A, int* ptr_B, int* array_A, int* array_B)
{
    ptr_A = array_A; // указатель на массив А
    ptr_B = array_B; // указатель на массив В
    for (int i = 0; i < N; i++)
        *(ptr_B++) = *(ptr_A++); // используем операцию разыменования указателя
    return array_B;
}


// 2. Пользуясь указателем на массив целых чисел, изменить порядок следования
//     элементов  массива на противоположный. Использовать в программе арифметику
//     указателей для продвижения по массиву, а также оператор разыменования.

#include <windows.h>
#include <iostream>
#include <stdlib.h> // rand() и srand()
#include <time.h>   // time()

#define N 10 // массив
using namespace std;

int main(void);
void dash(int);
void dot(int);
void equal(int);

int* input_array_random(int*); // заполнение массива целыми случайными числами
int* revArray(int*);           // изменения порядка следования
void output_array(int*);       // вывод массива на экран

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    system("cls");
    dash(75);
    cout << endl;
    cout << " 2. Пользуясь указателем на массив целых чисел, изменить порядок следования" << endl <<
         "    элементов  массива на противоположный." << endl << endl;
    dash(75);
    cout << endl;

    int* array = nullptr;
    array = new int[N];

    input_array_random(array);
    cout << " Исходные массивы данных:" << endl;
    cout << " Массив A:" << endl;
    output_array(array);

    dot(25);
    cout << endl;
    cout << " Меняем порядок Массива на противоположный:" << endl;
    cout << " Массив A:" << endl;
    revArray(array);
    output_array(array);

    delete[] array;
    array = nullptr;

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        cout << "-";
}

void dot(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout << " . ";
    cout << endl;
}

void equal(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout <<"=";
    cout << endl;
}

int* input_array_random(int* array)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 201 - 100;
    }
    return array;
}

void output_array(int* array)
{
    for (int i = 0; i < N; i++)
    {
        cout << " | " << array[i];
        if ((i + 1) % N == 0)
            cout << endl;
    }
}

int* revArray(int* array)
{
    int tmp = 0;
    for (int i = 0, j = N - 1; i < j; i++, j--)
    {
        tmp = *(array + i);
        *(array + i) = *(array + j);
        *(array + j) = tmp;
    }
    return array;
}


// 3. Пользуясь двумя указателями на массивы целых чисел, скопировать один массив
//     в другой так, чтобы во втором массиве элементы находились в обратном порядке.
//     Использовать в программе арифметику указателей для продвижения по массиву, а
//     также оператор разыменования.

#include <windows.h>
#include <iostream>
#include <stdlib.h> // rand() и srand()
#include <time.h>   // time()

#define N 10 // массив
using namespace std;

int main(void);
void dash(int);
void dot(int);
void equal(int);

int* input_array_random(int*);                 // заполнение массива целыми числами
int* exchange_pointer(int*, int*, int*, int*); // oбмен указателями
int* revArray(int*);                           // изменения порядка следования
void output_array(int*);                       // вывод массива на экран

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    system("cls");
    dash(75);
    cout << endl;
    cout << " 3. Скопировать один массив в другой так, чтобы во втором массиве" << endl <<
        "    элементы находились в обратном порядке." << endl << endl;
    dash(75);
    cout << endl;

    int* array_A = new int[N];
    int* array_B = new int[N];
    int* ptr_A = nullptr;
    int* ptr_B = nullptr;

    input_array_random(array_A);
    cout << " Исходные массивы данных:" << endl;
    cout << " Массив A:" << endl;
    output_array(array_A);
    cout << " Массив В:" << endl;
    output_array(array_B);

    dot(25);
    cout << endl;
    cout << " Копируем Массив А в Массив B в обратном порядке:" << endl;
    cout << " Массив A:" << endl;
    output_array(array_A);
    cout << " Массив В:" << endl;
    exchange_pointer(ptr_A, ptr_B, array_A, array_B);
    revArray(array_B);
    output_array(array_B);

    delete[] array_A;
    delete[] array_B;
    ptr_A = nullptr;
    ptr_B = nullptr;

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        cout << "-";
}

void dot(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout << " . ";
    cout << endl;
}

void equal(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout << "=";
    cout << endl;
}

int* input_array_random(int* array_A)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
    {
        array_A[i] = rand() % 201 - 100;
    }
    return array_A;
}

void output_array(int* array)
{
    for (int i = 0; i < N; i++)
    {
        cout << " | " << array[i];
        if ((i + 1) % N == 0)
            cout << endl;
    }
}

int* exchange_pointer(int* ptr_A, int* ptr_B, int* array_A, int* array_B)
{
    ptr_A = array_A; // указатель на массив А
    ptr_B = array_B; // указатель на массив В
    for (int i = 0; i < N; i++)
        *(ptr_B++) = *(ptr_A++); // используем операцию разыменования указателя
    return array_B;
}

int* revArray(int* array_B)
{
    int tmp = 0;
    for (int i = 0, j = N - 1; i < j; i++, j--)
    {
        tmp = *(array_B + i);
        *(array_B + i) = *(array_B + j);
        *(array_B + j) = tmp;
    }
    return array_B;
}


// 4. Пользуясь указателем на массив целых чисел, найти минимальный и
//     максимальный элемент массива. Использовать в программе арифметику
//     указателей для продвижения по массиву, а также оператор разыменования.

#include <windows.h>
#include <iostream>
#include <stdlib.h> // rand() и srand()
#include <time.h>   // time()

#define N 10 // массив
using namespace std;

int main(void);
void dash(int);
void dot(int);
void equal(int);

int* input_array_random(int*); // заполнение массива целыми числами
void minAndMax(int*, int*);    // минимальный и максимальный элемент массива
void output_array(int*);       // вывод массива на экран

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    system("cls");
    dash(75);
    cout << endl;
    cout << " 4. Пользуясь указателем на массив целых чисел, найти минимальный и" << endl <<
        "    максимальный элемент массива." << endl << endl;
    dash(75);
    cout << endl;

    int* ptr = nullptr;
    int* array = new int[N];
    ptr = array;

    input_array_random(array);
    cout << " Исходный массив данных:" << endl;
    cout << " Массив:" << endl;
    output_array(array);

    dot(25);
    cout << endl;
    cout << " Находим min и max в массиве:" << endl;
    minAndMax(array, ptr);

    delete[] array;
    ptr = nullptr;

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        cout << "-";
}

void dot(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout << " . ";
    cout << endl;
}

void equal(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout << "=";
    cout << endl;
}

int* input_array_random(int* array)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 201 - 100;
    }
    return array;
}

void output_array(int* array)
{
    for (int i = 0; i < N; i++)
    {
        cout << " | " << array[i];
        if ((i + 1) % N == 0)
            cout << endl;
    }
}

void minAndMax(int* array, int* ptr)
{
    int arrayMin = *ptr;
    int arrayMax = *ptr;
    for (; ptr != array + N; ++ptr)
    {
        if (*ptr < arrayMin)
            arrayMin = *ptr;
        if (*ptr > arrayMax)
            arrayMax = *ptr;
    }
    cout << " min = " << arrayMin << endl;
    cout << " max = " << arrayMax << endl;
}
*/

// 5. Пользуясь указателем на массив целых чисел, осуществить циклический сдвиг
//     массива на заданное число элементов. Направление сдвига задаётся
//     пользователем. Использовать в программе арифметику указателей для
//     продвижения по массиву, а также оператор разыменования.

#include <windows.h>
#include <iostream>
#include <stdlib.h> // rand() и srand()
#include <time.h>   // time()
#include <conio.h>  // getch()

#define N 10 // массив
using namespace std;

int main(void);
void dash(int);
void dot(int);
void equal(int);

int *input_array_random(int *); // заполнение массива целыми числами
void output_array(int *);       // вывод массива на экран

int main(void)
{
    int i1 = GetConsoleCP();
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    system("cls");
    dash(75);
    cout << endl;
    cout << " 5. Осуществить циклический сдвиг массива на заданное число элементов." << endl
         << "    Направление сдвига задаётся пользователем." << endl
         << endl;
    dash(75);
    cout << endl;

    int tmp;
    int array[N];
    int *ptr = nullptr;
    ptr = array; // указатель на массив целых чисел.

    input_array_random(array);
    cout << " Исходный массив данных:" << endl;
    output_array(array);

    dot(25);
    cout << endl;
    int shift; //количество сдвигов
    cout << " Задайте сдвиг массива на --> ";
    do
    {
        cin >> shift;
        if (shift < 0)
        {
            cout << endl
                 << " Сдвиг массива не может быть отрицательным." << endl;
            cout << " Задайте сдвиг массива на --> ";
        }
    } while (shift < 0);

    int menu_number = 0;
    bool go_back = true;
    do
    {
        cout << endl
             << "    | Сдвиг массива = " << shift << "  |" << endl;
        cout << " ___| Меню выбора сдвига |___" << endl;
        cout << " 1:    <<< Влево" << endl;
        cout << " 2:        Вправо >>>" << endl;
        cout << " 3:        ВыхоД" << endl
             << endl
             << ">";
        cin >> menu_number;
        switch (menu_number)
        {
        case 1:
            cout << endl
                 << " Сдвиг ВЛЕВО на " << shift;
            for (int k = 0; k < shift; k++)
            {
                tmp = ptr[0];
                for (int i = 1; i < N; i++)
                    ptr[i - 1] = ptr[i];
                ptr[N - 1] = tmp;
            }
            cout << endl;
            output_array(array);
            dash(60);
            break;

        case 2:
            cout << endl
                 << " Сдвиг ВПРАВО на " << shift;
            for (int k = 0; k < shift; k++)
            {
                tmp = ptr[N - 1];
                for (int i = N - 1; i > 0; i--)
                    ptr[i] = ptr[i - 1];
                ptr[0] = tmp;
            }
            cout << endl;
            output_array(array);
            dash(60);
            break;

        case 3:
            go_back = false;
            break;

        default:
            cout << endl
                 << " Неверный пункт меню." << endl;
            cout << " Будьте внимательны!!!" << endl;
            cout << " Для продолжения-<ENTER>" << endl;
            getch();
            break;
        }
    } while (go_back);

    ptr = nullptr;

    equal(75);
    SetConsoleCP(i1);
    SetConsoleOutputCP(i1);
    return 0;
}

void dash(int count)
{
    int i;
    for (i = 0; i < count; i++)
        cout << "-";
}

void dot(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout << " . ";
    cout << endl;
}

void equal(int count)
{
    int i;
    cout << endl;
    for (i = 0; i < count; i++)
        cout << "=";
    cout << endl;
}

int *input_array_random(int *array)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
    {
        array[i] = rand() % 201 - 100;
    }
    return array;
}

void output_array(int *array)
{
    for (int i = 0; i < N; i++)
    {
        cout << " " << array[i] << " |";
        if ((i + 1) % N == 0)
            cout << endl;
    }
}
