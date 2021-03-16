#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    int a[10];
    int b;
    int max;
    int maxA;
    int count = 1;
    int countnew = 1;

    cout << "Случайные числа массива" << endl;

    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 101;
        cout << count << ") " << a[i] << endl;
        count++;
    }

    for (int i = 10 - 1; i >= 0; i--)
    {
        max = a[i];
        maxA = i;
        //ищем максимальное число
        for (int j = i; j >= 0; j--)
        {
            if (a[j] > max)
            {
                max = a[j];
                maxA = j;
            }
        }
        //переворачиваем массив, чтобы максимальное число было сверху
        for (int j = 0; j <= maxA / 2; j++)
        {
            if (maxA == 0)
            {
                break;
            }
            b = a[j];
            a[j] = a[maxA - j];
            a[maxA - j] = b;
        }
        //переворачиваем массив, чтобы максимальное число было снизу
        for (int j = 0; j <= i / 2; j++)
        {
            b = a[j];
            a[j] = a[i - j];
            a[i - j] = b;
        }
    }
    cout << endl;
    cout << "Отсортированный массив методом оладий" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << countnew << ") " << a[i] << endl;
        countnew++;
    }
}