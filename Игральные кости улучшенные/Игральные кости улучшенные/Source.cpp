//#include <iostream>
//#include <time.h>
//#include <conio.h>
//using namespace std;
//
//int cube_1()
//{
//	while (true)
//	{
//	line1:
//		int code = _getch(); // пользователь нажимает клавишу
//		if (code == 32)
//		{
//			for (int i = 1; i <= 7; i++) // Кость 1
//			{
//				for (int j = 1; j <= 14; j++)
//				{
//					if (i == 1 || i == 7)
//						cout << "*";
//					else if (j == 1 || j == 14)
//						cout << "*";
//					else if (i == 4 && j == 7 || i == 4 && j == 8)
//						cout << "*";
//					else
//						cout << " ";
//				}
//				cout << endl;
//			}
//			return 1;
//		}
//		else
//			goto line1;
//
//	}
//}
//
//int cube_2()
//{
//line2:
//	int code = _getch(); // пользователь нажимает клавишу
//
//	if (code == 32)
//	{
//		for (int i = 1; i <= 7; i++) // Кость 2
//		{
//			for (int j = 1; j <= 14; j++)
//			{
//				if (i == 1 || i == 7)
//					cout << "*";
//				else if (j == 1 || j == 14)
//					cout << "*";
//				else if (i == 3 && j == 4 || i == 5 && j == 10)
//					cout << "*";
//				else if (i == 3 && j == 5 || i == 5 && j == 11)
//					cout << "*";
//				else
//					cout << " ";
//			}
//			cout << endl;
//		}
//		return 2;
//	}
//	else
//		goto line2;
//
//}
//
//int cube_3()
//{
//line3:
//	int code = _getch(); // пользователь нажимает клавишу
//
//	if (code == 32)
//	{
//		for (int i = 1; i <= 7; i++) // Кость 3
//		{
//			for (int j = 1; j <= 14; j++)
//			{
//				if (i == 1 || i == 7)
//					cout << "*";
//				else if (j == 1 || j == 14)
//					cout << "*";
//				else if (i == 3 && j == 4 || i == 5 && j == 10)
//					cout << "*";
//				else if (i == 4 && j == 7 || i == 4 && j == 8)
//					cout << "*";
//				else if (i == 3 && j == 5 || i == 5 && j == 11)
//					cout << "*";
//				else
//					cout << " ";
//			}
//			cout << endl;
//		}
//		return 3;
//	}
//	else
//		goto line3;
//
//}
//
//int cube_4()
//{
//line4:
//	int code = _getch(); // пользователь нажимает клавишу
//
//	if (code == 32)
//	{
//		for (int i = 1; i <= 7; i++) // Кость 4
//		{
//			for (int j = 1; j <= 14; j++)
//			{
//				if (i == 1 || i == 7)
//					cout << "*";
//				else if (j == 1 || j == 14)
//					cout << "*";
//				else if (i == 3 && j == 4 || i == 3 && j == 5)
//					cout << "*";
//				else if (i == 3 && j == 10 || i == 3 && j == 11)
//					cout << "*";
//				else if (i == 5 && j == 4 || i == 5 && j == 5)
//					cout << "*";
//				else if (i == 5 && j == 10 || i == 5 && j == 11)
//					cout << "*";
//				else
//					cout << " ";
//			}
//			cout << endl;
//		}
//		return 4;
//	}
//	else
//		goto line4;
//
//}
//
//int cube_5()
//{
//line5:
//	int code = _getch(); // пользователь нажимает клавишу
//
//	if (code == 32)
//	{
//		for (int i = 1; i <= 7; i++) // Кость 5
//		{
//			for (int j = 1; j <= 14; j++)
//			{
//				if (i == 1 || i == 7)
//					cout << "*";
//				else if (j == 1 || j == 14)
//					cout << "*";
//				else if (i == 3 && j == 4 || i == 3 && j == 5)
//					cout << "*";
//				else if (i == 3 && j == 10 || i == 3 && j == 11)
//					cout << "*";
//				else if (i == 4 && j == 7 || i == 4 && j == 8)
//					cout << "*";
//				else if (i == 5 && j == 4 || i == 5 && j == 5)
//					cout << "*";
//				else if (i == 5 && j == 10 || i == 5 && j == 11)
//					cout << "*";
//				else
//					cout << " ";
//			}
//			cout << endl;
//		}
//		return 5;
//	}
//	else
//		goto line5;
//
//}
//
//int cube_6()
//{
//line6:
//	int code = _getch(); // пользователь нажимает клавишу
//
//	if (code == 32)
//	{
//		for (int i = 1; i <= 7; i++) // Кость 6
//		{
//			for (int j = 1; j <= 14; j++)
//			{
//				if (i == 1 || i == 7)
//					cout << "*";
//				else if (j == 1 || j == 14)
//					cout << "*";
//				else if (i == 3 && j == 4 || i == 3 && j == 5)
//					cout << "*";
//				else if (i == 3 && j == 10 || i == 3 && j == 11)
//					cout << "*";
//				else if (i == 3 && j == 7 || i == 3 && j == 8)
//					cout << "*";
//				else if (i == 5 && j == 7 || i == 5 && j == 8)
//					cout << "*";
//				else if (i == 5 && j == 4 || i == 5 && j == 5)
//					cout << "*";
//				else if (i == 5 && j == 10 || i == 5 && j == 11)
//					cout << "*";
//				else
//					cout << " ";
//			}
//			cout << endl;
//		}
//		return 6;
//	}
//	else
//		goto line6;
//
//}
//
//void main()
//{
//	setlocale(LC_ALL, "rus");
//	srand(time(NULL));
//	char b;
//
//	do
//	{
//		system("cls");
//		int d;
//		int s = 0, f = 0, j = 0, k = 0, count_all = 1;
//		int player_1;
//		int player_2;
//		int p = 1;
//
//		cout << "введите кол-во раундов: " << endl;
//		cin >> d;
//		while (p <= d)
//		{
//			cout << "Раунд " << count_all << endl;
//			j = 0;
//			k = 0;
//			while (j < 2)
//			{
//				player_1 = rand() % 6 + 1;
//				if (player_1 == 1)
//					int result = cube_1();
//				else if (player_1 == 2)
//					int result = cube_2();
//				else if (player_1 == 3)
//					int result = cube_3();
//				else if (player_1 == 4)
//					int result = cube_4();
//				else if (player_1 == 5)
//					int result = cube_5();
//				else /*if (player_1 == 6)*/
//					int result = cube_6();
//				s += player_1;
//				j++;
//
//			}
//			cout << endl;
//			cout << "игрок 1: " << s << endl;
//			cout << endl;
//			/////////////////////////////////////////////////////////////////////
//
//			while (k < 2)
//			{
//				player_2 = rand() % 6 + 1;
//				if (player_2 == 1)
//					int result = cube_1();
//				else if (player_2 == 2)
//					int result = cube_2();
//				else if (player_2 == 3)
//					int result = cube_3();
//				else if (player_2 == 4)
//					int result = cube_4();
//				else if (player_2 == 5)
//					int result = cube_5();
//				else /*if (player_2 == 6)*/
//					int result = cube_6();
//				f += player_2;
//				k++;
//
//			}
//			cout << endl;
//			cout << "игрок 2: " << f << endl;
//			//cout << endl;
//			cout << "\n---------------------------------\n" << endl;
//			p++;
//			count_all++;
//		}
//		/////////////////////////////////////////////////////////////////////
//
//		cout << "игрок 1: " << s << endl;
//		cout << "игрок 2: " << f << endl;
//		if (s > f)
//		{
//			cout << "Первый игрок победил" << endl;
//		}
//
//		if (s < f)
//		{
//			cout << "Второй игрок победил" << endl;
//		}
//
//		if (s == f)
//		{
//			cout << "Ничья" << endl;
//		}
//		cout << endl;
//		cout << "Вы хотите продолжить? Y/N" << endl;
//
//		cin >> b;
//
//
//	} while (b == 'Y' || b == 'y');
//	{
//	}
//}