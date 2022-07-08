// 1. Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо
//     создать третий массив минимально возможного размера, в котором нужно собрать
//     общие элементы двух массивов без повторений.
// 2. Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо
//     создать третий массив минимально возможного размера, в котором нужно собрать
//     элементы массива A, которые не включаются в массив B, без повторений.
// 3. Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры). Необходимо
//     создать третий массив минимально возможного размера, в котором нужно собрать
//     элементы массивов A и B, которые не являются общими для них, без повторений.
// 4. Создать функцию, позволяющую добавлять блок элементов в конец массива.
// 5. Создать функцию, позволяющую вставлять блок элементов, начиная с
//     произвольного индекса массива.
// 6. Создать функцию, позволяющую удалять блок элементов, начиная с
//     произвольного индекса массива.
// 7. Написать функцию, которая получает указатель на динамический массив и его
//     размер. Функция должна удалить из массива все простые числа и вернуть
//     указатель на новый динамический массив.
// 8. Написать функцию, которая получает указатель на статический массив и его
//     размер. Функция распределяет положительные, отрицательные и нулевые
//     элементы в отдельные динамические массивы.

#include <windows.h>
#include <iostream>
#include <stdlib.h>	 // rand() и srand()
#include <time.h>	 // time()
#include <conio.h>	 // getch()
#include <stdbool.h> // true и false

#define N 20 // начальный размер массива (выделяем память)

using namespace std;
int main(void);

//////////////////////////////// функции ввода вывода ///////////////////////////

int *inputArrayRandom(int *, int *);
void outputArray(int *, int *);

//////////////////////////////// функции задания ////////////////////////////////

int *arrayTotalUnique(int *, int *, int *, int *, int *, int *);   // 1
int *arrayNoBUnique(int *, int *, int *, int *, int *, int *);	   // 2
int *arrayNoTotalUnique(int *, int *, int *, int *, int *, int *); // 3

int *arrayEndPaste(int *, int *, int *, int *, int *, int *);	   // 4
int *arrayIPaste(int *, int *, int *, int *, int *, int *, int *); // 5
int *arrayIErase(int *, int *, int *, int *, int *);			   // 6

int *arrayPrimeN(int *, int *, int *, int *, int *, int *);						 // 7
int *arrayPlasMinesZero(int *, int *, int *, int *, int *, int *, int *, int *); // 8

//////////////////////////////// функции вспомогательные  ////////////////////////

int *arrayUnique(int *, int *);
void dash(int);
void dot(int);
void equal(int);
bool primeN(int);

//////////////////////////////////////////////////////////////////////////////////

