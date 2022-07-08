// Разработать программу, в составе которой выполняли бы свою работу
// следующие написанные пользовательские функции:

// 1. Функция, которая возвращает куб числа.
// 2. Функция для нахождения наибольшего из двух чисел.
// 3. Функция, которая возвращает истину, если передаваемое значение
//     положительное и ложь, если отрицательное.
// 4. Функция, которая в зависимости от выбора пользователя вызывает функции
//     сложения, произведения, вычитания, деления двух чисел (эти функции тоже
//     нужно написать самостоятельно).
// 5. Функция, выводящая на экран прямоугольник с высотой N и шириной K.
// 6. Функция, которая проверяет, является ли переданное ей число простым? Число
//     называется простым, если оно делится без остатка только на себя и на единицу.
// 7. Написать функцию, вычисляющую факториал переданного ей числа.

#include <windows.h>
#include <stdio.h>
#include <conio.h>	 // в этом файле содержится функция getch()
#include <stdbool.h> //содержится определение логических констант true и false

int main(void);
void dash(int);

// 1. Функция, которая возвращает куб числа.
int cube(int);
// 2. Функция для нахождения наибольшего из двух чисел.
int max_num(int, int);
// 3. Функция, которая возвращает истину,
//    если передаваемое значение положительное и ложь, если отрицательное.
bool is_positive(int);
// 4. Функция, которая в зависимости от выбора пользователя вызывает функции:
//    сложения, произведения, вычитания, деления двух чисел.
float add_sub_div_mult(float, float, char);
// 5. Функция, выводящая на экран прямоугольник с высотой N и шириной K.
int rectangle(int, int);
// 6. Функция, которая проверяет, является ли переданное ей число простым?
bool prime_num(int);
// 7. Функция, вычисляющую факториал переданного ей числа.
long double factorial(int);

