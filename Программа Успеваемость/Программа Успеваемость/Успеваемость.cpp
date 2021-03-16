#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a[10];
    char p;
    cout << "Введите оценки:" << endl;
    for (int q = 0; q < 10; q++)
    {
        cout << "Оценка " << q + 1 << ":" << endl;
        cin >> a[q];
    }

    int b; //выбор
    int c = 1;
    do
    {
        system("cls");
        cout << "Меню" << endl;
        cout << "Вывод оценок (введите 1)" << endl;
        cout << "Пересдача экзамена (введите 2)" << endl;
        cout << "Будет ли получать стипендию  (введите 3)" << endl;
        cin >> b;
        cout << endl;

        switch (b)
        {
        case 1:
            for (int i = 0; i < 10; i++)
                cout << a[i] << "; ";
            cout << endl;
            break;
        case 2:
            int number;
            cout << "Выберите номер оценки:";
            cin >> number;
            cout << "Старая оценка: " << a[number - 1] << endl;
            cout << "Новая оценка: ";
            cin >> a[number - 1];
            break;
        case 3:
            int sum=0;
            double n; // средний балл

            for (int j = 0; j < 10; j++)
                sum += a[j];
                n = sum / 10;

            if (n == 10.7 || n > 10.7)
                cout << "Студент будет получать стипендию \n";
            else
                cout << "Студент не будет получать стипендию \n";
            break;
        }
        cout << "Вы хотите продолжить? Y/N" << endl;

        cin >> p;

    } while (p == 'Y' || p == 'y');
    {
    }

}