int main(void)
{
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned int)time(nullptr));

	const int s = 18;
	// статический массив для 8 задания
	int S[s] = {-6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8};

	int *g = nullptr; // указатель для индекса пользователя

	int *m = nullptr;  // указатель для размера массива А
	int *n = nullptr;  // указатель для размера массива B
	int *q = nullptr;  // указатель для размера массива C
	int *d = nullptr;  // указатель для размера массива D
	int *ss = nullptr; // указатель для размера массива S
	int *dn = nullptr; // указатель для размера массива DN
	int *dp = nullptr; // указатель для размера массива DP
	int *dm = nullptr; // указатель для размера массива DM
	int *dz = nullptr; // указатель для размера массива DZ
	int *tt = nullptr; // указатель для размера массива TT
	int *mc = nullptr; // указатель для размера массива А копия
	int *nc = nullptr; // указатель для размера массива B копия

	int *arrA = nullptr;  // указатель на элемент массива А
	int *arrB = nullptr;  // указатель на элемент массива B
	int *arrC = nullptr;  // указатель на элемент массива C
	int *arrD = nullptr;  // указатель на элемент массива D
	int *arrS = nullptr;  // указатель на элемент массива S
	int *arrDN = nullptr; // указатель на элемент массива DN
	int *arrDP = nullptr; // указатель на элемент массива DP
	int *arrDM = nullptr; // указатель на элемент массива DM
	int *arrDZ = nullptr; // указатель на элемент массива DZ
	int *arrTT = nullptr; // указатель на элемент массива DZ
	int *arrAC = nullptr; // указатель на элемент  массива А копия
	int *arrBC = nullptr; // указатель на элемент массива B копия

	int work_or_test = 0;
	int menu_number = 0;
	int option = 0;
	char repeat;
	bool memory1 = false; // проверка инициализации в память (ПЭВМ)
	bool memory2 = false; // проверка инициализации в память (ПЭВМ)
	bool memory3 = false; // проверка инициализации в память (ПЭВМ)
	bool go_back = true;

	system("cls");
	equal(75);
	cout << endl;
	cout << " ***| Программа обработки одномерных массивов |***" << endl
		 << endl;
	cout << "  Сделайте выбор:" << endl;
	cout << " 1:ПУСК программы." << endl; // работа в программе согласно условия
	cout << " 2:ТЕСТ программы." << endl; // тест программы вывод на экран всех условий
	cout << " 3: __| ВЫХОД |__" << endl;
	do
	{
		cout << endl
			 << " Выбор > ";
		cin >> work_or_test;
		if (work_or_test != 1 && work_or_test != 2 && work_or_test != 3)
		{
			cout << endl
				 << " Некорректный ввод (Выбор = 3 -выход).";
			cout << endl
				 << " Пожалуйста сделайте выбор.";
		}

	} while (work_or_test != 1 && work_or_test != 2 && work_or_test != 3);

	// ============================== пуск программы ====================================================

	if (work_or_test == 1)
	{
		do
		{
			system("cls");
			equal(75);
			cout << endl;
			cout << "  ***| Программа обработки одномерных массивов |***" << endl
				 << endl;
			cout << "  ___________| Главное меню |______________________________________________" << endl;
			cout << "  1:Инициализация А[M] и B[N] (ввод в память ПЭВМ)." << endl;
			cout << "  2:Вывод А[M] и В[N] на экран." << endl;
			cout << "  3:С[] min размера с общими элементами А[] и В[]." << endl;
			cout << "  4:С[] min размера с элементами А[] не включающие В[]." << endl;
			cout << "  5:С[] min размера с элементами А[] и В[] не являются общими." << endl;
			cout << "  6:Добавление блока элементов в конец массива." << endl;
			cout << "  7:Вставить блок элементов, начиная с произвольного индекса массива." << endl;
			cout << "  8:Удалить блок элементов, начиная с произвольного индекса массива." << endl;
			cout << "  9:Функция удаления из D[] всех простых чисел и запись в DN[]." << endl;
			cout << " 10:Функция распределение элементов из S[] положительных, отрицательных," << endl
				 << "    нулевых: в DP[], DM[], DZ[]." << endl;
			cout << " 11: |... ВыхоД ...|" << endl
				 << endl
				 << ">";
			cin >> menu_number;
			switch (menu_number)
			{
			case 1:
				do
				{
					dash(75);
					cout << endl
						 << " __| Инициализация массивов |__" << endl;
					cout << " 1:Задать размеры массивов (переопределить)." << endl;
					cout << " 2: | Отмена |" << endl; // оставить как есть

					do
					{
						cout << endl
							 << " Выбор > ";
						cin >> option;
						if (option != 1 && option != 2)
						{
							cout << endl
								 << " Некорректный ввод (Выбор = 2 -отмена).";
							cout << endl
								 << " Пожалуйста сделайте выбор." << endl;
						}

					} while (option != 1 && option != 2);

					if (option == 1) // задаем размер массивов
					{
						if (memory1)
						{
							delete[] arrBC;
							delete[] arrAC;
							delete[] arrB;
							delete[] arrA;
							delete nc;
							delete mc;
							delete n;
							delete m;
							memory1 = false; // не в памяти
							cout << endl
								 << " Переопределяем размеры для массивов." << endl;
						}

						m = new int;
						*m = 0;
						n = new int;
						*n = 0;
						mc = new int;
						*mc = 0;
						nc = new int;
						*nc = 0;
						dot(25);
						cout << endl
							 << endl;
						cout << " Массив А[M]:" << endl;
						cout << " Количество (M) должно быть не меньше 3 и не больше 10." << endl;
						do
						{
							cout << " Введите количество (M) в массиве = ";
							cin >> *m;
							if (*m < 3 || *m > 10)
								cout << endl
									 << " Количество (M) должно быть не меньше 3 и не больше 10." << endl;

						} while (*m < 3 || *m > 10);
						cout << " Задан размер массива A[" << *m << "]" << endl
							 << endl;
						dot(25);

						cout << endl
							 << endl;
						cout << " Массив B[N]:" << endl;
						cout << " Количество (N) должно быть не меньше 3 и не больше 10." << endl;
						do
						{
							cout << " Введите количество (N) в массиве = ";
							cin >> *n;
							if (*n < 3 || *n > 10)
								cout << endl
									 << " Количество (N) должно быть не меньше 3 и не больше 10." << endl;

						} while (*n < 3 || *n > 10);
						cout << " Задан размер массива B[" << *n << "]" << endl
							 << endl;
						dash(75);

						arrA = new int[N];
						arrB = new int[N];
						arrAC = new int[N];
						arrBC = new int[N];
						if (arrA && arrB && arrAC && arrBC)
						{
							arrA = inputArrayRandom(arrA, m);
							arrB = inputArrayRandom(arrB, n);

							// копируем размеры массивов
							for (int i = 0; i < *m; i++)
								*mc = *m;
							for (int i = 0; i < *n; i++)
								*nc = *n;

							// копируем значения массивов
							for (int i = 0; i < *m; i++)
								arrAC[i] = arrA[i];
							for (int i = 0; i < *n; i++)
								arrBC[i] = arrB[i];

							// удаляем дубликаты с массива А и массива В
							// элементы двух массивов без повторений согласно условию
							arrayUnique(arrA, m);
							arrayUnique(arrB, n);

							cout << endl
								 << " Массивы инициализированы в память успешно." << endl;
							memory1 = true; // в памяти
						}
						else
							cout << endl
								 << " Нет возможности выделить память для массивов." << endl;
					}

					equal(75);
					cout << endl
						 << " Y - Инициализировать массивы (переопределить).";
					cout << endl
						 << " Q - Выход в Главное меню." << endl
						 << ">";
					repeat = getch();
				} while (repeat == 'y' || repeat == 'Y');
				break;

			case 2:
				dash(75);
				if (memory1)
				{
					cout << endl
						 << " __| Исходные массивы данных |__" << endl
						 << endl;
					cout << " A[" << *mc << "] = ";
					outputArray(arrAC, mc);
					cout << " B[" << *nc << "] = ";
					outputArray(arrBC, nc);
					cout << endl;
				}
				else
					cout << endl
						 << " Массивы не инициализированы в оперативную память." << endl;

				equal(75);
				cout << endl
					 << " Для продолжения-<ENTER>";
				getch();
				break;

			case 3:
				dash(75);
				if (memory1)
				{
					cout << endl
						 << " __| Массивы без дубликатов |__" << endl
						 << endl;
					cout << " A[" << *m << "] = ";
					outputArray(arrA, m);
					cout << " B[" << *n << "] = ";
					outputArray(arrB, n);
					cout << endl;
					dot(25);
					cout << endl
						 << endl;

					q = new int;
					*q = 0;
					arrC = new int[N];
					cout << " __| Результат 3 пункта меню |__" << endl
						 << endl;
					arrayTotalUnique(arrA, arrB, arrC, m, n, q);
					cout << " C[" << *q << "] = ";
					outputArray(arrC, q);
					cout << endl;
					delete[] arrC;
					delete q;
				}
				else
					cout << endl
						 << " Массивы не инициализированы в оперативную память." << endl;

				equal(75);
				cout << endl
					 << " Для продолжения-<ENTER>";
				getch();
				break;

			case 4:
				dash(75);
				if (memory1)
				{
					cout << endl
						 << " __| Массивы без дубликатов |__" << endl
						 << endl;
					cout << " A[" << *m << "] = ";
					outputArray(arrA, m);
					cout << " B[" << *n << "] = ";
					outputArray(arrB, n);
					cout << endl;
					dot(25);
					cout << endl
						 << endl;

					q = new int;
					*q = 0;
					arrC = new int[N];
					cout << " __| Результат 4 пункта меню |__" << endl
						 << endl;
					arrayNoBUnique(arrA, arrB, arrC, m, n, q);
					cout << " C[" << *q << "] = ";
					outputArray(arrC, q);
					cout << endl;
					delete[] arrC;
					delete q;
				}
				else
					cout << endl
						 << " Массивы не инициализированы в оперативную память." << endl;

				equal(75);
				cout << endl
					 << " Для продолжения-<ENTER>";
				getch();
				break;

			case 5:
				dash(75);
				if (memory1)
				{
					cout << endl
						 << " __| Массивы без дубликатов |__" << endl
						 << endl;
					cout << " A[" << *m << "] = ";
					outputArray(arrA, m);
					cout << " B[" << *n << "] = ";
					outputArray(arrB, n);
					cout << endl;
					dot(25);
					cout << endl
						 << endl;

					q = new int;
					*q = 0;
					arrC = new int[N];
					cout << " __| Результат 5 пункта меню |__" << endl
						 << endl;
					arrayNoTotalUnique(arrA, arrB, arrC, m, n, q);
					cout << " C[" << *q << "] = ";
					outputArray(arrC, q);
					cout << endl;
					delete[] arrC;
					delete q;
				}
				else
					cout << endl
						 << " Массивы не инициализированы в оперативную память." << endl;

				equal(75);
				cout << endl
					 << " Для продолжения-<ENTER>";
				getch();
				break;

			case 6:
				dash(75);
				if (memory1)
				{
					cout << endl
						 << " __| Исходные массивы данных |__" << endl
						 << endl;
					cout << " Основной - A[" << *mc << "] = ";
					outputArray(arrAC, mc);
					cout << "     Блок - B[" << *nc << "] = ";
					outputArray(arrBC, nc);
					cout << endl;
					dot(25);
					cout << endl
						 << endl;

					q = new int;
					*q = 0;
					arrC = new int[N];
					arrayEndPaste(arrAC, arrBC, arrC, mc, nc, q);
					cout << endl
						 << " __| Результат 6 пункта меню |__" << endl
						 << endl;
					cout << " A[" << *q << "] = ";
					outputArray(arrC, q);
					cout << endl;
					delete[] arrC;
					delete q;
				}
				else
					cout << endl
						 << " Массивы не инициализированы в оперативную память." << endl;

				equal(75);
				cout << endl
					 << " Для продолжения-<ENTER>";
				getch();
				break;

			case 7:
				dash(75);
				if (memory1)
				{
					cout << endl
						 << " __| Исходные массивы данных |__" << endl
						 << endl;
					cout << " Основной - A[" << *mc << "] = ";
					outputArray(arrAC, mc);
					cout << "     Блок - B[" << *nc << "] = ";
					outputArray(arrBC, nc);
					cout << endl;
					dot(25);
					cout << endl
						 << endl;

					g = new int;
					*g = 0;
					q = new int;
					*q = 0;
					arrC = new int[N];
					arrayIPaste(arrAC, arrBC, arrC, mc, nc, q, g);
					cout << endl
						 << " __| Результат 7 пункта меню |__" << endl
						 << endl;
					cout << " A[" << *q << "] = ";
					outputArray(arrC, q);
					cout << endl;
					delete[] arrC;
					delete q;
					delete g;
				}
				else
					cout << endl
						 << " Массивы не инициализированы в оперативную память." << endl;

				equal(75);
				cout << endl
					 << " Для продолжения-<ENTER>";
				getch();
				break;

			case 8:
				dash(75);
				if (memory1)
				{
					cout << endl
						 << " __| Исходные массивы данных |__" << endl
						 << endl;
					cout << " Основной - A[" << *mc << "] = ";
					outputArray(arrAC, mc);
					cout << endl;
					dot(25);
					cout << endl
						 << endl;

					g = new int;
					*g = 0;
					q = new int;
					*q = 0;
					arrC = new int[N];
					arrayIErase(arrAC, arrC, mc, q, g);
					cout << endl
						 << " __| Результат 8 пункта меню |__" << endl
						 << endl;
					cout << " A[" << *q << "] = ";
					outputArray(arrC, q);
					cout << endl;
					delete[] arrC;
					delete q;
					delete g;
				}
				else
					cout << endl
						 << " Массивы не инициализированы в оперативную память." << endl;

				equal(75);
				cout << endl
					 << " Для продолжения-<ENTER>";
				getch();
				break;

			case 9:
				do
				{
					dash(75);
					cout << endl
						 << " __| Пункт меню 9 |__" << endl;
					cout << " 1:Выделить память для D[] и DN[] (перевыделить)." << endl;
					cout << " 2:Посмотреть работу функции." << endl;
					cout << " 3: | Отмена |" << endl; // оставить как есть
					do
					{
						cout << endl
							 << " Выбор > ";
						cin >> option;
						if (option != 1 && option != 2 && option != 3)
						{
							cout << endl
								 << " Некорректный ввод (Выбор = 3 -отмена).";
							cout << endl
								 << " Пожалуйста сделайте выбор." << endl;
						}

					} while (option != 1 && option != 2 && option != 3);

					if (option == 1) // выделяем память для массивов
					{
						if (memory2)
						{
							delete[] arrDN;
							delete[] arrD;
							delete dn;
							delete d;
							memory2 = false; // не в памяти
							cout << endl
								 << " Перевыделяем память для массивов.";
						}

						d = new int;
						*d = 20;
						dn = new int;
						*dn = 0;

						arrD = new int[N];
						arrDN = new int[N];
						if (arrD && arrDN)
						{
							arrD = inputArrayRandom(arrD, d);
							cout << endl
								 << " Память для массивов выделена успешно." << endl;
							memory2 = true; // в памяти
						}
						else
							cout << endl
								 << " Нет возможности выделить память для массивов." << endl;
					}

					if (option == 2) // просмотр работы функции
					{
						if (memory2)
						{
							cout << endl
								 << " Исходный массив:" << endl;
							cout << " D[" << *d << "] = ";
							outputArray(arrD, d);
							cout << endl;
							tt = new int;
							*tt = 0;
							arrTT = new int[N];
							arrayPrimeN(arrD, arrDN, arrTT, d, dn, tt);
							dot(25);
							cout << endl
								 << endl;
							cout << " Результат:" << endl;
							cout << " Удаляем из D[] все простые числа" << endl;
							cout << " D[" << *d << "] = ";
							outputArray(arrD, d);
							cout << " Записываем все простые числа из D[] в массив DN[]" << endl;
							cout << " DN[" << *dn << "] = ";
							outputArray(arrDN, dn);
							cout << endl;
							delete[] arrTT;
							delete tt;
						}
						else
							cout << endl
								 << " Память НЕ выделена для массивов." << endl;
					}

					equal(75);
					cout << endl
						 << " R - Вернутся к 9 пункту меню.";
					cout << endl
						 << " Q - Выход в Главное меню." << endl
						 << ">";
					repeat = getch();
				} while (repeat == 'r' || repeat == 'R');
				break;

			case 10:
				do
				{
					dash(75);
					cout << endl
						 << " __| Пункт меню 10 |__" << endl;
					cout << " 1:Выделить память для DP[], DM[], DZ[] (перевыделить)." << endl;
					cout << " 2:Посмотреть работу функции." << endl;
					cout << " 3: | Отмена |" << endl; // оставить как есть
					do
					{
						cout << endl
							 << " Выбор > ";
						cin >> option;
						if (option != 1 && option != 2 && option != 3)
						{
							cout << endl
								 << " Некорректный ввод (Выбор = 3 -отмена).";
							cout << endl
								 << " Пожалуйста сделайте выбор." << endl;
						}

					} while (option != 1 && option != 2 && option != 3);

					if (option == 1) // выделяем память для массивов
					{
						if (memory3)
						{
							delete[] arrDZ;
							delete[] arrDM;
							delete[] arrDP;
							delete[] arrS;
							delete dz;
							delete dm;
							delete dp;
							delete ss;
							memory3 = false; // не в памяти
							cout << endl
								 << " Перевыделяем память для массивов.";
						}

						dp = new int;
						*dp = 0;
						dm = new int;
						*dm = 0;
						dz = new int;
						*dz = 0;

						arrDP = new int[N];
						arrDM = new int[N];
						arrDZ = new int[N];
						if (arrDP && arrDM && arrDZ)
						{
							ss = new int;
							*ss = 0;
							arrS = new int[N];

							// создаем указатель на статический размер массива S[]
							for (int i = 0; i < s; i++)
								(*ss)++;
							// копируем статический массив S[] вместо простого указателя на статический массив
							// для стабильной работы на вход выход
							for (int i = 0; i < s; i++)
								if (S[i] != 0) // избавляемся от неточности
									arrS[i] = S[i];
								else
									arrS[i] = NULL;

							cout << endl
								 << " Память для массивов выделена успешно." << endl;
							memory3 = true; // в памяти
						}
						else
							cout << endl
								 << " Нет возможности выделить память для массивов." << endl;
					}

					if (option == 2) // просмотр работы функции
					{
						cout << endl
							 << " Исходный массив:" << endl;
						cout << " S[" << s << "] = ";
						cout << "{";
						for (int i = 0; i < s; i++)
						{
							cout << " " << S[i] << ",";
							if ((i + 1) % s == 0)
								cout << "}" << endl;
						}
						cout << endl;

						if (memory3)
						{
							arrayPlasMinesZero(arrS, arrDP, arrDM, arrDZ, dp, dm, dz, ss);
							cout << endl;
						}
						else
							cout << endl
								 << " Память НЕ выделена для массивов." << endl;
					}

					equal(75);
					cout << endl
						 << " R - Вернутся к 10 пункту меню.";
					cout << endl
						 << " Q - Выход в Главное меню." << endl
						 << ">";
					repeat = getch();
				} while (repeat == 'r' || repeat == 'R');
				break;

			case 11:
				cout << endl
					 << "    ....................................................................";
				cout << endl
					 << "    |   (^-^)/   (^-^)/   (^-^)/   (^-^)/   (^-^)/   (^-^)/   (^-^)/   |";
				cout << endl
					 << "    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''";
				cout << endl
					 << endl;
				if (memory1)
				{
					delete[] arrBC;
					delete[] arrAC;
					delete[] arrB;
					delete[] arrA;
					delete nc;
					delete mc;
					delete n;
					delete m;
					memory1 = false; // не в памяти
					cout << " // ПАМЯТЬ 1 очищена ";
				}
				if (memory2)
				{
					delete[] arrDN;
					delete[] arrD;
					delete dn;
					delete d;
					memory2 = false; // не в памяти
					cout << " // ПАМЯТЬ 2 очищена ";
				}
				if (memory3)
				{
					delete[] arrDZ;
					delete[] arrDM;
					delete[] arrDP;
					delete[] arrS;
					delete dz;
					delete dm;
					delete dp;
					delete ss;
					memory3 = false; // не в памяти
					cout << " // ПАМЯТЬ 3 очищена ";
				}
				go_back = false;
				break;

			default:
				cout << endl
					 << " Неверный пункт меню." << endl;
				cout << " Будьте внимательны!!!" << endl;
				cout << " Для продолжения-<ENTER>";
				getch();
				break;
			}

		} while (go_back);
	}

	// ============================== тест программы ====================================================

	if (work_or_test == 2)
	{
		system("cls");
		equal(75);
		cout << endl;
		cout << "____________________________| ТЕСТ программы |_____________________________" << endl;
		dash(75);

		m = new int;
		*m = 10;
		n = new int;
		*n = 10;
		mc = new int;
		*mc = 0;
		nc = new int;
		*nc = 0;

		arrA = new int[N];
		arrB = new int[N];
		arrAC = new int[N];
		arrBC = new int[N];

		if (arrA && arrB && arrAC && arrBC)
		{
			arrA = inputArrayRandom(arrA, m);
			arrB = inputArrayRandom(arrB, n);

			cout << endl
				 << " Массивы инициализированы в память успешно." << endl;
			memory1 = true; // в памяти
		}
		else
			cout << endl
				 << " Нет возможности выделить память для массивов." << endl;

		dash(75);
		if (memory1)
		{
			//------------------------------------------ I ---------------------------------------
			// копируем размеры массивов
			for (int i = 0; i < *m; i++)
				*mc = *m;
			for (int i = 0; i < *n; i++)
				*nc = *n;

			// копируем значения массивов
			for (int i = 0; i < *m; i++)
				arrAC[i] = arrA[i];
			for (int i = 0; i < *n; i++)
				arrBC[i] = arrB[i];

			// удаляем дубликаты с массива А и массива В
			// элементы двух массивов без повторений согласно условию
			arrayUnique(arrA, m);
			arrayUnique(arrB, n);

			cout << endl
				 << " __| Исходные массивы данных |__" << endl
				 << endl;
			cout << " A[" << *mc << "] = ";
			outputArray(arrAC, mc);
			cout << " B[" << *nc << "] = ";
			outputArray(arrBC, nc);
			cout << endl;
			dot(25);
			cout << endl;
			cout << endl
				 << " __| Массивы без дубликатов |__" << endl
				 << endl;
			cout << " A[" << *m << "] = ";
			outputArray(arrA, m);
			cout << " B[" << *n << "] = ";
			outputArray(arrB, n);
			cout << endl;

			dash(75);
			cout << endl;
			cout << " === С[] min размера с общими элементами А[] и В[] ===" << endl
				 << endl;
			q = new int;
			*q = 0;
			arrC = new int[N];
			arrayTotalUnique(arrA, arrB, arrC, m, n, q);
			cout << " C[" << *q << "] = ";
			outputArray(arrC, q);
			cout << endl;
			delete[] arrC;
			delete q;

			dash(75);
			cout << endl;
			cout << " === С[] min размера с элементами А[] не включающие В[] ===" << endl
				 << endl;
			q = new int;
			*q = 0;
			arrC = new int[N];
			arrayNoBUnique(arrA, arrB, arrC, m, n, q);
			cout << " C[" << *q << "] = ";
			outputArray(arrC, q);
			cout << endl;
			delete[] arrC;
			delete q;

			dash(75);
			cout << endl;
			cout << " === С[] min размера с элементами А[] и В[] не являются общими ===" << endl
				 << endl;
			q = new int;
			*q = 0;
			arrC = new int[N];
			arrayNoTotalUnique(arrA, arrB, arrC, m, n, q);
			cout << " C[" << *q << "] = ";
			outputArray(arrC, q);
			cout << endl;
			delete[] arrC;
			delete q;

			//------------------------------------------ II ---------------------------------------
			dash(75);
			cout << endl;
			cout << " === Добавление блока элементов в конец массива ===" << endl
				 << endl;
			cout << " Исходные массивы:" << endl;
			cout << " Основной - A[" << *mc << "] = ";
			outputArray(arrAC, mc);
			cout << "     Блок - B[" << *nc << "] = ";
			outputArray(arrBC, nc);
			cout << endl;
			dot(25);
			cout << endl
				 << endl;
			q = new int;
			*q = 0;
			arrC = new int[N];
			arrayEndPaste(arrAC, arrBC, arrC, mc, nc, q);
			cout << " Результат:" << endl;
			cout << " A[" << *q << "] = ";
			outputArray(arrC, q);
			cout << endl;
			delete[] arrC;
			delete q;

			dash(75);
			cout << endl;
			cout << " === Вставить блок элементов, начиная с произвольного индекса массива ===" << endl
				 << endl;
			cout << " Исходные массивы:" << endl;
			cout << " Основной - A[" << *mc << "] = ";
			outputArray(arrAC, mc);
			cout << "     Блок - B[" << *nc << "] = ";
			outputArray(arrBC, nc);
			cout << endl;
			q = new int;
			*q = 0;
			arrC = new int[N];
			cout << " Отсчет массива всегда начинается с нулевого индекса!" << endl;
			cout << " Задайте индекс c которого будет вставлен блок элементов." << endl;
			cout << ">5" << endl;
			for (int i = 0; i < 5; i++)
			{
				arrC[(*q)++] = arrAC[i];
			}
			for (int i = 0; i < *nc; i++)
			{
				arrC[(*q)++] = arrBC[i];
			}
			dot(25);
			cout << endl
				 << endl;
			cout << " Результат:" << endl;
			cout << " A[" << *q << "] = ";
			outputArray(arrC, q);
			cout << endl;
			delete[] arrC;
			delete q;

			dash(75);
			cout << endl;
			cout << " === Удалить блок элементов, начиная с произвольного индекса массива ===" << endl
				 << endl;
			cout << " Исходный массив:" << endl;
			cout << " A[" << *mc << "] = ";
			outputArray(arrAC, mc);
			cout << endl;
			q = new int;
			*q = 0;
			arrC = new int[N];
			cout << " Отсчет массива всегда начинается с нулевого индекса!" << endl;
			cout << " Задайте индекс c которого будет удален блок элементов." << endl;
			cout << ">5" << endl;
			for (int i = 0; i < 5; i++)
			{
				arrC[(*q)++] = arrAC[i];
			}
			dot(25);
			cout << endl
				 << endl;
			cout << " Результат:" << endl;
			cout << " A[" << *q << "] = ";
			outputArray(arrC, q);
			cout << endl;
			delete[] arrC;
			delete q;

			delete[] arrBC;
			delete[] arrAC;
			delete[] arrB;
			delete[] arrA;
			delete nc;
			delete mc;
			delete n;
			delete m;
			dash(75);
		}
		else
			cout << endl
				 << " Массивы не инициализированы в оперативную память." << endl;

		//------------------------------------------ III ---------------------------------------
		ss = new int;
		*ss = 0;
		arrS = new int[N];

		// создаем из указатель на статический размер массива S[]
		for (int i = 0; i < s; i++)
			(*ss)++;
		// копируем статический массив S[] вместо простого указателя на статический массив
		// для стабильной работы на вход выход
		for (int i = 0; i < s; i++)
			if (S[i] != 0) // избавляемся от неточности
				arrS[i] = S[i];
			else
				arrS[i] = NULL;

		d = new int;
		*d = 20;
		dn = new int;
		*dn = 0;
		dp = new int;
		*dp = 0;
		dm = new int;
		*dm = 0;
		dz = new int;
		*dz = 0;

		arrD = new int[N];
		arrDN = new int[N];
		arrDP = new int[N];
		arrDM = new int[N];
		arrDZ = new int[N];
		if (arrD && arrDN && arrDP && arrDM && arrDZ)
		{
			arrD = inputArrayRandom(arrD, d);
			cout << endl
				 << " Массивы инициализированы в память успешно." << endl;
			memory2 = true; // в памяти
		}
		else
			cout << endl
				 << " Нет возможности выделить память для массивов." << endl;

		dash(75);
		if (memory2)
		{
			cout << endl;
			cout << " === Удалить из D[] все простые числа и вернуть в DN[] ===" << endl
				 << endl;
			cout << " Исходный массив:" << endl;
			cout << " D[" << *d << "] = ";
			outputArray(arrD, d);
			cout << endl;
			tt = new int;
			*tt = 0;
			arrTT = new int[N];
			arrayPrimeN(arrD, arrDN, arrTT, d, dn, tt);
			dot(25);
			cout << endl
				 << endl;
			cout << " Результат:" << endl;
			cout << " Удаляем из D[] все простые числа" << endl;
			cout << " D[" << *d << "] = ";
			outputArray(arrD, d);
			cout << " Записываем все простые числа из D[] в массив DN[]" << endl;
			cout << " DN[" << *dn << "] = ";
			outputArray(arrDN, dn);
			cout << endl;
			delete[] arrTT;
			delete tt;

			dash(75);
			cout << endl;
			cout << " === Распределение элементов из S[] положительных, отрицательных, ===" << endl;
			cout << " === нулевых: в DP[], DM[], DZ[].                                 ===" << endl
				 << endl;
			cout << " Исходный массив:" << endl;
			cout << " S[" << s << "] = ";
			cout << "{";
			for (int i = 0; i < s; i++)
			{
				cout << " " << S[i] << ",";
				if ((i + 1) % s == 0)
					cout << "}" << endl;
			}
			cout << endl;
			arrayPlasMinesZero(arrS, arrDP, arrDM, arrDZ, dp, dm, dz, ss);

			delete[] arrDZ;
			delete[] arrDM;
			delete[] arrDP;
			delete[] arrDN;
			delete[] arrD;
			delete[] arrS;
			delete dz;
			delete dm;
			delete dp;
			delete dn;
			delete d;
			delete ss;
		}
		else
			cout << endl
				 << " Массивы не инициализированы в оперативную память." << endl;
	}

	arrBC = nullptr;
	arrAC = nullptr;
	arrTT = nullptr;
	arrDZ = nullptr;
	arrDM = nullptr;
	arrDP = nullptr;
	arrDN = nullptr;
	arrS = nullptr;
	arrD = nullptr;
	arrC = nullptr;
	arrB = nullptr;
	arrA = nullptr;

	nc = nullptr;
	mc = nullptr;
	tt = nullptr;
	dz = nullptr;
	dm = nullptr;
	dp = nullptr;
	dn = nullptr;
	ss = nullptr;
	d = nullptr;
	q = nullptr;
	n = nullptr;
	m = nullptr;

	g = nullptr;

	cout << endl;
	equal(75);
	SetConsoleCP(i1);
	SetConsoleOutputCP(i1);
	return 0;
}

