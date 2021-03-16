#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void add_col_in_position(int**& arr, int row, int& col, int position)
{
    int** temp = new int* [row];

    for (int i = 0; i < row; i++)
    {
        temp[i] = new int[col];
    }
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j >= position - 1) 
                temp[i][j] = arr[i][j + 1];
            else
                temp[i][j] = arr[i][j];
        }
    }
    col--;
    delete[] arr;
    arr = temp;
}

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int row, col, position;
line1:
    cout << "¬ведите колличество р€дов массива: ";
    cin >> row;
    if (row < 0)
    {
        cout << " олличество р€дов массива не может быть отрицательным";
        Sleep(1500);
        system("cls");
        goto line1;
    }
line2:
    cout << "¬ведите колличество колонок массива: ";
    cin >> col;
    if (col < 0)
    {
        cout << " олличество колонок массива не может быть отрицательным";
        Sleep(1500);
        system("cls");
        goto line2;
    }
line3:
    cout << "¬ведите позицию дл€ вставки: ";
    cin >> position;
    if (position <= 0 || position > col + 1)
    {
        cout << "ѕозици€ дл€ вставки не может выходить за границы или быть равной 0";
        Sleep(1500);
        system("cls");
        goto line3;
    }

    int** arr = new int* [row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 20;
            cout << arr[i][j] << " | ";
        }
        cout << endl;
    }

    add_col_in_position(arr, row, col, position);

    cout << endl;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " | ";
        }
        cout << endl;
    }
}