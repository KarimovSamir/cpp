#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");

    int a;
    char b;

    do
    {
        system("cls");
        cout << "�������� ����� ������::\n1.����������� ������ ������\n2.����������� ����� �����\n3.��� ������������ ������\n4.��� ������������ �����\n5.�������� ����\n6.������������ �������� ����\n7.��� ������������ �����\n8.��� ������������ ������\n9.����������� ����� ������\n10.����������� ������ �����" << endl;
        cin >> a;

        if (a == 1)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i > j)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << "*";
                    }
                }
                cout << endl;
            }
        }
        else if (a == 2)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i >= j)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        else if (a == 3)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i <= j && i <= 10 - j)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        else if (a == 4)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i >= j && i >= 10 - j)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        else if (a == 5)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i <= j && i <= 10 - j)
                    {
                        cout << "*";
                    }
                    else if (i >= j && i >= 10 - j)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        else if (a == 6)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i >= j && i <= 10 - j)
                    {
                        cout << "*";
                    }
                    else if (i <= j && i >= 10 - j)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        else if (a == 7)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i >= j && i <= 10 - j)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        else if (a == 8)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i <= j && i >= 10 - j)
                    {
                        cout << "*";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
        else if (a == 9)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i <= j)
                    {
                        cout << "*";
                    }

                }
                cout << endl;
            }
        }
        else if (a == 10)
        {
            for (int i = 0; i <= 10; i++)
            {
                for (int j = 0; j <= 10; j++)
                {
                    if (i <= 10 - j)
                        cout << " ";
                    else
                        cout << "*";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "������. ������� ����� �� 1 �� 10" << endl;
        }
        cout << "�� ������ ����������? Y/N" << endl;
        cin >> b;

    } while (b == 'Y' || b == 'y');
    {
    }

}