//============================= функции ввода вывода ========================================
//
// заполнение массива целыми случайными числами
int *inputArrayRandom(int *array, int *size)
{
	for (int i = 0; i < *size; i++)
	{
		array[i] = rand() % 10;
	}
	return array;
}

// вывод массива на экран
void outputArray(int *array, int *size)
{
	cout << "{";
	for (int i = 0; i < *size; i++)
	{
		cout << " " << array[i] << ",";
		if ((i + 1) % *size == 0)
			cout << "}" << endl;
	}
}

//============================= функции задания =============================================
//
// общий минимальный размер С[] и общие элементы A[] и B[]
int *arrayTotalUnique(int *arrA, int *arrB, int *arrC, int *m, int *n, int *q)
{
	for (int i = 0; i < *m; i++)
	{
		int count = 1;
		for (int j = 0; j < i; j++)
			if (arrA[j] == arrA[i])
				++count;
		for (int j = 0; count != 0 && j < *n; j++)
			if (arrB[j] == arrA[i])
				--count;

		if (count == 0)
			arrC[(*q)++] = arrA[i];
	}
	return arrC;
}

// общий минимальный размер С[] и элементы А[] не вкл B[]
int *arrayNoBUnique(int *arrA, int *arrB, int *arrC, int *m, int *n, int *q)
{
	for (int i = 0; i < *m; i++)
	{
		int count = 1;
		for (int j = 0; j < i; j++)
			if (arrA[j] == arrA[i])
				++count;
		for (int j = 0; count != 0 && j < *n; j++)
			if (arrB[j] == arrA[i])
				--count;

		if (count == 1)
			arrC[(*q)++] = arrA[i];
	}
	return arrC;
}

