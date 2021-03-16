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
//    dirs.push_back(3);//вниз
//    dirs.push_back(2);//вверх
//    dirs.push_back(1);//вправо
//    dirs.push_back(0);//влево
//
//    do
//    {
//        if (mode == 0) //рандом
//        {
//            x = rand() % SIZE;
//            y = rand() % SIZE;
//
//            if (sea_bot[x][y] == 1)
//            {
//                mode = 1; //переход в mode=1 при попадании, короче продолжит стрелять
//                sea_bot[x][y] = 2;
//                first_hit_x = x;
//                first_hit_y = y;
//                live--;
//
//                if (!dirs.empty()) // если не пустой, то берём элемент, а потом удаляем
//                {
//                    direction = dirs[dirs.size() - 1]; // получаем доступ к последному элементу, получаем индекс последнего элемента вектора
//                    dirs.pop_back(); // удаляем последний элемент
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
//            if (direction == 0) // Влево
//            {
//                if (x > 0)
//                {
//                    x--; //движение влево
//                }
//                else
//                {
//                    change_direction = true;
//                }
//            }
//            else if(direction == 1) //вправо
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
//            else if (direction == 2) //вверх
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
//            else if (direction == 3) //вниз
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
//                // меняем направление при достижении границы
//                    // если корабль у границы, то бот не будет стрелять вне границ, 
//                    // а сразу переключится на другую сторону, иначе он выстрелит вне границу
//                    // и тем самым пропустит ход
//                if (!dirs.empty())
//                {
//                    direction = dirs[dirs.size() - 1];
//                    dirs.pop_back();
//                }
//                x = first_hit_x; //возврат в исходную позицию
//                y = first_hit_y;
//                continue; // переход в начало цикла
//            }
//
//
//            if (sea_bot[x][y] == 1 && live > 1) // проверка: корабль ранен
//            {
//                
//                sea_bot[x][y] = 2;
//                cout << "Wound" << endl;
//                live--;
//            }
//            else if (sea_bot[x][y] == 1 && live == 1) // проверка: корабль уничтожен
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
//                // без continue потому что это промах
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