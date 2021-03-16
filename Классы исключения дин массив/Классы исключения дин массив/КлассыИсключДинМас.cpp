#include <iostream>
#include <time.h>
#include <Windows.h>

/*
        Задание 1:
        1. Реализуйте 2 класса исключений: LimitException, OutOfRangeException
        2. Реализуйте класс FixedArray<T, size_t> где T это тип элементов,
        которые хранятся в FixedArray а size_t их количество
        3. Реализуйте метод push_back для добавления элемента в конец массива.
           Данный метод должен бросать исключение типа LimitException
           если в массиве больше нет места
        4. Реализуйте operator[] для обращения по индексу к добавленным элементам
           через push_back. Данный оператор должен бросать исключение типа
           OutOfRangeException если вы вышли за пределы массива
        6. Реализуйте возможность внутри одного catch поймать как исключение
           вида LimitException так и исключение вида OutOfRangeException
*/

class OutOfRangeException : public std::exception
{
public:
    OutOfRangeException(const char* reason) : m_reason(reason)
    {

    }
    const char* what()
    {
        return m_reason;
    }

private:
    const char* m_reason;
};


class LimitException
{
public:
    LimitException(const char* reason) : m_reason(reason)
    {

    }
    const char* what()
    {
        return m_reason;
    }

private:
    const char* m_reason;
};

template<typename T, size_t S>
class FixedArray
{
private:
    T m_data[S] = {};
    size_t count = 0;
public:
    FixedArray() = default;

    void push_back(const T& element)
    {
        count++;
        if (count <= S)
        {
            for (size_t i = 1; i < S; i++)
            {
                m_data[i - 1] = m_data[i];
            }
            m_data[S - 1] = element;
        }
        else
        {
            throw LimitException("Error! Limit exception");
        }
    }

    T& operator[](const T& index) //const
    {
        if (0 <= index && index < S)
        {
            return m_data[index];
        }

        throw OutOfRangeException("Error! Out of range exception");
    }

    T getelement(size_t SIZE)
    {
        return m_data[SIZE];
    }
};

template<typename T, size_t S>
std::ostream& operator << (std::ostream& out, FixedArray<T, S>& ob)
{
    for (size_t i = 0; i < S; i++)
    {
        out << ob.getelement(i) << " | ";
    }
    return out;
}

int main()
{
    FixedArray<int, 3> array;
    try
    {
        array.push_back(5);
        array.push_back(3);
        array.push_back(7);
        //array.push_back(71);
        
        //std::cout << array[-1] << std::endl;
        std::cout << array[2] << std::endl;

        std::cout << array;
        std::cout << std::endl;
    }
    catch (OutOfRangeException & ex)
    {
        std::cout << ex.what();
    }
    catch (LimitException & ex)
    {
        std::cout << ex.what();
    }
}