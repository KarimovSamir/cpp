#include <iostream>
#include <time.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int a[10]; // ������ ������, � ������� ����� ����� ������� � �������.
    int m[10]; // ������ ������.
    int n[10]; // ������ ������.
    int i;
    int j;
    int b;
    cout << "���� 2 ������� ����������� N �� M.\n���������� ���������� � ������ ������ ����� ��������� ������� � �������." << endl;
    cout << "��������� ����� ������� �������" << endl;
    for (i = 0; i < 10; i++)
    {
        m[i] = rand() % 11; //��������� ����� �� 10, ��� �������� ��������. 
        cout << m[i] << "; ";
    }
    cout << endl;
    cout << "��������� ����� ������� �������" << endl;
    for (i = 0; i < 10; i++)
    {
        n[i] = rand() % 10; //��������� ����� �� 10, ��� �������� ��������. 
        cout << n[i] << "; ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < 10; i++)
            a[i] = m[i] + n[i];
    }
    cout << "����� ����� ������� � ������� �������" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << "; ";
    }
}