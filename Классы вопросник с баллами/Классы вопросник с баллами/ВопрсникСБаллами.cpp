#include <iostream>
#include <iomanip>

union M_voice
{
    int Int;
    float Float;
};

class Variant
{
private:
    std::string m_text;
    M_voice m_voice;
public:
    Variant() = default;

    Variant(std::string text, int voice)
    {
        m_text = text;
        m_voice.Int = voice;
    }

    std::string& get_text()
    {
        return m_text;
    }

    void set_voice_float(float voice) 
    {
        m_voice.Float = voice;
    }

    int get_voice_int() 
    {
        return m_voice.Int;
    }

    float get_voice_float() 
    {
        return m_voice.Float;
    }
};

class Poll
{
private:
    Variant* m_variants = nullptr;
    std::string m_title;
    int m_size = 0;
    int m_cout = 0;
public:
    Poll() = default;

    void add_question(std::string title)
    {
        m_title = title;
    }

    void add_variant(std::string text, int voice)
    {
        Variant* temp = new Variant[m_size + 1];
        for (int i = 0; i < m_size; i++)
        {
            temp[i] = m_variants[i];
        }
        temp[m_size] = Variant(text, voice);
        m_size++;
        delete[] m_variants;
        m_variants = temp;
    }

    void how_information_out(int choose)
    {
        if (choose == 2)
        {
            m_cout = choose;
            int temp = 0;
            for (int i = 0; i < m_size; i++)
            {
                temp += m_variants[i].get_voice_int();
            }
            for (int i = 0; i < m_size; i++)
            {
                m_variants[i].set_voice_float(100 * float(m_variants[i].get_voice_int()) / temp);
            }
        }
    }

    int get_choose()
    {
        return m_cout;
    }

    int get_size()
    {
        return m_size;
    }

    std::string& get_title()
    {
        return m_title;
    }

    Variant get_variant(int i)
    {
        return m_variants[i];
    }
    ~Poll()
    {
        delete[] m_variants;
    }

};

std::ostream& operator << (std::ostream& out, Poll& n)
{
    for (size_t i = 0; i < n.get_size(); i++)
    {
        if (n.get_title().empty())
        {
            out << "No question, no answers :)" << std::endl;
            break;
        }
        else
        {
            if (i == 0)
            {
                out << n.get_title() << std::endl;
            }
            out << i + 1 << ") " << n.get_variant(i).get_text() << "\tNumber of voices: " ;
            if (n.get_choose()) 
            { 
                out << std::setprecision(2) << n.get_variant(i).get_voice_float() << "%" << std::endl; 
            }
            else 
            { 
                out << n.get_variant(i).get_voice_int() << std::endl; 
            }
        }
    }
    return out;
}

int main()
{
    Poll poll;

    poll.add_question("What is the name of the hero in the game \"Serious Sam\"?");

    poll.add_variant("Serious Sam", 28);
    poll.add_variant("Sam Stone", 352);
    poll.add_variant("Big Sam", 55);
    poll.add_variant("Sam Bridge", 203);
    int choose;
    std::cout << "How do you want to get the information out?\n";
    std::cout << "1. Number of votes for each option\n";
    std::cout << "2. Percentage of the total number of votes for each option\n";
    std::cin >> choose;
    system("cls");
    poll.how_information_out(choose);
    std::cout << poll;

    /*
        Задание 1:
        - Реализуйте класс Poll (title: строка, variants: массив вариантов)
        - Реализуйте класс Variant (text: строка, count: количество голосов)
        - Реализуйте оператор вывода для типа Poll который печатает данные
          опроса (заголовок, варианты ответов и количество голосов)
        - При выводе информации пользователь должен выбрать как отобразить
          результаты опроса (количество голосов за каждый вариант или процент
          от общего количества голосов для каждого варианта)
     */
}

