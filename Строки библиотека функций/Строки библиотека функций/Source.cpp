//#include <iostream>
//#include <string.h>
//#include <windows.h>
//using namespace std;
//
///* char* mystrstr(char* str1, char* str2); -функция осуществляет поиск подстроки str2 в строке str1.
//Функция возвращает указатель на первое вхождение подстроки str2 в строку str1, в противном случае 0. */
//
//
//char* mystrstr(char* str1, char* str2)
//{
//    int size2 = 0;
//    int equal;
//    for (int i = 0; str2[i] != '\0'; i++)
//    {
//        size2++;
//    }
//    for (int i = 0; str1[i] != '\0'; i++)
//    {
//        if (str1[i] == str2[0])
//        {
//            equal = 0;
//            for (int j = 0, i2 = i; str2[j] != '\0'; j++, i2++)
//            {
//                if (str2[j] != str1[i2]) { break; }
//                else { equal++; }
//            }
//            if (equal == size2)
//            {
//                for (int k = 0; str1[k] != '\0'; k++, i++)
//                {
//                    str1[k] = str1[i];
//                }
//                return str1;
//                //cout << str1;
//            }
//        }
//    }
//    return 0;
//}
//
//void main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    char text[255];
//    char text2[255];
//    
//    cout << "Напишите str1" << endl;
//    cin.getline(text, 255);
//
//    
//    cout << "Напишите str2" << endl;
//    cin.getline(text2, 255);
//
//    cout << mystrstr(text, text2) << endl; 
//}