#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include "SeaShip.h"
using namespace std;

void SetCoordinates(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord);
}

// Функция стрельбы
int shoot(int field[10][10], int x, int y, int comp_or_human)
{
    int count = 0;
    if (field[x][y] == -1 || field[x][y] == -2) //проверка для бота, если бот попал или промахнулся, он будет снова рандомить координаты
    {                                           // чтобы повторно не стрелять в одно место
        count = 3;
    }
    //если содержимое ячейки больше или равно 1 значит там есть корабль
    else if (field[x][y] >= 1)
    {

        if (comp_or_human == 1)
        {
            //Уменьшаем масиив, уйдут те индексы, корабли которых ранены или убиты
            ships_comp[field[x][y]]--;

            if (ships_comp[field[x][y]] == 0)
            {
                count = 2; //Если корабль убит
            }
            else
            {
                count = 1; //Если корабль ранен
            }
            //Для данном значении массива, в выводе будет Х, то есть помечаем подбитые или убитые корабли 
            field[x][y] = -1;
        }
        else if (comp_or_human == 2)
        {
            ships_human[field[x][y]]--;

            if (ships_human[field[x][y]] == 0)
            {
                count = 2; //Если корабль убит
            }
            else
            {
                count = 1; //Если корабль ранен
            }
            //Для данном значении массива, в выводе будет Х, то есть помечаем подбитые или убитые корабли 
            field[x][y] = -1;
        }
    }
    else // бот попадает сюда при промахе
    {
        field[x][y] = -2; // помечаем ячейки с промахом
    }
    return count;
}

// Случайная расстановка кораблей
void enter_ship(int field[10][10], int SIZE, int ships_lenght, int comp_or_human)
{
    int direction = 0;
    int count_ship = 0;
    int count_tact = 0;
    while (count_ship < 1)
    {
        count_tact++;
        if (count_tact > 500)
        {
            break;
        }
        // начальная позиция для корабля
        int x = rand() % SIZE;
        int y = rand() % SIZE;

        //перезаписываем координаты (так нужно :) )
        int temp_x = x;
        int temp_y = y;

        //рандомно выбирает направление
        direction = rand() % 4;
        bool set_possible = 1;

        //Проверка: можно ли поставить корабль
        for (int i = 0; i < ships_lenght; i++)
        {
            //Проверка: выходит ли за пределы поля
            if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
            {
                set_possible = 0;
                break;
            }

            //Проверка: проверяет чтобы вокруг корабля были пустые поля
            if (field[x][y] >= 1 || field[x][y + 1] >= 1 || field[x][y - 1] >= 1 ||
                field[x + 1][y] >= 1 || field[x + 1][y + 1] >= 1 || field[x + 1][y - 1] >= 1 ||
                field[x - 1][y] >= 1 || field[x - 1][y + 1] >= 1 || field[x - 1][y - 1] >= 1)
            {
                set_possible = 0;
                break;
            }

            //изменение координат (x,y) в зависимости от направления (чтобы корабли не стояли рядом или не исчезали за полем)
            switch (direction)
            {
            case 0:
                x++; //напрво
                break;
            case 1:
                y++; //вниз
                break;
            case 2:
                x--; //влево
                break;
            case 3:
                y--; //вверх
                break;
            }
        }

        //если можно поставить корабль
        if (set_possible == 1)
        {
            //вот для этого мы перезаписали координаты, иначе проверку границ мы пройдём, 
            //но ставится корабль будет на изменённых координатах, поэтому даём им изначальное значение
            x = temp_x;
            y = temp_y;

            //по рандомному направлению ставим корабль в выбранном направлении
            for (int i = 0; i < ships_lenght; i++)
            {
                if (comp_or_human == 1)
                {
                    field[x][y] = ship_index_comp;
                }
                else if (comp_or_human == 2)
                {
                    field[x][y] = ship_index_human;
                }

                switch (direction)
                {
                case 0:
                    x++;
                    break;
                case 1:
                    y++;
                    break;
                case 2:
                    x--;
                    break;
                case 3:
                    y--;
                    break;
                }
            }
            // Сохраняет размер корабля в массив ships
            if (comp_or_human == 1)
            {
                ships_comp[ship_index_comp] = ships_lenght;
                ship_index_comp++;
                count_ship++;
            }
            else if (comp_or_human == 2)
            {
                ships_human[ship_index_human] = ships_lenght;
                ship_index_human++;
                count_ship++;
            }
        }
    }
}

