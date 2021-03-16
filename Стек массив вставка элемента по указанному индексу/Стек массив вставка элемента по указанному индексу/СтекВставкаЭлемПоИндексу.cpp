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

void add_pos(int*& mas, int& size, int pos, int val) // добавление елемента по индексу
{
	int* New_mas = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		New_mas[i] = mas[i];
	}
	for (int i = size; i > pos; i--)
	{
		New_mas[i] = mas[i - 1];
	}
	New_mas[pos] = val;
	size++;
	delete[] mas;
	mas = New_mas;
}

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int size, pos, num;

	cout << "¬ведите размер массива: ";
	cin >> size;
line1:
	cout << "¬ведите идекс массива в который хотите добавить число: ";
	cin >> pos;
	if (pos > size || pos < 0)
	{
		cout << "»декс массива не может быть больше его размера или меньше 0";
		Sleep(1000);
		system("cls");
		goto line1;
	}
	cout << "¬ведите число: ";
	cin >> num;
	int* arr = new int[size];

	Random(arr, size);
	Show(arr, size);

	add_pos(arr, size, pos, num);
	Show(arr, size);
}