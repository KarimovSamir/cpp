#include <iostream>
#include <windows.h>
using namespace std;

//Функция которая вычесляет факториал переданного числа.
long long fact(long long a)  
{
	long long fact = 1;
	for (int i = 2; i < a+1; i++)
	{
		fact = fact * i;
		
	}
	return fact;
}

void main()
{
	//Благодаря long long можно проверить факториал числа вплоть до 20
	long long a;
	setlocale(LC_ALL, "rus");
	line1:
	system("cls");                                                                  
	cout << "Введите число: ";
	cin >> a;
	if (a < 0)
	{
		cout << "Не вводи отрицательное число :(";
		Sleep(1000);
		goto line1;
	}
	cout << "Факториал числа  " << a << " = " << fact(a) << endl;

}