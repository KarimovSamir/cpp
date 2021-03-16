#include <iostream>
#include <time.h>
using namespace std;

void cycle(int a[], int x)
{
	--x;
	if (x == -1)  
		return; 
	cout << "1. arr[" << x << "] = " << a[x] << endl;
	cycle(a, x);
	cout << "2. arr[" << x << "] = " << a[x] << endl;
}

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
	cycle(arr, size);
}