/*
// 1. Используя указатели и оператор разыменования, определить наибольшее из двух
//     чисел.

#include <windows.h>
#include <stdio.h>

int main(void);
void dash(int);
void equal(int);

int main(void)
{
	system("cls");
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	dash(75);
	printf("\n 1. Используя указатели и оператор разыменования, определить\n"
		   "    наибольшее из двух чисел.\n\n");

	// C++11 для обнуления указателей появилось специальное ключевое слово nullptr.
	//В редких случаях, использование 0 как аргумента-литерала может привести к проблемам,
	//так как компилятор не сможет определить, используется ли нулевой указатель или целое число 0.
	double *num1 = nullptr; // пустота не указываем не на какой другой объект
	double *num2 = nullptr;

	num1 = (double *)malloc(sizeof(double)); //Выделение памяти у операционной системы для работы
	num2 = (double *)malloc(sizeof(double));

	// Защита от неправильного ввода
	while (printf(" Введите первое число = ") && scanf("%lf", num1) != 1)
	{
		char ch;
		while (scanf("%c", &ch) == 1 && ch != '\n')
			;
		printf("\n !!!Ошибка ввода.");
		printf("\n Введите только числа.");
		printf("\n Повторите ввод:\n\n");
	}
	printf(" | OK |  Первое число = %.2lf\n\n", *num1);

	while (printf(" Введите второе число = ") && scanf("%lf", num2) != 1)
	{
		char ch;
		while (scanf("%c", &ch) == 1 && ch != '\n')
			;
		printf("\n !!!Ошибка ввода.");
		printf("\n Введите только числа.");
		printf("\n Повторите ввод:\n\n");
	}
	printf(" | OK |  Второе число = %.2lf\n\n", *num2);

	if (*num1 > *num2)
	{
		//Чтобы использовать прописанное в адресе (хранимом в указательной переменной) значение,
		//нужно использовать операцию разыменования указательной переменной.
		//На экран выводится значение, прописанное в адресе, хранимом в указательной переменной "num1"
		printf("\n Наибольшее число из двух = %.2lf\n", *num1);
	}
	else
	{
		printf("\n Наибольшее число из двух = %.2lf\n", *num2);
	}
	free(num1); //Возврат памяти операционной системе
	free(num2);
	num1 = nullptr;
	num2 = nullptr;

	equal(75);
	SetConsoleCP(i1);
	SetConsoleOutputCP(i1);
	return 0;
}

void equal(int count)
{
	int i;
	printf("\n");
	for (i = 0; i < count; i++)
		printf("=");
	printf("\n");
}
void dash(int count)
{
	int i;
	for (i = 0; i < count; i++)
		printf("-");
}

// 2. Используя указатели и оператор разыменования, определить знак числа,
//     введённого с клавиатуры.

#include <windows.h>
#include <iostream>
using namespace std;

int main(void);
void dash(int);
void equal(int);

int main(void)
{
	system("cls");
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	dash(75);
	cout << endl;
	cout << " 2. Используя указатели и оператор разыменования, определить знак числа," << endl
		 << "    введенного с клавиатуры." << endl
		 << endl;

	// pointer - указатель
	double *pointer = nullptr; // pointer содержит специальное значение, называемое
							   // «нулевой указатель», который не указывает ни на какой другой объект.

	pointer = new double; // pointer содержит адрес части памяти, которая была выделена new double.
						  // Таким образом, в этой строке задействованы два выделения:
						  // pointer безымянная память и выделенная new.
						  // Это позволяет вывести адрес каждого из этих распределений отдельно.

	cout << " Введите число = ";
	cin >> *pointer; // Заносим значение в ячейку памяти

	if (*pointer >= 0)
	{
		// Разыменования указательной переменной.
		// На экран выводится значение, прописанное в адресе, хранимом в указательной переменной
		cout << endl
			 << " Знак числа " << *pointer << " положительный '+'" << endl;
	}
	else
	{
		cout << endl
			 << " Знак числа " << *pointer << " отрицательный '-'" << endl;
	}
	delete pointer;	   // Освобождение выделенной памяти
	pointer = nullptr; // Освобождение указателя

	equal(75);
	SetConsoleCP(i1);
	SetConsoleOutputCP(i1);
	return 0;
}

void equal(int count)
{
	int i;
	cout << endl;
	for (i = 0; i < count; i++)
		cout << "=";
	cout << endl;
}
void dash(int count)
{
	int i;
	for (i = 0; i < count; i++)
		cout << "-";
}

// 3. Используя указатели и оператор разыменования, обменять местами значения двух
//     переменных.

#include <windows.h>
#include <iostream>
using namespace std;

int main(void);
void equal(int);
void dash(int);

int main(void)
{
	system("cls");
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	dash(75);
	cout << endl;
	cout << " 3. Используя указатели и оператор разыменования, обменять местами" << endl
		 << "    значения двух переменных." << endl
		 << endl;

	double *a = nullptr;
	double *b = nullptr;

	a = new double;
	b = new double;

	cout << " Введите первую переменную a = ";
	cin >> *a;
	cout << " Введите вторую переменную b = ";
	cin >> *b;

	// меняем значение переменных
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;

	cout << endl
		 << " Меняем местами значения переменных a и b:" << endl;
	cout << " Переменная а = " << *a << endl;
	cout << " Переменная b = " << *b << endl;

	delete a;
	delete b;
	b = nullptr;
	a = nullptr;
	equal(75);
	SetConsoleCP(i1);
	SetConsoleOutputCP(i1);
	return 0;
}

void equal(int count)
{
	int i;
	cout << endl;
	for (i = 0; i < count; i++)
		cout << "=";
	cout << endl;
}
void dash(int count)
{
	int i;
	for (i = 0; i < count; i++)
		cout << "-";
}

// double a, b;
// cout << " a = ";
// cin >> a;
// cout <<" b = ";
// cin >> b;
// double* tmp = new double;
// *tmp = a;
// a = b;
// b = *tmp;
// delete tmp;
// cout << " a = " << a << " | " << "b = " << b;

// 4. Написать примитивный калькулятор, пользуясь только указателями.

#include <windows.h>
#include <iostream>
#include <conio.h> // getch()
using namespace std;

int main(void);
void dash(int);
void dot(int);
void equal(int);

double add_sub_div_mult(double *, double *, char *);

int main(void)
{
	system("cls");
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	dash(75);
	cout << endl;
	cout << " 4. Примитивный калькулятор, который использует только указатели." << endl
		 << endl;

	cout << " Для операции над числами используйте следующие символы:" << endl;
	cout << " сложение ( + ), вычитание ( - ), умножение ( * ) и деление ( / )." << endl;

	double *num1 = nullptr;
	double *num2 = nullptr;
	char *operation = nullptr;

	num1 = new double;
	num2 = new double;
	operation = new char;

	char repeat;
	do
	{
		dash(75);
		cout << endl;
		cout << " Введите:" << endl;
		cout << " Первое число    --> ";
		cin >> *num1;
		cout << " Символ операции --> ";
		cin >> *operation;
		cout << " Второе число    --> ";
		cin >> *num2;
		cout << " Ответ = " << add_sub_div_mult(num1, num2, operation);
		dot(25);
		cout << " " << *num1 << " " << *operation << " " << *num2 << " = " << add_sub_div_mult(num1, num2, operation) << endl
			 << endl;

		cout << " Y - Повторить." << endl;
		cout << " Q - ВыхоД" << endl
			 << ">";
		repeat = getch();
	} while (repeat == 'y' || repeat == 'Y');

	delete num1;
	delete num2;
	delete operation;
	num1 = nullptr;
	num2 = nullptr;
	operation = nullptr;

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
	cout << endl
		 << endl;
	for (i = 0; i < count; i++)
		cout << " . ";
	cout << endl
		 << endl;
}
void equal(int count)
{
	int i;
	cout << endl;
	for (i = 0; i < count; i++)
		cout << "=";
	cout << endl;
}

double add_sub_div_mult(double *num1, double *num2, char *operation)
{
	switch (*operation)
	{
	case '+':
		return (*num1) + (*num2);

	case '-':
		return (*num1) - (*num2);

	case '*':
		if ((*num1) * (*num2) == 0)
		{
			cout << " На ноль умножать бесполезно!" << endl;
			return 0;
			break;
		}
		else
		{
			return (*num1) * (*num2);
		}

	case '/':
		if ((*num1) / (*num2) == 0 || (*num2) / (*num1) == 0)
		{
			cout << " На ноль делить нельзя!" << endl;
			return 0;
			break;
		}
		else
		{
			return (*num1) / (*num2);
		}

	default:
		cout << " Такая операция не предусмотрена." << endl;
		return 0;
		break;
	}
}
*/

