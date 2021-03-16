//#include <iostream>
//#include <windows.h>
//#include <time.h>
//using namespace std;
//
//void add_col_start(int**& arr, int row, int col)
//{
//    col++;
//    int** temp = new int* [row + 1];
//    for (int i = 0; i < row; i++)
//    {
//        temp[i] = new int[col];
//    }
//    int count = 0;
//    bool test = false;
//
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            if (i == count)
//            {
//                temp[i][j] = rand() % 20;
//                count++;
//                test = true;
//            }
//            else if (test)
//            {
//                temp[i][j] = arr[i][j - 1];
//            }
//            
//        }
//    }
//
//    delete[] arr;
//    arr = temp;
//}
//
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    srand(time(NULL));
//
//line1:
//    int row, col;
//    cout << "¬ведите колличество р€дов массива: ";
//    cin >> row;
//    if (row < 0)
//    {
//        cout << " олличество р€дов массива не может быть отрицательным";
//        Sleep(1500);
//        system("cls");
//        goto line1;
//    }
//line2:
//    cout << "¬ведите колличество колонок массива: ";
//    cin >> col;
//    if (col < 0)
//    {
//        cout << " олличество колонок массива не может быть отрицательным";
//        Sleep(1500);
//        system("cls");
//        goto line2;
//    }
//
//    int** arr = new int* [row];
//
//    for (int i = 0; i < row; i++)
//    {
//        arr[i] = new int[col];
//        for (int j = 0; j < col; j++)
//        {
//            arr[i][j] = rand() % 20;
//            cout << arr[i][j] << " | ";
//        }
//        cout << endl;
//    }
//
//    add_col_start(arr, row, col);
//    col++;
//
//    cout << endl;
//
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            cout << arr[i][j] << " | ";
//        }
//        cout << endl;
//    }
//}