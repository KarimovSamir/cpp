#include <iostream>
#include <time.h>
using namespace std;

void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    const int size = 500;
    int arr[size] = {};
    int arr_copy[size] = {};
    cout << "������� ������ �� 500 ��������� ���������.\n����� ������ ������ �� ���� ��� ������������� ��������, � ��������� ������� ������." << endl;
    cout << endl;
    cout << "��������� �����" << endl;
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 101 - 50;
        cout << arr[i] << " | ";
    }
    cout << endl;
    
    for (int i = 0; i < size; i++)
    {
        int m = 600;
        int n = 0;
        int Z = 0;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < m)
            {
                m = arr[j];
                n = j;
            }
        }
        Z = arr[i];
        arr[i] = arr[n];
        arr[n] = Z;
    }
    cout << endl;
    cout << "��������������� ������" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " | ";
    }
    cout << endl;

    int a = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != arr[i + 1])
        {
            arr_copy[a] = arr[i];
            a++;
        }
    }
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            arr_copy[a] != arr[i];
            a++;
        }
    }
    cout << endl;
    cout << "������ ��������������� ������ � 0 ������ ������" << endl;
    for (int i = 0; i < a; i++)
    {
        cout << arr_copy[i] << " | ";
    }     
}