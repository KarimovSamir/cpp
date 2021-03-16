#include <iostream>
using namespace std;
int happy_num(int num)
{
	int a, b, c, d, e, f;
	a = num / 100000;
	b = num / 10000;
	c = num / 1000;
	int result1 = a + b + c;
	d = num % 10;
	e = num % 100;
	f = num % 1000;
	int result2 = d + e + f;
	if (result1 == result2)
		return true;
	else
		return false;
}
void main()
{
	setlocale(LC_ALL, "rus");
	int a;
	cin >> a;
	if(happy_num(a))
		cout << "У вас счастливый билет";
	else
		cout << "У вас не счастливый билет";
}