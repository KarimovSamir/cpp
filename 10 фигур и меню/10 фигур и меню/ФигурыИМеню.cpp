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
        cout << "Выберите номер фигуры::\n1.Треугольник справа сверху\n2.Треугольник слева снизу\n3.Пол треугольника сверху\n4.Пол треугольника снизу\n5.Песочные часы\n6.Перевернутые песочные часы\n7.Пол треугольника слева\n8.Пол треугольника справа\n9.Треугольник слева сверху\n10.Треугольник справа снизу" << endl;
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
            cout << "Ошибка. Введите число от 1 до 10" << endl;
        }
        cout << "Вы хотите продолжить? Y/N" << endl;
        cin >> b;

    } while (b == 'Y' || b == 'y');
    {
    }

}