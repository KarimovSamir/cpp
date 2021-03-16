#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>

const char* path = "text.txt";

struct User;
class All_Users;
struct Message;
class Autification;

std::ostream& operator << (std::ostream& out, User& ob);

struct User //имя логин пароль
{
    std::string login;
    std::string password;
    Message* head_message_box = nullptr;
    User* next = nullptr;
};

struct Message
{
    std::string message;
    std::string from_who;

    Message* next_message_box = nullptr;
};

class All_Users 
{
private:
    User* m_head_user = nullptr;
public:
    All_Users() = default;

    void read_file()
    {
        std::ifstream in;
        in.open(path);
        if (!in)
        {
            std::cout << "Error in opening file for reading.\n";
            return;
        }

        User* user = new User; // список польз
        m_head_user = user;

        Message* message = nullptr;

        std::string text;
        while (true)
        {
            std::getline(in, text);
            user->login = text;
            //std::cout << text << "\n";
            std::getline(in, text);
            user->password = text;
            //std::cout << text << "\n";

            if (in.eof())
            {
                break;
            }

            while (true)
            {
                std::getline(in, text);
                //std::cout << text << "\n";
                if (text == "NEXT USER")
                {
                    user->next = new User;
                    user = user->next;
                    break;
                }

                if (user->head_message_box == nullptr && text != "")
                { 
                    message = new Message;
                    user->head_message_box = message;
                }
                else 
                {
                    if (in.eof())
                    {
                        break;
                    }
                    message->next_message_box = new Message;
                    message = message->next_message_box;
                }
                message->from_who = text;
                std::getline(in, text);
                message->message = text;
                //std::cout << text << "\n";
            }
            if (in.eof())
            {
                break;
            }
        }
        in.close();
    }

    void add_to_file()
    {
        std::ofstream out;
        User* file_user = m_head_user;
        out.open(path, std::ios::trunc);
        if (!out)
        {
            std::cout << "Error in opening file for writing.\n";
        }
        while (true)
        {
            out << file_user->login << std::endl;
            out << file_user->password << std::endl;

            if (file_user->head_message_box != nullptr)
            {
                Message* data = file_user->head_message_box;
                while (true)
                {
                    out << data->from_who << std::endl;
                    out << data->message << std::endl;

                    if (data->next_message_box == nullptr)
                    {
                        break;
                    }
                    data = data->next_message_box;
                }
            }
            
            if (file_user->next == nullptr)
            {
                break;
            }
            out << "NEXT USER" << std::endl;
            file_user = file_user->next;
        }
        out.close();
    }

    void User_panel(User* user)
    {
        int menu;
        while (true)
        {
            add_to_file();
            system("cls");
            std::cout << "\n1. Send message\n";
            std::cout << "2. Check incoming messages\n";
            std::cout << "3. Information about user\n";
            std::cout << "4. Exit\n";

            std::cout << "Choose: ";
            std::cin >> menu;

            if (menu == 1)
            {
                send_message(user);
                system("pause");
            }
            if (menu == 2)
            {
                std::cout << *user;
                system("pause");
            }
            if (menu == 3)
            {
                std::cout << "User login: " << user->login << std::endl;
                std::cout << "User password: " << user->password << std::endl;
                system("pause");
            }
            if (menu == 4)
            {
                break;
            }
        }
    }

    void send_message(User* user)
    {
        system("cls");

        std::cout << "Select user:\n";
        User* temp = m_head_user;
        for (size_t i = 1;; i++)
        {
            std::cout << i << ". " << temp->login << "\n";

            if (temp->next == nullptr)
            {
                int c;
                do
                {
                    std::cout << "\nChoose: ";
                    std::cin >> c;
                } while (1 > c || c > i);

                temp = m_head_user;
                for (size_t i = 1; i < c; i++)
                {
                    temp = temp->next;
                }
                break;
            }
            temp = temp->next;
        }

        Message* new_message_box = new Message;
        system("cls");
        std::cout << "Enter message: ";
        std::cin.ignore();
        std::getline(std::cin, new_message_box->message);

        char s;
        std::cout << "Do you want to send? Y/N: ";
        std::cin >> s;
        if (s == 'y' || s == 'Y')
        {
            new_message_box->from_who = user->login;

            if (temp->head_message_box == nullptr)
            {
                temp->head_message_box = new_message_box;
            }
            else
            {
                Message* message_box = temp->head_message_box;
                while (true)
                {
                    if (message_box->next_message_box == nullptr)
                    {
                        break;
                    }
                    message_box = message_box->next_message_box;
                }
                message_box->next_message_box = new_message_box;
            }
            std::cout << "\nMessage send succesfuly\n";
        }
        else
        {
            delete new_message_box;
        }
    }

    User* Get_head_user()
    {
        return m_head_user;
    }

    void Set_head(User* head)
    {
        m_head_user = head;
    }

    All_Users* Get_user_data()
    {
        return this; // даёт ячейку памяти в котором хранится адрес ячейки All_Users
    }
};

