#include <iostream>
#include <time.h>
#include <Windows.h>

/*
        ������� 1:
        1. ���������� 2 ������ ����������: LimitException, OutOfRangeException
        2. ���������� ����� FixedArray<T, size_t> ��� T ��� ��� ���������,
        ������� �������� � FixedArray � size_t �� ����������
        3. ���������� ����� push_back ��� ���������� �������� � ����� �������.
           ������ ����� ������ ������� ���������� ���� LimitException
           ���� � ������� ������ ��� �����
        4. ���������� operator[] ��� ��������� �� ������� � ����������� ���������
           ����� push_back. ������ �������� ������ ������� ���������� ����
           OutOfRangeException ���� �� ����� �� ������� �������
        6. ���������� ����������� ������ ������ catch ������� ��� ����������
           ���� LimitException ��� � ���������� ���� OutOfRangeException
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