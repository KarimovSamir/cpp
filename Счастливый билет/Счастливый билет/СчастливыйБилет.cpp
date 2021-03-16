#include <iostream>
using namespace std;

int ticket(int number)
{
	int half_first;
	int half_first_sum = 0;
	int half_second;
	int half_second_sum = 0;

	half_first = number / 1000;
	half_second = number % 1000;
	while (half_first != 0)
	{
		half_first_sum += half_first % 10;
		half_first /= 10;
	}

	while (half_second != 0)
	{
		half_second_sum += half_second % 10;
		half_second /= 10;
	}
	if (half_first_sum == half_second_sum)
		return true;
	else
		return false;
}

void main()
{
	setlocale(LC_ALL, "rus");

	int number;
	cout << "Введите 6 цифр с билета: ";
	cin >> number;

	if (ticket(number))
		cout << "У вас счастливый билет :)";
	else
		cout << "У вас не счастливый билет :(";

}