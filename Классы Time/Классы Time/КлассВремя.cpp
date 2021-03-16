#include <iostream>
#include <ctime>
#include <iomanip>
#include <windows.h>

/*
        «адание 1: –еализуйте класс Time (формат времени - часы:минуты)
        - реализуйте конструктор через который можно установить начальное врем€
        - перегрузите постфиксные и префиксные операторы инкремента и декремента
        - операторы инкремента и декремента увеличивают и уменьшают
        минуты соответственно.
        - при достижении 60 минут (в результате инкремента),
          минуты должны обнул€тьс€ а часы должны быть
        увеличены на 1
        - при достижении 00 минут (в результате декремента),
          минуты должны быть равны 59 а часы должны быть уменьшены на 1
        - инкремент дл€ 23:59 устанавливает врем€ в 00:00
        - декремент дл€ 00:00 устанавливает врем€ в 23:59
        - реализуйте сравнение двух объеков типа Time (<,>,<=,>=, !=, ==)
        - перегрузите оператор ввода и вывода дл€ типа Time
*/

class Time
{
private:
    int seconds;
    int minutes;
    int hours;
    int sum;
public:
    Time(int seconds, int minutes, int hours)
    {
        this->seconds = seconds;
        this->minutes = minutes;
        this->hours = hours;
        int seconds1 = hours * 3600;
        int seconds2 = minutes * 3600 / 60;
        int seconds3 = seconds;
        int all_sec = seconds1 + seconds2 + seconds3;
        sum = all_sec;
    }

    Time() = default;

    void set_seconds(int seconds)
    {
        this->seconds = seconds;
    }

    void set_minutes(int minutes)
    {
        this->minutes = minutes;
    }

    void set_hours(int hours)
    {
        this->hours = hours;
    }

    int get_seconds()
    {
        return seconds;
    }

    int get_minutes()
    {
        return minutes;
    }

    int get_hours()
    {
        return hours;
    }

    Time operator++(int)
    {
        Time result(seconds, minutes, hours);
        ++seconds;
        if (seconds == 60)
        {
            minutes++;
            seconds = 0;
        }
        if (minutes == 60)
        {
            hours++;
            minutes = 0;
            seconds = 0;
        }
        if (hours == 24)
        {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        return result;
    }

    bool operator < (const Time& n)
    {
        return sum < n.sum;
    }

    bool operator > (const Time& n)
    {
        return sum > n.sum;
    }

    bool operator <= (const Time& n)
    {
        return sum <= n.sum;
    }

    bool operator >= (const Time& n)
    {
        return sum >= n.sum;
    }

    bool operator != (const Time& n)
    {
        return sum != n.sum;
    }

    bool operator == (const Time& n)
    {
        return sum == n.sum;
    }
};

int main()
{
    srand(time(NULL));
    int seconds1 = 55;
    int minutes1 = 59;
    int hours1 = 23;
    Time time1(seconds1, minutes1, hours1);

    int seconds2 = 58;
    int minutes2 = 55;
    int hours2 = 23;
    Time time2(seconds2, minutes2, hours2);


    if (time1 == time2)
    {
        std::cout << "Time is the same\n";
    }

    if(time1 != time2)
    {
        std::cout << "Time is different\n";
    }

    /////////////////////////////////////////////////////

    if (time1 < time2)
    {
        std::cout << "time2 is more than time1\n";
    }

    if (time1 > time2)
    {
        std::cout << "time1 is more than time1\n";
    }

    /////////////////////////////////////////////////////

    if (time1 <= time2)
    {
        std::cout << "time2 is more than time1 or they are the same\n";
    }

    if (time1 >= time2)
    {
        std::cout << "time1 is more than time2 or they are the same\n";
    }

    /////////////////////////////////////////////////////

    system("pause");

    while (true)
    {
        system("cls");
        std::cout << std::right << std::setw(2) << std::setfill('0') << time1.get_hours() << ':';
        std::cout << std::right << std::setw(2) << std::setfill('0') << time1.get_minutes() << ':';
        std::cout << std::right << std::setw(2) << std::setfill('0') << time1.get_seconds() << std::endl;
        Sleep(1000);
        time1++;
    }
}