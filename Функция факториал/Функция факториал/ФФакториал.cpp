#include <iostream>
#include <windows.h>
using namespace std;

//������� ������� ��������� ��������� ����������� �����.
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
	//��������� long long ����� ��������� ��������� ����� ������ �� 20
	long long a;
	setlocale(LC_ALL, "rus");
	line1:
	system("cls");                                                                  
	cout << "������� �����: ";
	cin >> a;
	if (a < 0)
	{
		cout << "�� ����� ������������� ����� :(";
		Sleep(1000);
		goto line1;
	}
	cout << "��������� �����  " << a << " = " << fact(a) << endl;

}