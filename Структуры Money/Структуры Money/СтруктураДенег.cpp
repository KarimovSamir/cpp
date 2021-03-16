#include <windows.h>
#include <iostream>
#include "Money.h"
using namespace std;

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Money m1;
	cout << "¬ведите манаты: ";
	cin >> m1.manat;
	cout << "¬ведите г€пии: ";
	cin >> m1.qepiy;

	cout << endl;

	Money m2;
	cout << "¬ведите манаты: ";
	cin >> m2.manat;
	cout << "¬ведите г€пии: ";
	cin >> m2.qepiy;

	///////////////////////////////////////////////////////////

	Money sum = plus_sum(m1, m2);
	cout << "—умма денег: ";
	print_money(sum);
	
	///////////////////////////////////////////////////////////

	Money subtract = minus_sum(m1, m2);
	cout << "¬ычет от второй суммы первую: ";
	print_money(subtract);
	

	///////////////////////////////////////////////////////////	

	if (money_cmp(m1, m2) == 1)
	{
		cout << "ѕерва€ сумма больше второй" << endl;
	}
	if (money_cmp(m1, m2) == -1)
	{
		cout << "¬тора€ сумма больше первой" << endl;
	}
	if (money_cmp(m1, m2) == 0)
	{
		cout << "ќбе суммы равны" << endl;
	}
	system("pause");
	system("cls");

	///////////////////////////////////////////////////////////

	cout << "¬ведите манаты: ";
	cin >> m1.manat;
	cout << "¬ведите г€пии: ";
	cin >> m1.qepiy;
	cout << "¬ведите коэффициент: ";
	int multi;
	cin >> multi;
	Money multiplication = multiply(m1, multi);
	cout << "—умма умноженна€ на коэффициент: ";
	print_money(multiplication);
	system("pause");
	system("cls");

	///////////////////////////////////////////////////////////

	cout << "¬ведите манаты: ";
	cin >> m1.manat;
	cout << "¬ведите г€пии: ";
	cin >> m1.qepiy;
	int div;
line1:
	cout << "¬ведите коэффициент: ";
	cin >> div;
	if (div == 0)
	{
		cout << "Ќа ноль делить нельз€";
		Sleep(1000);
		system("cls");
		goto line1;
	}
	Money split = divide(m1, div);
	cout << "—умма разделЄнна€ на коэффициент: ";
	print_money(split);
	system("pause");
	system("cls");

	///////////////////////////////////////////////////////////

	cout << "¬ведите манаты: ";
	cin >> m1.manat;
	cout << "¬ведите г€пии: ";
	cin >> m1.qepiy;
	cout << "ƒеньги в г€пи€х: ";
	cout << money_to_qepiy(m1) << endl;
	system("pause");
	system("cls");

	///////////////////////////////////////////////////////////

	int qepiyi;
	cout << "¬ведите г€пии: ";
	cin >> qepiyi;

	Money qep_to_mon = qepiy_to_money(qepiyi);
	cout << "√€пии в манаты и г€пии: ";
	print_money(qep_to_mon);
}