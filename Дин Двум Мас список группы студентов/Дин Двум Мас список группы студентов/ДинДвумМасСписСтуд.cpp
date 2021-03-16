#include <iostream>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <conio.h>

using namespace std;

/*
    15. Написать программу, позволяющую формировать список студентов академической группы.
    Интерфейс программы должен предоставлять пользователю следующие возможности:
    a.добавление студентов в список;
    b.удаление студента из списка;
    c.модификация студента в списке;
    d.печать списка студентов;
    e.сортировка списка студентов;
    f.поиск студента;
    g.выход из программы.
*/

char* getString();
void add_name(char**& names, int& size, char* name);
void AddStudents(char**& names, int& size);
void Print(char**& text, int& size);
int FindStudent(char**& names, int& size, char* find);
int EditStudent(char**& names, int& size, char* old_student, char* new_one);
void RemoveStudent(char**& names, int& size, char* student);
void Sort(char**& names, int& size);

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char exit;
    int cycle = 1;
    int size = 0;
    char** names = new char* [size];
    while (true)
    {
        cout << "Введите имя" << endl;
        char* new_name = getString();
        add_name(names, size, new_name);
        cout << "Ввести имя (y/n)?" << endl;
        char key = _getch();
        if (key == 'n' || key == 'N')
        {
            break;
        }
    }

    do
    {
        system("cls");
        int choose;
        cout << "Введите номер меню:\n"
            "1. Добавление студентов в список\n"       
            "2. Печать списка студентов\n"             
            "3. Сортировка списка студентов\n"         
            "4. Удаление студента из списка\n"         
            "5. Модификация студента в списке\n"       
            "6. Поиск студента\n"                      
            "7. Выход" << endl;                        
        cin >> choose;
        if (choose == 1)
        {
            cout << "Напишите имена новых студентов." << endl;
            AddStudents(names, size);
        }
        else if (choose == 2)
        {
            cout << "Список студентов" << endl;
            Print(names, size);
        }
        else if (choose == 3)
        {
            Sort(names, size);
            cout << "Список отсортирован" << endl;
        }
        else if (choose == 4)
        {
            char student[50];
            cin.ignore();
            cout << "Напишите имя студента которого хотите удалить" << endl;
            cin.getline(student, 50);
            RemoveStudent(names, size, student);
        }
        else if (choose == 5) 
        {
            cout << "Напишите имя студента которого хотите изменить" << endl;
            cin.ignore();
            char* old_student = getString();

            cout << "Напишите новое имя студента" << endl;
            char* new_one = getString();

            if (EditStudent(names, size, old_student, new_one) == 0)
            {
                cout << "Студент не найден" << endl;
            }
            else
            {
                cout << "Имя " << old_student << " изменено на " << new_one << endl;
            }
        }
        else if (choose == 6)
        {
            cout << "Введите имя студента которого хотите найти" << endl;
            cin.ignore();
            char* find = getString();

            if (FindStudent(names, size, find) == 0)
            {
                cout << "Студент не найден" << endl;
            }
            else
            {
                cout << "Ваш студент " << find << " найден" << endl;
            }
        }

        if (choose >= 1 && choose <= 6)
        {
            cout << "Вы хотите продолжить? Y/N" << endl;
            cin >> exit;

            if (exit == 'y' || exit == 'Y')
            {
                cycle = 1;
            }
            else
            {
                cycle = 0;
            }
        }
        if (choose == 7)
        {
            cout << "Выход";
            cycle = 0;

        }
    } while (cycle); {}
}

char* getString() // Выделяем строке ровно столько символов сколько вписываем
{
    char* name;
    char buffer[500];
    cin.getline(buffer, 500);
    name = new char[strlen(buffer) + 1];
    strcpy(name, buffer);
    return name;
}

void add_name(char**& names, int& size, char* name)
{
    char** temp = new char* [size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = names[i];
    }
    delete[]names;
    names = temp;
    names[size] = name;
    size++;
}

void AddStudents(char**& names, int& size)
{
    while (true)
    {
        char* new_student = getString();
        add_name(names, size, new_student);
        cout << "Ввести имя (y/n)?" << endl;
        char key = _getch();
        if (key == 'n' || key == 'N')
        {
            break;
        }
    }
}

void Print(char**& text, int& size)
{
    for (int i = 0; i < size; i++)
    {
        cout << text[i] << endl;
    }
}

void RemoveStudent(char**& names, int& size, char* student)
{
    for (int i = 0; i < size; i++)
    {   
        //Если strcmp подтвердит что строки равны, то освобождаем память и обнуляем указатель arr[i].
        if (strcmp(names[i], student) == 0)
        {
            delete[] names[i];
            names[i] = nullptr;
        }
    }

    int new_size = 0;

    for (int i = 0; i < size; i++)
    {
        if (names[i] != nullptr)
            new_size++;
    }

    char** new_names = new char* [new_size];

    for (int i = 0, j = 0; i <= new_size; i++)
    {
        if (names[i] != nullptr)
        {
            new_names[j] = names[i];
            j++;
        }
    }

    delete[] names;
    names = new_names;
    size = new_size;
}

int EditStudent(char**& names, int& size, char* old_student, char* new_one)
{
    int edit_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(names[i], old_student) == 0)
        {
            strcpy(names[i], new_one);
            edit_count++;
        }
    }
    if (edit_count == 0)
    {
        return 0;
    }
    
}

int FindStudent(char**& names, int& size, char* find)
{
    int find_count = 0;
    for (int i = 0; i < size; i++)
    {
        if (strlen(names[i]) == strlen(find))
        {
            if (strchr(names[i], find[i]))
            {
                find_count++;
            }
        }
    }
    if (find_count == 0)
    {
        return 0;
    }
}

void Sort(char**& names, int& size)
{
    char temp[500];
    
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}