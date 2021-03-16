//#pragma once
//
//int mystrlen_1(const char* lenght)
//{
//    int word_count = 0;
//    for (int i = 0; lenght[i] != '\0'; i++)
//    {
//        word_count++;
//    }
//    return word_count;
//}
//
//char* mystrcpy_2(char* text1, const char* text2)
//{
//    for (int i = 0; text1[i] != '\0'; i++)
//    {
//        text1[i] = text2[i];
//    }
//    return text1;
//}
//
//void mystrcat_3(char* text1, char* text2)
//{
//    while (*text1)
//        text1++;
//    while (*text2)
//    {
//        *text1++ = *text2++;
//    }
//    *text1 = '\0';
//}
//
//char* mystrchr_4(char* text, char symbol)
//{
//    while (*text != symbol && *text)
//        text++;
//    return text;
//}
//
//char* mystrstr_5(char* text1, char* text2)
//{
//
//    //samir dorimov doing something bad
//    //doing
//
//
//    int k = 0;
//
//    for (int i = 0; i < strlen(text1); i++)
//    {
//        for (int j = 0; j < strlen(text2); j++)
//        {
//            if (text1[i] == text2[j])
//            {
//                k++;
//            }
//            if (text1[i] != text2[j])
//            {
//
//            }
//        }
//    }
//
//    if (k == strlen(text2))
//        return text1;
//    else
//        return 0;
//
//
//    //int count = 0;
//    //for (int i = 0; text2[i] != '\0'; i++)
//    //{
//    //    for (int j = 0; text1[j] != '\0'; j++)
//    //    {
//    //        if (text2[j] == text1[i])
//    //        {
//    //            //i++;
//    //            count++;
//    //            cout << text2 << endl;
//    //        }
//    //        cout << text2 << endl;
//    //    }
//    //    cout << text2 << endl;
//    //}
//    //cout << text2 << endl;
//    //return text1;
//}
//
//int mystrcmp_6(const char* text1, const char* text2)
//{
//    int count1 = 0;
//    int count2 = 0;
//
//    for (int i = 0; text1[i] != '\0'; i++)
//    {
//        count1++;
//    }
//    for (int i = 0; text2[i] != '\0'; i++)
//    {
//        count2++;
//    }
//
//    if (count1 == count2)
//    {
//        return 0;
//    }
//    else if (count1 > count2)
//    {
//        return 1;
//    }
//    else if (count2 > count1)
//    {
//        return -1;
//    }
//
//}
//
//int StringToNumber_7(char* text)
//{
//    int number = 0;
//    int i = 0;
//    int sign = 0;
//    if (text[i] == '-')
//    {
//        sign = 1;
//        i++;
//    }
//
//    while (text[i] >= 48 && text[i] <= 57)
//    {
//        number = number + (text[i] & 0x0F);
//        number = number * 10;
//        i++;
//    }
//    number = number / 10;
//    if (sign == 1)
//        number = -number;
//    return number;
//
//}
//
//void NumberToString_8(int number)
//{
//    char text[255];
//    float n = number;
//    int amount = 1;
//    while (true)
//    {
//        n = n / 10;
//        if (n < 1)
//        {
//            break;
//        }
//        amount++;
//    }
//    for (int i = 0, m = 0; i < amount; i++)
//    {
//        text[i] = (int)(n * 10 + 48 - (m * 10));
//        n = n * 10;
//        m = n;
//    }
//
//    text[amount] = '\0';
//    cout << text << endl;
//}
//
//
//
//char* Uppercase_9(char* text)
//{
//    for (int i = 0; text[i] != '\0'; i++)
//    {
//        if (text[i] >= 97 && text[i] <= 122)
//        {
//            text[i] -= 32;
//        }
//        else
//        {
//            text[i];
//        }
//        //break;
//    }
//    return text;
//}
//
//char* Lowercase_10(char* text)
//{
//    for (int i = 0; text[i] != '\0'; i++)
//    {
//        if (text[i] >= 65 && text[i] <= 90)
//        {
//            text[i] += 32;
//        }
//        else
//        {
//            text[i];
//        }
//        //break;
//    }
//    return text;
//}
//
//char* mystrrev_11(char* text)
//{
//    char tmp;
//    int i = 0;
//    int size;
//    for (size = 0; text[size] != '\0'; size++)
//    {
//
//    }
//    size--;
//    while (i <= size)
//    {
//        tmp = text[i];
//        text[i] = text[size];
//        text[size] = tmp;
//        size--;
//        i++;
//    }
//    return text;
//}
