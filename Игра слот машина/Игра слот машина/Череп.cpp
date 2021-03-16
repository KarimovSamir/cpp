//#include <iostream>
//#include <time.h>
//#include <windows.h>
//using namespace std;
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
//void SetColor(ConsoleColor text, ConsoleColor background)
//{
//    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
//}
//
//void SetCoordinates(int x, int y)
//{
//    COORD coord;
//    coord.X = x;
//    coord.Y = y;
//    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//int GetWidth()
//{
//    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
//    return consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
//}
//
//int GetHeight()
//{
//    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
//    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleInfo);
//    return consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
//}
//
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    srand(time(NULL));
//    
//
    //*cout << "      *****************      " << endl;
    //cout << "     *******************     " << endl;;
    //cout << "     *******************     " << endl;
    //cout << "     ****    ***    ****     " << endl;
    //cout << "     ****    ***    ****     " << endl;
    //cout << "     ****    ***    ****     " << endl;
    //cout << "          **     **      " << endl;
    //cout << "          **     **      " << endl;
    //cout << "           *******       " << endl;
    //cout << "       ***************   " << endl;
    //cout << "     **               **     " << endl;
    //cout << "     **               **     " << endl;
    //cout << "     **               **     " << endl;
    //cout << "       ***************   " << endl;
    //cout << "   **                   **   " << endl;
    //cout << " ********           ******** " << endl;
    //cout << "     ********    ********     " << endl;
    //cout << "             ****             " << endl;
    //cout << "     ********    ********     " << endl;
    //cout << " ********           ******** " << endl;
    //cout << "   **                   **   " << endl;*/
//    
//        
//        
//        
//                                      
//
//
//
//
//    SetCoordinates(7, 11);
//    cout << "| 6 |" << endl;
//    SetCoordinates(12, 11);
//    cout << "| 7 |" << endl;
//    SetCoordinates(17, 11);
//    cout << "| 8 |" << endl;
//    SetCoordinates(0, 25);
//}