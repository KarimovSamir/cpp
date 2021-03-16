#include <iostream> 
#include <time.h>
#include <windows.h>
using namespace std;

void Random(int* const arr, int const size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 21;
	}
}

void Show(int* const arr, int const size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " | ";
	}
	cout << endl;
}

void delete_pos(int*& mas, int& size, int pos)
{
	int* New_mas = new int[size - 1];
	for (int j = 0; j < size - 1; j++)
	{
		New_mas[j] = mas[j];
	}
	for (int i = pos; i < size - 1; i++)
	{
		New_mas[i] = mas[i + 1];
	}
	size--;
	delete[] mas;
	mas = New_mas;
}

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int size, pos;

	cout << "¬ведите размер массива: ";
	cin >> size;
	line1:
	cout << "¬ведите идекс массива который хотите удалить: ";
	cin >> pos;
	if (pos>size||pos<0)
	{
		cout << "»декс массива не может быть больше его размера или меньше 0";
		Sleep(1000);
		system("cls");
		goto line1;
	}
	
	int* arr = new int[size];

	Random(arr, size);
	Show(arr, size);
	
	delete_pos(arr, size, pos);
	Show(arr, size);
}