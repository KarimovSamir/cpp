//#include <iostream>
//#include <time.h>
//using namespace std;
//
//void main()
//{
//    setlocale(LC_ALL, "rus");
//    srand(time(NULL));
//
//    char text[255];
//    cout << "Введите текст (у вас 255 символов)" << endl;
//    cin.getline(text, 255);
//    int count = 0;
//    int word_count = 0;
//
//    for (int i = 0; text[i] != '\0'; i++)
//    {
//        word_count++;
//    }
//
//    cout << "Количество букв: " << word_count << endl;
//
//    for (int i = 0; text[i] != '\0'; i++)
//    {
//        if (text[i] == text[word_count - i])
//            count++;
//    }
//
//    if (count == 4)
//        cout << "Палиндром";
//    else
//        cout << "Не палиндром";
//}