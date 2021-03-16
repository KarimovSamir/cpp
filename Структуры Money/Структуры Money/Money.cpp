#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include "Money.h"
using namespace std;

Money plus_sum(Money m1, Money m2)
{
	Money m3;
	m3.manat = m1.manat + m2.manat;
	m3.qepiy = m1.qepiy + m2.qepiy;

	while (m3.qepiy >= 100)
	{
		m3.qepiy -= 100;
		if (m3.qepiy < 100)
		{
			m3.manat++;
			m3.qepiy = m3.qepiy;
			break;
		}
		m3.manat++;
	}

	return m3;
}

Money minus_sum(Money m1, Money m2)
{
	Money m3;
	m3.manat = 0;
	m3.qepiy = (m2.manat * 100 + m2.qepiy) - (m1.manat * 100 + m1.qepiy);
	m3.manat = m3.qepiy / 100;
	m3.qepiy %= 100;

	/*if (m3.manat == 0 && m3.qepiy < 0)
		m3.manat = -m3.manat;*/

	return m3;
}

Money multiply(Money m, int k)
{
	Money m3;

	m3.manat = m.manat * k;
	m3.qepiy = m.qepiy * k;

	while (m3.qepiy >= 100)
	{
		m3.qepiy -= 100;
		if (m3.qepiy < 100)
		{
			m3.manat++;
			m3.qepiy = m3.qepiy;
			break;
		}
		m3.manat++;
	}

	return m3;
}

Money divide(Money m, int k)
{
	Money m3;
	m3.manat = 0;
	m3.qepiy = m.manat * 100 + m.qepiy;
	m3.qepiy /= k;

	while (m3.qepiy >= 100)
	{
		m3.qepiy -= 100;
		if (m3.qepiy < 100)
		{
			m3.manat++;
			m3.qepiy = m3.qepiy;
			break;
		}
		m3.manat++;
	}

	return m3;
}

Money qepiy_to_money(int q)
{
	Money m3;
	m3.manat = 0;
	m3.qepiy = q;

	while (m3.qepiy >= 100)
	{
		m3.qepiy -= 100;
		if (m3.qepiy < 100)
		{
			m3.manat++;
			m3.qepiy = m3.qepiy;
			break;
		}
		m3.manat++;
	}

	return m3;
}

int money_to_qepiy(Money m)
{
	int qepiy = m.manat * 100 + m.qepiy;

	return qepiy;
}

void print_money(Money m)
{
	if (m.manat == 0 && m.qepiy < 0)
	{
		cout << right << "-" << setw(2) << setfill('0') << m.manat << '.';
	}
	else
	{
		cout << right << setw(2) << setfill('0') << m.manat << '.';
	}
	cout << right << setw(2) << setfill('0') << abs(m.qepiy) << endl;
}

int money_cmp(Money m1, Money m2)
{
	int s1 = money_to_qepiy(m1);
	int s2 = money_to_qepiy(m2);

	if (s1 > s2) return 1;
	if (s1 < s2) return -1;
	return 0;
}