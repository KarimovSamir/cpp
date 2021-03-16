#include <windows.h>
#include <iostream>
#include "Time.h"
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int hour, minutes, seconds;
	Time t = now(4);
	print(t);

	cout << "Время в секундах: "<< time_to_seconds(t);
	cout << endl;
line1:	
	cout << "Введите часы: ";
	cin >> hour;
	if (hour < 0)
	{
		cout << "Нельзя вводить отрицательное число";
		Sleep(1000);
		system("cls");
		goto line1;
	}
	cout << endl;
	Time plus_hour = add_hours(t, hour);
	print(plus_hour);
line2:
	cout << "Введите минуты: ";
	cin >> minutes;
	if (minutes < 0)
	{
		cout << "Нельзя вводить отрицательное число";
		Sleep(1000);
		system("cls");
		goto line2;
	}
	cout << endl;
	Time plus_minute = add_minutes(plus_hour, minutes);
	print(plus_minute);
line3:
	cout << "Введите секунды: ";
	cin >> seconds;
	if (seconds < 0)
	{
		cout << "Нельзя вводить отрицательное число";
		Sleep(1000);
		system("cls");
		goto line3;
	}
	cout << endl;
	Time plus_seconds = add_seconds(plus_minute, seconds);
	print(plus_seconds);

////////////////////////////////////////////////////////////////

	cout << endl;
	cout << "Введите время для сравнения с нынешним временем" << endl;
	Time t1;
line4:
	cout << "Введите часы: ";
	cin >> t1.hours;
	if (t1.hours < 0)
	{
		cout << "Нельзя вводить отрицательное число";
		Sleep(1000);
		system("cls");
		goto line4;
	}

line5:	
	cout << "Введите минуты: ";
	cin >> t1.minutes;
	if (t1.minutes < 0)
	{
		cout << "Нельзя вводить отрицательное число";
		Sleep(1000);
		system("cls");
		goto line5;
	}

line6:
	cout << "Введите секунды: ";
	cin >> t1.seconds;
	if (t1.seconds < 0)
	{
		cout << "Нельзя вводить отрицательное число";
		Sleep(1000);
		system("cls");
		goto line6;
	}
	cout << endl;

	if (time_cmp(t, t1) == 1)
	{
		cout << "Нынешнее время больше времени введённое пользователем " << endl;
		cout << "Нынешнее время в секундах: " << time_to_seconds(t);
		cout << endl;
		cout << "Ввёдённое время в секундах: " << time_to_seconds(t1);
	}
	if (time_cmp(t, t1) == -1)
	{
		cout << "Нынешнее время меньше времени введённое пользователем " << endl;
		cout << "Нынешнее время в секундах: " << time_to_seconds(t);
		cout << endl;
		cout << "Ввёдённое время в секундах: " << time_to_seconds(t1);
	}
	if (time_cmp(t, t1) == 0)
	{
		cout << "Нынешнее время равно времени введённое пользователем " << endl;
		cout << "Нынешнее время в секундах: " << time_to_seconds(t);
		cout << endl;
		cout << "Ввёдённое время в секундах: " << time_to_seconds(t1);
	}
}