// общий минимальный размер С[] и элементы А[] и B[] не общие
int *arrayNoTotalUnique(int *arrA, int *arrB, int *arrC, int *m, int *n, int *q)
{
	// общий минимальный размер С[] и элементы B[] не вкл A[]
	for (int i = 0; i < *n; i++)
	{
		int count = 1;
		for (int j = 0; j < i; j++)
			if (arrB[j] == arrB[i])
				++count;
		for (int j = 0; count != 0 && j < *n; j++)
			if (arrA[j] == arrB[i])
				--count;

		if (count == 1)
			arrC[(*q)++] = arrB[i];
	}
	// общий минимальный размер С[] и элементы А[] не вкл B[]
	for (int i = 0; i < *m; i++)
	{
		int count = 1;
		for (int j = 0; j < i; j++)
			if (arrA[j] == arrA[i])
				++count;
		for (int j = 0; count != 0 && j < *n; j++)
			if (arrB[j] == arrA[i])
				--count;

		if (count == 1)
			arrC[(*q)++] = arrA[i];
	}
	return arrC;
}

///////////////////////////////////////////////////////////
// добавление блока элементов в конец массива
int *arrayEndPaste(int *arrAC, int *arrBC, int *arrC, int *mc, int *nc, int *q)
{
	// начальный массив
	for (int i = 0; i < *mc; i++)
		arrC[(*q)++] = arrAC[i];

	// массив блок
	for (int i = 0; i < *nc; i++)
		arrC[(*q)++] = arrBC[i];

	return arrC;

	// Правильно  будет вернуть обратно массив А[] + блок
	// Чтоб не нарушать структуру кода оставляем массив С[]
	/*
		// перезапись начального массива A[] к которому добавился блок
		*mc = 0; // сброс размера
		for (int i = 0; i < *q; i++)
		{
			arrAC[(*mc)++] = arrC[i];
		}
		return arrAC;
	*/
}

