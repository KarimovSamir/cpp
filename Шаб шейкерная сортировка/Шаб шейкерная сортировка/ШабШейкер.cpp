#include <iostream>
#include <time.h>
using namespace std;
//8) Создать шаблонную функцию, шейкер сортировка 
template <typename T>
T shaker(T a[]);
void main()
{
    setlocale(LC_ALL, "rus");
    int a[10];
    shaker(a);
}

template <typename T>
T shaker(T a[])
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        a[i] = rand() % 8 + 1;
        cout << a[i] << " | ";
    }
    cout << endl;

    int k = 9;
    int min = 1;
    int max = 9;
    int x;

    do
    {
        //минимальное 
        for (int j = max; j > 0; j--)
        {
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        }
        min = k + 1;

        //максимальное
        for (int j = 1; j <= max; j++)
        {
            if (a[j - 1] > a[j])
            {
                x = a[j - 1];
                a[j - 1] = a[j];
                a[j] = x;
                k = j;
            }
        }

        max = k - 1;
    } while (min < max);

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " | ";
    }
    return 0;
}