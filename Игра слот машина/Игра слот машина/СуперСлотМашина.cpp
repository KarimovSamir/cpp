#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15

};

void SetColor(ConsoleColor text, ConsoleColor background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

void SetCoordinates(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int GetWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
    return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
}

int GetHeight()
{
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
    return consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
}

void main()
{
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int i;
    char b;
    int bank;
    SetCoordinates(15, 0);
    cout << "      *****************      " << endl;
    SetCoordinates(15, 1);
    cout << "     *******************     " << endl;
    SetCoordinates(15, 2);
    cout << "     *******************     " << endl;
    SetCoordinates(15, 3);
    cout << "     ****";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "***";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "****     " << endl;
    SetCoordinates(15, 4);
    cout << "     ****";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "***";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "****     " << endl;
    SetCoordinates(15, 5);
    cout << "     ****";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "***";
    SetColor(Red, Red);
    cout << "    ";
    SetColor(White, Black);
    cout << "****     " << endl;
    SetCoordinates(15, 6);
    cout << "          **     **      " << endl;
    SetCoordinates(15, 7);
    cout << "          **     **      " << endl;
    SetCoordinates(15, 8);
    cout << "           *******       " << endl;
    SetCoordinates(15, 9);
    cout << "       ***************   " << endl;
    SetCoordinates(15, 10);
    cout << "     **               **     " << endl;
    SetCoordinates(15, 11);
    cout << "     **               **     " << endl;
    SetCoordinates(15, 12);
    cout << "     **               **     " << endl;
    SetCoordinates(15, 13);
    cout << "       ***************   " << endl;
    SetCoordinates(15, 14);
    cout << "   **                   **   " << endl;
    SetCoordinates(15, 15);
    cout << " ********           ******** " << endl;
    SetCoordinates(15, 16);
    cout << "     ********    ********     " << endl;
    SetCoordinates(15, 17);
    cout << "             ****             " << endl;
    SetCoordinates(15, 18);
    cout << "     ********    ********     " << endl;
    SetCoordinates(15, 19);
    cout << " ********           ******** " << endl;
    SetCoordinates(15, 20);
    cout << "   **                   **   " << endl;
    SetCoordinates(55, 4);
    cout << "Сыграем на твою душу человек";
    SetCoordinates(51, 5);
    cout << "Сколько денег ты принёс со своего мира?" << endl;
    SetCoordinates(68, 6);
    cin >> bank;

    do
    {
        system("cls");
        int stavka;
        int a[3];
        int j;

        for (int i = 0; i < 3; i++)
        {
            a[i] = rand() % 10;
        }

    line1:

        SetCoordinates(15, 0);
        cout << "      *****************      " << endl;
        SetCoordinates(15, 1);
        cout << "     *******************     " << endl;
        SetCoordinates(15, 2);
        cout << "     *******************     " << endl;
        SetCoordinates(15, 3);
        cout << "     ****";
        SetColor(Red, Red);
        cout << "    ";
        SetColor(White, Black);
        cout << "***";
        SetColor(Red, Red);
        cout << "    ";
        SetColor(White, Black);
        cout << "****     " << endl;
        SetCoordinates(15, 4);
        cout << "     ****";
        SetColor(Red, Red);
        cout << "    ";
        SetColor(White, Black);
        cout << "***";
        SetColor(Red, Red);
        cout << "    ";
        SetColor(White, Black);
        cout << "****     " << endl;
        SetCoordinates(15, 5);
        cout << "     ****";
        SetColor(Red, Red);
        cout << "    ";
        SetColor(White, Black);
        cout << "***";
        SetColor(Red, Red);
        cout << "    ";
        SetColor(White, Black);
        cout << "****     " << endl;
        SetCoordinates(15, 6);
        cout << "          **     **      " << endl;
        SetCoordinates(15, 7);
        cout << "          **     **      " << endl;
        SetCoordinates(15, 8);
        cout << "           *******       " << endl;
        SetCoordinates(15, 9);
        cout << "       ***************   " << endl;
        SetCoordinates(15, 10);
        cout << "     **               **     " << endl;
        SetCoordinates(15, 11);
        cout << "     **               **     " << endl;
        SetCoordinates(15, 12);
        cout << "     **               **     " << endl;
        SetCoordinates(15, 13);
        cout << "       ***************   " << endl;
        SetCoordinates(15, 14);
        cout << "   **                   **   " << endl;
        SetCoordinates(15, 15);
        cout << " ********           ******** " << endl;
        SetCoordinates(15, 16);
        cout << "     ********    ********     " << endl;
        SetCoordinates(15, 17);
        cout << "             ****             " << endl;
        SetCoordinates(15, 18);
        cout << "     ********    ********     " << endl;
        SetCoordinates(15, 19);
        cout << " ********           ******** " << endl;
        SetCoordinates(15, 20);
        cout << "   **                   **   " << endl;


        if (bank == 0)
        {
            SetCoordinates(55, 5);
            cout << "Ты банкрот. Теперь твоя душа моя!!!";
            SetCoordinates(55, 21);
            break;
        }

        SetCoordinates(64, 5);
        cout << "Твоя ставка?" << endl;
        SetCoordinates(69, 6);
        cin >> stavka;
        if (stavka <= 0)
        {
            SetCoordinates(45, 7);
            cout << "Глупец! Нельзя ничего не ставить или ставить минус ставку";
            Sleep(1000);
            system("cls");
            goto line1;
        }
        if (bank < stavka)
        {
            SetCoordinates(51, 7);
            cout << "Ты меня не обманешь! Твоя ставка больше твоих денег";
            Sleep(1000);
            system("cls");
            goto line1;
        }

        SetCoordinates(22, 11);
        for (j = 0; j < 3; j++)
        {
            if (a[j] == 0)
            {
                cout << "|";
                SetColor(White, Blue);
                cout << " @ ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 1)
            {
                cout << "|";
                SetColor(White, Green);
                cout << " & ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 2)
            {
                cout << "|";
                SetColor(White, Red);
                cout << " 7 ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 3)
            {
                cout << "|";
                SetColor(White, Cyan);
                cout << " 0 ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 4)
            {
                cout << "|";
                SetColor(White, Magenta);
                cout << " * ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 5)
            {
                cout << "|";
                SetColor(White, Brown);
                cout << " # ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 6)
            {
                cout << "|";
                SetColor(Black, Yellow);
                cout << " $ ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 7)
            {
                cout << "|";
                SetColor(Black, LightCyan);
                cout << " ^ ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 8)
            {
                cout << "|";
                SetColor(White, DarkGray);
                cout << " ! ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }
            if (a[j] == 9)
            {
                cout << "|";
                SetColor(White, LightRed);
                cout << " ~ ";
                SetColor(White, Black);
                cout << "|";
                Sleep(1000);
            }

        }

        if (a[0] == 2 and a[1] == 2 and a[2] == 2)
        {
            bank += stavka * 5;
        }

        else if (a[0] == a[1] and a[0] == a[2])
        {
            bank += stavka * 3;
        }

        else if (a[0] == a[1] or a[0] == a[2] or a[1] == a[2])
        {
            bank += stavka * 2;
        }

        else if (a[0] == 2 or a[1] == 2 or a[2] == 2)
        {
            bank = bank;
        }

        else if (a[0] != a[1] and a[0] != a[2] and a[1] != a[2] and a[0] != 2 and a[1] != 2 and a[2] != 2)
        {
            bank -= stavka;
        }

        SetCoordinates(59, 9);
        cout << "Твой жалкий остаток: " << bank << endl;
        SetCoordinates(53, 11);
        cout << "Продолжишь свои жалкие попытки? Y/N" << endl;
        SetCoordinates(69, 12);
        cin >> b;
        SetCoordinates(55, 21);
    } while (b == 'Y' || b == 'y');
    {
    }
    
}