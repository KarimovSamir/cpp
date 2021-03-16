//#include <iostream>
//#include <string>
//#include <windows.h>
//using namespace std;
//void Delete(int N, int M, int n, int** matrix) //функци удаления столба матрицы
//{
//	cout << endl;
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			if (j != n - 1)
//				cout << matrix[i][j] << '\t';
//		}
//		cout << endl;
//	}
//
//}
//int main()
//{
//	int N, M, d;
//	cout << "Skoko stolbov?: ";
//	cin >> M;
//	cout << "Strok?: ";
//	cin >> N;
//	int** matrix = new int* [M];// инициализация матрицы
//	for (int i = 0; i < M; i++)//
//		matrix[i] = new int[N];//
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//			matrix[i][j] = j * i;
//	}
//	for (int i = 0; i < M; i++)
//	{
//		for (int j = 0; j < N; j++)
//		{
//			cout << matrix[i][j] << '\t';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	cout << "Kakoy stolb udalit?: ";
//	cin >> d;
//	Delete(N, M, d, matrix);
//	for (int i = 0; i < M; i++)//освобождение памяти
//	{
//		delete[] matrix[i];
//	}
//	delete[] matrix;
//}