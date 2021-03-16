//#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//
//
//class str
//{
//private:
//    char* m_data = nullptr;
//    size_t m_length = 0;
//
//    void cpy(const char* source)
//    {
//        m_length = strlen(source);
//        m_data = new char[m_length + 1];
//        strcpy(m_data, source);
//    }
//
//public:
//    str()
//    {
//        std::cout << "Empty string created\n";
//    }
//
//    str(const char* source)
//    {
//        cpy(source);
//    }
//
//    str(const str& other)
//    {
//        std::cout << "str(const str& other)\n";
//
//        // алгоритм копирования строки
//        m_length = other.m_length;
//        m_data = new char[m_length + 1];
//        strcpy(m_data, other.m_data);
//    }
//
//    size_t length()
//    {
//        return m_length;
//    }
//
//    char* data()
//    {
//        return m_data;
//    }
//
//    ~str()
//    {
//        delete[] m_data;
//    }
//
//};
//
//int main()
//{
//    char text[255];
//    std::cout << "Enter a line (you have 254 characters)" << std::endl;
//    std::cin.getline(text, 255);
//    char symbol;
//    str m_text(text);
//
//    std::cout << m_text.data();
//    std::cout << std::endl;
//
//    /////////////////////////////////////////////
//}