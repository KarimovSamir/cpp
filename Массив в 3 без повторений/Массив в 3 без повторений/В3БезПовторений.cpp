#include <iostream>
#include <time.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int i;
    int j;
    int k;
    int a[10];
    int b[10];
    int c[20]{};
    int d = 0; // ����������� �����
    int e = 0;
    int f = 0;

    cout << "���� 2 ������� ����������� N �� M.\n���������� ���������� � ������ ������ �� �������� ������� ������� ������� ��� �� ������ ��� ����������." << endl;
    cout << "������ ������:" << endl;
    for (i = 0; i < 10; i++)
    {
        a[i] = rand() % 11; //��������� ����� �� 0 �� 10, ��� �������� ��������
        cout << a[i] << " ";
    }
    cout << endl << "������ ������:" << endl;
    for (i = 0; i < 10; i++)
    {
        b[i] = rand() % 11;
        cout << b[i] << " ";
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (b[j] == a[i])
            {
                d++;
            }
        }
        if (d == 0)
        {
            for (k = 0; k < 20; k++)
            {
                if (c[k] == a[i])
                    f++;
            }
            if (f == 0)
            {
                c[e] = a[i];
                e++;
            }
        }
        d = 0;
    }
    cout << endl << "������ ������:" << endl;
    for (i = 0; i < 20; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
}