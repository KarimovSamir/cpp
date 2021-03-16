#include <iostream>
#include <time.h>
using namespace std;

template <typename T>
T bubble_sort(T a[], T size);

void main()
{
    setlocale(LC_ALL, "rus");
    const int size = 10;
    int a[size];
    cout << "При помощи пузырьковой сортировки отсортировать массив в порядке убывания." << endl;
    bubble_sort(a, size);
}

template <typename T>
T bubble_sort(T a[], T size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 201 - 100;
        cout << a[i] << " | ";
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int b = a[j];
                a[j] = a[j + 1];
                a[j + 1] = b;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " | ";
    }
    cout << endl;
    return 0;
}