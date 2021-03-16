//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//#include <time.h>
//using namespace std;
//
//bool GameOver_check(char arr[][3]);
//void Menu(int* menu);
//void field(char arr[][3]);
//void win_lose_check(char arr[][3], int* win, int* lose);
//bool repeat_check_X_O(int* array_X, int* array_Y, char arr[][3]);
//void move(int* coordinate_X, int* coordinate_Y, int* array_X, int* array_Y, char arr[][3], int* Player_X, int* Player_O, int* TwoPlayer);
//void coordinate_to_index(int* coordinate_X, int* coordinate_Y, int* array_X, int* array_Y);
//void select_X_O(int* array_X, int* array_Y, char arr[][3], int* Player_X, int* Player_O, int* TwoPlayer);
//void set_cursor(int x, int y);
//void GameOver(int* menu, int* Player_X, int* Player_O, int* win, int* lose);
//void zero(int* coordinate_X, int* coordinate_Y, int* array_X, int* array_Y, char arr[][3], int* TwoPlayer, int* EXIT, int* win, int* lose);
//void enter_X_O(int* array_X, int* array_Y, char arr[][3], int* TwoPlayer);
//bool replay(int exit);
//
//void main()
//{
//	setlocale(LC_ALL, "rus");
//	srand(time(NULL));
//	const int size = 3;
//	char arr[size][size] = {};
//	int PN_X = 1;
//	int* Player_X = &PN_X;
//	int PN_O = 2;
//	int* Player_O = &PN_O;
//	int menyu;
//	int* M = &menyu;
//	int x;
//	int* coordinate_X = &x;
//	int y;
//	int* coordinate_Y = &y;
//	int arrayX;
//	int* array_X = &arrayX;
//	int arrayY;
//	int* array_Y = &arrayY;
//	int two_player;
//	int* TwoPlayer = &two_player;
//	int exit;
//	int* EXIT = &exit;
//	int winner;
//	int* win = &winner;
//	int looser;
//	int* lose = &looser;
//	do
//	{
//		system("cls");
//		zero(coordinate_X, coordinate_Y, array_X, array_Y, arr, TwoPlayer, EXIT, win, lose);
//		Menu(M);
//		if (menyu != 4)
//		{
//			do
//			{
//				move(coordinate_X, coordinate_Y, array_X, array_Y, arr, Player_X, Player_O, TwoPlayer);
//				enter_X_O(array_X, array_Y, arr, TwoPlayer);
//
//				if (menyu == 1) { two_player++; }
//				win_lose_check(arr, win, lose);
//			} while (winner && looser && GameOver_check(arr));
//			system("cls");
//			field(arr);
//			GameOver(M, Player_X, Player_O, win, lose);
//		}
//		else
//		{
//			exit = 1;
//		}
//	} while (replay(exit));
//}
//
//void set_cursor(int x, int y)
//{
//	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD coord = {};
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(h, coord);
//}
//
//void zero(int* coordinate_X, int* coordinate_Y, int* array_X, int* array_Y, char arr[][3], int* TwoPlayer, int* EXIT, int* win, int* lose)
//{
//	*coordinate_X = 5;
//	*coordinate_Y = 3;
//	*array_X = 1;
//	*array_Y = 1;
//	*TwoPlayer = 0;
//	*EXIT = 0;
//	*win = 1;
//	*lose = 1;
//	for (int Y = 0; Y < 3; Y++)
//	{
//		for (int X = 0; X < 3; X++)
//		{
//			arr[Y][X] = char(' ');
//		}
//	}
//}
//
//// меню
//void Menu(int* menu)
//{
//	int error = -1;
//	int a;
//	do
//	{
//		system("cls");
//		error++;
//		if (error > 1)
//		{
//			cout << "Введите 1\n" << endl;
//		}
//		cout << "------------------------------------------" << endl;
//		cout << "| 1 | Игра с человеком (Введите 1)       |" << endl;
//		cout << "------------------------------------------" << endl;
//		cout << "| Для ввода 'Х' и 'О' пользуйтесь 'Enter'|" << endl;
//		cout << "------------------------------------------" << endl;
//		cin >> *menu;
//	} while (*menu != 1);
//}
//
//void field(char arr[][3])
//{
//	cout << "\n " << arr[0][0]; cout << " "; cout << "|";
//	cout << " " << arr[0][1] << " "; cout << "|";
//	cout << " " << arr[0][2] << " " << endl;
//	cout << " ---------" << endl;
//
//	cout << " " << arr[1][0]; cout << " "; cout << "|";
//	cout << " " << arr[1][1] << " "; cout << "|";
//	cout << " " << arr[1][2] << " " << endl;
//	cout << " ---------" << endl;
//
//	cout << " " << arr[2][0]; cout << " "; cout << "|";
//	cout << " " << arr[2][1] << " "; cout << "|";
//	cout << " " << arr[2][2] << " " << endl;
//}
//
//void move(int* coordinate_X, int* coordinate_Y, int* array_X, int* array_Y, char arr[][3], int* Player_X, int* Player_O, int* TwoPlayer)
//{
//	do
//	{
//		bool c;
//		int move;
//		do
//		{
//			system("cls");
//			c = true;
//			field(arr);
//			select_X_O(array_X, array_Y, arr, Player_X, Player_O, TwoPlayer);
//			set_cursor(*coordinate_X, *coordinate_Y);
//			move = _getch();
//			if (move == 224)
//			{
//				continue;
//			}
//			switch (move)
//			{
//				    
//			case(13): c = false; break;
//				    // вверх
//			case(72): if (*coordinate_Y == 1) { *coordinate_Y = 5; }
//					else { *coordinate_Y = *coordinate_Y - 2; }
//					coordinate_to_index(coordinate_X, coordinate_Y, array_X, array_Y);
//					break;
//					// вниз
//			case(80): if (*coordinate_Y == 5) { *coordinate_Y = 1; }
//					else { *coordinate_Y = *coordinate_Y + 2; }
//					coordinate_to_index(coordinate_X, coordinate_Y, array_X, array_Y);
//					break;
//					// влево
//			case(75): if (*coordinate_X == 1) { *coordinate_X = 9; }
//					else { *coordinate_X = *coordinate_X - 4; }
//					coordinate_to_index(coordinate_X, coordinate_Y, array_X, array_Y);
//					break;
//					// вправо
//			case(77): if (*coordinate_X == 9) { *coordinate_X = 1; }
//					else { *coordinate_X = *coordinate_X + 4; }
//					coordinate_to_index(coordinate_X, coordinate_Y, array_X, array_Y);
//					break;
//			}
//		} while (c);
//	} while (repeat_check_X_O(array_X, array_Y, arr));
//}
//
//void select_X_O(int* array_X, int* array_Y, char arr[][3], int* Player_X, int* Player_O, int* TwoPlayer)
//{
//	if (repeat_check_X_O(array_X, array_Y, arr)) { set_cursor(0, 7); cout << "Выберите другую ячейку"; }
//	set_cursor(0, 8);
//	if (*TwoPlayer % 2 == 0) { cout << " " << *Player_X << ", выберите X"; }
//	else { cout << " " << *Player_O << ", выберите O"; }
//}
//
//void coordinate_to_index(int* coordinate_X, int* coordinate_Y, int* array_X, int* array_Y)
//{
//	if (*coordinate_X == 1) { *array_X = 0; }
//	else if (*coordinate_X == 5) { *array_X = 1; }
//	else if (*coordinate_X == 9) { *array_X = 2; }
//	if (*coordinate_Y == 1) { *array_Y = 0; }
//	else if (*coordinate_Y == 3) { *array_Y = 1; }
//	else if (*coordinate_Y == 5) { *array_Y = 2; }
//}
//
//bool repeat_check_X_O(int* array_X, int* array_Y, char arr[][3])
//{
//	if (arr[*array_Y][*array_X] == char(' ')) { return false; }
//	else
//	{
//		int X, Y;
//		for (int Y = 0; Y < 3; Y++)
//		{
//			for (int X = 0; X < 3; X++)
//			{
//				if (arr[Y][X] == char(' ')) { return true; }
//			}
//		}
//		return false;
//	}
//}
//
//void enter_X_O(int* array_X, int* array_Y, char arr[][3], int* TwoPlayer)
//{
//	if (*TwoPlayer % 2 == 0) { arr[*array_Y][*array_X] = char('X'); }
//	else { arr[*array_Y][*array_X] = char('0'); }
//}
//
//void win_lose_check(char arr[][3], int* win, int* lose)
//{
//	if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {
//		if (arr[0][0] == char('X')) { *win = 0;}
//		if (arr[0][0] == char('0')) { *lose = 0;}
//	}
//	if (arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) {
//		if (arr[0][2] == char('X')) { *win = 0;}
//		if (arr[0][2] == char('0')) { *lose = 0;}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2])
//		{
//			if (arr[i][0] == char('X')) { *win = 0;}
//			if (arr[i][0] == char('0')) { *lose = 0;}
//		}
//		if (arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
//		{
//			if (arr[0][i] == char('X')) { *win = 0;}
//			if (arr[0][i] == char('0')) { *lose = 0;}
//		}
//	}
//}
//
//bool GameOver_check(char arr[][3])
//{
//	for (int y = 0; y < 3; y++)
//	{
//		for (int x = 0; x < 3; x++)
//		{
//			if (arr[y][x] == char(' ')) { return true; }
//		}
//	}
//	return false;
//}
//
//void GameOver(int* menu, int* Player_X, int* Player_O, int* win, int* lose)
//{
//	if (*win == 0)
//	{
//		if (*menu == 1)
//		{
//			set_cursor(0, 7);
//			cout << "Поздравляю 1 игрок, вы победили" << endl;
//			cout << "Вы проиграли 2 игрок";
//		}
//		else
//		{
//			set_cursor(0, 7);
//			cout << "Поздравляю 1 игрок, вы победили" << endl;
//		}
//	}
//	else if (*lose == 0)
//	{
//		if (*menu == 1)
//		{
//			set_cursor(0, 7);
//			cout << "Поздравляю 2 игрок, вы победили" << endl;
//			cout << "Вы проиграли 1 игрок";
//		}
//		else
//		{
//			set_cursor(0, 7);
//			cout << "Вы проиграли 1 игрок";
//		}
//	}
//	else
//	{
//		set_cursor(0, 7);
//		cout << "Конец игры" << endl;
//	}
//}
//
//bool replay(int exit)
//{
//	if (exit)
//	{
//		return false;
//	}
//	else
//	{
//		char replay;
//		set_cursor(0, 10);
//		cout << "Хотите продолжить? (Y/N): ";
//		cin >> replay;
//		if (replay == 'Y' || replay == 'y')
//		{
//			return true;
//		}
//		else
//		{
//			return false;
//		}
//	}
//}