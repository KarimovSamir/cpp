#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <Windows.h>
#include <iomanip>

/*
        Задание 3: Система покупки билетов
        - Свойства билета: (номер, направление, дата, цена)
        - Реализуйте возможность покупать билеты
        - По мере покупки билетов они должны пропадать из списка
        - Реализуйте сортировку билетов к цене
        - При решении задачи используйте классы и объекты
*/


class Ticket
{
private:
    std::string m_destination; //направление
    int m_day;                 //дата
    int m_mounth;
    int m_year;                        
    int m_value;               //цена

public:
    Ticket() = default;

    Ticket(std::string destination, int day, int mounth, int year, int value)
    {
        m_destination = destination;
        m_day = day;
        m_mounth = mounth;
        m_year = year;
        m_value = value;
    }

    std::string get_destination() // исп ссылку
    {
        return m_destination;
    }
    int get_day()
    {
        return m_day;
    }
    int get_mounth()
    {
        return m_mounth;
    }
    int get_year()
    {
        return m_year;
    }
    int get_value()
    {
        return m_value;
    }
};

class all_tickets
{
private:
    Ticket* all_ticket = nullptr;
    static int m_count;                  //счётчик(номер)
public:

    all_tickets() = default;

    void add_ticket(std::string destination, int day, int mounth, int year, int value)
    {
        Ticket* temp = new Ticket[m_count + 1];
        for (int i = 0; i < m_count; i++)
        {
            temp[i] = all_ticket[i];
        }
        temp[m_count] = Ticket(destination, day, mounth, year, value);
        m_count++;
        delete[] all_ticket;
        all_ticket = temp;
    }

    void buy_ticket(int ticket_number)
    {
        m_count--;
        Ticket* temp = new Ticket[m_count];
        for (int i = 0; i < m_count; i++)
        {
            if (i < ticket_number - 1)
            {
                temp[i] = all_ticket[i];
            }
            else
            {
                temp[i] = all_ticket[i + 1];
            }
        }
        delete[] all_ticket;
        all_ticket = temp;
    }

    void sort()
    {
        for (size_t i = 0; i < m_count; i++)
        {
            for (size_t j = 0; j < m_count - 1 - i; j++)
            {
                if (all_ticket[j].get_value() > all_ticket[j + 1].get_value())
                {
                    Ticket temp = all_ticket[j];
                    all_ticket[j] = all_ticket[j + 1];
                    all_ticket[j + 1] = temp;
                }
            }
        }
    }

    static int get_count()
    {
        return m_count;
    }

    Ticket get_array(int i)
    {
        return all_ticket[i];
    }
    
    ~all_tickets()
    {
        delete[] all_ticket;
        //m_count--;
    }
};

int all_tickets::m_count = 0;

std::ostream& operator << (std::ostream& out, all_tickets& n)
{
    for (size_t i = 0; i < n.get_count(); i++)
    {
        out << i + 1 << ". Destination: " << n.get_array(i).get_destination() << ". Date: " << std::setw(2) << std::setfill('0') << n.get_array(i).get_day() << "." << std::setw(2) << std::setfill('0') << n.get_array(i).get_mounth() << "." << n.get_array(i).get_year() << " Price: " << n.get_array(i).get_value() << "$" << std::endl;
    }
    return out;
}

bool Exit(int x)
{
    if (x == 0) 
    { 
        std::cout << "All tickets gone" << std::endl;
        return false; 
    }
    char exit;
    std::cout << "Do you want buy more ticket" << std::endl;
    std::cin >> exit;
    return exit == 'Y' || exit == 'y';
}

int main()
{
    srand(time(NULL));
    int number_of_ticket;

    all_tickets ticket;

    ticket.add_ticket("Moskow", 4, 5, 1993, 1300);
    ticket.add_ticket("Amsterdam", 1, 8, 1984, 2530);
    ticket.add_ticket("London", 21, 10, 1984, 4340);
    ticket.add_ticket("Baku", 10, 12, 1984, 1430);
    ticket.add_ticket("Italy", 12, 7, 1984, 980);
    ticket.add_ticket("USA", 11, 1, 1984, 790);

    ticket.sort();
    do 
    {
        system("cls");
        std::cout << ticket << std::endl;
        std::cout << "Enter ticket number please: ";
        std::cin >> number_of_ticket;

        while (number_of_ticket > ticket.get_count() || number_of_ticket <= 0)
        {
            std::cout << "Enter right ticket number please: ";
            std::cin >> number_of_ticket;
        }
        ticket.buy_ticket(number_of_ticket);
        std::cout << ticket << std::endl;

    } while (Exit(ticket.get_count()));
}