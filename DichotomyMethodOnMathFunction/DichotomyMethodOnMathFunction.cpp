#define _USE_MATH_DEFINES 
#include <iostream>
#include <math.h> 
#include <string>
#include <algorithm>
#include <conio.h>
#include <cstdlib>

using namespace std;
struct Data
{
	string Lfront;
	string Rfront;
	string E;
	string TempNumberFunc;
};

void ErrorProcess(const bool priznakif, const string errormessage)
{
	if (priznakif)
		throw errormessage;
}

void InputValue(string& outValue, const string& LastMenu, const string& limitInput)
{
	system("cls");
	cout << LastMenu << ": ";
	cin >> outValue;
	cin.clear();
	cin.ignore(32767, '\n');
	if (outValue.find_first_not_of(limitInput) != -1 ||
		(count(outValue.begin(), outValue.end(), '.') > 1 || count(outValue.begin(), outValue.end(), '-') > 1) ||
		(outValue[0] == '.' || outValue[outValue.length()] == '.') ||
		(outValue[0] == '-' || outValue[outValue.length()] == '-'))
	{
		cout << "Ошибка: Неккоректный ввод";
		outValue = "Не задано";
		system("pause");
	}
}

double InputFile_1(double x)
{
	return
#include "Formelvu1.txt"
		;
}

double f1(double x)
{
	double exp = M_E;
	double pi = M_PI;
	double y = (pi / 2) * pow(abs((1.3333334) * x * sin(x) - pow(pow(exp, x) + 0.2, 0.3333334) + 0.35), 0.5) - 2 * pow(x, 2);
	return y;
}


double f2(double x)
{
	double exp = M_E;
	double pi = M_PI;
	double y = y = (pi * pow(x * 0.2, 0.333334)) + ((log(0.3 + pow(abs(sin(x)), (0.5)))) / pow(exp, (1 - x))) - 1.5;
	return y;
}

int MainMenuPoint_1(Data& TempValue)
{
	int NumberSideMain = 0;
	while (true)
	{
		system("cls");
		cout << "Для ввода функции по умолчанию нажмите 1" << endl;
		cout << "Для ввода функции из файла нажмите 2" << endl;
		cout << "Для возврата в главное меню введите любую цифру или число, кроме 1 и 2" << endl;
		cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Ввод: ";
		cin >> NumberSideMain;
		switch (NumberSideMain)
		{
		case 1:
			InputValue(TempValue.TempNumberFunc, "Введите соответсвующий номер функции:\nФункция №1: pi/2*((|(4/3)*xsinx-корень из(e^x+0.2)+0.35|))^1/2-2x^2\nФункция №1: pi*(x/4)*3+(ln(0.3+|sinx|^1/2))/(e^(1-x))-3/2\nВведите соответсвующий номер функии: ", "12");
			break;
		case 2:
			//не реализовано
			break;
		default:
			if (TempValue.TempNumberFunc == "1")
				TempValue.TempNumberFunc = "pi/2*((|(4/3)*xsinx-корень из(e^x+0.2)+0.35|))^1/2-2x^2";
			else
				TempValue.TempNumberFunc = "pi*(x/4)*3+(ln(0.3+|sinx|^1/2))/(e^(1-x))-3/2";
			return 0;
		}
	}
}

int MainMenuPoint_2(Data& TempValue)
{
	int NumberSideMain = 0;
	while (true)
	{
		system("cls");
		cout << "Для ввода левой и правой границ интервала F(x) нажмите 1\n";
		cout << "Для ввода точности нажмите 2\n";
		cout << "Для возврата в главное меню нажмите любую цифру или число, кроме 1 и 2\n";
		cout << "---------------------------------------------------------------------------------------------------------------------\n";
		cout << "Ввод: ";
		cin >> NumberSideMain;
		if (NumberSideMain < 1 || NumberSideMain>2)
			return 0;
		switch (NumberSideMain)
		{
		case 1:
			InputValue(TempValue.Lfront, "Введите левую границу интервала F(x)", "01234567890.-");
			InputValue(TempValue.Rfront, "Введите правую границу интервала F(x)", "01234567890.-");
			break;
		case 2:
			InputValue(TempValue.E, "Введите точность на интервале от 0 до 0.1", "01234567890.");
			break;
		}
	}
}

double FindRoot(double(*f)(double), double Lfront, double Rfront, double exc)
{
	double TempRoot;
	while (fabs(Rfront - Lfront) > exc)
	{
		TempRoot = (Lfront + Rfront) / 2;
		if (f(Lfront) * f(TempRoot) > 0)
			Lfront = TempRoot;
		else
			Rfront = TempRoot;
	}
	TempRoot = (Lfront + Rfront) / 2;
	return TempRoot;
}

