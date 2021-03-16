#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    const int size = 10;
    int a[size] = {};
    int* ptr_a = a;
    int choose;
    int* ptr_choose = &choose;
    int shift;
    int* ptr_shift = &shift;
    int shift_full;
    int* ptr_shift_full = &shift_full;

    for (int i = 0; i < size; i++)
    {
        *(ptr_a + i) = rand() % 11;
        cout << *(ptr_a + i) << " | ";
    }
    cout << endl;

line2:
    cout << "На сколько сдвинется?" << endl;
    cin >> *ptr_shift;
    if (*ptr_shift < 0)
    {
        cout << "Введите положительное число";
        Sleep(1000);
        system("cls");
        goto line2;
    }

line1:
    cout << "Введите куда двинется\n1)Влево\n2)Вправо" << endl;
    cin >> choose;

    if (*ptr_choose == 1)
    {
        for (int i = 0; i < *ptr_shift; i++)
        {
            for (int i = 0; i < size - 1; i++)
            {
                *ptr_shift_full = *(ptr_a + i);
                *(ptr_a + i) = *(ptr_a + i + 1);
                *(ptr_a + i + 1) = *ptr_shift_full;
            }
        }
    }

    else if (*ptr_choose == 2)
    {
        for (int i = 0; i < *ptr_shift; i++)
        {
            for (int i = size - 1; i > 0; i--)
            {
                *ptr_shift_full = *(ptr_a + i);
                *(ptr_a + i) = *(ptr_a + i - 1);
                *(ptr_a + i - 1) = *ptr_shift_full;
            }
        }
    }

    else
    {
        cout << "Введите либо 1, либо 2";
        Sleep(1000);
        system("cls");
        goto line1;
    }

    for (int i = 0; i < size; i++)
    {
        cout << *(ptr_a + i) << " | ";
    }
}