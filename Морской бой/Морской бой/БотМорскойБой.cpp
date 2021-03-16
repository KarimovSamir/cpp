//#include <iostream>
//#include <ctime>
//#include <iomanip>
//#include <windows.h>
//#include <conio.h>
//#include <vector>
//using namespace std;
//
//void main()
//{
//    srand(time(NULL));
//    const int SIZE = 10;
//    int sea_bot[SIZE][SIZE] = { 
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}, 
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0, 1 ,1 ,1 ,1 ,0 ,0 ,0 ,0 ,0},
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0},
//        {0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0}
//    };
//    int live = 4;
//    int mode = 0;
//    int x = 0 , y = 0;
//    int first_hit_x = 0;
//    int first_hit_y = 0;
//    int direction = 0;
//    int hard_bot = 4;
//
//    vector <int> dirs;
//    dirs.push_back(3);//����
//    dirs.push_back(2);//�����
//    dirs.push_back(1);//������
//    dirs.push_back(0);//�����
//
//    do
//    {
//        if (mode == 0) //������
//        {
//            x = rand() % SIZE;
//            y = rand() % SIZE;
//
//            if (sea_bot[x][y] == 1)
//            {
//                mode = 1; //������� � mode=1 ��� ���������, ������ ��������� ��������
//                sea_bot[x][y] = 2;
//                first_hit_x = x;
//                first_hit_y = y;
//                live--;
//
//                if (!dirs.empty()) // ���� �� ������, �� ���� �������, � ����� �������
//                {
//                    direction = dirs[dirs.size() - 1]; // �������� ������ � ���������� ��������, �������� ������ ���������� �������� �������
//                    dirs.pop_back(); // ������� ��������� �������
//                }
//                cout << "Wound" << endl;
//            }
//            else
//            {
//                sea_bot[x][y] = 3;
//                cout << "Miss" << endl;
//            }
//        }
//
//        else if (mode == 1) 
//        {
//            bool change_direction = false;
//            if (direction == 0) // �����
//            {
//                if (x > 0)
//                {
//                    x--; //�������� �����
//                }
//                else
//                {
//                    change_direction = true;
//                }
//            }
//            else if(direction == 1) //������
//            {
//                if (x < SIZE - 1)
//                {
//                    x++; 
//                }
//                else
//                {
//                    change_direction = true;
//                }
//            }
//            else if (direction == 2) //�����
//            {
//                if (y > 0)
//                {
//                    y--; 
//                }
//                else
//                {
//                    change_direction = true;
//                }
//            }
//            else if (direction == 3) //����
//            {
//                if (y < SIZE - 1)
//                {
//                    y++; 
//                }
//                else
//                {
//                    change_direction = true;
//                }
//            }
//
//            if (change_direction == true)
//            {
//                // ������ ����������� ��� ���������� �������
//                    // ���� ������� � �������, �� ��� �� ����� �������� ��� ������, 
//                    // � ����� ������������ �� ������ �������, ����� �� ��������� ��� �������
//                    // � ��� ����� ��������� ���
//                if (!dirs.empty())
//                {
//                    direction = dirs[dirs.size() - 1];
//                    dirs.pop_back();
//                }
//                x = first_hit_x; //������� � �������� �������
//                y = first_hit_y;
//                continue; // ������� � ������ �����
//            }
//
//
//            if (sea_bot[x][y] == 1 && live > 1) // ��������: ������� �����
//            {
//                
//                sea_bot[x][y] = 2;
//                cout << "Wound" << endl;
//                live--;
//            }
//            else if (sea_bot[x][y] == 1 && live == 1) // ��������: ������� ���������
//            {
//                sea_bot[x][y] = 2;
//                cout << "Destroy" << endl;
//                mode = 0;
//                live = 0;
//            }
//            else
//            {
//                sea_bot[x][y] = 3;
//                if (!dirs.empty())
//                {
//                    direction = dirs[dirs.size() - 1];
//                    dirs.pop_back();
//                }
//                x = first_hit_x; 
//                y = first_hit_y;
//                // ��� continue ������ ��� ��� ������
//                cout << "Miss" << endl;
//            }
//
//
//        }
//        for (int i = 0; i < SIZE; i++)
//        {
//            for (int j = 0; j < SIZE; j++)
//            {
//                cout << sea_bot[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    } while (live != 0);
//
//}