#include <iostream>
#include <time.h>
using namespace std;

//7) �������� ������� ����� ������������ ����� � �������, ������� ������ ������� ������ ��������� �����.
void max(int num[], int size);

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	const int size = 10;
	int a[size];

	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 11;
		cout << a[i] << " ";
	}
	cout << endl;
	max(a, size);
}

void max(int arr[], int size)
{
	int max = -1000;
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	cout << "������������ �������: " << max;

	for (int i = 0; i < size; i++)
	{
		if (max == arr[i])
		{
			cout << endl;
			cout << "������ " << max << " = " << i;
		}
	}
}