// вставить блок элементов
int *arrayIPaste(int *arrAC, int *arrBC, int *arrC, int *mc, int *nc, int *q, int *g)
{
	cout << " Отсчет массива всегда начинается с нулевого индекса!" << endl;
	cout << " Задайте индекс c которого будет вставлен блок элементов." << endl;
	do
	{
		cout << ">";
		cin >> *g;

		if (*g > *mc || *g < 0)
		{
			cout << endl
				 << " Некорректный ввод индекса.";
			cout << endl
				 << " Индекс выходит за пределы массива.";
			cout << endl
				 << " Индекс может быть от 0 до " << *mc << "." << endl;
		}

	} while (*g > *mc || *g < 0);

	// начальный массив
	for (int i = 0; i < *g; i++)
		arrC[(*q)++] = arrAC[i];

	// массив блок
	for (int i = 0; i < *nc; i++)
		arrC[(*q)++] = arrBC[i];

	return arrC;
}

// удалить блок
int *arrayIErase(int *arrAC, int *arrC, int *mc, int *q, int *g)
{
	cout << " Отсчет массива всегда начинается с нулевого индекса!" << endl;
	cout << " Задайте индекс c которого будет удален блок элементов." << endl;
	do
	{
		cout << ">";
		cin >> *g;

		if (*g > *mc || *g < 0)
		{
			cout << endl
				 << " Некорректный ввод индекса.";
			cout << endl
				 << " Индекс выходит за пределы массива.";
			cout << endl
				 << " Индекс может быть от 0 до " << *mc << "." << endl;
		}

	} while (*g > *mc || *g < 0);

	// начальный массив
	for (int i = 0; i < *g; i++)
		arrC[(*q)++] = arrAC[i];

	return arrC;
}

