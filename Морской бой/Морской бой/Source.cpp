//#include <iostream>
//#include <ctime>
//#include <iomanip>
//#include <windows.h>
//#include <conio.h>
//#include <vector>
//#include "Header.h"
//using namespace std;
//
////������� ��������
//int ship_index_comp = 1;
////���������� � ������ ���� ������� � ������ ���������� ��� ��������: ���� ������� ��� �����
//int ships_comp[11] = { 0 };
//
//int ship_index_human = 1;
//int ships_human[11] = { 0 };
//
//const char* Fileplace = "file.bin";
//
//void main()
//{
//    srand(time(NULL));
//
//    int menu_choose = 0;
//    int continue_or_not = 0;
//
//    const int SIZE = 10;
//    int field[SIZE][SIZE] = { 0 };
//    int second_field[SIZE][SIZE] = { 0 };
//
//    int ships1[11] = { 0,4,3,3,2,2,2,1,1,1,1 }; // �� ��������� ������� � ������� �������� ������� ������� ������� ����� 0
//    int ships2[11] = { 0,4,3,3,2,2,2,1,1,1,1 }; 
//    int mode = 0;
//
//    int x = 0, y = 0;
//    int first_hit_x = 0, first_hit_y = 0;
//    int bot_x = 0, bot_y = 0;
//    int set_me_or_random = 0;
//    int direction = 0; // �����������
//    int ships_lenght = 4; // ����� �������
//
//
//    int comp_or_human;
//    vector <int> dirs;
//    //���������� �������� � ����� �������
//    dirs.push_back(3);//����
//    dirs.push_back(2);//�����
//    dirs.push_back(1);//������
//    dirs.push_back(0);//�����
//
//    SetCoordinates(15, 2);
//    cout << "Greetings creature,";
//    Sleep(1500);
//    SetCoordinates(34, 2);
//    cout << " you have entered our territory";
//    Sleep(1500);
//    SetCoordinates(65, 2);
//    cout << " and now you will be";
//    Sleep(1500);
//    skull();
//    SetCoordinates(43, 15);
//    cout << "EXTERMINATED!";
//    SetCoordinates(30, 25);
//    system("pause");
//    system("cls");
//    SetCoordinates(34, 2);
//    cout << "Galactic battle of ships";
//    SetCoordinates(40, 4);
//    cout << "1) New game";
//    SetCoordinates(40, 5);
//    cout << "2) Continue";
//    SetCoordinates(40, 6);
//    cout << "3) Instruction";
//    SetCoordinates(40, 7);
//    cout << "Choose: ";
//    cin >> menu_choose;
//    
//    system("cls");
//
//    if (menu_choose == 1)
//    {
//        line2:
//        SetCoordinates(8, 2);
//        cout << "Do you want to set up ships on the field yourself or do you us to do it, GREAT MINDS?!";
//        SetCoordinates(40, 4);
//        cout << "1) I can do it myself";
//        SetCoordinates(40, 5);
//        cout << "2) Please, help me GREAT MINDS!";
//        SetCoordinates(40, 6);
//        cout << "Choose: ";
//        cin >> set_me_or_random;
//        system("cls");
//
//        if (set_me_or_random == 1)
//        {
//            while (ships_lenght != 0)
//            {
//                print(field, SIZE, 1);
//                hand_placing_ship(x + x, y, direction, ships_lenght); // ������� �������
//                // ��������� ���������� ����� �� ����������
//                int temp_x = x;
//                int temp_y = y;
//                int temp_direction = direction;
//                int pressed_key = _getch();
//                switch (pressed_key)
//                {
//                case 97: // �����, ������ 'a'
//                    x--;
//                    break;
//                case 100: // ������, ������ 'd'
//                    x++;
//                    break;
//                case 115: // ����, ������ 's'
//                    y++;
//                    break;
//                case 119: // �����, ������ 'w'
//                    y--;
//                    break;
//                case 114: // �������, ������ 'r'
//                    direction = !direction; // ������������� ��� �����������
//                    break;
//                case 13: // Enter
//                    if (set_ship(field, SIZE, x, y, ships_lenght, direction, 2))
//                    {
//                        //set_ship(field, SIZE, x, y, ships_lenght, direction);
//                        x = 0;
//                        y = 0;
//                        direction = 0;
//                        ships_lenght--; //������ �������
//                    }
//                }
//                //���� �� ���������� �� �����, �� ������ ����� ����������
//                if (!stays_on_board(x, y, SIZE, direction, ships_lenght))
//                {
//                    //������� �� ���������
//                    x = temp_x;
//                    y = temp_y;
//                    direction = temp_direction;
//                }
//                system("cls");
//            }
//        }
//        else if (set_me_or_random == 2)
//        {
//            //��������� ����������� ��������
//            for (int i = 1; i <= SIZE + 1; i++)
//            {
//                enter_ship(field, SIZE, ships1[i], 2); // ������������
//            }
//        }
//        else 
//        {
//            SetCoordinates(30, 9);
//            cout << "SELECT OPTION 1 OR 2, STUPID CREATURE!!!";
//            Sleep(1500);
//            system("cls");
//            goto line2;
//        }
//
//
//    }
//
//    else if (menu_choose == 2)
//    {
//        continue_or_not = 1;
//        //do
//        //{
//        //    //system("cls");
//        //    //cout << "Continue? y/n: ";
//        //    
//        //} while (continue_or_not != 'Y' && continue_or_not != 'y' && continue_or_not != 'N' && continue_or_not != 'n');
//    }
//    
//    else if (menu_choose == 3)
//    {
//
//
//
//    }
//
//    system("cls");
//    
//
//    for (int i = 1; i <= SIZE + 1; i++)
//    {
//        enter_ship(second_field, SIZE, ships2[i], 1); // ����
//    }
//
//    if (continue_or_not == 1) // ����������� ����
//    {
//        Continue(field, second_field, SIZE);
//    }
//
//    int shot_result = 0;
//    int turn = 1; // ���� 0, �� ����� ������ ����, ���� 1, �� ������ ����� �������
//    char letter;
//    int human_victory = 0;
//    int computer_victory = 0;
//    while (human_victory == 0 && computer_victory == 0)
//    {
//        do
//        {
//        line1:
//            system("cls");
//            print(field, SIZE, 1); // 1 - ������ ������� �����
//            second_print(second_field, SIZE, 1); // 0 - ������ ������� �� �����
//
//            save_game(field, second_field, SIZE);
//
//            if (turn == 1)
//            {
//                SetCoordinates(28, 17);
//                cout << "Enter coordinates" << endl;
//                SetCoordinates(28, 18);
//                cout << "Enter letter: ";
//                cin >> letter;
//                if ((letter >= 65 && letter <= 74) || (letter >= 97 && letter <= 106))
//                {
//                    if (letter >= 65 && letter <= 74)
//                    {
//                        x = letter - 65;
//                    }
//                    else if (letter >= 97 && letter <= 106)
//                    {
//                        x = letter - 97;
//                    }
//                }
//                else
//                {
//                    SetCoordinates(28, 19);
//                    cout << "Write correctly!!!" << endl;
//                    Sleep(1000);
//                    goto line1;
//                }
//                SetCoordinates(28, 19);
//                cout << "Enter number: ";
//                cin >> y;
//
//                if (y >= 1 && y <= 10)
//                {
//                    y--;
//                }
//                else
//                {
//                    SetCoordinates(28, 20);
//                    cout << "Write correctly!!!" << endl;
//                    Sleep(1000);
//                    goto line1;
//                }
//
//                shot_result = shoot(second_field, x, y, 1);
//
//                if (shot_result == 2)
//                {
//                    int destroy_human = 1;
//
//                    if (win_or_not(SIZE, destroy_human, human_victory, 2) == 1)
//                    {
//                        human_victory = 1;
//                        break;
//                    }
//
//                    
//                    SetCoordinates(28, 20);
//                    cout << "Destroy" << endl;
//                }
//                else if (shot_result == 1)
//                {
//                    SetCoordinates(28, 20);
//                    cout << "Wound" << endl;
//                }
//                else
//                {
//                    SetCoordinates(28, 20);
//                    cout << "Miss" << endl;
//                }
//            }
//            ///////////////////////////////////////////////////////
//            //                                                   //
//            //                 EXTERMINATE!!!                    //
//            //                                                   //
//            ///////////////////////////////////////////////////////
//            else
//            {
//                cout << "Computer move" << endl;
//                //Sleep(500);
//
//                if (mode == 0) //������
//                {
//                    do //���� ��� ����� �� ������ �� ������� ��� �������, �� �� �� ������ �� �����, 
//                       //� ����� ���������� �� ��� ���, ���� �� ������ � ������ �� ������� ��� �� �������
//                    {
//                        bot_x = rand() % SIZE;
//                        bot_y = rand() % SIZE;
//                        shot_result = shoot(field, bot_x, bot_y, 2);
//
//                    } while (shot_result == 3);
//
//                    if (shot_result == 1)
//                    {
//                        mode = 1; //������� � mode = 1 ��� ���������, ��� ����������� ��������
//
//                        first_hit_x = bot_x;
//                        first_hit_y = bot_y;
//
//                        if (!dirs.empty()) // �������� �� �������, ���� �� ������, �� ���� �������, � ����� �������
//                        {
//                            //size() - ���������� ����������� ���������
//                            direction = dirs[dirs.size() - 1]; // �������� ������ � ���������� ��������, �������� ������ ���������� �������� �������
//                            dirs.pop_back(); // ������� ��������� �������
//                        }
//                        cout << "Wound" << endl;
//                    }
//                    else if (shot_result == 2)
//                    {
//                        int destroy_computer = 1;
//
//                        if (win_or_not(SIZE, destroy_computer, computer_victory, 1) == 1)
//                        {
//                            computer_victory = 1; //�������� �� ������ �����
//                            break;
//                        }
//                    }
//                    else
//                    {
//                        cout << "Miss" << endl;
//                    }
//                }
//
//                else if (mode == 1)
//                {
//                    int change_direction = 0;
//
//                    if (direction == 0) // �����
//                    {
//                        if (bot_x > 0)
//                        {
//                            bot_x--; //�������� �����
//                        }
//                        else
//                        {
//                            change_direction = 1;
//                        }
//                    }
//                    else if (direction == 1) //������
//                    {
//                        if (bot_x < SIZE - 1)
//                        {
//                            bot_x++;
//                        }
//                        else
//                        {
//                            change_direction = 1;
//                        }
//                    }
//                    else if (direction == 2) //�����
//                    {
//                        if (bot_y > 0)
//                        {
//                            bot_y--;
//                        }
//                        else
//                        {
//                            change_direction = 1;
//                        }
//                    }
//                    else if (direction == 3) //����
//                    {
//                        if (bot_y < SIZE - 1)
//                        {
//                            bot_y++;
//                        }
//                        else
//                        {
//                            change_direction = 1;
//                        }
//                    }
//
//                    if (change_direction == 1)
//                    {
//                        // ������ ����������� ��� ���������� �������
//                        // ���� ������� � �������, �� ��� �� ����� �������� ��� ������, 
//                        // � ����� ������������ �� ������ �������, ����� �� ��������� ��� �������
//                        // � ��� ����� ��������� ���
//                        if (!dirs.empty())
//                        {
//                            direction = dirs[dirs.size() - 1];
//                            dirs.pop_back();
//                        }
//                        bot_x = first_hit_x; //������� � �������� �������
//                        bot_y = first_hit_y;
//                        continue; // ������� � ������ �����
//                    }
//
//                    shot_result = shoot(field, bot_x, bot_y, 2);
//
//                    if (shot_result == 1)
//                    {
//                        cout << "Wound" << endl;
//                    }
//                    else if (shot_result == 2)
//                    {
//                        mode = 0;
//                        dirs.clear(); // ������� �������
//                        // �������������� �������
//                        dirs.push_back(3);//����
//                        dirs.push_back(2);//�����
//                        dirs.push_back(1);//������
//                        dirs.push_back(0);//�����
//
//                        int destroy_computer = 1;
//
//                        if (win_or_not(SIZE, destroy_computer, computer_victory, 1) == 1)
//                        {
//                            computer_victory = 1; //�������� �� ������ �����
//                            break;
//                        }
//                        cout << "Destroy" << endl;
//                    }
//                    else
//                    {
//                        if (!dirs.empty())
//                        {
//                            direction = dirs[dirs.size() - 1];
//                            dirs.pop_back();
//                        }
//                        bot_x = first_hit_x;
//                        bot_y = first_hit_y;
//                        // ��� continue ������ ��� ��� ������
//                        cout << "Miss" << endl;
//                    }
//
//                }
//            }
//            Sleep(500);
//            system("cls");
//        } while (shot_result != 0);
//        turn = !turn;
//    }
//
//    system("cls");
//    print(field, SIZE, 1);
//    cout << endl;
//    second_print(second_field, SIZE, 1);
//
//    if (human_victory == 1)
//    {
//        cout << "You're the winner";
//
//    }
//    else if (computer_victory == 1)
//    {
//        cout << "Computer the winner, you're the looser ";
//
//    }
//    cout << endl;
//
//}