#include <iostream>
#include <Windows.h>
using namespace std;

struct Str
{
    char add_arr[200];
    int count;
};

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FILE* text1;
    fopen_s(&text1, "text1.txt", "w");
    if (text1 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }

    fputs("What is love, baby don't hurt me, don't hurt me, no more.5505", text1);
    //fputs("���� ��������� � � ��������, � �����, ���� ������� ����� ��, ��� � �� ����, ������ ����.", text1);
    fclose(text1);
    text1 = nullptr;

    FILE* text2;
    fopen_s(&text2, "text2.txt", "w");
    if (text2 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }

    fputs("What is love, baby don't hurt me, don't hurt me, no more.", text2);
    //fputs("���� ��������� � � ��������, � �����, ���� ������� ����� ��, ��� � �� ����, ������ ����.5505", text2);

    fclose(text2);
    text2 = nullptr;

    char arr1[500]{};
    char arr2[500]{};

    fopen_s(&text1, "text1.txt", "r");
    if (text1 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }

    fopen_s(&text2, "text2.txt", "r");
    if (text2 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }

    cout << "1) ���� ��� ��������� �����. ��������, ��������� �� �� ������.\n���� ���, �� ������� ������������� ������ �� ������� �����." << endl << endl;

    while (!feof(text1) && !feof(text2))
    {
        fgets(arr1, 1000, text1);
        fgets(arr2, 1000, text2);
        if (strlen(arr1) == strlen(arr1))
        {
            for (int i = 0; i < strlen(arr1) + 1; i++)
            {
                if (arr1[i] != arr2[i])
                {
                    cout << arr1 << endl << arr2 << endl;
                    break;
                }
            }
        }
        else
        {
            cout << arr1 << endl << arr2 << endl;
        }
        cout << endl;
    }

    fclose(text1);
    text1 = nullptr;
    fclose(text2);
    text2 = nullptr;
    system("pause");
    system("cls");

    cout << "2) ��� ��������� ����.\n���������� ������� ����� ���� � �������� � ���� ��������� ���������� �� ��������� �����." << endl << endl;

    Str col[4] =
    {
       { "���������� �������� = ", 0 },

       { "\n���������� ������� ���� = ", 0 },

       { "\n���������� ��������� ���� = ", 0 },

       { "\n���������� ���� = ", 0 }
    };

    fopen_s(&text1, "text1.txt", "r");
    if (text1 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }

    while (!feof(text1))
    {
        fgets(arr1, 500, text1);
        cout << arr1;
        for (int i = 0; arr1[i] != '\0'; i++)
        {
            // ����������
            if ((arr1[i] >= 65 && arr1[i] <= 90) || (arr1[i] >= 97 && arr1[i] <= 122))
            {
                //������� ������� �����
                if (arr1[i] == 65 || arr1[i] == 69 || arr1[i] == 73 || arr1[i] == 79 || arr1[i] == 85)
                {
                    col[1].count++;
                }
                //��������� ������� �����
                else if (arr1[i] == 97 || arr1[i] == 101 || arr1[i] == 105 || arr1[i] == 111 || arr1[i] == 117)
                {
                    col[1].count++;
                }
                // ���������� ��������� ����
                else
                {
                    col[2].count++;
                }
            }
            // �������
            else if (arr1[i] == -72 || arr1[i] == -88 || -65 < arr1[i] && arr1[i] < 0)
            {
                //������� ������� �����
                if (arr1[i] == -32 || arr1[i] == -27 || arr1[i] == -24 || arr1[i] == -72 || arr1[i] == -18 || arr1[i] == -13 || arr1[i] == -5 || arr1[i] == -3 || arr1[i] == -2 || arr1[i] == -1)
                {
                    col[1].count++;
                }
                //��������� ������� �����
                else if (arr1[i] == -64 || arr1[i] == -59 || arr1[i] == -56 || arr1[i] == -88 || arr1[i] == -50 || arr1[i] == -45 || arr1[i] == -37 || arr1[i] == -35 || arr1[i] == -34 || arr1[i] == -33)
                {
                    col[1].count++;
                }
                // � � � �����
                else if (arr1[i] == -4 || arr1[i] == -6 || arr1[i] == -36 || arr1[i] == -38)
                {
                }
                // ���������� ��������� ����
                else
                {
                    col[2].count++;
                }
            }
            // ���������� ����
            else if (47 < arr1[i] && arr1[i] < 58)
            {
                col[3].count++;
            }
            // ���������� ��������
            else
            {
                if (arr1[i] == 32)
                {
                }
                else
                {
                    col[0].count++;
                }
            }

        }
    }

    fclose(text1);
    text1 = nullptr;

    fopen_s(&text2, "text2.txt", "w");
    if (text2 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        fprintf_s(text2, "%-s%d", col[i].add_arr, col[i].count);
    }

    fclose(text2);
    text2 = nullptr;

    cout << endl;
    fopen_s(&text2, "text2.txt", "r");
    if (text2 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }
    while (!feof(text2))
    {
        fgets(arr2, 500, text2);
        fputs(arr2, stdout);
    }
    fclose(text2);
    text2 = nullptr;
    cout << endl << endl;
    system("pause");
    system("cls");

    cout << "3) ���� ������ � ���� �� ���������� ������.\n��� ���������� ������ ������ ���������� ������, ��������� �� ���� � �������� �� ������������� ����� �������." << endl << endl;
    FILE* text3;
    fopen_s(&text3, "text3.txt", "w");
    if (text3 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }
    fopen_s(&text1, "text1.txt", "r");
    if (text1 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }

    cout << "��������� ����� �����!!!" << endl;
    while (!feof(text1))
    {
        fgets(arr1, 500, text1);
        for (int i = 0; arr1[i] != '\0'; i++)
        {
            if (arr1[i] == 32)
            {
                arr2[i] = char(int(arr1[i]));
            }
            else
            {
                arr2[i] = char(int(arr1[i]) - 3);
            }

        }
        cout << arr2 << endl;
        fputs(arr2, text3);
    }

    fclose(text1);
    text1 = nullptr;
    fclose(text3);
    text3 = nullptr;
    cout << endl;

    cout << "��������� �����!!!" << endl;
    fopen_s(&text3, "text3.txt", "r");
    if (text3 == nullptr)
    {
        cout << "������ �������� �����!" << endl;
    }

    while (!feof(text3))
    {
        fgets(arr1, 500, text3);
        for (int i = 0; arr1[i] != '\0'; i++)
        {
            if (arr1[i] == 32)
            {
                arr2[i] = char(int(arr1[i]));
            }
            else
            {
                arr2[i] = char(int(arr1[i]) + 3);
            }

        }
        fputs(arr2, stdout);
    }
    fclose(text3);
    text3 = nullptr;
    cout << endl;
}