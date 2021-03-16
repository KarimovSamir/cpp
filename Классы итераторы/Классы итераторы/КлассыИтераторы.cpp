#include <iostream>
#include <time.h>
#include <Windows.h>

/*
        Задание: Для FixedArray реализуйте итератор
        Методы итератора:
        - ++
        - --
        - !=
        - *
        - +
        В FixedArray добавьте begin() и end():
        Распечатайте содержимое FixedArray используя итераторы
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
    class Iterator;

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

    Iterator begin()
    {
        return m_data;
    }

    Iterator end()
    {
        return m_data + S;
    }

    class Iterator
    {
    private:
        T* fixed_array;
    public:
        Iterator(T* first)
        {
            fixed_array = first;
        }
        T& operator+(int number)
        {
            return *(fixed_array + number);
        }
        T& operator++(int)
        {
            return *fixed_array++;
        }
        T& operator--(int)
        {
            return *fixed_array--;
        }
        bool operator!=(const Iterator& temp)
        {
            return fixed_array!=temp.fixed_array;
        }
        T& operator*()
        {
            return *fixed_array;
        }
    };
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
        std::cout << array;
        //std::cout << array[2] << std::endl;

        std::cout << "\nIterators" << std::endl;
        auto iter = FixedArray<int, 3>::Iterator(array.begin());
        std::cout << "iter + 1 = " << iter + 1 << std::endl;
        while (iter != array.end())
        {
            std::cout << *iter << " | ";
            iter++;
        }
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