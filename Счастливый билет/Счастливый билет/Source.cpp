//#include <iostream>
//using namespace std;
//
//int tickets()
//{
//    int sum = 0;
//    int i, j, k;
//    char builet[6];
//    for (i = 0; i <= 999999; i++) 
//    {
//        for (k = i, j = 0; j < 6; j++, k /= 10) 
//        {
//            builet[j] = k % 10;
//        }
//        if (builet[0] + builet[2] + builet[4] == builet[1] + builet[3] + builet[5]) 
//        {
//            ++sum;
//        }
//    }
//    return sum;
//}
//
//int main()
//{
//    setlocale(0, "");
//
//
//    int k = tickets();
//    cout << "Количество счастливых билетов: " << k << endl;
//
//}
//
