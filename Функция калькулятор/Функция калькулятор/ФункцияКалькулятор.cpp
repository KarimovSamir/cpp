#include <iostream>
#include <windows.h>
using namespace std;
//�������� ������� ������� ���������� �������, ���� ������������ �������� ������������� � ���� ���� �������������.

//��������� �����
float sum(float a, float b)
{
	float result = a + b;
	return result;
}
//��������� ��������
float super_minus(float a, float b)
{
	float result = a - b;
	return result;
}
//��������� ���������
float multiplication(float a, float b)
{
	float result = a * b;
	return result;
}
//��������� �������
float division(float a, float b)
{
	float result = a / b;
	return result;
}

void main()
{
	setlocale(LC_ALL, "rus");

	float a;
	cout << "������� 1 �����: " << endl;
	cin >> a;

	float b;
	cout << "������� 2 �����" << endl;
	cin >> b;

	line1:
	int t;
	cout << "�������� ����\n1) + \n2) - \n3) * \n4) / " << endl;
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
		cout << "�� 0 ������ ������";
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
		cout << "����� �� 1 �� 4";
		Sleep(1000);
		system("cls");
		goto line1;
	}

}
