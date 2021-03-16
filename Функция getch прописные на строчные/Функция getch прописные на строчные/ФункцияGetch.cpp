#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

char super_getch(char result)
{
	if ((result < 91 and result>64) or (result < 128 and result>96))
	{
		if (result > 96)
		{
			result = result - 32;
			cout << result;
		}

		else
		{
			result = result + 32;
			cout << result;
		}
	}

	else
	{
		cout << result;
	}
	return result;
}

void main()
{
	setlocale(LC_ALL, "rus");
	cout << "Для выхода нажмите '.'" << endl;
line1:
	char result = _getch();
	super_getch(result);
	if (result == '.')
	{
		
	}
	else
	{
		goto line1;
	}

}