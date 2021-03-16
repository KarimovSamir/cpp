#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

//13. Напишите функцию для обращения двумерного массива в одномерный массив.
void two_dim_to_one_dim_arr(int** two_dim_arr, int row, int col, int* one_dim_arr) 
{
    int counter = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            one_dim_arr[counter] = two_dim_arr[i][j];
            counter++;
        }
    }
}

void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int row, col;
line1:
    cout << "Введите колличество рядов массива: ";
    cin >> row;
    if (row <= 0)
    {
        cout << "Колличество рядов массива не может быть меньше 1";
        Sleep(1500);
        system("cls");
        goto line1;
    }
line2:
    cout << "Введите колличество колонок массива: ";
    cin >> col;
    if (col <= 0)
    {
        cout << "Колличество колонок массива не может быть меньше 1";
        Sleep(1500);
        system("cls");
        goto line2;
    }

    int** two_dim_arr = new int* [row];
    for (int i = 0; i < row; i++)
    {
        two_dim_arr[i] = new int[col];
    }

    int size = row * col;
    int* one_dim_arr = new int[size];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            two_dim_arr[i][j] = rand() % 100;
            cout << two_dim_arr[i][j] << " | "; 
        }
        cout << endl;
    }
    cout << endl;

    two_dim_to_one_dim_arr(two_dim_arr, row, col, one_dim_arr);

    for (int i = 0; i < size; i++)
    {
        cout << one_dim_arr[i] << " | ";
    }
    
    delete[] one_dim_arr;

    for (int i = 0; i < row; i++)
    {
        delete[]two_dim_arr[i];
    }
    delete[]two_dim_arr;
}