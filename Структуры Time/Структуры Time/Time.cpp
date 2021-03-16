#include <iostream>
#include <ctime>
#include <iomanip>
#include "Time.h"
using namespace std;

Time now(int timeshift)
{
	int s = time(nullptr);
	int s_today = s % (24 * 60 * 60);

	Time t = seconds_to_time(s_today);
	if (timeshift)
	{
		t = add_hours(t, timeshift);
	}
	return t;
}

Time add_seconds(Time t, int seconds)
{
	t.seconds += seconds;
	while (t.seconds >= 60)
	{
		t.seconds -= 60;

		if (t.seconds < 60)
		{
			t.minutes++;
			t.seconds = t.seconds;
			break;
		}

		t.minutes++;

		if (t.minutes >= 60)
		{
			t.minutes = 0;
			t.hours++;
		}
		if (t.hours >= 24)
		{
			t.hours = 0;
		}
	}

	return t;
}

Time add_minutes(Time t, int minutes)
{
	t.minutes += minutes;
	while (t.minutes >= 60)
	{
		t.minutes -= 60;
		
		if (t.minutes < 60)
		{
			t.hours++;
			t.minutes = t.minutes;
			break;
		}
		t.hours++;
		if (t.hours >= 24)
		{
			t.hours = 0;
		}
	}
	
	return t;

}

Time add_hours(Time t, int hours)
{
	t.hours += hours;
	while (t.hours >= 24)
	{
		t.hours -= 24;
		if (t.hours < 24)
		{
			t.hours = t.hours;
			break;
		}
	}
	
	return t;
}

int time_to_seconds(Time t)
{
	int seconds1, seconds2, seconds3;
	seconds1 = t.hours * 3600;
	seconds2 = t.minutes * 3600 / 60;
	seconds3 = t.seconds;
	
	int all_sec = seconds1 + seconds2 + seconds3;

	return all_sec;
}

Time seconds_to_time(int seconds)
{
	Time t;
	t.hours = seconds / 3600;
	t.minutes = seconds % 3600 / 60;
	t.seconds = seconds % 60;

	return t;
}

void print(Time t)
{
	cout << "Время: ";
	cout << right << setw(2) << setfill('0') << t.hours << ':';
	cout << right << setw(2) << setfill('0') << t.minutes << ':';
	cout << right << setw(2) << setfill('0') << t.seconds << endl;
}

int time_cmp(Time t1, Time t2)
{
	int s1 = time_to_seconds(t1);
	int s2 = time_to_seconds(t2);

	if (s1 > s2) return 1;
	if (s1 < s2) return -1;
	return 0;
}