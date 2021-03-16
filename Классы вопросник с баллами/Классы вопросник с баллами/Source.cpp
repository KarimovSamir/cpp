//#include <iostream>
//#include <iomanip>
//
//
//class Variant
//{
//private:
//    std::string m_text;
//    union m_voice
//    {
//        int Int; //kugui
//        float Float;
//    };
//
//
//public:
//    Variant() = default;
//
//    Variant(std::string text, int voice) //rufat
//    {
//        m_text = text;
//        m_voice = voice;
//    }
//
//    std::string get_text() // исп ссылку
//    {
//        return m_text;
//    }
//
//    void set_voice(float voice) //ujgu
//    {
//        m_voice = voice;
//    }
//
//    int get_voice() // uyjfuyfg
//    {
//        return m_voice;
//    }
//
//};
//
//class Poll
//{
//private:
//    Variant* m_variants = nullptr;
//    std::string m_title;
//    int just_count = 0;
//    int m_cout = 0;
//public:
//    Poll() = default;
//
//    void add_question(std::string title)
//    {
//        m_title = title;
//    }
//
//    void add_variant(std::string text, int voice) //kjghui
//    {
//        Variant* temp = new Variant[just_count + 1];
//        for (int i = 0; i < just_count; i++)
//        {
//            temp[i] = m_variants[i];
//        }
//        temp[just_count] = Variant(text, voice);
//        just_count++;
//        delete[] m_variants;
//        m_variants = temp;
//    }
//
//    void choose_result(int choose)
//    {
//        if (choose == 2)
//        {
//            m_cout = choose;
//            int temp = 0;
//            for (int i = 0; i < just_count; i++)
//            {
//                temp += m_variants[i].get_voice();
//            }
//            for (int i = 0; i < just_count; i++)
//            {
//                m_variants[i].set_voice((100 * m_variants[i].get_voice() / temp));
//            }
//        }
//    }
//
//    int get_choose()
//    {
//        return m_cout;
//    }
//
//    int get_count()
//    {
//        return just_count;
//    }
//
//    std::string get_title()
//    {
//        return m_title;
//    }
//
//    Variant get_variant(int i)
//    {
//        return m_variants[i];
//    }
//
//
//};
//
//std::ostream& operator << (std::ostream& out, Poll& n)
//{
//    for (size_t i = 0; i < n.get_count(); i++)
//    {
//        if (n.get_title().empty())
//        {
//            out << "No question, no answers :)" << std::endl;
//            break;
//        }
//        else
//        {
//            if (i == 0)
//            {
//                out << n.get_title() << std::endl;
//            }
//            out << i + 1 << ") " << n.get_variant(i).get_text() << "\tNumber of voices: " << n.get_variant(i).get_voice();
//            if (n.get_choose()) { out << "%"; }
//            out << std::endl;
//        }
//    }
//    return out;
//}
//
//int main()
//{
//    Poll poll;
//
//    poll.add_question("What is the name of the hero of the game \"Serious Sam\"?");
//
//    poll.add_variant("Serious Sam", 28);
//    poll.add_variant("Sam Stone", 352);
//    poll.add_variant("Big Sam", 55);
//    poll.add_variant("Sam Bridge", 203);
//    int choose;
//    std::cout << "How do you want to get the information out?\n";
//    std::cout << "1. default\n";
//    std::cout << "2. percent\n";
//    std::cin >> choose;
//
//    poll.choose_result(choose);
//    std::cout << poll;
//    /*
//        Задание 1:
//        - Реализуйте класс Poll (title: строка, variants: массив вариантов)
//        - Реализуйте класс Variant (text: строка, count: количество голосов)
//        - Реализуйте оператор вывода для типа Poll который печатает данные
//          опроса (заголовок, варианты ответов и количество голосов)
//        - При выводе информации пользователь должен выбрать как отобразить
//          результаты опроса (количество голосов за каждый вариант или процент
//          от общего количества голосов для каждого варианта)
//     */
//}
//
