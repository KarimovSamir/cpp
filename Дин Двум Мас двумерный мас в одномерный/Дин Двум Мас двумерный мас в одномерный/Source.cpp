//#include <iostream>
//#include <time.h>
//using namespace std;
//
//void two_dim_to_one_dim_arr(int** arr, int rows, int cols, int*& arr2, int& size2)
//{
//
//
//
//}
//
//void main()
//{
//    srand(time(NULL));
//    setlocale(LC_ALL, "rus");
//    int row, col;
//    cout << "������� ���������� ����� �������: ";
//    cin >> row;
//    cout << "������� ���������� �������� �������: ";
//    cin >> col;
//
//    int** two_dim_arr = new int* [row];
//    for (int i = 0; i < row; i++)
//    {
//        two_dim_arr[i] = new int[col];
//    }
//
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            two_dim_arr[i][j] = rand() % 100;
//            cout << two_dim_arr[i][j] << " | ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//
//    int* one_dim_arr = new int[row * col]; // �������� ����������� ������������� ������� 
//    int counter = 0; // ����������-������ ��� ����������� �������
//
//    for (int i = 0; i < row; i++)
//    {
//        for (int j = 0; j < col; j++)
//        {
//            one_dim_arr[counter] = two_dim_arr[i][j]; // ���������� �������� ������� � ���������� ������
//            cout << one_dim_arr[counter] << " | "; // ������ ��������� ����������� �������
//            counter++; // ��������� �������
//        }
//    }
//
//    delete[] one_dim_arr; // ������������� ������, ��������� ��� ���������� ������
//
//    // �������� ���������� ������������� �������
//    for (int count = 0; count < row; count++)
//        delete[]two_dim_arr[count];
//    cout << endl;
//
//
//
//}