///////////////////////////////////////////////////////////
// удалить из D[] все простые числа и вернуть в DN[]
int *arrayPrimeN(int *arrD, int *arrDN, int *arrTT, int *d, int *dn, int *tt)
{
	for (int i = 0; i < *d; i++)
	{
		if (primeN(arrD[i]))
		{
			arrDN[(*dn)++] = arrD[i];
		}
		else
		{
			arrTT[(*tt)++] = arrD[i];
		}
	}

	// перезапись массива D[] без простых чисел
	*d = 0; // сброс размера
	for (int i = 0; i < *tt; i++)
	{
		arrD[(*d)++] = arrTT[i];
	}

	return arrDN;
}

// распределение элементов и стат массива в динамические
int *arrayPlasMinesZero(int *arrS, int *arrDP, int *arrDM, int *arrDZ, int *dp, int *dm, int *dz, int *ss)
{
	for (int i = 0; i < *ss; i++)
	{
		if (arrS[i] > 0)
			arrDP[(*dp)++] = arrS[i];
		if (arrS[i] < 0)
			arrDM[(*dm)++] = arrS[i];
		if (arrS[i] == 0)
			arrDZ[(*dz)++] = NULL;
	}

	dot(25);
	cout << endl
		 << endl;
	cout << " Результат:" << endl;
	cout << " Положительные  элементы из S[]" << endl;
	cout << " DP[" << *dp << "] = ";
	outputArray(arrDP, dp);
	cout << " Отрицательные элементы из S[]" << endl;
	;
	cout << " DP[" << *dm << "] = ";
	outputArray(arrDM, dm);
	cout << " Нулевые элементы из S[] " << endl;
	cout << " DZ[" << *dz << "] = ";
	outputArray(arrDZ, dz);

	// сброс размеров для повторного входа
	*dp = 0;
	*dm = 0;
	*dz = 0;

	return arrS;
}

