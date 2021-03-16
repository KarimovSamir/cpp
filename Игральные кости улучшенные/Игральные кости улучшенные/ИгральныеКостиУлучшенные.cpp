#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

int cube_1()
{
	for (int i = 1; i <= 7; i++) // Кость 1
	{
		for (int j = 1; j <= 14; j++)
		{
			if (i == 1 || i == 7)
				cout << "*";
			else if (j == 1 || j == 14)
				cout << "*";
			else if (i == 4 && j == 7 || i == 4 && j == 8)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 1;
}

int cube_2()
{
	for (int i = 1; i <= 7; i++) // Кость 2
	{
		for (int j = 1; j <= 14; j++)
		{
			if (i == 1 || i == 7)
				cout << "*";
			else if (j == 1 || j == 14)
				cout << "*";
			else if (i == 3 && j == 4 || i == 5 && j == 10)
				cout << "*";
			else if (i == 3 && j == 5 || i == 5 && j == 11)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 2;
}

int cube_3()
{
	for (int i = 1; i <= 7; i++) // Кость 3
	{
		for (int j = 1; j <= 14; j++)
		{
			if (i == 1 || i == 7)
				cout << "*";
			else if (j == 1 || j == 14)
				cout << "*";
			else if (i == 3 && j == 4 || i == 5 && j == 10)
				cout << "*";
			else if (i == 4 && j == 7 || i == 4 && j == 8)
				cout << "*";
			else if (i == 3 && j == 5 || i == 5 && j == 11)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 3;
}

int cube_4()
{
	for (int i = 1; i <= 7; i++) // Кость 4
	{
		for (int j = 1; j <= 14; j++)
		{
			if (i == 1 || i == 7)
				cout << "*";
			else if (j == 1 || j == 14)
				cout << "*";
			else if (i == 3 && j == 4 || i == 3 && j == 5)
				cout << "*";
			else if (i == 3 && j == 10 || i == 3 && j == 11)
				cout << "*";
			else if (i == 5 && j == 4 || i == 5 && j == 5)
				cout << "*";
			else if (i == 5 && j == 10 || i == 5 && j == 11)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 4;
}

int cube_5()
{
	for (int i = 1; i <= 7; i++) // Кость 5
	{
		for (int j = 1; j <= 14; j++)
		{
			if (i == 1 || i == 7)
				cout << "*";
			else if (j == 1 || j == 14)
				cout << "*";
			else if (i == 3 && j == 4 || i == 3 && j == 5)
				cout << "*";
			else if (i == 3 && j == 10 || i == 3 && j == 11)
				cout << "*";
			else if (i == 4 && j == 7 || i == 4 && j == 8)
				cout << "*";
			else if (i == 5 && j == 4 || i == 5 && j == 5)
				cout << "*";
			else if (i == 5 && j == 10 || i == 5 && j == 11)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	return 5;
}

int cube_6()
{
	for (int i = 1; i <= 7; i++) // Кость 6
	{
		for (int j = 1; j <= 14; j++)
		{
			if (i == 1 || i == 7)
				cout << "*";
			else if (j == 1 || j == 14)
				cout << "*";
			else if (i == 3 && j == 4 || i == 3 && j == 5)
				cout << "*";
			else if (i == 3 && j == 10 || i == 3 && j == 11)
				cout << "*";
			else if (i == 3 && j == 7 || i == 3 && j == 8)
				cout << "*";
			else if (i == 5 && j == 7 || i == 5 && j == 8)
				cout << "*";
			else if (i == 5 && j == 4 || i == 5 && j == 5)
				cout << "*";
			else if (i == 5 && j == 10 || i == 5 && j == 11)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
		return 6;
}

int cube_player1(int player_1, int result)
{
	int cube1 = 0;
	while (cube1 < 1)
	{
		if (player_1 == 1)
			int result = cube_1();
		else if (player_1 == 2)
			int result = cube_2();
		else if (player_1 == 3)
			int result = cube_3();
		else if (player_1 == 4)
			int result = cube_4();
		else if (player_1 == 5)
			int result = cube_5();
		else 
			int result = cube_6();
		cube1++;
	}
	return result;
}

int cube_player2(int player_2, int result)
{
	int cube2 = 0;
	while (cube2 < 1)
	{
		if (player_2 == 1)
			int result = cube_1();
		else if (player_2 == 2)
			int result = cube_2();
		else if (player_2 == 3)
			int result = cube_3();
		else if (player_2 == 4)
			int result = cube_4();
		else if (player_2 == 5)
			int result = cube_5();
		else
			int result = cube_6();
		cube2++;
	}
	return result;
}

void main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	char exit;

	do
	{
		system("cls");
		int round;
		int summ_first_player = 0, summ_second_player = 0;
		int throw_player1 = 0, cube2 = 0, count_all = 1, cube1 = 0, throw_player2 = 0;
		int player_1;
		int player_2;
		int round_start = 1;

		cout << "Введите кол-во раундов: " << endl;
		cin >> round;
		while (round_start <= round)
		{
			cout << "Нажмите пробел для броска" << endl;
			int result = 0;
			cout << "Раунд " << count_all << endl;
			throw_player1 = 0;
			cube1 = 0;
			cube2 = 0;
			throw_player2 = 0;
			while (throw_player1 < 2)
			{
			line1:
				int code = _getch();// пользователь нажимает клавишу
				if (code == 32)
				{
					while (cube1 < 2)
					{
						player_1 = rand() % 6 + 1;
						int smth = cube_player1(player_1, result);
						throw_player1++;
						summ_first_player = summ_first_player + player_1;
						cube1++;
					}
				}
				else
					goto line1;
			}
			cout << endl;
			cout << "Игрок 1: " << summ_first_player << endl;
			cout << endl;
			/////////////////////////////////////////////////////////////////////
			while (throw_player2 < 2)
			{
			line2:
				int code = _getch();// пользователь нажимает клавишу
				if (code == 32)
				{
					while (cube2 < 2)
					{
						player_2 = rand() % 6 + 1;
						int smth2 = cube_player2(player_2, result);
						throw_player2++;
						summ_second_player = summ_second_player + player_2;
						cube2++;
					}
				}
				else
					goto line2;
			}
				cout << endl;
				cout << "Игрок 2: " << summ_second_player << endl;
				count_all++;
				cout << "\n---------------------------------\n" << endl;
			round_start++;
		}
				cout << "Игрок 1: " << summ_first_player << endl;
				cout << "Игрок 2: " << summ_second_player << endl;
				if (summ_first_player > summ_second_player)
				{
					cout << "Первый игрок победил" << endl;
				}

				if (summ_first_player < summ_second_player)
				{
					cout << "Второй игрок победил" << endl;
				}

				if (summ_first_player == summ_second_player)
				{
					cout << "Ничья" << endl;
				}
				cout << endl;
				cout << "Вы хотите продолжить? Y/N" << endl;
				cin >> exit;

	} while (exit == 'Y' || exit == 'y');
	{
	}
}