// Поставить корабль на поле
int set_ship(int field[10][10], int SIZE, int x, int y, int ships_lenght, int direction, int comp_or_human)
{
    int temp_x = x;
    int temp_y = y;

    bool set_possible = 1;
    //Проверка: можно ли поставить корабль
    for (int i = 0; i < ships_lenght; i++)
    {
        //Проверка: выходит ли за пределы поля
        if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
        {
            set_possible = 0;
            break;
        }

        // Данная проверка проверяет, окажется ли x или y в пределах поля после того как увеличится или уменьшится
        // Без данной проверки возникала проблема, не получалось ставить корабли на границе поля
        // Старая проверка не работала корректно, так как x или y увеличивались на единицу, когда мы хотели поставить корабль на край поля
        // И наш значение массива выходило за пределы поля
        if (field[x][y] >= 1)
        {
            set_possible = 0;
            break;
        }

        if (y < SIZE - 1)
        {
            if (field[x][y + 1] >= 1)
            {
                set_possible = 0;
                break;
            }
        }

        if (y > 0)
        {
            if (field[x][y - 1] >= 1)
            {
                set_possible = 0;
                break;
            }
        }

        if (x < SIZE - 1)
        {
            if (field[x + 1][y] >= 1)
            {
                set_possible = 0;
                break;
            }
        }

        if (x < SIZE - 1 && y < SIZE - 1)
        {
            if (field[x + 1][y + 1] >= 1)
            {
                set_possible = 0;
                break;
            }
        }

        if (x < SIZE - 1 && y > 0)
        {
            if (field[x + 1][y - 1] >= 1)
            {
                set_possible = 0;
                break;
            }
        }

        if (x > 0)
        {
            if (field[x - 1][y] >= 1)
            {
                set_possible = 0;
                break;
            }
        }

        if (x > 0 && y < SIZE - 1)
        {
            if (field[x - 1][y + 1] >= 1)
            {
                set_possible = 0;
                break;
            }
        }

        if (x > 0 && y > 0)
        {
            if (field[x - 1][y - 1] >= 1)
            {
                set_possible = 0;
                break;
            }
        }

        //изменение координат (x,y) в зависимости от направления (чтобы корабли не стояли рядом или не исчезали за полем)
        switch (direction)
        {
        case 0:
            x++; //напрво
            break;
        case 1:
            y++; //вниз
            break;
        case 2:
            x--; //влево
            break;
        case 3:
            y--; //вверх
            break;
        }
    }

    //если можно поставить корабль
    if (set_possible == 1)
    {
        //вот для этого мы перезаписали координаты, иначе проверку границ мы пройдём, 
        //но ставится корабль будет на изменённых координатах, поэтому даём им изначальное значение
        x = temp_x;
        y = temp_y;

        //по рандомному направлению ставим корабль в выбранном направлении
        for (int i = 0; i < ships_lenght; i++)
        {
            if (comp_or_human == 1)
            {
                field[x][y] = ship_index_comp;
            }
            else if (comp_or_human == 2)
            {
                field[x][y] = ship_index_human;
            }

            switch (direction)
            {
            case 0:
                x++;
                break;
            case 1:
                y++;
                break;
            case 2:
                x--;
                break;
            case 3:
                y--;
                break;
            }
        }
        // Сохраняет размер корабля в массив ships
        if (comp_or_human == 1)
        {
            ships_comp[ship_index_comp] = ships_lenght;
            ship_index_comp++;
        }
        else if (comp_or_human == 2)
        {
            ships_human[ship_index_human] = ships_lenght;
            ship_index_human++;
        }
    }
    return set_possible;
}

// Проверка, чтобы корабль не выходил за борт
int stays_on_board(int x, int y, int SIZE, int direction, int ships_lenght) // Проверка, чтобы не выходил за границу
{
    bool on_board = 1;

    //Проверка: можно ли поставить корабль
    for (int i = 0; i < ships_lenght; i++)
    {
        //Проверка: выходит ли за пределы поля
        if (x < 0 || y < 0 || x >= SIZE || y >= SIZE)
        {
            on_board = 0;
            break;
        }

        //изменение координат (x,y) в зависимости от направления (чтобы корабли не стояли рядом или не исчезали за полем)
        switch (direction)
        {
        case 0:
            x++; //напрво
            break;
        case 1:
            y++; //вниз
            break;
        case 2:
            x--; //влево
            break;
        case 3:
            y--; //вверх
            break;
        }
    }
    return on_board;
}

