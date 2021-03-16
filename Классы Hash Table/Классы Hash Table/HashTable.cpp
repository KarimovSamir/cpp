#include <iostream>
#include <functional> // <-- для std::hash
/*
        Задание 1: Реализуйте класс HashTable<TKey, TValue>
        - Реализуйте класс HashTable<TKey, TValue> где TKey это тип ключа
          которому соответствует некоторое значение типа TValue.
        - В классе HashTable<TKey, TValue> перегрузите оператор [] для доступа к элементам по ключу
        - Доступ к элементам по ключу через оператор [] должен осуществляться в соответствии с логикой хеш таблицы

        Пример использования:
        HashTable<std::string, int> table;
        table["Mike"] = 15;
        std::cout << table["Mike"]; // печатает 15
    */

template <typename Key, typename Val>
struct Pair
{
    Key TKey;
    Val TValue;
    Pair<Key, Val>* m_next = nullptr; // Указатель на следующую ячейку
};

template <typename Key, typename Val>
class HashTable
{
private:
    static const int SIZE = 10;
    Pair<Key, Val>* m_data[SIZE] = {};
    std::hash<std::string> hashFunction;
public:
    HashTable() = default;

    int& operator[] (Key key)
    {
        Pair<Key, Val>* my_value = new Pair<Key, Val>;
        my_value->TKey = key;
        int index = hashFunction(key) % 10;
        //int index = key % 10;
        if (!m_data[index]) //Если там пусто то записываем значение
        { 
            m_data[index] = my_value; 
            return my_value->TValue; 
        }

        Pair<Key, Val>* list = m_data[index];
        while (true) 
        {
            if (list->TKey == key)
            {
                return list->TValue;
            }
            if (list->m_next == nullptr) 
            { 
                break; 
            } 
            list = list->m_next;
        }
        list->m_next = my_value; // если новое значение, но список уже есть, то он записывает его в конец
        list = list->m_next;
        return list->TValue;
    }

    void Get_data()
    {
        Pair<Key, Val>* list;
        for (size_t i = 0; i < 10; i++)
        {
            std::cout << "data[" << i << "] ";
            if (!m_data[i]) 
            { 
                std::cout << std::endl; 
                continue; 
            }
            list = m_data[i];
            std::cout << list->TValue;
            while (list->m_next != nullptr)
            {
                list = list->m_next;
                std::cout << " --> " << list->TValue;
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    size_t buckets = 10;
    //HashTable<int, int> table;
    HashTable<std::string, int> table;
    std::hash<std::string> hashFunction;

    std::cout << "Index for Mike = " << hashFunction("Mike") % buckets << '\n';
    std::cout << "Index for John = " << hashFunction("Sam") % buckets << '\n';
    std::cout << "Index for Jack = " << hashFunction("Jack") % buckets << '\n';
    std::cout << "Index for C = " << hashFunction("C") % buckets << '\n';

    table["Mike"] = 10;
    table["Sam"] = 4;
    table["Jack"] = 5;
    table["C"] = 25;
    /*table[31] = 10;
    table[41] = 4;
    table[51] = 5;
    table[61] = 6;
    table[23] = 7;
    table[23] = 8;*/

    std::cout << table["Mike"] << std::endl;
    std::cout << table["Sam"] << std::endl;
    std::cout << table["Jack"] << std::endl;
    std::cout << table["C"] << std::endl;
    /*std::cout << table[31] << std::endl;
    std::cout << table[41] << std::endl;
    std::cout << table[51] << std::endl;
    std::cout << table[61] << std::endl;
    std::cout << table[23] << std::endl;*/

    table.Get_data();
}