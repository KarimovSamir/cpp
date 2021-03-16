//#include <iostream>
//#include <ctime>
//#include <windows.h>
//#include <conio.h>
//#include "Header.h"
//using namespace std;
//
//void SetCoordinates(int x, int y)
//{
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(
//        GetStdHandle(STD_OUTPUT_HANDLE),
//        coord);
//}
//
////������� ��������
//int shoot(int field[10][10], int x, int y, int comp_or_human)
//{
//    int count = 0;
//    if (field[x][y] == -1 || field[x][y] == -2) //�������� ��� ����, ���� ��� ����� ��� �����������, �� ����� ����� ��������� ����������
//    {                                           // ����� �������� �� �������� � ���� �����
//        count = 3;
//    }
//    //���� ���������� ������ ������ ��� ����� 1 ������ ��� ���� �������
//    else if (field[x][y] >= 1)
//    {
//
//        if (comp_or_human == 1)
//        {
//            //��������� ������, ����� �� �������, ������� ������� ������ ��� �����
//            ships_comp[field[x][y]]--;
//
//            if (ships_comp[field[x][y]] == 0)
//            {
//                count = 2; //���� ������� ����
//            }
//            else
//            {
//                count = 1; //���� ������� �����
//            }
//            //��� ������ �������� �������, � ������ ����� �, �� ���� �������� �������� ��� ������ ������� 
//            field[x][y] = -1;
//        }
//        else if (comp_or_human == 2)
//        {
//            ships_human[field[x][y]]--;
//
//            if (ships_human[field[x][y]] == 0)
//            {
//                count = 2; //���� ������� ����
//            }
//            else
//            {
//                count = 1; //���� ������� �����
//            }
//            //��� ������ �������� �������, � ������ ����� �, �� ���� �������� �������� ��� ������ ������� 
//            field[x][y] = -1;
//        }
//    }
//    else // ��� �������� ���� ��� �������
//    {
//        field[x][y] = -2; // �������� ������ � ��������
//    }
//    return count;
//}
//
////��������� ����������� ��������
//void enter_ship(int field[10][10], int SIZE, int ships_lenght, int comp_or_human)
//{
//    int direction = 0;
//    int count_ship = 0;
//    int count_tact = 0;
//    while (count_ship < 1)
//    {
//        count_tact++;
//        if (count_tact > 500)
//        {
//            break;
//        }
//        // ��������� ������� ��� �������
//        int x = rand() % SIZE;
//        int y = rand() % SIZE;
//
//        //�������������� ���������� (��� ����� :) )
//        int temp_x = x;
//        int temp_y = y;
//
//        //�������� �������� �����������
//        direction = rand() % 4;
//        bool set_possible = 1;
//
//        //��������: ����� �� ��������� �������
//        for (int i = 0; i < ships_lenght; i++)
//        {
//            //��������: ������� �� �� ������� ����
//            if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
//            {
//                set_possible = 0;
//                break;
//            }
//
//            //��������: ��������� ����� ������ ������� ���� ������ ����
//            if (field[x][y] >= 1 || field[x][y + 1] >= 1 || field[x][y - 1] >= 1 ||
//                field[x + 1][y] >= 1 || field[x + 1][y + 1] >= 1 || field[x + 1][y - 1] >= 1 ||
//                field[x - 1][y] >= 1 || field[x - 1][y + 1] >= 1 || field[x - 1][y - 1] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//
//            //��������� ��������� (x,y) � ����������� �� ����������� (����� ������� �� ������ ����� ��� �� �������� �� �����)
//            switch (direction)
//            {
//            case 0:
//                x++; //������
//                break;
//            case 1:
//                y++; //����
//                break;
//            case 2:
//                x--; //�����
//                break;
//            case 3:
//                y--; //�����
//                break;
//            }
//        }
//
//        //���� ����� ��������� �������
//        if (set_possible == 1)
//        {
//            //��� ��� ����� �� ������������ ����������, ����� �������� ������ �� ������, 
//            //�� �������� ������� ����� �� ��������� �����������, ������� ��� �� ����������� ��������
//            x = temp_x;
//            y = temp_y;
//
//            //�� ���������� ����������� ������ ������� � ��������� �����������
//            for (int i = 0; i < ships_lenght; i++)
//            {
//                if (comp_or_human == 1)
//                {
//                    field[x][y] = ship_index_comp;
//                }
//                else if (comp_or_human == 2)
//                {
//                    field[x][y] = ship_index_human;
//                }
//
//                switch (direction)
//                {
//                case 0:
//                    x++;
//                    break;
//                case 1:
//                    y++;
//                    break;
//                case 2:
//                    x--;
//                    break;
//                case 3:
//                    y--;
//                    break;
//                }
//            }
//            // ��������� ������ ������� � ������ ships
//            if (comp_or_human == 1)
//            {
//                ships_comp[ship_index_comp] = ships_lenght;
//                ship_index_comp++;
//                count_ship++;
//            }
//            else if (comp_or_human == 2)
//            {
//                ships_human[ship_index_human] = ships_lenght;
//                ship_index_human++;
//                count_ship++;
//            }
//        }
//    }
//}
//
//// ��������� ������� �� ����
//int set_ship(int field[10][10], int SIZE, int x, int y, int ships_lenght, int direction, int comp_or_human)
//{
//    int temp_x = x;
//    int temp_y = y;
//
//    bool set_possible = 1;
//    //��������: ����� �� ��������� �������
//    for (int i = 0; i < ships_lenght; i++)
//    {
//        //��������: ������� �� �� ������� ����
//        if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
//        {
//            set_possible = 0;
//            break;
//        }
//
//        // ������ �������� ���������, �������� �� x ��� y � �������� ���� ����� ���� ��� ���������� ��� ����������
//        // ��� ������ �������� ��������� ��������, �� ���������� ������� ������� �� ������� ����
//        // ������ �������� �� �������� ���������, ��� ��� x ��� y ������������� �� �������, ����� �� ������ ��������� ������� �� ���� ����
//        // � ��� �������� ������� �������� �� ������� ����
//        if (field[x][y] >= 1)
//        {
//            set_possible = 0;
//            break;
//        }
//
//        if (y < SIZE - 1)
//        {
//            if (field[x][y + 1] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//        }
//
//        if (y > 0)
//        {
//            if (field[x][y - 1] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//        }
//
//        if (x < SIZE - 1)
//        {
//            if (field[x + 1][y] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//        }
//
//        if (x < SIZE - 1 && y < SIZE - 1)
//        {
//            if (field[x + 1][y + 1] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//        }
//
//        if (x < SIZE - 1 && y > 0)
//        {
//            if (field[x + 1][y - 1] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//        }
//
//        if (x > 0)
//        {
//            if (field[x - 1][y] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//        }
//
//        if (x > 0 && y < SIZE - 1)
//        {
//            if (field[x - 1][y + 1] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//        }
//
//        if (x > 0 && y > 0)
//        {
//            if (field[x - 1][y - 1] >= 1)
//            {
//                set_possible = 0;
//                break;
//            }
//        }
//
//        //��������� ��������� (x,y) � ����������� �� ����������� (����� ������� �� ������ ����� ��� �� �������� �� �����)
//        switch (direction)
//        {
//        case 0:
//            x++; //������
//            break;
//        case 1:
//            y++; //����
//            break;
//        case 2:
//            x--; //�����
//            break;
//        case 3:
//            y--; //�����
//            break;
//        }
//    }
//
//    //���� ����� ��������� �������
//    if (set_possible == 1)
//    {
//        //��� ��� ����� �� ������������ ����������, ����� �������� ������ �� ������, 
//        //�� �������� ������� ����� �� ��������� �����������, ������� ��� �� ����������� ��������
//        x = temp_x;
//        y = temp_y;
//
//        //�� ���������� ����������� ������ ������� � ��������� �����������
//        for (int i = 0; i < ships_lenght; i++)
//        {
//            if (comp_or_human == 1)
//            {
//                field[x][y] = ship_index_comp;
//            }
//            else if (comp_or_human == 2)
//            {
//                field[x][y] = ship_index_human;
//            }
//
//            switch (direction)
//            {
//            case 0:
//                x++;
//                break;
//            case 1:
//                y++;
//                break;
//            case 2:
//                x--;
//                break;
//            case 3:
//                y--;
//                break;
//            }
//        }
//        // ��������� ������ ������� � ������ ships
//        if (comp_or_human == 1)
//        {
//            ships_comp[ship_index_comp] = ships_lenght;
//            ship_index_comp++;
//        }
//        else if (comp_or_human == 2)
//        {
//            ships_human[ship_index_human] = ships_lenght;
//            ship_index_human++;
//        }
//    }
//    return set_possible;
//}
//
//// ��������, ����� ������� �� ������� �� ����
//int stays_on_board(int x, int y, int SIZE, int direction, int ships_lenght) // ��������, ����� �� ������� �� �������
//{
//    bool on_board = 1;
//
//    //��������: ����� �� ��������� �������
//    for (int i = 0; i < ships_lenght; i++)
//    {
//        //��������: ������� �� �� ������� ����
//        if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
//        {
//            on_board = 0;
//            break;
//        }
//
//        //��������� ��������� (x,y) � ����������� �� ����������� (����� ������� �� ������ ����� ��� �� �������� �� �����)
//        switch (direction)
//        {
//        case 0:
//            x++; //������
//            break;
//        case 1:
//            y++; //����
//            break;
//        case 2:
//            x--; //�����
//            break;
//        case 3:
//            y--; //�����
//            break;
//        }
//    }
//    return on_board;
//}
//
//// ������ ����������� ��������
//void hand_placing_ship(int x, int y, int direction, int ships_lenght)
//{
//    char ship = 254;
//    //��������� �����������
//    for (int i = 0; i < ships_lenght; i++)
//    {
//        //���� � �����������, ����� �� ����� �� ������� ���� ��� � = 0 ��� y = 0 
//        SetCoordinates(x + 3, y + 1);
//
//        cout << ship;
//        switch (direction)
//        {
//        case 0:
//            x += 2;
//            break;
//        case 1:
//            y++;
//            break;
//        case 2:
//            x -= 2;
//            break;
//        case 3:
//            y--;
//            break;
//        }
//    }
//}
//
////void smth2()
////{
////    //������ ����������� ��������
////    while (true)
////    {
////        print(field, SIZE, add_field, 1);
////        hand_placing_ship(x, y, direction, ships_lenght);
////        pressed_key = _getch();
////
////        // ��������� ���������� ����� �� ����������
////        temp_x = x;
////        temp_y = y;
////        temp_direction = direction;
////
////        pressed_key = _getch();
////
////        switch (pressed_key)
////        {
////        case 97: // �����, ������ 'a'
////            x--;
////            break;
////        case 100: // ������, ������ 'd'
////            x++;
////            break;
////        case 115: // ����, ������ 's'
////            y++;
////            break;
////        case 119: // �����, ������ 'w'
////            y--;
////            break;
////        case 114: // �������, ������ 'r'
////            direction = !direction; // ������������� ��� �����������
////            break;
////        case 13: // Enter
////            if (set_ship(field, SIZE, x, y, ships_lenght, direction))
////            {
////                //bool set_ship(int field[10][10], int SIZE,int x, int y, int ships_lenght, int direction)
////                x = 0;
////                y = 0;
////                direction = 0;
////                
////                ships_lenght--; //������ �������
////            }
////        }
////
////        //���� �� ���������� �� �����, �� ������ ����� ����������
////        if (!stays_on_board(x, y, SIZE, direction, ships_lenght))
////        {
////            //bool stays_on_board(int x, int y, int SIZE, int direction, int ships_lenght)
////            //������� �� ���������
////            x = temp_x;
////            y = temp_y;
////            direction = temp_direction;
////        }
////        system("cls");
////    }
////}
//
//// ���������� ����
//void save_game(int field[10][10], int second_field[10][10], int SIZE)
//{
//    int a;
//    int b;
//    FILE* fd;
//    fopen_s(&fd, Fileplace, "wb");
//
//    //fwrite(&field, sizeof(field[0][0]), SIZE, fd);
//    //fwrite(&second_field, sizeof(second_field[0][0]), SIZE, fd);
//
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = 0; j < SIZE; j++)
//        {
//            a = field[i][j];
//            b = second_field[i][j];
//            fwrite(&a, sizeof(a), 1, fd);
//            fwrite(&b, sizeof(b), 1, fd);
//        }
//    }
//    fclose(fd);
//}
//
//// ����������� ����
//void Continue(int field[10][10], int second_field[10][10], int SIZE)
//{
//    int a;
//    int b;
//    FILE* fd;
//    fopen_s(&fd, "C:\\Users\\Jonathan Kent\\source\\repos\\������� ���\\������� ���\\file.bin", "rb");
//
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = 0; j < SIZE; j++)
//        {
//            fread(&a, sizeof(int), 1, fd);
//            fread(&b, sizeof(int), 1, fd);
//            field[i][j] = a;
//            second_field[i][j] = b;
//        }
//    }
//    fclose(fd);
//}
//
//// ����� ������� ����
//void print(int field[10][10], int SIZE, int want_see_my_ships)
//{
//    SetCoordinates(25, 2);
//    cout << "Galactic battle of ships";
//    char ship = 254;
//    char miss = 177;
//    char letter = 65;
//    int count1 = 10;
//    int count2 = 5;
//
//    SetCoordinates(count1, count2);
//    cout << "  ";
//    for (int i = 0; i < SIZE; i++)
//    {
//        if (i == SIZE - 1)
//        {
//            cout << "|" << letter << "|";
//        }
//        else
//        {
//            cout << "|" << letter;
//        }
//        letter++;
//    }
//
//    //count1++;
//    count2++;
//
//    SetCoordinates(count1, count2);
//
//    for (int i = 0; i < SIZE; i++) // number
//    {
//        SetCoordinates(count1, count2);
//        if (i < 9) { cout << " "; }
//        cout << i + 1;
//
//        for (int j = 0; j < SIZE; j++) // letter
//        {
//            //j = letter;
//            if (want_see_my_ships == 1)
//            {
//                if (field[j][i] == 0) // ������� ������� �� ���� ���� ������
//                {
//                    cout << "|" << " ";
//                    if (j == SIZE - 1)
//                    {
//                        cout << "|";
//                    }
//
//                }
//                else if (field[j][i] == -1)
//                {
//                    cout << "|" << "X";
//                    if (j == SIZE - 1)
//                    {
//                        cout << "|";
//                    }
//
//                }
//                else if (field[j][i] == -2)
//                {
//                    cout << "|" << miss;
//
//                    if (j == SIZE - 1)
//                    {
//                        cout << "|";
//                    }
//                }
//                else
//                {
//                    if (j == SIZE - 1)
//                    {
//                        cout << "|" << ship << "|";
//                    }
//                    else
//                    {
//                        cout << "|" << ship;
//                    }
//                }
//            }
//            else
//            {
//                if (j == SIZE - 1)
//                {
//                    cout << "|" << " " << "|";
//                }
//                else
//                {
//                    cout << "|" << " ";
//                }
//            }
//            letter++;
//
//        }
//        cout << endl;
//        //count1++;
//        count2++;
//    }
//}
//
//// ����� ������� ����
//void second_print(int second_field[10][10], int SIZE, int want_see_my_ships)
//{
//    char ship = 254;
//    char miss = 177;
//    char letter = 65;
//    int count1 = 40;
//    int count2 = 5;
//    //������ ����� ����� �����
//    SetCoordinates(count1, count2);
//    cout << "  ";
//    for (int i = 0; i < SIZE; i++)
//    {
//        if (i == SIZE - 1)
//        {
//            cout << "|" << letter << "|";
//        }
//        else
//        {
//            cout << "|" << letter;
//        }
//        letter++;
//    }
//    //count1++;
//    count2++;
//    //cout << endl;
//    SetCoordinates(count1, count2);
//    //count++;
//    for (int i = 0; i < SIZE; i++) // number
//    {
//        SetCoordinates(count1, count2);
//        if (i < 9) { cout << " "; }
//        cout << i + 1;
//
//        for (int j = 0; j < SIZE; j++) // letter
//        {
//            if (want_see_my_ships == 1)
//            {
//                if (second_field[j][i] == 0) // ���� ���� ������
//                {
//                    cout << "|" << " ";
//                    if (j == SIZE - 1)
//                    {
//                        cout << "|";
//                    }
//
//                }
//                else if (second_field[j][i] == -1) // ���� ����� ��� ����                
//                {
//                    cout << "|" << "X";
//                    if (j == SIZE - 1)
//                    {
//                        cout << "|";
//                    }
//
//                }
//                else if (second_field[j][i] == -2) // ���� ������
//                {
//                    cout << "|" << miss;
//
//                    if (j == SIZE - 1)
//                    {
//                        cout << "|";
//                    }
//                }
//                else
//                {
//                    if (j == SIZE - 1)
//                    {
//                        cout << "|" << ship << "|";
//                    }
//                    else
//                    {
//                        cout << "|" << ship;
//                    }
//                }
//            }
//            else
//            {
//                if (j == SIZE - 1)
//                {
//                    cout << "|" << " " << "|";
//                }
//                else
//                {
//                    cout << "|" << " ";
//                }
//            }
//            letter++;
//        }
//        cout << endl;
//        //count1++;
//        count2++;
//    }
//}
//
//int win_or_not(int SIZE, int destroy, int victory, int comp_or_human)
//{
//    for (int i = 1; i < SIZE + 1; i++)
//    {
//        if (comp_or_human == 1)
//        {
//            if (ships_human[i] != 0)
//            {
//                destroy = 0;
//                break;
//            }
//        }
//        else if (comp_or_human == 2)
//        {
//            if (ships_comp[i] != 0)
//            {
//                destroy = 0;
//                break;
//            }
//        }
//    }
//    if (destroy == 1)
//    {
//        victory = 1; //�������� �� ������
//    }
//    return victory;
//}
//
//void SetColor(ConsoleColor text, ConsoleColor background)
//{
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
//}
//
//void skull()
//{
//    SetCoordinates(35, 4);
//    cout << "      *****************      " << endl;
//    SetCoordinates(35, 5);
//    cout << "     *******************     " << endl;
//    SetCoordinates(35, 6);
//    cout << "     *******************     " << endl;
//    SetCoordinates(35, 7);
//    cout << "     ****";
//    SetColor(Red, Red);
//    cout << "    ";
//    SetColor(White, Black);
//    cout << "***";
//    SetColor(Red, Red);
//    cout << "    ";
//    SetColor(White, Black);
//    cout << "****     " << endl;
//    SetCoordinates(35, 8);
//    cout << "     ****";
//    SetColor(Red, Red);
//    cout << "    ";
//    SetColor(White, Black);
//    cout << "***";
//    SetColor(Red, Red);
//    cout << "    ";
//    SetColor(White, Black);
//    cout << "****     " << endl;
//    SetCoordinates(35, 9);
//    cout << "     ****";
//    SetColor(Red, Red);
//    cout << "    ";
//    SetColor(White, Black);
//    cout << "***";
//    SetColor(Red, Red);
//    cout << "    ";
//    SetColor(White, Black);
//    cout << "****     " << endl;
//    SetCoordinates(35, 10);
//    cout << "          **     **      " << endl;
//    SetCoordinates(35, 11);
//    cout << "          **     **      " << endl;
//    SetCoordinates(35, 12);
//    cout << "           *******       " << endl;
//    SetCoordinates(35, 13);
//    cout << "       ***************   " << endl;
//    SetCoordinates(35, 14);
//    cout << "     **               **     " << endl;
//    SetCoordinates(35, 15);
//    cout << "     **               **     " << endl;
//    SetCoordinates(35, 16);
//    cout << "     **               **     " << endl;
//    SetCoordinates(35, 17);
//    cout << "       ***************   " << endl;
//    SetCoordinates(35, 18);
//    cout << "   **                   **   " << endl;
//    SetCoordinates(35, 19);
//    cout << " ********           ******** " << endl;
//    SetCoordinates(35, 20);
//    cout << "     ********    ********     " << endl;
//    SetCoordinates(35, 21);
//    cout << "             ****             " << endl;
//    SetCoordinates(35, 22);
//    cout << "     ********    ********     " << endl;
//    SetCoordinates(35, 23);
//    cout << " ********           ******** " << endl;
//    SetCoordinates(35, 24);
//    cout << "   **                   **   " << endl;
//}