//#include <iostream>
//#include <windows.h>
//#include <iomanip>
//#include <cstring>
//#include <string>
//#include <cmath>
//#include <fstream>
//
//#ifdef _DEBUG
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
//// allocations to be of _CLIENT_BLOCK type
//#else
//#define DBG_NEW new
//#endif
//
//// std::getline(std::cin >> std::ws, text);
//// std::atof(text.c_str()); // текстовое представление числа с плавающей точкой двойной точности
//
//#define DEBUG
//#define FILE
//#define Auto_add_question
//
//// All users file
//const char* path1 = "AllUsers.txt";
//// Question file
//const char* path2 = "Question.txt";
//
//std::string encryption(const std::string& text);
//std::string decryption(const std::string& text);
//
//float twelve_point_grade(const float& Correct, const float& False, bool percent = false)
//{
//    float temp;
//    if (percent == true)
//    {
//        temp = ((Correct / (Correct + False)) * 100);
//        return temp;
//    }
//    temp = round((Correct / (Correct + False)) * 12);
//    if (temp == 0) { temp = 1; }
//    return temp;
//}
//
//struct User_list;
//struct Question;
//struct Grade;
//struct Test_type;
//class User;
//class All_Test;
//class Authentication;
//
//std::istream& operator >> (std::istream& in, User_list& ob);
//std::ostream& operator << (std::ostream& out, User_list& ob);
//std::istream& operator >> (std::istream& in, User& ob);
//std::ostream& operator << (std::ostream& out, User& ob);
//std::istream& operator >> (std::istream& in, Authentication& ob);
//std::istream& operator >> (std::istream& in, Test_type& ob);
//std::ostream& operator << (std::ostream& out, Test_type& ob);
//std::istream& operator >> (std::istream& in, All_Test& ob);
//std::ostream& operator << (std::ostream& out, All_Test& ob);
//
//struct Test_type // внутри тест тайпов хран€тс€ вопросы
//{
//    std::string test_type_name;
//    Question* question_head = nullptr;
//    float count_of_pass = 0;
//    Test_type* next_test_type = nullptr;
//};
//
//struct Question
//{
//    std::string m_question;
//    std::string m_answer1;
//    std::string m_answer2;
//    std::string m_answer3;
//    std::string m_answer4;
//    int m_correct_answer = 0;
//    Question* m_next = nullptr;
//};
//
//struct Grade
//{
//    std::string test_type_name;
//    int correct_answers = 0;
//    int false_answers = 0;
//    Grade* m_next_grade = nullptr;
//};
//
//struct User_list //им€ логин пароль
//{
//    std::string name;
//    std::string surname;
//    int telephone = 0;
//    std::string login;
//    std::string password;
//    Grade* all_grades = nullptr;
//    Test_type* incomplete_test = nullptr;
//
//    User_list* next = nullptr;
//};
//
//class All_Test
//{
//private:
//    User* user = nullptr;
//    Test_type* m_head_test_type = nullptr;
//    User_list* m_user_online = nullptr; // какой user выполн€ет действи€
//public:
//
//    All_Test(User* user)
//    {
//        this->user = user;
//    }
//
//    /////////////////////////////////////////////
//#ifdef FILE
//    void File_write_question()
//    {
//        std::ofstream out;
//        Test_type* type = m_head_test_type;
//        Question* q = nullptr;
//        out.open(path2, std::ios::trunc);
//        if (!out)
//        {
//            std::cout << "Error in opening file for writing.\n";
//        }
//        if (m_head_test_type == nullptr) { out.close(); return; } // proverka na test type
//
//        while (true)
//        {
//            out << type->test_type_name << std::endl;
//            out << type->count_of_pass << std::endl;
//
//            if (type->question_head != nullptr) // proverka na question
//            {
//                q = type->question_head;
//                while (true)
//                {
//                    out << q->m_question << std::endl;
//                    out << q->m_answer1 << std::endl;
//                    out << q->m_answer2 << std::endl;
//                    out << q->m_answer3 << std::endl;
//                    out << q->m_answer4 << std::endl;
//                    out << q->m_correct_answer << std::endl;
//
//                    if (q->m_next == nullptr)
//                    {
//                        break;
//                    }
//                    q = q->m_next;
//                }
//            }
//
//            if (type->next_test_type == nullptr) { break; }
//            type = type->next_test_type;
//            out << "NEXT TEST TYPE" << std::endl;
//        }
//        out.close();
//    }
//
//    void File_read_question()
//    {
//        std::ifstream in;
//        in.open(path2);
//        if (!in)
//        {
//            /*std::cout << "Error in opening file for reading.\n";*/ return;
//        }
//
//        Test_type* type = nullptr;
//        Question* q = nullptr;
//        std::string text;
//
//        while (true)
//        {
//            std::getline(in, text);
//            if (text == "") // exit
//            {
//                in.close();
//                return;
//            }
//            if (m_head_test_type == nullptr)
//            {
//                type = m_head_test_type = DBG_NEW Test_type;
//            }
//
//            type->test_type_name = text;
//            std::getline(in, text);
//            type->count_of_pass = std::stoi(text);
//
//            if (in.eof()) // exit
//            {
//                in.close();
//                return;
//            }
//
//            while (true)
//            {
//                std::getline(in, text);
//                if (text == "") // exit
//                {
//                    in.close();
//                    return;
//                }
//                if (text == "NEXT TEST TYPE")
//                {
//                    type = type->next_test_type = DBG_NEW Test_type;
//                    break;
//                }
//                if (type->question_head == nullptr)
//                {
//                    q = type->question_head = DBG_NEW Question;
//                }
//                else
//                {
//                    q = q->m_next = DBG_NEW Question; // proverit
//                }
//
//
//                q->m_question = text;
//
//                std::getline(in, text);
//                q->m_answer1 = text;
//                std::getline(in, text);
//                q->m_answer2 = text;
//                std::getline(in, text);
//                q->m_answer3 = text;
//                std::getline(in, text);
//                q->m_answer4 = text;
//                std::getline(in, text);
//                q->m_correct_answer = std::stoi(text);
//
//                if (in.eof()) // exit
//                {
//                    in.close();
//                    return;
//                }
//            }
//        }
//        in.close();
//    }
//#endif // FILE
//    /////////////////////////////////////////////
//
//    void Set_head_test_type(Test_type* type) // *&
//    {
//        m_head_test_type = type;
//    }
//
//    Test_type* Get_head_test_type()
//    {
//        return m_head_test_type;
//    }
//
//    void Set_user_online(User_list* user)
//    {
//        m_user_online = user;
//    }
//
//    User_list* Get_user_online()
//    {
//        return m_user_online;
//    }
//
//    User* Get_user()
//    {
//        return user;
//    }
//
//    Test_type* choose_type(bool& cancel, bool add = false)
//    {
//        if (m_head_test_type == nullptr)
//        {
//            std::cout << "\nNo test";
//            return nullptr;
//        }
//        Test_type* temp = m_head_test_type;
//        int count = 0;
//        while (true)
//        {
//            count++;
//            if (temp->next_test_type == nullptr) { break; }
//            temp = temp->next_test_type;
//        }
//        int c;
//        do
//        {
//            system("cls");
//            std::cout << *m_head_test_type; // —писок test type
//            if (add) { std::cout << ++count << ". *Add test type\n"; } // add function
//            if (cancel) { std::cout << ++count << ". *Cancel\n"; }     // cancel function
//            std::cout << "Choose: ";
//            std::cin >> c;
//        } while (1 > c || c > count);
//
//        temp = m_head_test_type;
//
//        if (c == count && add) // Add test type
//        {
//            std::cin >> *temp;
//            while (true)
//            {
//                if (temp->next_test_type == nullptr) { break; }
//                temp = temp->next_test_type;
//            }
//            return temp;
//        }
//        if (c == count && cancel) { return nullptr; } // proverit
//        cancel = false;
//        for (size_t i = 1; i < c; i++) { temp = temp->next_test_type; }
//        return temp;
//    }
//
//    void auto_add_test()
//    {
//        std::string Logic = "Logic";
//        std::string Math = "Math";
//        //////////////////////////
//        Test_type* type = nullptr;
//        std::string type_name;
//
//        Question* q = nullptr;
//        Question* temp = nullptr;
//        for (size_t Q = 1; Q <= 11; Q++)
//        {
//            if (Q == 1)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Logic;
//                q->m_question = "Whats my name?";
//                q->m_answer1 = "Heizenberg";
//                q->m_answer2 = "Escanor";
//                q->m_answer3 = "I don't know";
//                q->m_answer4 = "Nothing";
//                q->m_correct_answer = 1;
//            }
//            if (Q == 2)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Math;
//                q->m_question = "2 + 2";
//                q->m_answer1 = "5";
//                q->m_answer2 = "4";
//                q->m_answer3 = "I don't know";
//                q->m_answer4 = "Nothing";
//                q->m_correct_answer = 2;
//            }
//            if (Q == 3)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Math;
//                q->m_question = "1 + 1";
//                q->m_answer1 = "1";
//                q->m_answer2 = "3";
//                q->m_answer3 = "2";
//                q->m_answer4 = "I don't know";
//                q->m_correct_answer = 3;
//            }
//            if (Q == 4)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Math;
//                q->m_question = "5 / 1";
//                q->m_answer1 = "1";
//                q->m_answer2 = "5";
//                q->m_answer3 = "0";
//                q->m_answer4 = "Nothing";
//                q->m_correct_answer = 4;
//            }
//            if (Q == 5)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Math;
//                q->m_question = "5 / 2";
//                q->m_answer1 = "1";
//                q->m_answer2 = "5";
//                q->m_answer3 = "0";
//                q->m_answer4 = "Nothing";
//                q->m_correct_answer = 4;
//            }
//            if (Q == 6)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Math;
//                q->m_question = "5 / 3";
//                q->m_answer1 = "1";
//                q->m_answer2 = "5";
//                q->m_answer3 = "0";
//                q->m_answer4 = "Nothing";
//                q->m_correct_answer = 4;
//            }
//            if (Q == 7)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Math;
//                q->m_question = "5 / 4";
//                q->m_answer1 = "1";
//                q->m_answer2 = "5";
//                q->m_answer3 = "0";
//                q->m_answer4 = "Nothing";
//                q->m_correct_answer = 4;
//            }
//            if (Q == 8)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Math;
//                q->m_question = "5 / 5";
//                q->m_answer1 = "1";
//                q->m_answer2 = "5";
//                q->m_answer3 = "0";
//                q->m_answer4 = "Nothing";
//                q->m_correct_answer = 4;
//            }
//            if (Q == 9)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Math;
//                q->m_question = "5 / 0";
//                q->m_answer1 = "1";
//                q->m_answer2 = "5";
//                q->m_answer3 = "0";
//                q->m_answer4 = "Nothing";
//                q->m_correct_answer = 4;
//            }
//            if (Q == 10)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Logic;
//                q->m_question = "Whats?";
//                q->m_answer1 = "Heiz";
//                q->m_answer2 = "Esca";
//                q->m_answer3 = "I do";
//                q->m_answer4 = "Not";
//                q->m_correct_answer = 1;
//            }
//            if (Q == 11)
//            {
//                q = DBG_NEW Question;
//
//                type_name = Logic;
//                q->m_question = "Whats name?";
//                q->m_answer1 = "Heizen";
//                q->m_answer2 = "Es";
//                q->m_answer3 = "I know";
//                q->m_answer4 = "Thing";
//                q->m_correct_answer = 1;
//            }
//            /////////////////////////////////////////////////////////////////////////////////////////////////////////
//            if (m_head_test_type == nullptr) // esli test type pustoy
//            {
//                type = m_head_test_type = DBG_NEW Test_type;
//                type->test_type_name = type_name;
//                type->question_head = q;
//                continue;
//            }
//
//            type = m_head_test_type;
//            while (true)
//            {
//                if (type->test_type_name == type_name) // esli type name uje sushestvuyet
//                {
//                    if (type->question_head == nullptr)
//                    {
//                        type->test_type_name = type_name;
//                        type->question_head = q;
//                        break;
//                    }
//
//                    temp = type->question_head;
//                    while (true)
//                    {
//                        if (temp->m_next == nullptr)
//                        {
//                            temp->m_next = q;
//                            break;
//                        }
//                        temp = temp->m_next;
//                    }
//                    break;
//                }
//                if (type->next_test_type == nullptr)
//                {
//                    type = type->next_test_type = DBG_NEW Test_type;
//                    type->test_type_name = type_name;
//                    type->question_head = q;
//                    break;
//                }
//                type = type->next_test_type;
//            }
//        }
//    }
//
//    void show_all_question()
//    {
//        if (m_head_test_type == nullptr)
//        {
//            std::cout << "\nNo test";
//            system("pause");
//            return;
//        }
//        ////////////////////////////////////////////////////
//        bool cancel = true;
//        Test_type* temp = choose_type(cancel);
//        if (cancel) { return; } // vixod
//        ////////////////////////////////////////////////////
//        std::cout << "\nTest type: " << temp->test_type_name << std::endl;
//        if (temp->question_head == nullptr) { std::cout << "\nEmpty"; system("pause"); return; } // esli nutu voprocov
//
//        Question* q;
//        q = temp->question_head;
//        while (true)
//        {
//            std::cout << "\nQuestion: " << q->m_question << std::endl;
//            std::cout << "Answer 1: " << q->m_answer1 << std::endl;
//            std::cout << "Answer 2: " << q->m_answer2 << std::endl;
//            std::cout << "Answer 3: " << q->m_answer3 << std::endl;
//            std::cout << "Answer 4: " << q->m_answer4 << std::endl;
//            std::cout << "Correct answer: " << q->m_correct_answer << std::endl;
//            if (q->m_next == nullptr) { break; }
//            q = q->m_next;
//        }
//        system("pause");
//    }
//    /*~All_Test()
//    {
//        delete q;
//    }*/
//};
//
//class User //им€ логин пароль
//{
//private:
//    User_list* m_head_user = nullptr;
//public:
//    User() = default;
//
//    void Admin_panel(All_Test* tests_data)
//    {
//        int menu;
//        while (true)
//        {
//            while (true)
//            {
//                system("cls");
//                std::cout << "Hello " << m_head_user->name << std::endl;
//                std::cout << "Modification tools:\n";
//                std::cout << "1. Users\n";
//                std::cout << "2. Test\n";
//                std::cout << "3. Test type\n";
//                std::cout << "4. Change account\n";
//                std::cout << "5. Exit\n";
//
//                std::cout << "Choose: ";
//                std::cin >> menu;
//                if (1 > menu || menu > 5)
//                {
//                    std::cout << "\nError";
//                    Sleep(1000);
//                    continue;
//                }
//                break;
//            }
//
//            if (menu == 1)
//            {
//                Modification_user();
//            }
//            if (menu == 2)
//            {
//                Modification_test(tests_data);
//            }
//            if (menu == 3)
//            {
//                Modification_test_type(tests_data);
//            }
//            if (menu == 4)
//            {
//                if (m_head_user->next == nullptr)
//                {
//                    std::cout << "You need add user" << std::endl;
//                    Sleep(1000);
//                    system("cls");
//                }
//                else
//                {
//                    break;
//                }
//            }
//            if (menu == 5)
//            {
//                exit(0);
//            }
//        }
//    }
//
//    void Modification_user() // zapis v file
//    {
//        User_list* temp;
//        User_list* temp2;
//        int menu;
//        int amount_of_users;
//        size_t index;
//        while (true)
//        {
//            temp = m_head_user;
//            temp2 = m_head_user;
//            while (true)
//            {
//                system("cls");
//                std::cout << "Modification tools:\n";
//                std::cout << "1. Add user\n";
//                std::cout << "2. Delete user\n";
//                std::cout << "3. Users modification\n";
//                std::cout << "4. My settings\n";
//                std::cout << "5. Cancel\n";
//
//                std::cout << "Choose: ";
//                std::cin >> menu;
//                if (1 > menu || menu > 5)
//                {
//                    std::cout << "\nError";
//                    Sleep(1000);
//                    continue;
//                }
//                break;
//            }
//            //////////////////////////////////////// podscet kolicestvo user
//            amount_of_users = 0;
//            while (true)
//            {
//                if (temp->next == nullptr) { break; }
//                temp = temp->next;
//                amount_of_users++;
//            }
//            ////////////////////////////////////////
//            temp = m_head_user;
//            ////////////////////////////////////////
//            if (menu == 1)
//            {
//                std::cin >> *this;
//            }
//            if (menu == 2)
//            {
//                if (temp->next == nullptr) { std::cout << "No any user to delete"; Sleep(1000); continue; }
//
//                std::cout << "Delete mode:\n";
//                std::cout << *this; // —писок всех user по login
//                std::cout << amount_of_users + 1 << ". *Cancel\n"; // Cancel
//
//
//                std::cout << "Choose: ";
//                std::cin >> index;
//
//                if (1 > index || index > amount_of_users) { continue; } // Cancel
//
//                temp = temp->next;
//                for (size_t i = 1; i < index; i++)
//                {
//                    temp = temp->next;
//                    temp2 = temp2->next;
//                }
//                temp2->next = temp->next;
//
//#ifdef FILE
//                clean_TESTDATA(temp); // ociwenie pamyati
//#endif // FILE
//                delete temp;          // ociwenie pamyati
//                std::cout << "\nUser deleted succesfully";
//                Sleep(1000);
//            }
//            if (menu == 3)
//            {
//                if (temp->next == nullptr) { std::cout << "No any user to modificate"; Sleep(1000); continue; }
//
//                std::cout << "Modification mode:\n";
//                std::cout << *this; // —писок всех user по login
//                std::cout << amount_of_users + 1 << ". *Cancel\n"; // Cancel
//
//
//                std::cout << "Choose: ";
//                std::cin >> index;
//
//                if (1 > index || index > amount_of_users) { continue; } // Cancel
//
//                for (size_t i = 0; i < index; i++)
//                {
//                    temp = temp->next;
//                }
//                std::cout << *temp;
//                std::cin >> *temp;
//            }
//            if (menu == 4)
//            {
//                std::cout << *temp;
//                std::cin >> *temp;
//            }
//            if (menu == 5)
//            {
//                return;
//            }
//            //////////////////////////////////////////////////////////// zapis v file
//#ifdef FILE
//            File_write_user_and_TESTDATA();
//#endif // FILE
//            ////////////////////////////////////////////////////////////
//        }
//    }
//
//    void Modification_test(All_Test* tests_data)
//    {
//        int menu;
//        while (true)
//        {
//            while (true)
//            {
//                system("cls");
//                std::cout << "Test tools:\n";
//                std::cout << "1. Add test\n";
//                std::cout << "2. Show all test\n";
//                std::cout << "3. Show statistic\n";
//                std::cout << "4. Cancel\n";
//
//                std::cout << "Choose: ";
//                std::cin >> menu;
//                if (1 > menu || menu > 4)
//                {
//                    std::cout << "\nError";
//                    Sleep(1000);
//                    continue;
//                }
//                break;
//            }
//
//            if (menu == 1)
//            {
//                std::cin >> *tests_data;
//            }
//            if (menu == 2)
//            {
//                tests_data->show_all_question();
//            }
//            if (menu == 3)
//            {
//                int all = 0;
//                Test_type* temp = tests_data->Get_head_test_type();
//
//                if (temp == nullptr) { std::cout << "\nNo statistic\n"; system("pause"); continue; }
//
//                while (true)
//                {
//                    std::cout << "\n" << temp->test_type_name << " - " << temp->count_of_pass;
//                    all += temp->count_of_pass;
//                    if (temp->next_test_type == nullptr) { break; }
//                    temp = temp->next_test_type;
//                }
//                std::cout << "\nAll - " << all << std::endl;
//                system("pause");
//            }
//            if (menu == 4) { break; }
//        }
//    }
//
//    // zapis v file
//    void Modification_test_type(All_Test* tests_data)
//    {
//        int menu;
//        while (true)
//        {
//            while (true)
//            {
//                system("cls");
//                std::cout << "Test type tools:\n";
//                std::cout << "1. Add test type\n";
//                std::cout << "2. Show all test types\n";
//                std::cout << "3. Cancel\n";
//
//                std::cout << "Choose: ";
//                std::cin >> menu;
//                if (1 > menu || menu > 3)
//                {
//                    std::cout << "\nError";
//                    Sleep(1000);
//                    continue;
//                }
//                break;
//            }
//
//            if (menu == 1)
//            {
//                char add;
//                while (true)
//                {
//                    if (tests_data->Get_head_test_type() == nullptr) { tests_data->Set_head_test_type(DBG_NEW Test_type); }
//
//                    std::cin >> *(tests_data->Get_head_test_type());
//#ifdef FILE
//                    tests_data->File_write_question();               // zapis v file
//#endif // FILE
//
//                    std::cout << "\nAdd more? Y/N?: ";
//                    std::cin >> add;
//                    if (add != 'y' && add != 'Y')
//                    {
//                        break;
//                    }
//                }
//            }
//            if (menu == 2)
//            {
//                std::cout << *(tests_data->Get_head_test_type());
//                system("pause");
//            }
//            if (menu == 3) { break; }
//        }
//    }
//
//    ///////////////////////////////////////////////////////////////
//
//    void User_panel(All_Test* tests_data, User_list* user)
//    {
//        int menu;
//        while (true)
//        {
//            while (true)
//            {
//                system("cls");
//                std::cout << "Hello " << user->surname << " " << user->name << std::endl;
//                std::cout << "\n1. To do test\n";
//                std::cout << "2. Show statistic\n";
//                std::cout << "3. Information about user\n";
//                std::cout << "4. Change account\n";
//                std::cout << "5. Exit\n";
//
//                std::cout << "Choose: ";
//                std::cin >> menu;
//                if (1 > menu || menu > 5)
//                {
//                    std::cout << "\nError";
//                    Sleep(1000);
//                    continue;
//                }
//                break;
//            }
//
//            if (menu == 1)
//            {
//                std::cout << *tests_data;
//            }
//            if (menu == 2)
//            {
//                User_grade(user);
//            }
//            if (menu == 3)
//            {
//                std::cout << "\nUser name: " << user->name << std::endl;
//                std::cout << "User surname: " << user->surname << std::endl;
//                std::cout << "User telephone: " << user->telephone << std::endl;
//                std::cout << "User login: " << user->login << std::endl;
//                std::cout << "User password: " << user->password << std::endl;
//                system("pause");
//            }
//            if (menu == 4)
//            {
//                break;
//            }
//
//            if (menu == 5)
//            {
//                exit(0);
//            }
//        }
//    }
//
//    void User_grade(User_list* user)
//    {
//        if (user->all_grades == nullptr) { std::cout << "\nNo data\n"; system("pause"); return; }
//
//        Grade* temp = user->all_grades;
//        while (true)
//        {
//            std::cout << "\nTest type name   - " << temp->test_type_name << std::endl;
//            std::cout << "Grade            - " << twelve_point_grade(temp->correct_answers, temp->false_answers) << std::endl;
//            std::cout << "Percent          - " << std::setprecision(3) << twelve_point_grade(temp->correct_answers, temp->false_answers, true) << "%" << std::endl;
//            std::cout << "Correct answers  - " << temp->correct_answers << std::endl;
//            std::cout << "False answers    - " << temp->false_answers << std::endl;
//
//            if (temp->m_next_grade == nullptr) { break; }
//            temp = temp->m_next_grade;
//        }
//        system("pause");
//    }
//
//    ///////////////////////////////////////////////////////////////
//#ifdef FILE
//
//    void File_read_user_and_TESTDATA()
//    {
//        std::ifstream in;
//        in.open(path1);
//        if (!in)
//        {
//            /*std::cout << "Error in opening file for reading.\n";*/ return;
//        }
//
//        User_list* user = DBG_NEW User_list;
//        m_head_user = user;
//
//        Grade* grade = nullptr;
//
//        std::string text;
//        while (true)
//        {
//            std::getline(in, text);
//            user->name = text;
//            std::getline(in, text);
//            user->surname = text;
//            std::getline(in, text);
//            user->telephone = std::stoi(text);
//            std::getline(in, text);
//            user->login = decryption(text); // wifrovanie
//            std::getline(in, text);
//            user->password = decryption(text); // wifrovanie
//
//            if (in.eof())
//            {
//                break;
//            }
//
//            while (true)
//            {
//                std::getline(in, text);
//                if (text == "NEXT USER")
//                {
//                    user->next = DBG_NEW User_list;
//                    user = user->next;
//                    break;
//                }
//                /////////////////////////////////////////////////////////////// TEST DATA
//                if (text == "TEST DATA +" || text == "LAST TEST DATA")
//                {
//                    std::string data = text;
//                    std::getline(in, text);
//
//                    Test_type* temp = user->incomplete_test;
//                    if (temp == nullptr)
//                    {
//                        temp = user->incomplete_test = DBG_NEW Test_type;
//                    }
//                    else
//                    {
//                        while (true)
//                        {
//                            if (temp->test_type_name == text) { break; }
//                            if (temp->next_test_type == nullptr) { temp = temp->next_test_type = DBG_NEW Test_type; break; }
//                            temp = temp->next_test_type;
//                        }
//                    }
//                    // запоминает непройденые тесты
//                    if (data == "TEST DATA +")
//                    {
//                        temp->test_type_name = text;
//
//                        std::getline(in, text);
//                        temp->count_of_pass = std::atof(text.c_str());
//                    }
//                    // записывает при выходе из программы, при новом заходе, записывает данные в TEST DATA + и удал€етс€
//                    if (data == "LAST TEST DATA")
//                    {
//                        temp->test_type_name = text;
//
//                        std::getline(in, text);
//                        temp->count_of_pass = std::stoi(text);
//
//                        std::getline(in, text);
//                        temp->count_of_pass = (temp->count_of_pass / 10) + std::stoi(text);
//                    }
//                    continue;
//                }
//                ///////////////////////////////////////////////////////////////
//                //text != "" - проверка на пустую строку и заходит в else если text равен пустоте
//                if (user->all_grades == nullptr && text != "")
//                {
//                    grade = DBG_NEW Grade;
//                    user->all_grades = grade;
//                }
//                else
//                {
//                    if (in.eof())
//                    {
//                        break;
//                    }
//                    grade->m_next_grade = DBG_NEW Grade;
//                    grade = grade->m_next_grade;
//                }
//                grade->test_type_name = text;
//
//                std::getline(in, text);
//                grade->correct_answers = std::stoi(text);
//                std::getline(in, text);
//                grade->false_answers = std::stoi(text);
//            }
//            if (in.eof())
//            {
//                break;
//            }
//        }
//        in.close();
//    }
//
//    // параметры работают во врем€ выполнени€ теста 
//    void File_write_user_and_TESTDATA(bool turn_on = false, std::string user_login = "", std::string test_type_name = "", float Correct = 0, float False = 0)
//    {
//        std::ofstream fout;
//        User_list* file_user = m_head_user;
//        fout.open(path1, std::ios::trunc);
//        if (!fout)
//        {
//            std::cout << "Error in opening file for writing.\n";
//        }
//        while (true)
//        {
//            fout << file_user->name << std::endl;
//            fout << file_user->surname << std::endl;
//            fout << file_user->telephone << std::endl;
//            fout << encryption(file_user->login) << std::endl; // wifrovanie
//            fout << encryption(file_user->password) << std::endl; // wifrovanie
//
//            if (file_user->all_grades != nullptr)
//            {
//                Grade* data = file_user->all_grades;
//                while (true)
//                {
//                    fout << data->test_type_name << std::endl;
//                    fout << data->correct_answers << std::endl;
//                    fout << data->false_answers << std::endl;
//
//                    if (data->m_next_grade == nullptr)
//                    {
//                        break;
//                    }
//                    data = data->m_next_grade;
//                }
//            }
//
//            if (file_user->incomplete_test != nullptr)
//            {
//                Test_type* temp = file_user->incomplete_test;
//                while (true)
//                {
//                    fout << "TEST DATA +" << std::endl;
//                    fout << temp->test_type_name << std::endl;
//                    fout << temp->count_of_pass << std::endl;
//
//                    if (temp->next_test_type == nullptr) { break; }
//                    temp = temp->next_test_type;
//                }
//            }
//            //////////////////////////////////////////////////////
//            //user_login - проверка на конкретного user который проходит тест
//            if (turn_on && file_user->login == user_login)
//            {
//                fout << "LAST TEST DATA" << std::endl;
//                fout << test_type_name << std::endl;
//                fout << Correct << std::endl;
//                fout << False << std::endl;
//            }
//            //////////////////////////////////////////////////////
//            if (file_user->next == nullptr)
//            {
//                break;
//            }
//            fout << "NEXT USER" << std::endl;
//            file_user = file_user->next;
//        }
//        fout.close();
//    }
//
//    // type_to_clean - передаЄм конкретное название type дл€ удалени€, когда user его окончательно сдал и он чистит из TEST DATA +
//    // если ничего не передать он удалит все незаконченные тесты, передаЄт по умолчанию "CLEAN ALL DATA"
//    // когда мы удал€ем user с незаконченными тестами, очищает User_list -> Test_type* incomplete_test
//    // 
//    void clean_TESTDATA(User_list* user, std::string type_to_clean = "CLEAN ALL DATA")
//    {
//        // если у user нет незаконченых тестов
//        if (user->incomplete_test == nullptr) { return; }
//
//        Test_type* user_data = nullptr;
//        Test_type* temp = user->incomplete_test;
//        // удал€ет всЄ
//        if (type_to_clean == "CLEAN ALL DATA")
//        {
//            while (true)
//            {
//                user_data = temp->next_test_type;
//                delete temp; // ociwenie pamyati
//
//                if (user_data == nullptr) { return; }
//                temp = user_data;
//            }
//        }
//        // удал€ет конкретный test_type
//        if (temp->test_type_name == type_to_clean)
//        {
//            user->incomplete_test = temp->next_test_type;
//            delete temp; // ociwenie pamyati
//            return;
//        }
//
//        temp = temp->next_test_type;
//        if (temp != nullptr)
//        {
//            user_data = user->incomplete_test;
//            while (true)
//            {
//                if (temp->test_type_name == type_to_clean)
//                {
//                    break;
//                }
//
//                if (user_data->next_test_type == nullptr) { return; }
//                user_data = user_data->next_test_type;
//                temp = temp->next_test_type;
//            }
//            user_data->next_test_type = temp->next_test_type;
//            delete temp; // ociwenie pamyati
//        }
//    }
//
//#endif // FILE
//
//    User_list* Get_head()
//    {
//        return m_head_user;
//    }
//
//    void Set_head(User_list* head)
//    {
//        m_head_user = head;
//    }   
//};
//
//class Authentication
//{
//private:
//    User m_users_data;
//    All_Test m_tests_data = nullptr; // нет дефолт конструктора
//public:
//
//    Authentication(User& data, All_Test& data2)
//    {
//        m_users_data = data;
//        m_tests_data = data2;
//    }
//
//    bool Admin_check(User_list* Admin)
//    {
//        return Admin == m_users_data.Get_head();
//    }
//
//    bool password_check(User_list* user, std::string& password_check)
//    {
//        if (password_check == user->password)
//        {
//            return true;
//        }
//        return false;
//    }
//
//    User_list* login_check(std::string& login_check)
//    {
//        User_list* temp = m_users_data.Get_head();
//        while (true)
//        {
//            if (login_check == temp->login)
//            {
//                return temp;
//            }
//            if (temp->next == nullptr)
//            {
//                break;
//            }
//            temp = temp->next;
//        }
//        return nullptr;
//    }
//
//    User* Get_m_users_data()
//    {
//        return &m_users_data;
//    }
//
//    All_Test* Get_m_tests_data()
//    {
//        return &m_tests_data;
//    }
//};
//
//// »зменение данных user
//std::istream& operator >> (std::istream& in, User_list& ob)
//{
//    int menu;
//    while (true)
//    {
//        do
//        {
//            std::cout << "\nChange:\n";
//            std::cout << "1. Login\n";
//            std::cout << "2. Password\n";
//            std::cout << "3. Name\n";
//            std::cout << "4. Surname\n";
//            std::cout << "5. Telephone\n";
//            std::cout << "6. Cancel\n";
//
//            std::cout << "Choose: ";
//            in >> menu;
//            if (1 > menu || menu > 6)
//            {
//                std::cout << "Error";
//                Sleep(1000);
//            }
//        } while (1 > menu || menu > 6);
//
//        std::cout << "\n:";
//        if (menu == 1)
//        {
//            std::getline(in >> std::ws, ob.login);
//        }
//        if (menu == 2)
//        {
//            std::getline(in >> std::ws, ob.password);
//        }
//        if (menu == 3)
//        {
//            std::getline(in >> std::ws, ob.name);
//        }
//        if (menu == 4)
//        {
//            std::getline(in >> std::ws, ob.surname);
//        }
//        if (menu == 5)
//        {
//            in >> ob.telephone;
//        }
//        if (menu == 6)
//        {
//            break;
//        }
//    }
//    return in;
//}
//
//// ƒанные user
//std::ostream& operator << (std::ostream& out, User_list& ob)
//{
//    system("cls");
//    out << "User info:\n";
//    out << "Login     - " << ob.login << "\n";
//    out << "Password  - " << ob.password << "\n";
//    out << "Name      - " << ob.name << "\n";
//    out << "Surname   - " << ob.surname << "\n";
//    out << "Telephone - " << ob.telephone << "\n";
//    return out;
//}
//
//// ƒобавление user -> (zapis v file user)
//std::istream& operator >> (std::istream& in, User& ob)
//{
//    User_list* temp; // логин который вводим
//    User_list* temp2; // проверка на повтор логина
//    std::string password_check;
//    bool c = false;
//    char add;
//    while (true)
//    {
//        temp = DBG_NEW User_list;
//
//        if (ob.Get_head() == nullptr)
//        {
//            temp->name = "Admin";
//            std::cout << "Hi " << temp->name << "\n";
//        }
//        else
//        {
//#ifndef DEBUG
//            std::cout << "Enter name: ";
//            std::getline(in >> std::ws, temp->name);
//            std::cout << "Enter surname: ";
//            std::getline(in >> std::ws, temp->surname);
//            std::cout << "Enter telephone: ";
//            in >> temp->telephone;
//#endif // DEBUG
//        }
//
//        do
//        {
//            std::cout << "Enter login: ";
//            std::getline(in >> std::ws, temp->login);
//
//            temp2 = ob.Get_head();
//            while (temp2 != nullptr)
//            {
//                if (temp->login == temp2->login)
//                {
//                    std::cout << "This login is already taken";
//                    Sleep(1000);
//                    system("cls");
//                    c = true;
//                    break;
//                }
//
//                if (temp2->next == nullptr)
//                {
//                    c = false;
//                    break;
//                }
//                temp2 = temp2->next;
//            }
//        } while (ob.Get_head() != nullptr && c);
//
//        std::cout << "Enter password: ";
//        std::getline(in >> std::ws, temp->password);
//
//        do
//        {
//            system("cls");
//            std::cout << "Enter password again: ";
//            std::getline(in >> std::ws, password_check);
//            if (temp->password != password_check)
//            {
//                std::cout << "Error, enter password again: ";
//                Sleep(1000);
//            }
//        } while (temp->password != password_check);
//
//        // добавление в user_list
//        if (ob.Get_head() == nullptr)
//        {
//            ob.Set_head(temp);
//        }
//        else
//        {
//            temp2 = ob.Get_head();
//            while (true)
//            {
//                if (temp2->next == nullptr)
//                {
//                    temp2->next = temp;
//                    break;
//                }
//                temp2 = temp2->next;
//            }
//        }
//        //////////////////////////////////////////////// zapis v file
//#ifdef FILE
//        ob.File_write_user_and_TESTDATA();
//#endif // FILE
//        ////////////////////////////////////////////////
//        std::cout << "\nAdd more user? Y/N?: ";
//        in >> add;
//        if (add != 'y' && add != 'Y')
//        {
//            break;
//        }
//        system("cls");
//    }
//    return in;
//}
//
//// —писок всех user по login
//std::ostream& operator << (std::ostream& out, User& ob)
//{
//    User_list* temp = ob.Get_head()->next;
//    size_t index = 1;
//    out << "\nUsers list:\n";
//    while (true)
//    {
//        out << index << ". " << temp->login << "\n"; // list of logins
//        index++;
//
//        if (temp->next == nullptr)
//        {
//            break;
//        }
//        temp = temp->next;
//    }
//    return out;
//}
//
//// јутентификаци€
//std::istream& operator >> (std::istream& in, Authentication& ob)
//{
//    User_list* user;
//    std::string login;
//    do
//    {
//        system("cls");
//        std::cout << "Enter to your account\n";
//        std::cout << "Enter login: ";
//        in >> login;
//        user = ob.login_check(login);
//        if (!user)
//        {
//            std::cout << "Error, enter login again";
//            Sleep(1000);
//        }
//    } while (!user);
//
//    std::string password;
//    do
//    {
//        system("cls");
//        std::cout << "Enter password: ";
//        in >> password;
//        if (password != user->password)
//        {
//            std::cout << "Error, enter password again: ";
//            Sleep(1000);
//        }
//    } while (!ob.password_check(user, password));
//
//    if (ob.Admin_check(user))
//    {
//        system("cls");
//        ob.Get_m_users_data()->Admin_panel(ob.Get_m_tests_data());
//    }
//    else
//    {
//        system("cls");
//        ob.Get_m_tests_data()->Set_user_online(user);
//        ob.Get_m_users_data()->User_panel(ob.Get_m_tests_data(), user);
//    }
//
//    return in;
//}
//
//// ƒобавление test type
//std::istream& operator >> (std::istream& in, Test_type& ob)
//{
//    if (ob.test_type_name == "") // без ссылки не приравниваетс€ к nullptr
//    {
//        system("cls");
//        std::cout << "\nPlease write the type of tests: ";
//        std::getline(in >> std::ws, ob.test_type_name);
//        return in;
//    }
//
//    Test_type* last = &ob;
//    Test_type* temp = nullptr;
//    while (true)
//    {
//        if (last->next_test_type == nullptr)
//        {
//            break;
//        }
//        last = last->next_test_type;
//    }
//
//    last = last->next_test_type = DBG_NEW Test_type;
//
//    while (true)
//    {
//        system("cls");
//        std::cout << "Please write the type of tests: ";
//
//        std::getline(in >> std::ws, last->test_type_name);
//
//        temp = &ob;
//        while (true)
//        {
//            if (last->test_type_name == temp->test_type_name && temp->next_test_type != nullptr)
//            {
//                std::cout << "\nName of type already taken\n";
//                system("pause");
//                break;
//            }
//
//            if (temp->next_test_type == nullptr)
//            {
//                return in;
//            }
//            temp = temp->next_test_type;
//        }
//    }
//    return in;
//}
//
//// —писок test type
//std::ostream& operator << (std::ostream& out, Test_type& ob)
//{
//    size_t index = 1;
//    Test_type* temp = &ob;
//    if (temp == nullptr)
//    {
//        out << "No test type\n";
//        return out;
//    }
//    out << "\nTest type:\n";
//    while (true)
//    {
//        out << index << ". " << temp->test_type_name << "\n";
//        index++;
//
//        if (temp->next_test_type == nullptr)
//        {
//            break;
//        }
//        temp = temp->next_test_type;
//    }
//    return out;
//}
//
//// ƒобавление test -> (zapis v file question)
//std::istream& operator >> (std::istream& in, All_Test& ob)
//{
//    Question* temp;
//    Test_type* type = nullptr;
//    Test_type* type2;
//
//    size_t index;
//    size_t choose_type;
//    char add;
//    while (true)
//    {
//        temp = DBG_NEW Question;
//        std::cout << "\nWrite question: ";
//        std::getline(in >> std::ws, temp->m_question);
//
//        std::cout << "Answer 1: ";
//        std::getline(in >> std::ws, temp->m_answer1);
//
//        std::cout << "Answer 2: ";
//        std::getline(in >> std::ws, temp->m_answer2);
//
//        std::cout << "Answer 3: ";
//        std::getline(in >> std::ws, temp->m_answer3);
//
//        std::cout << "Answer 4: ";
//        std::getline(in >> std::ws, temp->m_answer4);
//
//        std::cout << "Correct answer (enter number): ";
//        in >> temp->m_correct_answer;
//
//        /////////////////////////////////////// 
//        if (ob.Get_head_test_type() == nullptr)
//        {
//            ob.Set_head_test_type(DBG_NEW Test_type);
//
//            std::cout << "\nPlease add test type: ";
//            std::getline(in >> std::ws, ob.Get_head_test_type()->test_type_name);
//            type = ob.Get_head_test_type();
//        }
//        else
//        {
//            bool cancel = false;
//            type = ob.choose_type(cancel, true);
//        }
//        ///////////////////////////////////////
//
//        ///////////////////////////////////////
//        if (type->question_head == nullptr)
//        {
//            type->question_head = temp;
//        }
//        else
//        {
//            Question* temp2 = type->question_head;
//            while (true)
//            {
//                if (temp2->m_next == nullptr)
//                {
//                    temp2->m_next = temp;
//                    break;
//                }
//                temp2 = temp2->m_next;
//            }
//        }
//        ///////////////////////////////////////
//#ifdef FILE
//        ob.File_write_question(); // zapis v file
//#endif // FILE
//
//        std::cout << "\nAdd more? Y/N?: ";
//        std::cin >> add;
//        if (add == 'n' || add == 'N')
//        {
//            break;
//        }
//        system("cls");
//    }
//    return in;
//}
//
//// —писок и прохождение test -> (zapis v file user & TEST DATA)
//std::ostream& operator << (std::ostream& out, All_Test& ob)
//{
//    if (ob.Get_head_test_type() == nullptr)
//    {
//        out << "No test yet, please add a test\n";
//        system("pause");
//        return out;
//    }
//    //////////////////////////////////////////
//    Test_type* type = ob.Get_head_test_type();
//    Test_type* temp = nullptr;
//    float Correct = 0;
//    float False = 0;
//    ////////////////////////////////////////// vibor type
//
//    bool data = false;
//    bool cancel = false;
//    type = ob.choose_type(cancel);
//
//    if (ob.Get_user_online()->incomplete_test != nullptr)
//    {
//        temp = ob.Get_user_online()->incomplete_test;
//
//        while (true)
//        {
//            if (type->test_type_name == temp->test_type_name)
//            {
//                False = trunc(temp->count_of_pass);
//                Correct = trunc((temp->count_of_pass - False) * 10);
//                data = true;
//                break;
//            }
//
//            if (temp->next_test_type == nullptr) { break; }
//            temp = temp->next_test_type;
//        }
//    }
//    ///////////////////////////////
//
//    if (type->question_head == nullptr) // proverka na pustotu test type
//    {
//        out << "\nEmpty";
//        Sleep(1000);
//        return out;
//    }
//
//    int s;
//    Question* test = type->question_head;
//    while (true)
//    {
//        //////////////////////////////////////////////////////// esli est ne zakocheniy test
//        if (data)
//        {
//            for (size_t i = 0; i < int(Correct + False); i++)
//            {
//                test = test->m_next;
//            }
//            data = false;
//        }
//        ////////////////////////////////////////////////////////
//        do
//        {
//            system("cls");
//            out << type->test_type_name << std::endl;
//            out << Correct + False + 1 << " question: " << test->m_question << std::endl;
//            out << "1) " << test->m_answer1 << std::endl;
//            out << "2) " << test->m_answer2 << std::endl;
//            out << "3) " << test->m_answer3 << std::endl;
//            out << "4) " << test->m_answer4 << std::endl;
//
//            out << "\nSelect answer: ";
//            std::cin >> s;
//        } while (1 > s || s > 4);
//
//        if (s == test->m_correct_answer)
//        {
//            Correct++;
//        }
//        else
//        {
//            False++;
//        }
//        /////////////////////////////////////////////// запись в файл во врем€ прохождени€ теста
//#ifdef FILE
//        ob.Get_user()->File_write_user_and_TESTDATA(true, ob.Get_user_online()->login, type->test_type_name, Correct, False);
//#endif // FILE
//        ///////////////////////////////////////////
//        if (test->m_next == nullptr)
//        {
//            break;
//        }
//        test = test->m_next;
//    }
//
//    //////////////////////////////////////////////// rasstavlenie ocenok
//
//    Grade* grade = ob.Get_user_online()->all_grades;
//    if (grade == nullptr)                             // esli polzovatel v perviy raz proxodit test
//    {
//        ob.Get_user_online()->all_grades = grade = DBG_NEW Grade;
//    }
//    else                                              // esli polzovatel uje proxodil test
//    {
//        while (true)
//        {
//            if (grade->test_type_name == type->test_type_name)
//            {
//                break;
//            }
//            if (grade->m_next_grade == nullptr)
//            {
//                grade = grade->m_next_grade = DBG_NEW Grade;
//                break;
//            }
//            grade = grade->m_next_grade;
//        }
//    }
//
//    ////////////////////////////////////////////////
//
//    type->count_of_pass++;                                         // scocik proxojdeniya testa
//    grade->test_type_name = type->test_type_name;                  // zapis test type name
//    grade->correct_answers = Correct;                              // pravilnie
//    grade->false_answers = False;                                  // ne pravilnie
//
//    ///////////////////////////////////////////////////////// zapis v file user & question
//#ifdef FILE
//    ob.Get_user()->clean_TESTDATA(ob.Get_user_online(), type->test_type_name);
//    ob.Get_user()->File_write_user_and_TESTDATA();
//    ob.File_write_question(); // записывает count_of_pass
//#endif // FILE
//    /////////////////////////////////////////////////////////
//
//    out << "\nCorrect: " << grade->correct_answers << "\n";
//    out << "false: " << grade->false_answers << "\n";
//    out << std::setprecision(3) << "Percent: " << twelve_point_grade(grade->correct_answers, grade->false_answers, true) << "%\n";
//    out << "grade: " << twelve_point_grade(grade->correct_answers, grade->false_answers) << "\n";
//    system("pause");
//    return out;
//}
//
//bool is_empty(std::ifstream& pFile)
//{
//    return pFile.peek() == std::ifstream::traits_type::eof();
//}
//
//std::string encryption(const std::string& text)
//{
//    std::string temp = text;
//    for (int i = 0; i < text.size(); i++)
//    {
//        if (temp[i] != 32)
//        {
//            temp[i] = temp[i] + 3;
//        }
//    }
//    return temp;
//}
//
//std::string decryption(const std::string& text)
//{
//    std::string temp = text;
//    for (int i = 0; i < text.size(); i++)
//    {
//        if (temp[i] != 32)
//        {
//            temp[i] = temp[i] - 3;
//        }
//    }
//    return temp;
//}
//
//int main()
//{
//    User registration;
//
//#ifdef FILE
//    registration.File_read_user_and_TESTDATA();
//#endif // FILE
//    std::ifstream file(path1);
//    if (is_empty(file))
//    {
//        std::cin >> registration;
//    }
//
//    All_Test all_test(&registration);
//
//#ifdef FILE
//    all_test.File_read_question();
//#endif // FILE
//    if (is_empty(file))
//    {
//#ifdef Auto_add_question
//        all_test.auto_add_test();
//#endif // Auto_add_question
//
//#ifdef FILE
//        all_test.File_write_question();
//#endif // FILE
//    }
//
//    Authentication autification(registration, all_test);
//    /*while (true)
//    {
//        
//    }*/
//    std::cin >> autification;
//    _CrtDumpMemoryLeaks();
//    
//    return 0;
//}