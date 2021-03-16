#include <iostream>
#include "header.h""
using namespace std;



void main()
{
    setlocale(LC_ALL, "rus");
    int choose;
    cout << "Выберите номер функции: ";
    cin >> choose;
    if (choose == 1) //++
    {
        cout << "Функция определяет длину строки" << endl;
        char text[255];
        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text, 255);
        cout << "Ваш текст: " << mystrlen_1(text) << endl;
    }
    else if (choose == 2) //++
    {
        cout << "Функция копирует строку str2 в буфер, адресуемый через str1. Функция возвращает указатель на первую строку str1" << endl;
        char text1[255];
        char text2[255];
        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text2, 255);
        cout << "Ваш текст: " << mystrcpy_2(text1, text2) << endl;
    }
    else if (choose == 3) //++
    {
        cout << "Функция присоединяет строку str2 к строке str1. Функция возвращает указатель на первую строку str1" << endl;
        char text1[255];
        char text2[255];
        cin.ignore();
        cout << "Введите 1 текст (у вас 254 символов)" << endl;
        cin.getline(text1, 255);

        cout << "Введите 2 текст (у вас 254 символов)" << endl;
        cin.getline(text2, 255);
        mystrcat_3(text1, text2);
        cout << text1;
    }
    else if (choose == 4) //++
    {
        cout << "Функция осуществляет поиск символа symbol в строке str. Функция возвращает указатель на первое вхождение символа в строку, в противном случае 0" << endl;
        char text[255];
        char symbol;
        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text, 255);
        cout << "Введите символ который хотите найти" << endl;
        cin >> symbol;
        cout << "Ваш текст: " << mystrchr_4(text, symbol) << endl;
    }
    else if (choose == 5) //++
    {
        cout << "Функция осуществляет поиск подстроки str2 в строке str1. Функция возвращает указатель на первое вхождение подстроки str2 в строку str1, в противном случае 0" << endl;
        char text1[255];
        char text2[255];
        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text1, 255);

        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text2, 255);
        cout << "Ваш текст: " << mystrstr_5(text1, text2) << endl;
    }
    else if (choose == 6) //++
    {
        cout << "Функция сравнивает две строки, и, если строки равны возвращает 0, если первая строка больше второй, то возвращает 1, иначе -1" << endl;
        char text1[255];
        char text2[255];
        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text1, 255);

        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text2, 255);
        cout << "Ваш текст: " << mystrcmp_6(text1, text2) << endl;

    }
    else if (choose == 7) //++
    {
        cout << "Функция конвертирует строку в число и возвращает это число." << endl;
        char text[255];

        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text, 255);
        
        cout << "Ваш текст: " << StringToNumber_7(text) << endl;
    }
    else if (choose == 8) //??
    {
        cout << "Функция конвертирует число в строку и возвращает указатель на эту строку" << endl;
        int number;
        cout << "Введите число" << endl;
        cin >> number;
        cout << "Ваш текст: " << NumberToString_8(number);
        
    }
    else if (choose == 9) //++
    {
        cout << "Функция преобразует строку в верхний регистр" << endl;
        char text[255];
        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text, 255);
        cout << "Ваш текст: " << Uppercase_9(text) << endl;
    }
    else if (choose == 10) //++
    {
        cout << "Функция преобразует строку в нижний регистр" << endl;
        char text[255];
        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text, 255);
        cout << "Ваш текст: " << Lowercase_10(text) << endl;
    }
    else if (choose == 11) //++
    {
        cout << "Функция реверсирует строку и возвращает указатель на новую строку" << endl;
        char text[255];
        cin.ignore();
        cout << "Введите текст (у вас 254 символов)" << endl;
        cin.getline(text, 255);
        cout << "Ваш текст: " << mystrrev_11(text) << endl;
    }

}