// Ручная расстановка кораблей
void hand_placing_ship(int x, int y, int direction, int ships_lenght)
{
    char ship = 254;
    //Изменение направления
    for (int i = 0; i < ships_lenght; i++)
    {
        //Плюс к координатам, чтобы не вылез за пределы поля при х = 0 или y = 0 
        SetCoordinates(x + 13, y + 6);

        cout << ship;
        switch (direction)
        {
        case 0:
            x += 2;
            break;
        case 1:
            y++;
            break;
        case 2:
            x -= 2;
            break;
        case 3:
            y--;
            break;
        }
    }
}

// Сохранение игры
void save_game(int field[10][10], int second_field[10][10], int SIZE)
{
    int a;
    int b;
    FILE* fb;
    fopen_s(&fb, Fileplace, "wb");

    //fwrite(&field, sizeof(field[0][0]), SIZE, fd);
    //fwrite(&second_field, sizeof(second_field[0][0]), SIZE, fd);

    int l = 0;
    fwrite(&l, sizeof(int), 1, fb);
    for (int i = 0; i < 11; i++)
    {
        a = ships_comp[i];
        b = ships_human[i];
        fwrite(&a, sizeof(a), 1, fb);
        fwrite(&b, sizeof(b), 1, fb);
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            a = field[i][j];
            b = second_field[i][j];
            fwrite(&a, sizeof(a), 1, fb);
            fwrite(&b, sizeof(b), 1, fb);
        }
    }
    fclose(fb);
}

// Продолжение игры
void Continue(int field[10][10], int second_field[10][10], int SIZE)
{
    int a;
    int b;
    FILE* fd;
    fopen_s(&fd, "file.bin", "rb");
    fread(&a, sizeof(int), 1, fd);
    for (int i = 0; i < 11; i++)
    {
        fread(&a, sizeof(int), 1, fd);
        fread(&b, sizeof(int), 1, fd);
        ships_comp[i] = a;
        ships_human[i] = b;
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            fread(&a, sizeof(int), 1, fd);
            fread(&b, sizeof(int), 1, fd);
            
            field[i][j] = a;
            second_field[i][j] = b;
        }
    }
    fclose(fd);
}

// Вывод первого поля
void print(int field[10][10], int SIZE, int want_see_my_ships)
{
    SetCoordinates(25, 2);
    cout << "Galactic battle of ships";
    char ship = 254;
    char miss = 177;
    char letter = 65;
    int count1 = 10;
    int count2 = 5;

    SetCoordinates(count1, count2);
    cout << "  ";
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {
            cout << "|" << letter << "|";
        }
        else
        {
            cout << "|" << letter;
        }
        letter++;
    }

    //count1++;
    count2++;

    SetCoordinates(count1, count2);

    for (int i = 0; i < SIZE; i++) // number
    {
        SetCoordinates(count1, count2);
        if (i < 9) { cout << " "; }
        cout << i + 1;

        for (int j = 0; j < SIZE; j++) // letter
        {
                if (field[j][i] == 0) // Выводим прочерк на если поле пустое
                {
                    cout << "|" << " ";
                    if (j == SIZE - 1)
                    {
                        cout << "|";
                    }

                }
                else if (field[j][i] == -1)
                {
                    cout << "|" << "X";
                    if (j == SIZE - 1)
                    {
                        cout << "|";
                    }
                }
                else if (field[j][i] == -2)
                {
                    cout << "|" << miss;

                    if (j == SIZE - 1)
                    {
                        cout << "|";
                    }
                }
                else
                {
                    if (want_see_my_ships == 1)
                    {
                        if (j == SIZE - 1)
                        {
                            cout << "|" << " " << "|";
                        }
                        else
                        {
                            cout << "|" << " ";
                        }
                    }
                    else
                    {
                        if (j == SIZE - 1)
                        {
                            cout << "|" << ship << "|";
                        }
                        else
                        {
                            cout << "|" << ship;
                        }
                    }
                }
            
            
            letter++;

        }
        cout << endl;
        //count1++;
        count2++;
    }
}

