#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void one_dim_to_two_dim_arr(int* one_dim_arr, int** two_dim_arr, int one_dim_arr_size, int two_dim_line_size, int& size)
{
    //если при делении получается не целое число, то int его округляет, поэтому нужен size++, иначе размер будет минус 1
    size = one_dim_arr_size / two_dim_line_size;
    if (one_dim_arr_size % two_dim_line_size > 0)
    {
        size++;
    }

    for (int i = 0; i < size; i++)
    {
        two_dim_arr[i] = new int[two_dim_line_size];
        for (int j = 0; j < two_dim_line_size; j++)
        {
            two_dim_arr[i][j] = 0;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < two_dim_line_size; j++)
        {
            if (i * two_dim_line_size + j == one_dim_arr_size)
            {
                break; //Проверка, чтобы не было мусора. break когда больше нечего записывать
            }
            two_dim_arr[i][j] = one_dim_arr[i * two_dim_line_size + j];
        }  
    }
}

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int one_dim_arr_size, two_dim_line_size, size = 2;
line1:
    cout << "Размер одномерного массива" << endl;
    cin >> one_dim_arr_size;
    if (one_dim_arr_size < 0)
    {
        cout << "Размер массива не может быть отрицательным";
        Sleep(1500);
        system("cls");
        goto line1;
    }
line2:
    cout << "Колличество рядов двумерного массива" << endl;
    cin >> two_dim_line_size;
    if (two_dim_line_size <= 0)
    {
        cout << "Колличество рядов массива не может быть отрицательным или быть равным 0";
        Sleep(1500);
        system("cls");
        goto line2;
    }
    int* one_dim_arr = new int[one_dim_arr_size];

    for (int i = 0; i < one_dim_arr_size; i++)
    {
        one_dim_arr[i] = rand() % 10;
        cout << one_dim_arr[i] << " | ";
    }
    cout << endl << endl;

    int** two_dim_arr = new int* [size];

    one_dim_to_two_dim_arr(one_dim_arr, two_dim_arr, one_dim_arr_size, two_dim_line_size, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < two_dim_line_size; j++)
        {
            cout << two_dim_arr[i][j] << " | ";
        }
        cout << endl;
    }

}