class Autification
{
private:
    All_Users m_users_data;
public:

    Autification(All_Users& data)
    {
        m_users_data = data;
    }

    bool password_check(User* user, std::string& password_check)
    {
        if (password_check == user->password)
        {
            return true;
        }
        return false;
    }

    User* login_check(std::string& login_check)
    {
        User* temp = m_users_data.Get_head_user();
        while (true)
        {
            if (login_check == temp->login)
            {
                return temp;
            }
            if (temp->next == nullptr)
            {
                break;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    All_Users* Get_m_users_data()
    {
        return &m_users_data;
    }
};

std::ostream& operator << (std::ostream& out, User& ob)
{
    Message* temp = ob.head_message_box;

    if (temp == nullptr) 
    { 
        out << "No message";
        system("pause");
        return out; 
    }

    for (size_t i = 1;; i++)
    {
        out << i << ". message from: " << temp->from_who << "\n";
        out << temp->message << "\n";

        if (temp->next_message_box == nullptr)
        {
            break;
        }
        temp = temp->next_message_box;
    }
    return out;
}

std::istream& operator >> (std::istream& in, All_Users& ob)
{
    User* temp;
    std::string password_check;
    char add;
    while (true)
    {        
        User* temp2;
        do
        {
            temp = new User;
            temp2 = ob.Get_user_data()->Get_head_user();
            std::cout << "Enter login: ";

            std::ifstream file(path, std::ios::ate);
            if (!file.tellg())
            {
                in.ignore();
            }
            if (temp2 != nullptr) // perviy vxod bez file
            {
                in.ignore();
            }
            std::getline(in, temp->login);

            while (temp2 != nullptr)
            {
                if (temp->login == temp2->login)
                {
                    std::cout << "This login is already taken";
                    Sleep(1000);
                    system("cls");
                    break;
                }

                if (temp2->next == nullptr)
                {
                    temp2 = nullptr;
                    break;
                }
                temp2 = temp2->next;
            }

            if (temp2 == nullptr)
            {
                break;
            }
        } while (ob.Get_user_data()->Get_head_user() != nullptr);

        std::cout << "Enter password: ";
        std::getline(in, temp->password);

        do
        {
            system("cls");
            std::cout << "Enter password again: ";
            std::getline(in, password_check);
            if (temp->password != password_check)
            {
                std::cout << "Error, enter password again: ";
                Sleep(1000);
            }
        } while (temp->password != password_check);


        if (ob.Get_user_data()->Get_head_user() == nullptr)
        {
            ob.Get_user_data()->Set_head(temp);
        }
        else
        {
            temp2 = ob.Get_user_data()->Get_head_user();
            while (true)
            {
                if (temp2->next == nullptr)
                {
                    temp2->next = temp;
                    break;
                }
                temp2 = temp2->next;
            }
        }

        std::cout << "\nAdd more user? Y/N?: ";
        in >> add;
        if (add == 'n' || add == 'N')
        {
            break;
        }
        system("cls");
    }
    std::cout << "\nUser added successfully\n";
    return in;
}

std::istream& operator >> (std::istream& in, Autification& ob)
{
    User* user;
    std::string login;
    do
    {
        system("cls");
        std::cout << "Enter to your account\n";
        std::cout << "Enter login: ";

        in >> login;
        user = ob.login_check(login);
        if (!user)
        {
            std::cout << "Error, enter login again";
            Sleep(1000);
        }
    } while (!user);

    std::string password;
    do
    {
        system("cls");
        std::cout << "Enter password: ";
        in >> password;
        if (password != user->password)
        {
            std::cout << "Error, enter password again: ";
            Sleep(1000);
        }
    } while (!ob.password_check(user, password));

    system("cls");
    All_Users all_users;
    all_users = *ob.Get_m_users_data();
    all_users.User_panel(user);
    return in;
}

int main()
{
    All_Users registration;
    registration.read_file();
    

    char z;
    char x;
    while (true)
    {
        if (registration.Get_head_user() == nullptr) 
        {
            std::cin >> registration;
        }
        else 
        {
            std::cout << "Do you want to registrate? Y/N";
            std::cin >> z;
            if (z == 'y' || z == 'Y')
            {
                std::cin >> registration;
            }
        }
        Autification autification(registration);
        while (true)
        {
            std::cin >> autification;

            std::cout << "Do you want to continue? Y/N";
            std::cin >> x;
            if (x != 'y' && x != 'Y')
            {
                return 0;
            }
        }
    }
}

 /*
        Задание 1: Обмен сообщениями
        - Регистрация
            - ввод логина и пароля
        - Аутентификация
            - вход на основе правильного логина и пароля
        - Отправка сообщений:
            - выбор пользователя
            - отправка сообщения выбранному пользователю
        - Чтение сообщений:
            - просмотр сообщений, которые пришли от других пользователей

        При завершении работы с программной сообщения должны быть сохранены.
 */