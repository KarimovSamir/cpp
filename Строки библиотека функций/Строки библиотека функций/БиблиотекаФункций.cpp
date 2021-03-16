#include <iostream>
#include "header.h""
using namespace std;



void main()
{
    setlocale(LC_ALL, "rus");
    int choose;
    cout << "�������� ����� �������: ";
    cin >> choose;
    if (choose == 1) //++
    {
        cout << "������� ���������� ����� ������" << endl;
        char text[255];
        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text, 255);
        cout << "��� �����: " << mystrlen_1(text) << endl;
    }
    else if (choose == 2) //++
    {
        cout << "������� �������� ������ str2 � �����, ���������� ����� str1. ������� ���������� ��������� �� ������ ������ str1" << endl;
        char text1[255];
        char text2[255];
        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text2, 255);
        cout << "��� �����: " << mystrcpy_2(text1, text2) << endl;
    }
    else if (choose == 3) //++
    {
        cout << "������� ������������ ������ str2 � ������ str1. ������� ���������� ��������� �� ������ ������ str1" << endl;
        char text1[255];
        char text2[255];
        cin.ignore();
        cout << "������� 1 ����� (� ��� 254 ��������)" << endl;
        cin.getline(text1, 255);

        cout << "������� 2 ����� (� ��� 254 ��������)" << endl;
        cin.getline(text2, 255);
        mystrcat_3(text1, text2);
        cout << text1;
    }
    else if (choose == 4) //++
    {
        cout << "������� ������������ ����� ������� symbol � ������ str. ������� ���������� ��������� �� ������ ��������� ������� � ������, � ��������� ������ 0" << endl;
        char text[255];
        char symbol;
        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text, 255);
        cout << "������� ������ ������� ������ �����" << endl;
        cin >> symbol;
        cout << "��� �����: " << mystrchr_4(text, symbol) << endl;
    }
    else if (choose == 5) //++
    {
        cout << "������� ������������ ����� ��������� str2 � ������ str1. ������� ���������� ��������� �� ������ ��������� ��������� str2 � ������ str1, � ��������� ������ 0" << endl;
        char text1[255];
        char text2[255];
        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text1, 255);

        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text2, 255);
        cout << "��� �����: " << mystrstr_5(text1, text2) << endl;
    }
    else if (choose == 6) //++
    {
        cout << "������� ���������� ��� ������, �, ���� ������ ����� ���������� 0, ���� ������ ������ ������ ������, �� ���������� 1, ����� -1" << endl;
        char text1[255];
        char text2[255];
        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text1, 255);

        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text2, 255);
        cout << "��� �����: " << mystrcmp_6(text1, text2) << endl;

    }
    else if (choose == 7) //++
    {
        cout << "������� ������������ ������ � ����� � ���������� ��� �����." << endl;
        char text[255];

        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text, 255);
        
        cout << "��� �����: " << StringToNumber_7(text) << endl;
    }
    else if (choose == 8) //??
    {
        cout << "������� ������������ ����� � ������ � ���������� ��������� �� ��� ������" << endl;
        int number;
        cout << "������� �����" << endl;
        cin >> number;
        cout << "��� �����: " << NumberToString_8(number);
        
    }
    else if (choose == 9) //++
    {
        cout << "������� ����������� ������ � ������� �������" << endl;
        char text[255];
        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text, 255);
        cout << "��� �����: " << Uppercase_9(text) << endl;
    }
    else if (choose == 10) //++
    {
        cout << "������� ����������� ������ � ������ �������" << endl;
        char text[255];
        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text, 255);
        cout << "��� �����: " << Lowercase_10(text) << endl;
    }
    else if (choose == 11) //++
    {
        cout << "������� ����������� ������ � ���������� ��������� �� ����� ������" << endl;
        char text[255];
        cin.ignore();
        cout << "������� ����� (� ��� 254 ��������)" << endl;
        cin.getline(text, 255);
        cout << "��� �����: " << mystrrev_11(text) << endl;
    }

}