// Вывод второго поля
void second_print(int second_field[10][10], int SIZE, int want_see_my_ships)
{
    char ship = 254;
    char miss = 177;
    char letter = 65;
    int count1 = 40;
    int count2 = 5;
    //Ставим цифры перед полем
    SetCoordinates(count1, count2);
    cout << "  ";
    for (int i = 0; i < SIZE; i++)
    {
        if (i == SIZE - 1)
        {
            cout << "|" << letter << "|";
        }
        else
        {
            cout << "|" << letter;
        }
        letter++;
    }
    //count1++;
    count2++;
    //cout << endl;
    SetCoordinates(count1, count2);
    //count++;
    for (int i = 0; i < SIZE; i++) // number
    {
        SetCoordinates(count1, count2);
        if (i < 9) { cout << " "; }
        cout << i + 1;

        for (int j = 0; j < SIZE; j++) // letter
        {
            
                if (second_field[j][i] == 0) // Если поле пустое
                {
                    cout << "|" << " ";
                    if (j == SIZE - 1)
                    {
                        cout << "|";
                    }

                }
                else if (second_field[j][i] == -1) // Если ранен или убит                
                {
                    cout << "|" << "X";
                    if (j == SIZE - 1)
                    {
                        cout << "|";
                    }
                }
                else if (second_field[j][i] == -2) // Если промах
                {
                    cout << "|" << miss;

                    if (j == SIZE - 1)
                    {
                        cout << "|";
                    }
                }
                else
                {
                    if (want_see_my_ships == 1)
                    {
                        if (j == SIZE - 1)
                        {
                            cout << "|" << " " << "|";
                        }
                        else
                        {
                            cout << "|" << " ";
                        }
                    }
                    else
                    {
                        if (j == SIZE - 1)
                        {
                            cout << "|" << ship << "|";
                        }
                        else
                        {
                            cout << "|" << ship;
                        }
                    }
                }
            
            
            letter++;
        }
        cout << endl;
        //count1++;
        count2++;
    }
}

// Проверка на победу
int win_or_not(int SIZE, int destroy, int victory, int comp_or_human)
{
    for (int i = 1; i < SIZE + 1; i++)
    {
        if (comp_or_human == 1)
        {
            if (ships_human[i] != 0)
            {
                destroy = 0;
                break;
            }
        }
        else if (comp_or_human == 2)
        {
            if (ships_comp[i] != 0)
            {
                destroy = 0;
                break;
            }
        }
    }
    if (destroy == 1)
    {
        victory = 1; //проверка на победу
        FILE* fb;
        fopen_s(&fb, Fileplace, "rb+");
        int l = 1;
        fwrite(&l, sizeof(int), 1, fb);
        fclose(fb);
        fb = nullptr;
    }
    return victory;
}

void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

// Мой любимый череп из домашки, где я делал игру "Кости" (Я ДЕЛАЛ ЕГО НЕ ПРОСТО ТАК!!!)
void skull()
{
    SetCoordinates(35, 4);
    cout << "      *****************      " << endl;
    SetCoordinates(35, 5);
    cout << "     *******************     " << endl;
    SetCoordinates(35, 6);
    cout << "     *******************     " << endl;
    SetCoordinates(35, 7);
    cout << "     ****";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "***";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "****     " << endl;
    SetCoordinates(35, 8);
    cout << "     ****";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "***";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "****     " << endl;
    SetCoordinates(35, 9);
    cout << "     ****";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "***";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "****     " << endl;
    SetCoordinates(35, 10);
    cout << "          **     **      " << endl;
    SetCoordinates(35, 11);
    cout << "          **     **      " << endl;
    SetCoordinates(35, 12);
    cout << "           *******       " << endl;
    SetCoordinates(35, 13);
    cout << "       ***************   " << endl;
    SetCoordinates(35, 14);
    cout << "     **               **     " << endl;
    SetCoordinates(35, 15);
    cout << "     **               **     " << endl;
    SetCoordinates(35, 16);
    cout << "     **               **     " << endl;
    SetCoordinates(35, 17);
    cout << "       ***************   " << endl;
    SetCoordinates(35, 18);
    cout << "   **                   **   " << endl;
    SetCoordinates(35, 19);
    cout << " ********           ******** " << endl;
    SetCoordinates(35, 20);
    cout << "     ********    ********     " << endl;
    SetCoordinates(35, 21);
    cout << "             ****             " << endl;
    SetCoordinates(35, 22);
    cout << "     ********    ********     " << endl;
    SetCoordinates(35, 23);
    cout << " ********           ******** " << endl;
    SetCoordinates(35, 24);
    cout << "   **                   **   " << endl;
}