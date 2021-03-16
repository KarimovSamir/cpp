//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <windows.h>
//
///*
//        �������� �������:
//        - ���������� ����� Page (����� ��������, ���������� ��������)
//        - ���������� ����� Book (��������, �����, ��� �������, ������ Page)
//        - ��� ������� ��������� ������������ ������ ��������� ������ �����
//        - �������� ������ ���� ��������� �� ��� ��� ���� ������������ ��
//        �������� ���������� ��������� ����� ��������
//        - ����� ������ ���� ��������� 2 �����
//        - � ������� ��������� ������������ cin, cout
//        - ������������ ��� ������ ���� ����
//*/
//
//class Page
//{
//private:
//    int page_number = 0;                  // ����� ��������
//    char* page_content = nullptr;        // ���������� ��������        
//    size_t page_length = 0;
//
//    void cpy(const char* source)
//    {
//        page_length = strlen(source);
//        page_content = new char[page_length + 1];
//        strcpy(page_content, source);
//    }
//
//public:
//    Page() = default;
//
//    Page(const char* source)
//    {
//        cpy(source);
//    }
//
//    Page(int page_number, const char* page_content)
//    {
//        cpy(page_content);
//        this->page_number = page_number;
//    }
//
//    //Page(const Page& other)
//    //{
//    //    // �������� ����������� ������
//    //    page_length = other.page_length;
//    //    page_content = new char[page_length + 1];
//    //    strcpy(page_content, other.page_content);
//    //}
//
//    /*void set_page_content(const char* page_content)
//    {
//        strcpy(this->page_content, page_content);
//    }*/
//
//    char* get_page_content()
//    {
//        return page_content;
//    }
//
//    int get_page_number()
//    {
//        return page_number;
//    }
//
//    /*~Page()
//    {
//        delete[] page_content;
//    }*/
//};
//
//class Book
//{
//private:
//    char book_title[255];           // �������� �����
//    char author_of_book[255];       // ����� �����
//    int publication_year = 0;                 // ��� �������
//    Page* book;
//    int page_number;
//
//public:
//
//    Book() = default;
//
//    void set_year(int publication_year)
//    {
//        this->publication_year = publication_year;
//    }
//
//    void set_title(const char* book_title)
//    {
//        strcpy(this->book_title, book_title);
//    }
//
//    void set_author(const char* author_of_book)
//    {
//        strcpy(this->author_of_book, author_of_book);
//    }
//
//    int get_year()
//    {
//        return publication_year;
//    }
//
//    const char* get_title()
//    {
//        return book_title;
//    }
//
//    const char* get_author()
//    {
//        return author_of_book;
//    }
//
//    void add_page(const Page& page)
//    {
//        Page* temp = new Page[page_number + 1];
//        for (size_t i = 0; i < page_number; i++)
//        {
//            temp[i] = book[i];
//        }
//        delete[]book;
//        book = temp;
//        book[page_number] = page;
//        page_number++;
//    }
//
//    void print()
//    {
//        int page_count = 1;
//        for (size_t i = 0; i < page_number; i++)
//        {
//            std::cout << "�������� ����� " << page_count << "\n";
//            std::cout << book[i].get_page_content() << "\n";
//            page_count++;
//        }
//    }
//
//    /*~Book()
//    {
//        delete[] book_title;
//        delete[] author_of_book;
//    }*/
//};
//
//
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    // 1 �����
//    char book_title[255];           // �������� �����
//    char author_of_book[255];       // ����� �����
//    int publication_year;           // ��� �������
//    char page_content[255];         // ���������� �������� �����
//    int number_of_page;             // ����������� ������� � �����
//    Book book1;
//
//    std::cout << "������� �������� ������ �����: ";
//    std::cin.getline(book_title, 255);
//
//    std::cout << "������� ��� ������ ������ �����: ";
//    std::cin.getline(author_of_book, 255);
//
//    std::cout << "������� ��� ������� ������ �����: ";
//    std::cin >> publication_year;
//
//    book1.set_title(book_title);
//    book1.set_author(author_of_book);
//    book1.set_year(publication_year);
//
//    std::cout << "������� ������� � �����?" << "\n";
//    std::cin >> number_of_page;
//
//    std::cin.ignore();
//    for (size_t i = 0; i < number_of_page; i++)
//    {
//        std::cout << "�������� ���������� ��������" << "\n";
//        std::cin.getline(page_content, 255);
//        Page page1(number_of_page, page_content);
//        book1.add_page(page1);
//    }
//
//    //////////////////////////////////////////////////////////////
//    // 2 �����
//    char book_title2[255];             // �������� �����
//    char author_of_book2[255];         // ����� �����
//    int publication_year2;             // ��� �������
//    char page_content2[255];           // ���������� �������� �����
//    int number_of_page2;               // ����������� ������� � �����
//    Book book2;
//
//    std::cout << "������� �������� ������ �����: ";
//    std::cin.getline(book_title2, 255);
//
//    std::cout << "������� ��� ������ ������ �����: ";
//    std::cin.getline(author_of_book2, 255);
//
//    std::cout << "������� ��� ������� ������ �����: ";
//    std::cin >> publication_year2;
//
//    book2.set_title(book_title2);
//    book2.set_author(author_of_book2);
//    book2.set_year(publication_year2);
//
//    //////////////////////////////////////////////////////////////
//    
//    std::cout << "������� ������� � �����?" << "\n";
//    std::cin >> number_of_page2;
//
//    std::cin.ignore();
//    for (size_t i = 0; i < number_of_page2; i++)
//    {
//        std::cout << "�������� ���������� ��������" << "\n";
//        std::cin.getline(page_content2, 255);
//        Page page2(number_of_page2, page_content2);
//        book2.add_page(page2);
//    }
//
//    //////////////////////////////////////////////////////////////
//    // �����
//
//    std::cout << book1.get_title() << "\n";
//    std::cout << book1.get_author() << "\n";
//    std::cout << book1.get_year() << "\n";
//    book1.print();
//
//    std::cout << book2.get_title() << "\n";
//    std::cout << book2.get_author() << "\n";
//    std::cout << book2.get_year() << "\n";
//    book2.print();
//}