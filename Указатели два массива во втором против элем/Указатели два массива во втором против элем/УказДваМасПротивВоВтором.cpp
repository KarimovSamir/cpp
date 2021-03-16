#include <iostream>
#include <time.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));
    const int size = 10;
    int arr1[size];
    int arr2[size];
    int* ptr_arr1 = arr1;
    int* ptr_arr2 = arr2;

    cout << "Первый массив: ";
    for (int i = 0; i < size; i++)
    {
        ptr_arr1[i] = rand() % 11;
        cout << *(ptr_arr1 + i) << " | ";
        *(ptr_arr2 + i) = *(ptr_arr1 + i);
    }

    cout << endl;
    cout << "Второй массив: ";
    for (int i = 0; i < 5; i++)
    {
        *(ptr_arr2 + i) += *(ptr_arr2 + 10 - i - 1);
        *(ptr_arr2 + 10 - i - 1) = *(ptr_arr2 + i) - *(ptr_arr2 + 10 - i - 1);
        *(ptr_arr2 + i) -= *(ptr_arr2 + 10 - i - 1);
    }

    for (int i = 0; i < size; i++)
    {
        cout << *(ptr_arr2 + i) << " | ";
    }

}