int main()
{
	setlocale(LC_CTYPE, "ru");
	int MainNumber;
	Data DataManager;
	DataManager.Lfront = "не задано";
	DataManager.Rfront = "не задано";
	DataManager.E = "не задано";
	DataManager.TempNumberFunc = "не задано";
	double(*TempFunc[2])(double) = { f1, f2 };
	std::size_t offset = 0;
	int(*TempMenu[2])(Data&) = { MainMenuPoint_1, MainMenuPoint_2 };
	while (true)
	{
		system("cls");
		cout << "Текущие состояние системы:" << endl;
		cout << "Текущая функция: " << DataManager.TempNumberFunc << endl;
		cout << "Текущая левая граница интервала: " << DataManager.Lfront << endl;
		cout << "Текущая правая граница интервала: " << DataManager.Rfront << endl;
		cout << "Текущая точность: " << DataManager.E << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Меню:" << endl;
		cout << "Для ввода функции, а именно фунции из списка по умолчанию или из файла нажмите 1" << endl;
		cout << "Для задания параметров системы, а именно левой, правой границ интервала и точности корня - введите 2" << endl;  //Доделать
		cout << "Для нахождения корня заданной функции - введите 3" << endl;
		cout << "Для выхода из программы - введите любомй символ кроме 1,2,3" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Введите соответствующий пункт меню: ";
		cin >> MainNumber;
		try
		{
			if (MainNumber >= 1 && MainNumber <= 2)
				(*TempMenu[MainNumber - 1])(DataManager);
			else if (MainNumber == 3)
			{
				if (DataManager.TempNumberFunc == "pi/2*((|(4/3)*xsinx-корень из(e^x+0.2)+0.35|))^1/2-2x^2")
					DataManager.TempNumberFunc = "1";
				else if (DataManager.TempNumberFunc == "pi*(x/4)*3+(ln(0.3+|sinx|^1/2))/(e^(1-x))-3/2")
					DataManager.TempNumberFunc = "2";
				double InputRoot;
				ErrorProcess(DataManager.TempNumberFunc == "не задано" || stoi(&DataManager.TempNumberFunc[0], &offset) < 1 || stoi(&DataManager.TempNumberFunc[0], &offset) > 3, "Функция не задана ни одним из доступных способов");
				ErrorProcess(DataManager.Lfront == "не задано" || DataManager.Rfront == "не задано" || (stod(&DataManager.Lfront[0], &offset) > stod(&DataManager.Rfront[0], &offset)), "Ошибка: Параметры системы не заданы.");
				ErrorProcess(DataManager.TempNumberFunc == "не задано" || TempFunc[stoi(&DataManager.TempNumberFunc[0], &offset) - 1](stod(&DataManager.Lfront[0], &offset)) * TempFunc[stoi(&DataManager.TempNumberFunc[0], &offset) - 1](stod(&DataManager.Rfront[0], &offset)) > 0, "Ошибка: На заданном интервале нет корня либо он не один");
				ErrorProcess(stod(&DataManager.E[0], &offset) <= 0 || stod(&DataManager.E[0], &offset) > 0.1, "Ошибка: Неккоректно Введенная точность. Введетие точность на диазононе от 0 до 0.1 не включительно");
				InputRoot = FindRoot(TempFunc[stoi(&DataManager.TempNumberFunc[0], &offset) - 1], stod(&DataManager.Lfront[0], &offset), stod(&DataManager.Rfront[0], &offset), stod(&DataManager.E[0], &offset));
				cout << "Корень заданной функции равен: " << InputRoot << endl;
				cout << "Значение F(x) при найденном корне x: " << TempFunc[stoi(&DataManager.TempNumberFunc[0], &offset) - 1](InputRoot) << endl;
				if (DataManager.TempNumberFunc == "1")
					DataManager.TempNumberFunc = "pi/2*((|(4/3)*xsinx-корень из(e^x+0.2)+0.35|))^1/2-2x^2";
				else if (DataManager.TempNumberFunc == "2")
					DataManager.TempNumberFunc = "pi*(x/4)*3+(ln(0.3+|sinx|^1/2))/(e^(1-x))-3/2";
				_getch();
			}
			else
				return 0;
		}
		catch (string exception)
		{
			cerr << "Error: " << exception << endl;
			system("pause");
		}
	}
}
