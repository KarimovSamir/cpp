#include <iostream>
#include <windows.h>
using namespace std;

int fact(int num);

void main()
{
line1:
	setlocale(LC_ALL, "rus");
	int num;
	cout << "������� �����: ";
	cin >> num;
	if (num < 0)
	{
		cout << "������� ������������� �����";
		Sleep(1000);
		system("cls");
		goto line1;
	}
	cout << "����� �� 0 �� ���������� �����: ";
	cout << fact(num) << endl;
}

int fact(int num)
{
	if (num == 0)
		return 0;
	int res = fact(num - 1);
	return res + num;
}