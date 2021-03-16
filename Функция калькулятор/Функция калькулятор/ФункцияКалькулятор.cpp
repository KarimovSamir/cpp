#include <iostream>
#include <windows.h>
using namespace std;
//Написать функцию которая возвращает истинну, если передаваемое значение положительное и ложь если отрицательное.

//Вычисляет сумму
float sum(float a, float b)
{
	float result = a + b;
	return result;
}
//Вычисляет разность
float super_minus(float a, float b)
{
	float result = a - b;
	return result;
}
//Вычисляет умножение
float multiplication(float a, float b)
{
	float result = a * b;
	return result;
}
//Вычисляет деление
float division(float a, float b)
{
	float result = a / b;
	return result;
}

void main()
{
	setlocale(LC_ALL, "rus");

	float a;
	cout << "Введите 1 число: " << endl;
	cin >> a;

	float b;
	cout << "Введите 2 число" << endl;
	cin >> b;

	line1:
	int t;
	cout << "Выберите знак\n1) + \n2) - \n3) * \n4) / " << endl;
	cin >> t;
	cout << endl;
	if (t == 1)
	{
		cout << sum(a, b);
	}
	else if (t == 2)
	{
		cout << super_minus(a, b);
	}
	else if (t == 3)
	{
		cout << multiplication(a, b);
	}
	else if (t == 4 and b == 0)
	{
		cout << "На 0 делить нельзя";
		Sleep(1000);
		system("cls");
		goto line1;
	}
	else if (t == 4)
	{
		cout << division(a, b);
	}
	else
	{
		cout << "Вводи от 1 до 4";
		Sleep(1000);
		system("cls");
		goto line1;
	}

}
