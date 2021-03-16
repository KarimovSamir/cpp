#include <windows.h>
#include <iostream>
#include "Money.h"
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Money m1;
	cout << "������� ������: ";
	cin >> m1.manat;
	cout << "������� �����: ";
	cin >> m1.qepiy;

	cout << endl;

	Money m2;
	cout << "������� ������: ";
	cin >> m2.manat;
	cout << "������� �����: ";
	cin >> m2.qepiy;

	///////////////////////////////////////////////////////////

	Money sum = plus_sum(m1, m2);
	cout << "����� �����: ";
	print_money(sum);
	
	///////////////////////////////////////////////////////////

	Money subtract = minus_sum(m1, m2);
	cout << "����� �� ������ ����� ������: ";
	print_money(subtract);
	

	///////////////////////////////////////////////////////////	

	if (money_cmp(m1, m2) == 1)
	{
		cout << "������ ����� ������ ������" << endl;
	}
	if (money_cmp(m1, m2) == -1)
	{
		cout << "������ ����� ������ ������" << endl;
	}
	if (money_cmp(m1, m2) == 0)
	{
		cout << "��� ����� �����" << endl;
	}
	system("pause");
	system("cls");

	///////////////////////////////////////////////////////////

	cout << "������� ������: ";
	cin >> m1.manat;
	cout << "������� �����: ";
	cin >> m1.qepiy;
	cout << "������� �����������: ";
	int multi;
	cin >> multi;
	Money multiplication = multiply(m1, multi);
	cout << "����� ���������� �� �����������: ";
	print_money(multiplication);
	system("pause");
	system("cls");

	///////////////////////////////////////////////////////////

	cout << "������� ������: ";
	cin >> m1.manat;
	cout << "������� �����: ";
	cin >> m1.qepiy;
	int div;
line1:
	cout << "������� �����������: ";
	cin >> div;
	if (div == 0)
	{
		cout << "�� ���� ������ ������";
		Sleep(1000);
		system("cls");
		goto line1;
	}
	Money split = divide(m1, div);
	cout << "����� ���������� �� �����������: ";
	print_money(split);
	system("pause");
	system("cls");

	///////////////////////////////////////////////////////////

	cout << "������� ������: ";
	cin >> m1.manat;
	cout << "������� �����: ";
	cin >> m1.qepiy;
	cout << "������ � ������: ";
	cout << money_to_qepiy(m1) << endl;
	system("pause");
	system("cls");

	///////////////////////////////////////////////////////////

	int qepiyi;
	cout << "������� �����: ";
	cin >> qepiyi;

	Money qep_to_mon = qepiy_to_money(qepiyi);
	cout << "����� � ������ � �����: ";
	print_money(qep_to_mon);
}