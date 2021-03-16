#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char text[255];
    cout << "Напишите текст" << endl;
    cin.getline(text, 255);
    char word[255];
    int wordsize = 0;

    // для корректировки первой буквы
    int corrector = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' || text[i] == ',' || i == 0)
        {
            for (int j = i + corrector, size = 0; ; j++, size++)
            {
                if (text[j] == ' ' || text[j] == ',' || text[j] == '.' || text[j] == '\0')
                {
                    if (wordsize < size)
                    {
                        wordsize = size;
                        for (int w = 0, t = i + corrector; w <= size; w++, t++)
                        {
                            word[w] = text[t];
                        }
                        word[size] = '\0';
                    }
                    break;
                }
            }
        }
        corrector = 1;
    }
    cout << word;
}