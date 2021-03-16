#include <iostream>
#include <time.h>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int a[10]; // Третий массив, в котором будет сумма первого и второго.
    int m[10]; // Первый массив.
    int n[10]; // Второй массив.
    int i;
    int j;
    int b;
    cout << "Даны 2 массива размерности N на M.\nНеобходимо переписать в третий массив сумму элементов первого и второго." << endl;
    cout << "Случайные числа первого массива" << endl;
    for (i = 0; i < 10; i++)
    {
        m[i] = rand() % 11; //Случайные числа до 10, для удобства проверки. 
        cout << m[i] << "; ";
    }
    cout << endl;
    cout << "Случайные числа второго массива" << endl;
    for (i = 0; i < 10; i++)
    {
        n[i] = rand() % 10; //Случайные числа до 10, для удобства проверки. 
        cout << n[i] << "; ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        for (int i = 0; i < 10; i++)
            a[i] = m[i] + n[i];
    }
    cout << "Сумма чисел первого и второго массива" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << "; ";
    }
}