// 5. Пользуясь указателем на массив целых чисел, посчитать сумму элементов
//     массива. Использовать в программе арифметику указателей для продвижения по
//     массиву, а также оператор разыменования.

#include <windows.h>
#include <stdio.h>
#include <stdlib.h> // rand() и srand() (malloc, calloc, realloc)
#include <time.h>	// time()
#include <conio.h>	// getch()

int main(void);
void dash(int);
void dot(int);
void equal(int);
void eatline(void);

int *input_array_keyboard(int *, int *, int, int); // ввод массива числами с клавиатуры
int *input_array_random(int *, int *, int, int);   // ввод массива числами   рандомными
void output_array(int *, int, int);				   // вывод массива

// 1. Посчёт суммы элементов массива целых чисел.
int sum_array(int *, int, int);

int main(void)
{
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int *array = NULL;
	int *tmp = NULL;
	int n;
	int m;
	char repeat;
	do
	{
		int *option = NULL;
		option = (int *)malloc(sizeof(int));

		system("cls");
		dash(75);
		printf("\n 5. Пользуясь указателем на массив целых чисел, подсчитать сумму элементов\n"
			   "    массива.\n\n");
		dash(75);
		printf("\n _______| Подсчет суммы элементов в массиве |_______\n");
		printf("\n   Выберите действие:\n");
		printf(" 1:Задать массив для работы.\n");
		printf(" 2:Тест работы в заданном массиве.\n");
		printf(" 3:Отмена выбора.\n");
		do
		{
			printf("\n Действие >");
			scanf_s("%d", option);
			eatline();
			if (*option == 3) // отмена
				dash(75);
			else
			{
				if (*option != 1 && *option != 2)
				{
					printf("\n Некорректный ввод (Действие = 3 -отмена).");
					printf("\n Пожалуйста сделайте выбор.");
				}
				else if (*option == 1) // задать массив с клавиатуры
				{
					printf("\n ___| Выбрано 1 действие |___\n");
					printf("\n Задайте двумерный массив порядка N*M:");
					printf("\n Количество строк (N) и столбцов (M) должно быть не меньше 3 и не больше 7.\n");
					do
					{
						printf("\n Введите количество строк в массиве = ");
						scanf_s("%d", &n);
						eatline();
						if (n < 3 || n > 7)
							printf("\n Количество строк должно быть не меньше 3 и не больше 7.");

					} while (n < 3 || n > 7);
					printf(" [%d][]\n", n);
					do
					{
						printf("\n Введите количество столбцов в массиве = ");
						scanf_s("%d", &m);
						eatline();
						if (m < 3 || m > 7)
							printf("\n Количество столбцов должно быть не меньше 3 и не больше 7.");
					} while (m < 3 || m > 7);
					printf(" [%d][%d]\n\n", n, m);

					array = (int *)calloc(1, sizeof(int));
					if (array)
					{
						array = input_array_keyboard(array, tmp, n, m);
						printf("\n Исходный массив данных:\n\n");
						output_array(array, n, m);
						dot(25);
						printf("\n Сумма элементов массива = %d\n", sum_array(array, n, m));
						if (tmp)
						{
							array = tmp;
						}
						free(array);
						array = NULL;
					}
					else
						printf("\n Нет возможности выделить память под первый элемент массива.\n");

					dash(75);
				}
				else if (*option == 2) //тест
				{
					n = 7;
					m = 7;
					printf("\n ___| Выбрано 2 действие |___\n");
					printf("\n Задан двумерный массив порядка [%d][%d]", n, m);

					array = (int *)calloc(1, sizeof(int));
					if (array)
					{
						array = input_array_random(array, tmp, n, m);
						printf("\n Исходный массив данных:\n\n");
						output_array(array, n, m);
						dot(25);
						printf("\n Сумма элементов массива = %d\n", sum_array(array, n, m));
						if (tmp)
						{
							array = tmp;
						}
						free(array);
						array = NULL;
					}
					else
						printf("\n Нет возможности выделить память под первый элемент массива.\n");

					dash(75);
				}
			}
		} while (*option != 1 && *option != 2 && *option != 3);

		free(option);
		option = NULL;
		printf("\n Y - Вернутся к выбору действия.");
		printf("\n Q - Выход из программы.\n>");
		repeat = getch();
	} while (repeat == 'y' || repeat == 'Y');

	equal(75);
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
void dot(int count)
{
	int i;
	printf("\n");
	for (i = 0; i < count; i++)
		printf(" . ");
	printf("\n");
}
void equal(int count)
{
	int i;
	printf("\n");
	for (i = 0; i < count; i++)
		printf("=");
	printf("\n");
}
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

// ручной ввод чисел
int *input_array_keyboard(int *array, int *tmp, int n, int m)
{
	int i = 0;
	int j = 0;
	char ch;
	tmp = (int *)realloc(array, n * m * sizeof(int));
	while (1)
	{
		printf(" Элемент массива [%d][%d] = ", i, j);
		// Чтение символа символа из стандартного вывода, заканчивающегося символом новой строки.
		if (!scanf_s("%d", tmp) || getchar() != '\n')
		{
			// Очищаем стандартный вывод перед чтением следующего символа.
			while ((ch = getchar()) != '\n' && ch != EOF)
				;
		}
		else
			break;

		printf("\n !!!Ошибка ввода.");
		printf("\n Введите целые числа.");
		printf("\n Повторите ввод:\n\n");
	}
	if (tmp)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (i == 0 && j == 0)
					continue;
				else
				{
					while (1)
					{
						printf(" Элемент массива [%d][%d] = ", i, j);
						if (!scanf_s("%d", tmp + j + (m * i)) || getchar() != '\n')
							while ((ch = getchar()) != '\n' && ch != EOF)
								;
						else
							break;

						printf("\n !!!Ошибка ввода.");
						printf("\n Введите целые числа.");
						printf("\n Повторите ввод:\n\n");
					}
				}
			}
		}
		return tmp;
	}
	else
		printf("\n Нет возможности выделить память под оставшиеся элементы массива.\n");
	return 0;
}

// рандомный ввод чисел
int *input_array_random(int *array, int *tmp, int n, int m)
{
	int i, j;
	tmp = (int *)realloc(array, n * m * sizeof(int));
	srand((unsigned)time(NULL));
	if (tmp)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (i == 0 && j == 0)
					continue;
				else
				{
					*(tmp + j + (m * i)) = rand() % 201 - 100;
				}
			}
		}
		return tmp;
	}
	else
		printf("\n Нет возможности выделить память под оставшиеся элементы массива.\n");
	return 0;
}

// вывод массива на экран
void output_array(int *array, int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%6d", *(array + j + (m * i)));
			if ((j + 1) % m == 0)
				printf("\n");
		}
	}
}

// сумма элементов в массиве
int sum_array(int *array, int n, int m)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sum += *(array + j + (m * i));
	return sum;
}
