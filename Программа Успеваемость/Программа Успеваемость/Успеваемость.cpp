#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a[10];
    char p;
    cout << "������� ������:" << endl;
    for (int q = 0; q < 10; q++)
    {
        cout << "������ " << q + 1 << ":" << endl;
        cin >> a[q];
    }

    int b; //�����
    int c = 1;
    do
    {
        system("cls");
        cout << "����" << endl;
        cout << "����� ������ (������� 1)" << endl;
        cout << "��������� �������� (������� 2)" << endl;
        cout << "����� �� �������� ���������  (������� 3)" << endl;
        cin >> b;
        cout << endl;

        switch (b)
        {
        case 1:
            for (int i = 0; i < 10; i++)
                cout << a[i] << "; ";
            cout << endl;
            break;
        case 2:
            int number;
            cout << "�������� ����� ������:";
            cin >> number;
            cout << "������ ������: " << a[number - 1] << endl;
            cout << "����� ������: ";
            cin >> a[number - 1];
            break;
        case 3:
            int sum=0;
            double n; // ������� ����

            for (int j = 0; j < 10; j++)
                sum += a[j];
                n = sum / 10;

            if (n == 10.7 || n > 10.7)
                cout << "������� ����� �������� ��������� \n";
            else
                cout << "������� �� ����� �������� ��������� \n";
            break;
        }
        cout << "�� ������ ����������? Y/N" << endl;

        cin >> p;

    } while (p == 'Y' || p == 'y');
    {
    }

}