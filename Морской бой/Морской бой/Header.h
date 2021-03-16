//#pragma once
//
////индексы кораблей
//extern int ship_index_comp;
////Записываем в массив наши корабли и дальше используем для проверки: убит корабль или ранен
//extern int ships_comp[11];
//
//extern int ship_index_human;
//extern int ships_human[11];
//
//extern const char* Fileplace;
//
//void SetCoordinates(int x, int y);
//
//void enter_ship(int field[10][10], int SIZE, int ships_lenght, int comp_or_human);
//
//void Continue(int field[10][10], int second_field[10][10], int SIZE);
//
//void save_game(int field[10][10], int second_field[10][10], int SIZE);
//
//int set_ship(int field[10][10], int SIZE, int x, int y, int ships_lenght, int direction, int comp_or_human);
//
//int stays_on_board(int x, int y, int SIZE, int direction, int ships_lenght); // Проверка, чтобы не выходил за границу
//
//void hand_placing_ship(int x, int y, int direction, int ships_lenght); // Ручная расстановка кораблей
//
//int shoot(int field[10][10], int x, int y, int comp_or_human);
//
//void print(int field[10][10], int SIZE, int want_see_my_ships);
//
//void second_print(int second_field[10][10], int SIZE, int want_see_my_ships);
//
//int win_or_not(int SIZE, int destroy, int victory, int comp_or_human);
//
//void skull();
//
//enum ConsoleColor
//{
//    Black = 0,
//    Blue = 1,
//    Green = 2,
//    Cyan = 3,
//    Red = 4,
//    Magenta = 5,
//    Brown = 6,
//    LightGray = 7,
//    DarkGray = 8,
//    LightBlue = 9,
//    LightGreen = 10,
//    LightCyan = 11,
//    LightRed = 12,
//    LightMagenta = 13,
//    Yellow = 14,
//    White = 15
//
//};
//
//void SetColor(ConsoleColor text, ConsoleColor background);
//
