#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void main()
{
    system("cls");
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    char x;
    int cycle = 1;
    int ICQ[10];
    int telephone[10];
    int s[20];
    int v;
    int w = 1;
    int r = 1;

    cout << "Введите номера ICQ" << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << w << ") ";
        cin >> ICQ[i];
        w++;
    }

    cout << "\nВаши номера ICQ: ";

    for (int i = 0; i < 10; ++i)
    {
        cout << ICQ[i] << " | ";
    }

    cout << endl;
    cout << "Введите номера телефонов" << endl;

    for (int p = 0; p < 10; p++)
    {
        cout << r << ") ";
        cin >> telephone[p];
        r++;
    }

    cout << "\nВаши номера телефонов: ";

    for (int p = 0; p < 10; ++p)
    {
        cout << telephone[p] << " | ";
    }
    do
    {
        cout << endl;
    line1:
        system("cls");
        cout << "Программа \"Справочник\"" << endl;
        cout << "1) Отсортировать по номерам ICQ" << endl;
        cout << "2) Отсортировать по номерам телефона" << endl;
        cout << "3) Вывести список пользователей" << endl;
        cout << "4) Выход" << endl;
        cin >> v;

        if (v == 1)
        {
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10 - 1 - i; j++)
                {
                    if (ICQ[j] > ICQ[j + 1])
                    {
                        int b = ICQ[j];
                        ICQ[j] = ICQ[j + 1];
                        ICQ[j + 1] = b;
                        int u = telephone[j];
                        telephone[j] = telephone[j + 1];
                        telephone[j + 1] = u;
                    }
                }
            }

            for (int i = 0; i < 10; i++)
            {
                cout << ICQ[i] << "; ";
            }
            cout << endl;
        }

        else if (v == 2)
        {
            for (int p = 0; p < 10; p++)
            {
                for (int j = 0; j < 10 - 1 - p; j++)
                {
                    if (telephone[j] > telephone[j + 1])
                    {
                        int u = telephone[j];
                        telephone[j] = telephone[j + 1];
                        telephone[j + 1] = u;
                        int b = ICQ[j];
                        ICQ[j] = ICQ[j + 1];
                        ICQ[j + 1] = b;
                    }
                }
            }

            for (int p = 0; p < 10; p++)
            {
                cout << telephone[p] << "; ";
            }
            cout << endl;
        }

        else if (v == 3)
        {
            int l = 0;
            for (int i = 0; i < 10; i++)
            {
                l++;
                cout << l << ") " << ICQ[i] << " | " << telephone[i] << endl;

            }
            cout << endl;
        }

        if (v == 1 || v == 2 || v == 3)
        {
            cout << "Вы хотите продолжить? Y/N" << endl;
            cin >> x;

            if (x == 'y' || x == 'Y')
            {
                cycle = 1;
            }
            else
            {
                cycle = 0;
            }
        }

        if (v == 4)
        {
            cout << "Выход";
            cycle = 0;
        }

    } while (cycle);
}