//============================= функции вспомогательные =========================================
//
// определяем элементы массива в единственном экземпляре
int *arrayUnique(int *array, int *size)
{
	for (int i = 0; i < *size; i++)
	{
		for (int j = i + 1; j < *size; j++)
		{
			if (array[i] == array[j]) // если найден одинаковый элемент
			{
				for (int shift = j; shift < *size - 1; shift++)
				{
					// выполнить сдвиг всех остальных элементов массива на -1,
					// начиная со следующего элемента, после найденного дубля
					array[shift] = array[shift + 1];
				}
				*size -= 1; // уменьшить размер массива на 1

				if (array[i] == array[j]) // если следующий элемент - дубль
				{
					j--; // выполнить переход на предыдущий элемент
				}
			}
		}
	}

	return size;
}
void dash(int count)
{
	for (int i = 0; i < count; i++)
		cout << "-";
}
void dot(int count)
{
	for (int i = 0; i < count; i++)
		cout << " . ";
}
void equal(int count)
{
	for (int i = 0; i < count; i++)
		cout << "=";
}
// проверка числа (простое или не простое)
bool primeN(int n)
{
	if (n > 1)
	{
		// в цикле перебираем числа от 2 до n - 1
		for (int i = 2; i < n; i++)
			if (n % i == 0) // если n делится без остатка на i - возвращаем false (число не простое)
				return false;
		// если программа дошла до данного оператора, то возвращаем true (число простое) - проверка пройдена
		return true;
	}
	else
		return false;
}
