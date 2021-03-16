//#include <iostream>
//#include <iomanip>
//#include <cstring>
//#include <string>
//
//class Student
//{
//public:
//    // ��� ������ �����, ����� ������ �����
//    Student(const std::string& name, unsigned int score)
//        : m_name(name), m_score(score) {}
//
//    friend std::ostream& operator << (std::ostream& os, const Student& s)
//    {
//        os << "name  = " << s.m_name << '\n';
//        os << "score = " << s.m_score << '\n';
//        return os;
//    }
//private:
//    std::string m_name;
//    unsigned int m_score;
//};
//
//int main()
//{
//    std::cout << std::boolalpha;
//    std::string str = "hello";
//    std::cout << "str.empty() = " << str.empty() << '\n';
//    std::cout << "str.size() = " << str.size() << '\n';
//    str += " world";
//    std::cout << "str = " << str << '\n';
//    std::cout << "str.c_str() = " << str.c_str() << '\n';
//    std::cout << "str.data() = " << str.data() << '\n';
//    std::cout << "str[0] = " << str[0] << '\n';
//    std::cout << "str.front() = " << str.front() << '\n';
//    std::cout << "str.back() = " << str.back() << '\n';
//    //std::cout << "str + \"!!!\" = " << str + "!!!" << '\n';
//    str.append("!!!");
//    std::cout << "str = " << str << '\n';
//    std::string::size_type pos = str.find('e');
//    std::cout << "pos = " << pos << '\n';
//    std::cout << "std::string::npos = " << std::string::npos << '\n';
//    if (pos == std::string::npos) {
//        std::cout << "Not found\n";
//    }
//    std::string s1 = "hello";
//    std::string s2 = "world";
//    if (s1 == s2) {
//        std::cout << "s1 == s2\n";
//    }
//
//    /*
//        char ch[] = "hello";
//        std::string str2(ch);
//
//        char *cpy = new char[str.size() + 1];
//        strcpy(cpy, str.c_str());
//        std::cout << "cpy = " << cpy << '\n';
//        delete[] cpy;
//    */
//
//    Student s("Mike", 100);
//
//    std::cout << s;
//
//    /*
//        char data[20];
//        std::cin.getline(data, 20);
//        std::cout << data << '\n';
//    */
//
//    /*
//        std::string data;
//        std::getline(std::cin, data);
//        std::cout << data << '\n';
//    */
//
//    // ������
//    unsigned int age;
//    std::cin >> age;
//    std::cin.ignore();
//
//    std::string name;
//    std::getline(std::cin, name);
//
//    //std::cout << "age = " << age << '\n';
//    //std::cout << "name = " << name << '\n';
//
//
//    /*
//        ������� 1:
//        1. �������� ��� ���������� std::string (������������ ������ ���������
//        �� �������)
//        2. �������� ��� ���� ������ ������� ����� �������� �� ������ � ������
//        ������. �������� 1 ������: hello, 2 ������: world, 3 ������: hello world
//        3. ������������ 3 ������
//
//        ������� 2: ������ �����
//        1. ��������� "����������" ����� ������� ������������ ������ �������
//        2. ���� ������ ���� ���������, ����� ������������ ������� �����
//
//�������� �������:
//        ������� 3: ������� ������� �������
//        - �������� ������: (�����, �����������, ����, ����)
//        - ���������� ����������� �������� ������
//        - �� ���� ������� ������� ��� ������ ��������� �� ������
//        - ���������� ���������� ������� � ����
//        - ��� ������� ������ ����������� ������ � �������
//
//        � ������ ������ ������ ���������, ��� � ��� �� ����� ������ ����������
//        ������� ��� ������� ������ ������
//    */
//}
//