int main(void)
{
	int i1 = GetConsoleCP();
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char repeat;
	int menu_number = 0;
	bool go_back = true;
	do
	{
		system("cls");
		printf(" ***| Программа работы с функциями | ***\n\n");
		printf(" ___________| Главное меню |____________\n");
		printf("   Выберите ФУКЦИЮ для работы:\n");
		printf(" 1:Которая возвращает куб числа.\n");
		printf(" 2:Нахождения наибольшего из двух чисел.\n");
		printf(" 3:Которая возвращает истину, если передаваемое значение \n"
			   "   положительное и ложь, если отрицательное.\n");
		printf(" 4:Которая в зависимости от выбора пользователя вызывает функции\n"
			   "   сложения, произведения, вычитания, деления двух чисел.\n");
		printf(" 5:Выводящая на экран прямоугольник с высотой N и шириной K.\n");
		printf(" 6:Которая проверяет, является ли переданное ей число простым?\n");
		printf(" 7:Вычисляющую факториал переданного ей числа.\n");
		printf(" 8: | ВыхоД |\n\n>");
		scanf("%d", &menu_number);
		switch (menu_number)
		{
		case 1:
			do
			{
				dash(40);
				printf("\n Вы находитесь в 1 пункте меню.\n");
				int num, result;
				printf("\n Введите число --> ");
				scanf("%d", &num);
				result = cube(num);
				printf(" Куб числа %d = %d\n", num, result);
				printf("\n Y - Продолжить.");
				printf("\n Q - Выход в Главное меню.\n>");
				repeat = getch();
			} while (repeat == 'y' || repeat == 'Y');
			break;

		case 2:
			do
			{
				dash(40);
				printf("\n Вы находитесь в 2 пункте меню.\n");
				int num1, num2, result;
				printf("\n Введите первое число --> ");
				scanf("%d", &num1);
				printf(" Введите второе число --> ");
				scanf("%d", &num2);
				result = max_num(num1, num2);
				printf(" MAX число из двух чисел = %d\n", result);
				printf("\n Y - Продолжить.");
				printf("\n Q - Выход в Главное меню.\n>");
				repeat = getch();
			} while (repeat == 'y' || repeat == 'Y');
			break;

		case 3:
			do
			{
				dash(40);
				printf("\n Вы находитесь в 3 пункте меню.\n");
				int num, result;
				printf("\n Введите число --> ");
				scanf("%d", &num);
				result = is_positive(num);
				if (result == 1)
					printf(" Число = %d положительное. (bool = %d)\n", num, result);
				else
					printf(" Число = %d отрицательное. (bool = %d)\n", num, result);
				printf("\n Y - Продолжить.");
				printf("\n Q - Выход в Главное меню.\n>");
				repeat = getch();
			} while (repeat == 'y' || repeat == 'Y');
			break;

		case 4:
			do
			{
				dash(40);
				printf("\n Вы находитесь в 4 пункте меню.\n");
				int operation;
				float num1, num2, result;
				printf("\n Введите первое число --> ");
				scanf("%f", &num1);
				printf(" Введите второе число --> ");
				scanf("%f", &num2);
				printf("\n Операции над числами:");
				printf("\n Сложение  нажмите 1.");
				printf("\n Вычитание нажмите 2.");
				printf("\n Умножения нажмите 3.");
				printf("\n Деления   нажмите 4.");
				printf("\n>");
				scanf("%d", &operation);
				result = add_sub_div_mult(num1, num2, operation);
				printf(" Ответ = %.2f\n", result);
				printf("\n Y - Продолжить.");
				printf("\n Q - Выход в Главное меню.\n>");
				repeat = getch();
			} while (repeat == 'y' || repeat == 'Y');
			break;

		case 5:
			do
			{
				dash(40);
				printf("\n Вы находитесь в 5 пункте меню.\n");
				int n, k;
				printf("\n Введите высоту прямоугольника N = ");
				scanf("%d", &n);
				printf(" Введите ширину прямоугольника K = ");
				scanf("%d", &k);
				rectangle(n, k);
				printf("\n Y - Продолжить.");
				printf("\n Q - Выход в Главное меню.\n>");
				repeat = getch();
			} while (repeat == 'y' || repeat == 'Y');
			break;

		case 6:
			do
			{
				dash(40);
				printf("\n Вы находитесь в 6 пункте меню.\n");
				int num, result;
				printf("\n Введите число --> ");
				scanf("%d", &num);
				if (prime_num(num) == 1)
					printf(" Введенное число %d простое.\n", num);
				else
					printf(" Введенное число %d сложное.\n", num);
				printf("\n Y - Продолжить.");
				printf("\n Q - Выход в Главное меню.\n>");
				repeat = getch();
			} while (repeat == 'y' || repeat == 'Y');
			break;

		case 7:
			do
			{
				dash(40);
				printf("\n Вы находитесь в 7 пункте меню.\n");
				int num;
				long long result;
				printf("\n Введите число --> ");
				scanf("%d", &num);
				result = factorial(num);
				printf(" Факториал числа %d = %lld\n", num, result);
				printf("\n Y - Продолжить.");
				printf("\n Q - Выход в Главное меню.\n>");
				repeat = getch();
			} while (repeat == 'y' || repeat == 'Y');
			break;

		case 8:
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

int cube(int num)
{
	int result;
	result = num * num * num;
	return result;
}

int max_num(int num1, int num2)
{
	return (num1 > num2) ? num1 : num2;
}

bool is_positive(int num)
{
	bool result;
	if (num > 0)
		result = 1;
	else
		result = 0;
	return result;
}

float add_sub_div_mult(float num1, float num2, char operation)
{
	switch (operation)
	{
	case 1:
		return num1 + num2;

	case 2:
		return num1 - num2;

	case 3:
		if (num1 * num2 == 0)
		{
			printf(" На ноль умножать нельзя!\n");
			return 0;
			break;
		}
		else
		{
			return num1 * num2;
		}

	case 4:
		if (num1 / num2 == 0 || num2 / num1 == 0)
		{
			printf(" На ноль делить нельзя!\n");
			return 0;
			break;
		}
		else
		{
			return num1 / num2;
		}

	default:
		printf(" Такая операция не предусмотрена\n");
		return 0;
		break;
	}
}

bool prime_num(int num)
{
	if (num > 1)
	{
		for (int i = 2; i < num; i++)
			if (num % i == 0)
				return false;
		return true;
	}
	else
		return false;
}

int rectangle(int n, int k)
{
	printf(" \n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			if (i == 0 || i == n - 1 || j == 0 || j == k - 1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
		}
		printf(" \n");
	}
	return 0;
}

long double factorial(int num)
{
	if (num < 0)
		return 0;
	if (num == 0)
		return 1;
	else
		return num * factorial(num - 1);
}
