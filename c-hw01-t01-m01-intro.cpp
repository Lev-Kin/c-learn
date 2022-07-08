/*
// 1. Написать программу, вычисляющую среднее арифметическое двух чисел.

// Подключаем файлы
#include <windows.h>
#include <iostream>
// определение пространства имен,
// в котором есть cout<< и cin>>
using namespace std;
// главная функция
main(void)
{
	//вызов команды ОС очистки экрана
	system("cls");
	//Объявляем переменную OneNum
	double OneNum;
	//Приглашение ввести первую цифру
	cout << "insert the first number\n";
	//ввод значения в переменную OneNum
	cin >> OneNum;
	//Объявляем переменную TwoNum
	double TwoNum;
	//Приглашение ввести вторую цифру
	cout << "insert the second number\n";
	// ввод значения в переменную TwoNum
	cin >> TwoNum;
	//Объявляем переменную MidNum
	double MidNum;
	//вычисляем значение переменной MidNum
	MidNum = ((OneNum + TwoNum) / 2);
	// выводим итоговое среднее число
	cout << "Youre middle number is " << MidNum << "\n";
}

// 2. Написать программу, которая переводит белорусские рубли в доллары США,
//    евро, российские рубли.

// Подключаем файлы
#include <windows.h>
#include <iostream>
// определение пространства имен,
// в котором есть cout<< и cin>>
using namespace std;

// Главная функция
void main(void)
{
	//Вызов команды ОС очистки экрана
	system("cls");
	//Объявляем переменную белорусские рубли
	double BYN;
	//Приглашение ввести белорусские рубли для перевода в доллары США, евро, российские рубли.
	cout << "insert the quantity BYN money for change\n";
	//Ввод значения в переменную BYN
	cin >> BYN;
	//Объявляем переменную USD, EUR, RUB
	double USD = 2.0434;
	double EUR = 2.2636;
	double RUB = 3.2112;
	double USDc;
	double EURc;
	double RUBc;
	//Вычисляем значение переменной USD, EUR, RUB

	USDc = BYN / USD;
	EURc = BYN / EUR;
	RUBc = (BYN*100) / RUB;


	//ИТОГО Обмен составил по USD, EUR, RUB
	cout << "Youre change " << BYN << " BYN ----> " << USDc << " USD""\n";
	cout << "Youre change " << BYN << " BYN ----> " << EURc << " EUR""\n";
	cout << "Youre change " << BYN << " BYN ----> " << RUBc << " RUB""\n";

}


// 3. Вывести на экран следующий текст:
//     ”To be, or not to be!”
//     \Shakespeare\

// Подключаем необходимые файлы
#include <windows.h>
#include <iostream>
// определение пространства имен, в котором есть cout<<
using namespace std;
// Главная функция
void main(void)
{
	//Вызов команды ОС очистки экрана
	system("cls");
	// Выводит пустую строку
	cout << "\n";
	// Выводит пустую строку
	cout << "\n";
	// Выводим фразу в строку
	cout << "\t\"" << "\To be, or not to be!\"\n";

	cout << "\t\\" << "\Shakespeare\\\n";

	// Выводит пустую строку
	cout << "\n";
}

// 4. В языке С++ нет операции возведения в квадрат. Написать программу, которая
//     возводит в квадрат любое введённое число.
// Подключаем файлы
#include <windows.h>
#include <iostream>
// определение пространства имен,
// в котором есть cout<< и cin>>
using namespace std;
// Главная функция
void main(void)
{
	//Вызов команды ОС очистки экрана
	system("cls");
	//Объявляем переменную OneNum
	double OneNum;
	//Приглашение ввести первую цифру
	cout << "entered number will be squared\n";
	//Ввод значения в переменную OneNum
	cin >> OneNum;

	//Объявляем переменную SquNum
	float SquNum;
	//Вычисляем значение переменной SquNum
	SquNum = OneNum * OneNum;
	// Выводим итоговое среднее число
	cout << "Squared is " << OneNum << " = " << SquNum << "\n";
}
*/

// 5. Написать программу, которая вводит в память машины три числа и выводит на
//     экран сумму этих чисел и их произведение.
// Подключаем файлы
#include <windows.h>
#include <iostream>
// определение пространства имен,
// в котором есть cout<< и cin>>
using namespace std;
// Главная функция
void main(void)
{
	//Вызов команды ОС очистки экрана
	system("cls");
	//Объявляем переменную OneNum
	double OneNum;
	//Приглашение ввести первую цифру
	cout << "insert the first number\n";
	//Ввод значения в переменную OneNum
	cin >> OneNum;
	//Объявляем переменную TwoNum
	double TwoNum;
	//Приглашение ввести вторую цифру
	cout << "insert the second number\n";
	// Ввод значения в переменную TwoNum
	cin >> TwoNum;
	//Объявляем переменную ThreeNum;
	double ThreeNum;
	//Приглашение ввести третью цифру
	cout << "insert the third number\n";
	// Ввод значения в переменную ThreeNum
	cin >> ThreeNum;
	//Объявляем переменную SumNum
	double SumNum;
	//Вычисляем значение переменной MidNum
	SumNum = OneNum + TwoNum + ThreeNum;
	// Выводим итоговое cумарное число трех чисел
	cout << "Youre summa of numbers is " << SumNum << "\n";
	double MulNum;
	//Вычисляем значение переменной MidNum
	MulNum = OneNum * TwoNum * ThreeNum;
	// Выводим итоговое произведение трех чисел
	cout << "Youre multiplication of numbers is " << MulNum << "\n";
}
