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

void main()
{
	system("cls");
	setlocale(LC_ALL, "Russian");
	int a;
	int m = 0; //??????? ?????????? ???????
	//?????????? ?????? ??? ????????
	//1) 3
	//2) 2
	//3) 2
	//4) 2
	//5) 3
	//6) 3
	//7) 4
	//8) 4
	//9) 3
	//10) 2
	//11) 2
	//12) 3

	// 1 ??????
	cout << "1.????????? ? ";
	cout << "\n1) ?????? ??????????, ? ??????? ????????? ????? ??? ????? ????.";
	cout << "\n2) ?????? ??????????, ? ??????? ????????? ?????????? ???? ? ?????????????? ? ???????????.";
	cout << "\n3) ?????? ????? ? ?????, ? ??????? ????????? ???????? ????, ?? ????????? ? ??????????.";
	cout << "\n4) ?????? ????? ? ?????, ? ??????? ????????? ?????? ?????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "1.????????? ? ";
		SetColor(White, Red);
		cout << "\n1) ?????? ??????????, ? ??????? ????????? ????? ??? ????? ????.";
		SetColor(White, Black);
		cout <<	"\n2) ?????? ??????????, ? ??????? ????????? ?????????? ???? ? ?????????????? ? ???????????.";
		cout << "\n3) ?????? ????? ? ?????, ? ??????? ????????? ???????? ????, ?? ????????? ? ??????????.";
		cout << "\n4) ?????? ????? ? ?????, ? ??????? ????????? ?????? ?????." << endl;
	}
	else if (a == 2)
	{
		cout << "1.????????? ? ";
		cout << "\n1) ?????? ??????????, ? ??????? ????????? ????? ??? ????? ????.";
		SetColor(White, Red);
		cout << "\n2) ?????? ??????????, ? ??????? ????????? ?????????? ???? ? ?????????????? ? ???????????.";
		SetColor(White, Black);
		cout << "\n3) ?????? ????? ? ?????, ? ??????? ????????? ???????? ????, ?? ????????? ? ??????????.";
		cout << "\n4) ?????? ????? ? ?????, ? ??????? ????????? ?????? ?????." << endl;
	}
	else if (a == 3)
	{
		cout << "1.????????? ? ";
		cout << "\n1) ?????? ??????????, ? ??????? ????????? ????? ??? ????? ????.";
		cout << "\n2) ?????? ??????????, ? ??????? ????????? ?????????? ???? ? ?????????????? ? ???????????.";
		SetColor(White, Green);
		cout << "\n3) ?????? ????? ? ?????, ? ??????? ????????? ???????? ????, ?? ????????? ? ??????????.";
		SetColor(White, Black);
		cout << "\n4) ?????? ????? ? ?????, ? ??????? ????????? ?????? ?????." << endl;
		m++;
	}
	else if (a == 4)
	{
		cout << "1.????????? ? ";
		cout << "\n1) ?????? ??????????, ? ??????? ????????? ????? ??? ????? ????.";
		cout << "\n2) ?????? ??????????, ? ??????? ????????? ?????????? ???? ? ?????????????? ? ???????????.";
		cout << "\n3) ?????? ????? ? ?????, ? ??????? ????????? ???????? ????, ?? ????????? ? ??????????.";
		SetColor(White, Red);
		cout << "\n4) ?????? ????? ? ?????, ? ??????? ????????? ?????? ?????." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 2 ??????
	cout << "2.?????????????? ? ";
	cout << "\n1) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????.";
	cout << "\n2) ????????? ???? ? ????? ?????????????? ????, ????????? ?? ?????? ? ?????????????.";
	cout << "\n3) ??????? ?? ???? ??????? ?????? ???????????.";
	cout << "\n4) ??????? ?? ???????? ??????????? ? ???????????? ???????????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "2.?????????????? ? ";
		SetColor(White, Red);
		cout << "\n1) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????.";
		SetColor(White, Black);
		cout << "\n2) ????????? ???? ? ????? ?????????????? ????, ????????? ?? ?????? ? ?????????????.";
		cout << "\n3) ??????? ?? ???? ??????? ?????? ???????????.";
		cout << "\n4) ??????? ?? ???????? ??????????? ? ???????????? ???????????." << endl;
	}
	else if (a == 2)
	{
		cout << "2.?????????????? ? ";
		cout << "\n1) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????.";
		SetColor(White, Green);
		cout << "\n2) ????????? ???? ? ????? ?????????????? ????, ????????? ?? ?????? ? ?????????????.";
		SetColor(White, Black);
		cout << "\n3) ??????? ?? ???? ??????? ?????? ???????????.";
		cout << "\n4) ??????? ?? ???????? ??????????? ? ???????????? ???????????." << endl;
		m++;
	}
	else if (a == 3)
	{
		cout << "2.?????????????? ? ";
		cout << "\n1) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????.";
		cout << "\n2) ????????? ???? ? ????? ?????????????? ????, ????????? ?? ?????? ? ?????????????.";
		SetColor(White, Red);
		cout << "\n3) ??????? ?? ???? ??????? ?????? ???????????.";
		SetColor(White, Black);
		cout << "\n4) ??????? ?? ???????? ??????????? ? ???????????? ???????????." << endl;
	}
	else if (a == 4)
	{
		cout << "2.?????????????? ? ";
		cout << "\n1) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????.";
		cout << "\n2) ????????? ???? ? ????? ?????????????? ????, ????????? ?? ?????? ? ?????????????.";
		cout << "\n3) ??????? ?? ???? ??????? ?????? ???????????.";
		SetColor(White, Red);
		cout << "\n4) ??????? ?? ???????? ??????????? ? ???????????? ???????????." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 3 ??????
	cout << "3.??????? ??????????? ? ";
	cout << "\n1) ??????? ?? ???? ??? ?????????? ?????????? ?????? ???????????.";
	cout << "\n2) ??????? ?? ???? ??? ?????????? ??????? ???????????.";
	cout << "\n3) ??????? ?? ???? ??? ?????????? ?????????? ????????.";
	cout <<	"\n4) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "3.??????? ??????????? ? ";
		SetColor(White, Red);
		cout << "\n1) ??????? ?? ???? ??? ?????????? ?????????? ?????? ???????????.";
		SetColor(White, Black);
		cout << "\n2) ??????? ?? ???? ??? ?????????? ??????? ???????????.";
		cout << "\n3) ??????? ?? ???? ??? ?????????? ?????????? ????????.";
		cout << "\n4) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????." << endl;
	}
	else if (a == 2)
	{
		cout << "3.??????? ??????????? ? ";
		cout << "\n1) ??????? ?? ???? ??? ?????????? ?????????? ?????? ???????????.";
		SetColor(White, Green);
		cout << "\n2) ??????? ?? ???? ??? ?????????? ??????? ???????????.";
		SetColor(White, Black);
		cout << "\n3) ??????? ?? ???? ??? ?????????? ?????????? ????????.";
		cout << "\n4) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????." << endl;
		m++;
	}
	else if (a == 3)
	{
		cout << "3.??????? ??????????? ? ";
		cout << "\n1) ??????? ?? ???? ??? ?????????? ?????????? ?????? ???????????.";
		cout << "\n2) ??????? ?? ???? ??? ?????????? ??????? ???????????.";
		SetColor(White, Red);
		cout << "\n3) ??????? ?? ???? ??? ?????????? ?????????? ????????.";
		SetColor(White, Black);
		cout << "\n4) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????." << endl;
	}
	else if (a == 4)
	{
		cout << "3.??????? ??????????? ? ";
		cout << "\n1) ??????? ?? ???? ??? ?????????? ?????????? ?????? ???????????.";
		cout << "\n2) ??????? ?? ???? ??? ?????????? ??????? ???????????.";
		cout << "\n3) ??????? ?? ???? ??? ?????????? ?????????? ????????.";
		SetColor(White, Red);
		cout << "\n4) ??????? ?? ?????? ??? ?????????? ???? ,??????????????? ????????????? ??????????????." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 4 ??????
	cout << "4.??????? ??????????? ? ??????? ???????? ?????????? ???? ?? ?????";
	cout << "\n1) ???????.";
	cout << "\n2) ????????.";
	cout << "\n3) ?????????????? ??????.";
	cout << "\n4) ??????????????? ??????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "4.??????? ??????????? ? ??????? ???????? ?????????? ???? ?? ?????";
		SetColor(White, Red);
		cout << "\n1) ???????.";
		SetColor(White, Black);
		cout << "\n2) ????????.";
		cout << "\n3) ?????????????? ??????.";
		cout << "\n4) ??????????????? ??????." << endl;
	}
	else if (a == 2)
	{
		cout << "4.??????? ??????????? ? ??????? ???????? ?????????? ???? ?? ?????";
		cout << "\n1) ???????.";
		SetColor(White, Green);
		cout << "\n2) ????????.";
		SetColor(White, Black);
		cout << "\n3) ?????????????? ??????.";
		cout << "\n4) ??????????????? ??????." << endl;
		m++;
	}
	else if (a == 3)
	{
		cout << "4.??????? ??????????? ? ??????? ???????? ?????????? ???? ?? ?????";
		cout << "\n1) ???????.";
		cout << "\n2) ????????.";
		SetColor(White, Red);
		cout << "\n3) ?????????????? ??????.";
		SetColor(White, Black);
		cout << "\n4) ??????????????? ??????." << endl;
	}
	else if (a == 4)
	{
		cout << "4.??????? ??????????? ? ??????? ???????? ?????????? ???? ?? ?????";
		cout << "\n1) ???????.";
		cout << "\n2) ????????.";
		cout << "\n3) ?????????????? ??????.";
		SetColor(White, Red);
		cout << "\n4) ??????????????? ??????." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 5 ??????
	cout << "5.??????? ??????????? ??????????? ? ??????? ? ??????? ...";
	cout << "\n1) ???????????? ???????????????, ?????????? ?????????? ????????.";
	cout << "\n2) ??????, ?????????, ??????.";
	cout << "\n3) ?????? ??? ??? ??????, ?? ?????? ? ????????????.";
	cout << "\n4) ?????????? ?????? ???????????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "5.??????? ??????????? ??????????? ? ??????? ? ??????? ...";
		SetColor(White, Red);
		cout << "\n1) ???????????? ???????????????, ?????????? ?????????? ????????.";
		SetColor(White, Black);
		cout << "\n2) ??????, ?????????, ??????.";
		cout << "\n3) ?????? ??? ??? ??????, ?? ?????? ? ????????????.";
		cout << "\n4) ?????????? ?????? ???????????." << endl;
	}
	else if (a == 2)
	{
		cout << "5.??????? ??????????? ??????????? ? ??????? ? ??????? ...";
		cout << "\n1) ???????????? ???????????????, ?????????? ?????????? ????????.";
		SetColor(White, Red);
		cout << "\n2) ??????, ?????????, ??????.";
		SetColor(White, Black);
		cout << "\n3) ?????? ??? ??? ??????, ?? ?????? ? ????????????.";
		cout << "\n4) ?????????? ?????? ???????????." << endl;		
	}
	else if (a == 3)
	{
		cout << "5.??????? ??????????? ??????????? ? ??????? ? ??????? ...";
		cout << "\n1) ???????????? ???????????????, ?????????? ?????????? ????????.";
		cout << "\n2) ??????, ?????????, ??????.";
		SetColor(White, Green);
		cout << "\n3) ?????? ??? ??? ??????, ?? ?????? ? ???????????? .";
		SetColor(White, Black);
		cout << "\n4) ?????????? ?????? ??????????? ." << endl;
		m++;
	}
	else if (a == 4)
	{
		cout << "5.??????? ??????????? ??????????? ? ??????? ? ??????? ...";
		cout << "\n1) ???????????? ???????????????, ?????????? ?????????? ????????.";
		cout << "\n2) ??????, ?????????, ??????.";
		cout << "\n3) ?????? ??? ??? ??????, ?? ?????? ? ???????????? .";
		SetColor(White, Red);
		cout << "\n4) ?????????? ?????? ??????????? ." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 6 ??????
	cout << "6.??????????? ? ??????? ? ???????? ??????? ??????? ?? ...";
	cout << "\n1) ??????? ? ???????.";
	cout << "\n2) ?????????? ? ????????????.";
	cout << "\n3) ??? ? ???.";
	cout << "\n4) ?????? ? ?????????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "6.??????????? ? ??????? ? ???????? ??????? ??????? ?? ...";
		SetColor(White, Red);
		cout << "\n1) ??????? ? ???????.";
		SetColor(White, Black);
		cout << "\n2) ?????????? ? ????????????.";
		cout << "\n3) ??? ? ???.";
		cout << "\n4) ?????? ? ?????????." << endl;
	}
	else if (a == 2)
	{
		cout << "6.??????????? ? ??????? ? ???????? ??????? ??????? ?? ...";
		cout << "\n1) ??????? ? ???????.";
		SetColor(White, Red);
		cout << "\n2) ?????????? ? ????????????.";
		SetColor(White, Black);
		cout << "\n3) ??? ? ???.";
		cout << "\n4) ?????? ? ?????????." << endl;
	}
	else if (a == 3)
	{
		cout << "6.??????????? ? ??????? ? ???????? ??????? ??????? ?? ...";
		cout << "\n1) ??????? ? ???????.";
		cout << "\n2) ?????????? ? ????????????.";
		SetColor(White, Green);
		cout << "\n3) ??? ? ???.";
		SetColor(White, Black);
		cout << "\n4) ?????? ? ?????????." << endl;
		m++;
	}
	else if (a == 4)
	{
		cout << "6.??????????? ? ??????? ? ???????? ??????? ??????? ?? ...";
		cout << "\n1) ??????? ? ???????.";
		cout << "\n2) ?????????? ? ????????????.";
		cout << "\n3) ??? ? ???.";
		SetColor(White, Red);
		cout << "\n4) ?????? ? ?????????." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 7 ??????
	cout << "7.??? ? ???";
	cout << "\n1) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ??????????? ???????.";
	cout << "\n2) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
	cout << "\n3) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
	cout << "\n4) ??????? ???????????, ? ??????? ??????? ??????????? ??????????? ?? ?????? ? ???????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "7.??? ? ???";
		SetColor(White, Red);
		cout << "\n1) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ??????????? ???????.";
		SetColor(White, Black);
		cout << "\n2) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
		cout << "\n3) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
		cout << "\n4) ??????? ???????????, ? ??????? ??????? ??????????? ??????????? ?? ?????? ? ???????." << endl;
	}
	else if (a == 2)
	{
		cout << "7.??? ? ???";
		cout << "\n1) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ??????????? ???????.";
		SetColor(White, Red);
		cout << "\n2) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
		SetColor(White, Black);
		cout << "\n3) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
		cout << "\n4) ??????? ???????????, ? ??????? ??????? ??????????? ??????????? ?? ?????? ? ???????." << endl;
	}
	else if (a == 3)
	{
		cout << "7.??? ? ???";
		cout << "\n1) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ??????????? ???????.";
		cout << "\n2) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
		SetColor(White, Red);
		cout << "\n3) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
		SetColor(White, Black);
		cout << "\n4) ??????? ???????????, ? ??????? ??????? ??????????? ??????????? ?? ?????? ? ???????." << endl;
	}
	else if (a == 4)
	{
		cout << "7.??? ? ???";
		cout << "\n1) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ??????????? ???????.";
		cout << "\n2) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
		cout << "\n3) ??????? ???????????, ? ??????? ??????? ??????????? ????????? ????????????? ???????.";
		SetColor(White, Green);
		cout << "\n4) ??????? ???????????, ? ??????? ??????? ??????????? ??????????? ?? ?????? ? ???????." << endl;
		SetColor(White, Black);
		m++;
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 8 ??????
	cout << "8.????? ????? ????????????? ???";
	cout << "\n1) [ ? ], (??? ?).";
	cout << "\n2) [ ? ], (??? ?).";
	cout << "\n3) (???? ?), [ ? ].";
	cout << "\n4) [ ], ? [ ]." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "8.????? ????? ????????????? ???";
		SetColor(White, Red);
		cout << "\n1) [ ? ], (??? ?).";
		SetColor(White, Black);
		cout << "\n2) [ ? ], (??? ?).";
		cout << "\n3) (???? ?), [ ? ].";
		cout << "\n4) [ ], ? [ ]." << endl;
	}
	else if (a == 2)
	{
		cout << "8.????? ????? ????????????? ???";
		cout << "\n1) [ ? ], (??? ?).";
		SetColor(White, Red);
		cout << "\n2) [ ? ], (??? ?).";
		SetColor(White, Black);
		cout << "\n3) (???? ?), [ ? ].";
		cout << "\n4) [ ], ? [ ]." << endl;
	}
	else if (a == 3)
	{
		cout << "8.????? ????? ????????????? ???";
		cout << "\n1) [ ? ], (??? ?).";
		cout << "\n2) [ ? ], (??? ?).";
		SetColor(White, Red);
		cout << "\n3) (???? ?), [ ? ].";
		SetColor(White, Black);
		cout << "\n4) [ ], ? [ ]." << endl;
	}
	else if (a == 4)
	{
		cout << "8.????? ????? ????????????? ???";
		cout << "\n1) [ ? ], (??? ?).";
		cout << "\n2) [ ? ], (??? ?).";
		cout << "\n3) (???? ?), [ ? ].";
		SetColor(White, Green);
		cout << "\n4) [ ], ? [ ]." << endl;
		SetColor(White, Black);
		m++;
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 9 ??????
	cout << "9.??????? ????? ????";
	cout << "\n1) ????.";
	cout << "\n2) ???.";
	cout << "\n3) ???.";
	cout << "\n4) ??????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "9.??????? ????? ????";
		SetColor(White, Red);
		cout << "\n1) ????.";
		SetColor(White, Black);
		cout << "\n2) ???.";
		cout << "\n3) ???.";
		cout << "\n4) ??????." << endl;
	}
	else if (a == 2)
	{
		cout << "9.??????? ????? ????";
		cout << "\n1) ????.";
		SetColor(White, Red);
		cout << "\n2) ???.";
		SetColor(White, Black);
		cout << "\n3) ???.";
		cout << "\n4) ??????." << endl;
	}
	else if (a == 3)
	{
		cout << "9.??????? ????? ????";
		cout << "\n1) ????.";
		cout << "\n2) ???.";
		SetColor(White, Green);
		cout << "\n3) ???.";
		SetColor(White, Black);
		cout << "\n4) ??????." << endl;
		m++;
	}
	else if (a == 4)
	{
		cout << "9.??????? ????? ????";
		cout << "\n1) ????.";
		cout << "\n2) ???.";
		cout << "\n3) ???.";
		SetColor(White, Red);
		cout << "\n4) ??????." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 10 ??????
	cout << "10.? ????? ???? ??????????? ????????????? ?????? ?????[-=], ??[=]:";
	cout << "\n1) ???? ???? ? ??????????????? ??????, ? ??? ? ???? ??? ???? ???????? ? ???.";
	cout << "\n2) ? ???? ??? ?????, ?? ? ???????? ?????? ???????????.";
	cout << "\n3) ?? ?? ???????? ?????? ?????? ??????? ?????????, ?? ? ???????? ????????? ?????? ??????? ????.";
	cout << "\n4) ?? ? ??? ?? ??????? ??????, ??? ?????? ????? ? ????????????, ???????, ???????, ??? ???." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "10.? ????? ???? ??????????? ????????????? ?????? ?????[-=], ??[=]:";
		SetColor(White, Red);
		cout << "\n1) ???? ???? ? ??????????????? ??????, ? ??? ? ???? ??? ???? ???????? ? ???.";
		SetColor(White, Black);
		cout << "\n2) ? ???? ??? ?????, ?? ? ???????? ?????? ???????????.";
		cout << "\n3) ?? ?? ???????? ?????? ?????? ??????? ?????????, ?? ? ???????? ????????? ?????? ??????? ????.";
		cout << "\n4) ?? ? ??? ?? ??????? ??????, ??? ?????? ????? ? ????????????, ???????, ???????, ??? ???." << endl;
	}
	else if (a == 2)
	{
		cout << "10.? ????? ???? ??????????? ????????????? ?????? ?????[-=], ??[=]:";
		cout << "\n1) ???? ???? ? ??????????????? ??????, ? ??? ? ???? ??? ???? ???????? ? ???.";
		SetColor(White, Green);
		cout << "\n2) ? ???? ??? ?????, ?? ? ???????? ?????? ???????????.";
		SetColor(White, Black);
		cout << "\n3) ?? ?? ???????? ?????? ?????? ??????? ?????????, ?? ? ???????? ????????? ?????? ??????? ????.";
		cout << "\n4) ?? ? ??? ?? ??????? ??????, ??? ?????? ????? ? ????????????, ???????, ???????, ??? ???." << endl;
		m++;
	}
	else if (a == 3)
	{
		cout << "10.? ????? ???? ??????????? ????????????? ?????? ?????[-=], ??[=]:";
		cout << "\n1) ???? ???? ? ??????????????? ??????, ? ??? ? ???? ??? ???? ???????? ? ???.";
		cout << "\n2) ? ???? ??? ?????, ?? ? ???????? ?????? ???????????.";
		SetColor(White, Red);
		cout << "\n3) ?? ?? ???????? ?????? ?????? ??????? ?????????, ?? ? ???????? ????????? ?????? ??????? ????.";
		SetColor(White, Black);
		cout << "\n4) ?? ? ??? ?? ??????? ??????, ??? ?????? ????? ? ????????????, ???????, ???????, ??? ???." << endl;
	}
	else if (a == 4)
	{
		cout << "10.? ????? ???? ??????????? ????????????? ?????? ?????[-=], ??[=]:";
		cout << "\n1) ???? ???? ? ??????????????? ??????, ? ??? ? ???? ??? ???? ???????? ? ???.";
		cout << "\n2) ? ???? ??? ?????, ?? ? ???????? ?????? ???????????.";
		cout << "\n3) ?? ?? ???????? ?????? ?????? ??????? ?????????, ?? ? ???????? ????????? ?????? ??????? ????.";
		SetColor(White, Red);
		cout << "\n4) ?? ? ??? ?? ??????? ??????, ??? ?????? ????? ? ????????????, ???????, ???????, ??? ???." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 11 ??????
	cout << "11.??????? ???, ????? ??????? ??????? ?? ????? ???????, ??? ??? ??????? ????? ?????????????? ????(????? ?? ???????????)";
	cout << "\n1) ? ???? ????? ? ???? ???????? ???????? ????????.";
	cout << "\n2) ??????? ?????? ???????? ???? ? ??????? ????? ??????? ???.";
	cout << "\n3) ???? ????? ??????? ? ????? ?????? ??????.";
	cout << "\n4) ???????? ???? ? ?????? ???????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "11.??????? ???, ????? ??????? ??????? ?? ????? ???????, ??? ??? ??????? ????? ?????????????? ????(????? ?? ???????????)";
		SetColor(White, Red);
		cout << "\n1) ? ???? ????? ? ???? ???????? ???????? ????????.";
		SetColor(White, Black);
		cout << "\n2) ??????? ?????? ???????? ???? ? ??????? ????? ??????? ???.";
		cout << "\n3) ???? ????? ??????? ? ????? ?????? ??????.";
		cout << "\n4) ???????? ???? ? ?????? ???????." << endl;
	}
	else if (a == 2)
	{
		cout << "11.??????? ???, ????? ??????? ??????? ?? ????? ???????, ??? ??? ??????? ????? ?????????????? ????(????? ?? ???????????)";
		cout << "\n1) ? ???? ????? ? ???? ???????? ???????? ????????.";
		SetColor(White, Green);
		cout << "\n2) ??????? ?????? ???????? ???? ? ??????? ????? ??????? ???.";
		SetColor(White, Black);
		cout << "\n3) ???? ????? ??????? ? ????? ?????? ??????.";
		cout << "\n4) ???????? ???? ? ?????? ???????." << endl;
		m++;
	}
	else if (a == 3)
	{
		cout << "11.??????? ???, ????? ??????? ??????? ?? ????? ???????, ??? ??? ??????? ????? ?????????????? ????(????? ?? ???????????)";
		cout << "\n1) ? ???? ????? ? ???? ???????? ???????? ????????.";
		cout << "\n2) ??????? ?????? ???????? ???? ? ??????? ????? ??????? ???.";
		SetColor(White, Red);
		cout << "\n3) ???? ????? ??????? ? ????? ?????? ??????.";
		SetColor(White, Black);
		cout << "\n4) ???????? ???? ? ?????? ???????." << endl;
	}
	else if (a == 4)
	{
		cout << "11.??????? ???, ????? ??????? ??????? ?? ????? ???????, ??? ??? ??????? ????? ?????????????? ????(????? ?? ???????????)";
		cout << "\n1) ? ???? ????? ? ???? ???????? ???????? ????????.";
		cout << "\n2) ??????? ?????? ???????? ???? ? ??????? ????? ??????? ???.";
		cout << "\n3) ???? ????? ??????? ? ????? ?????? ??????.";
		SetColor(White, Red);
		cout << "\n4) ???????? ???? ? ?????? ???????." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	// 12 ??????
	cout << "12.??????? ?????????? ???????????.";
	cout << "\n1) ?? ????? ????????, ? ????? ?????.";
	cout << "\n2) ?? ???????? ???????? ???, ? ????????.";
	cout << "\n3) ??? ??????? ? ??? ?????? ?????.";
	cout << "\n4) ?? ???????? ???????? ? ???????? ??? ?????." << endl;
	cin >> a;
	system("cls");
	if (a == 1)
	{
		cout << "12.??????? ?????????? ???????????.";
		SetColor(White, Red);
		cout << "\n1) ?? ????? ????????, ? ????? ?????.";
		SetColor(White, Black);
		cout << "\n2) ?? ???????? ???????? ???, ? ????????.";
		cout << "\n3) ??? ??????? ? ??? ?????? ?????.";
		cout << "\n4) ?? ???????? ???????? ? ???????? ??? ?????." << endl;
	}
	else if (a == 2)
	{
		cout << "12.??????? ?????????? ???????????.";
		cout << "\n1) ?? ????? ????????, ? ????? ?????.";
		SetColor(White, Red);
		cout << "\n2) ?? ???????? ???????? ???, ? ????????.";
		SetColor(White, Black);
		cout << "\n3) ??? ??????? ? ??? ?????? ?????.";
		cout << "\n4) ?? ???????? ???????? ? ???????? ??? ?????." << endl;		
	}
	else if (a == 3)
	{
		cout << "12.??????? ?????????? ???????????.";
		cout << "\n1) ?? ????? ????????, ? ????? ?????.";
		cout << "\n2) ?? ???????? ???????? ???, ? ????????.";
		SetColor(White, Green);
		cout << "\n3) ??? ??????? ? ??? ?????? ?????.";
		SetColor(White, Black);
		cout << "\n4) ?? ???????? ???????? ? ???????? ??? ?????." << endl;
		m++;
	}
	else if (a == 4)
	{
		cout << "12.??????? ?????????? ???????????.";
		cout << "\n1) ?? ????? ????????, ? ????? ?????.";
		cout << "\n2) ?? ???????? ???????? ???, ? ????????.";
		cout << "\n3) ??? ??????? ? ??? ?????? ?????.";
		SetColor(White, Red);
		cout << "\n4) ?? ???????? ???????? ? ???????? ??? ?????." << endl;
		SetColor(White, Black);
	}
	else
	{
		cout << "???????? ????? ?? 1 ?? 4. ???? ????? ????????." << endl;
	}
	Sleep(1000);
	system("cls");
	cout << m << " ?????????? ??????? ?? 12.";
}