#include <iostream>
#include <time.h>
using namespace std;

int cycle(int a[], int x);

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	const int size = 10;
	int arr[size] = {};

	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
	}
	cout << "Сумма элементов: " << cycle(arr, size) << endl;	
}

int cycle(int a[], int x)
{
	--x;
	if (x == -1)
		return 0;
	cout << "1. arr[" << x << "] = " << a[x] << endl;
	return a[x] + cycle(a, x);
}