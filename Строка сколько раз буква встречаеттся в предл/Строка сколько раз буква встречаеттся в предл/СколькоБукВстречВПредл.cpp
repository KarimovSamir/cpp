#include <iostream>
#include <Windows.h>
using namespace std;

int count_letter(char* text, char letter)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == letter)
            count++;
    }
    return count;
}

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int drift = 0;
    char text[255];
    char letter;

    cout << "������� ����� (� ��� 255 ��������)" << endl;
    cin.getline(text, 255);
    cout << "������� ������ ������� ������ �����." << endl;
    cin >> letter;

    cout << "������ \"" << letter << "\" ����������� � ������ " << count_letter(text, letter) << " ���";
}