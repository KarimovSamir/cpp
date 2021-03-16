//#include <iostream>
//#include <time.h>
//#include <Windows.h>
//
///*
//        Задание: Для FixedArray реализуйте итератор
//        Методы итератора:
//        - ++
//        - --
//        - !=
//        - *
//        - +
//        В FixedArray добавьте begin() и end():
//        Распечатайте содержимое FixedArray используя итераторы
//*/
//
//
//
////class OutOfRangeException : public std::exception
////{
////public:
////    OutOfRangeException(const char* reason) : m_reason(reason)
////    {
////
////    }
////    const char* what()
////    {
////        return m_reason;
////    }
////
////private:
////    const char* m_reason;
////};
////
////
////class LimitException
////{
////public:
////    LimitException(const char* reason) : m_reason(reason)
////    {
////
////    }
////    const char* what()
////    {
////        return m_reason;
////    }
////
////private:
////    const char* m_reason;
////};
//
//template<typename T>
//class Array
//{
//private:
//    T* m_arr;
//    size_t m_size;
//public:
//    class Iterator;
//
//    Array(size_t size)
//    {
//        m_size = size;
//        m_arr = new T[size];
//    }
//
//    T& operator[](const int& index) //const
//    {
//        if (index > 0 && index < m_size)
//        {
//            return m_arr[index];
//        }
//        return m_arr[0];
//    }
//    T get_element(size_t size)
//    {
//        return m_arr[size];
//    }
//    T get_size()
//    {
//        return m_size;
//    }
//
//    Iterator begin()
//    {
//        return m_arr;
//    }
//    Iterator end()
//    {
//        //count++;
//        return m_arr + m_size;
//    }
//
//    class Iterator
//    {
//    private:
//        T* fixed_array;
//    public:
//        Iterator(T* first)
//        {
//            fixed_array = first;
//        }
//        T& operator+(int number)
//        {
//            return *(fixed_array + number);
//        }
//        T& operator++(int)
//        {
//            return *fixed_array++;
//        }
//        T& operator--(int)
//        {
//            return *fixed_array--;
//        }
//        bool operator!=(const Iterator& temp)
//        {
//            return fixed_array != temp.fixed_array;
//        }
//        T& operator*()
//        {
//            return *fixed_array;
//        }
//        
//    };
//};
//
//template<typename T>
//std::ostream& operator << (std::ostream& out, Array<T>& ob)
//{
//    for (size_t i = 0; i < ob.get_size(); i++)
//    {
//        out << ob.get_element(i) << " | ";
//    }
//    return out;
//}
//
//int main()
//{
//    Array<int> array(5);
//
//    array[0] = 14;
//    array[1] = 71;
//    array[2] = 35;
//    array[3] = 8;
//    array[4] = 23;
//    std::cout << array << std::endl;
//
//    auto iter = Array<int>::Iterator(array.begin());
//
//    std::cout << iter + 1 << " | ";
//    while (iter != array.end())
//    {
//        std::cout << *iter << " | ";
//        iter++;
//    }
//
//    std::cout << std::endl;
//}
//
//
//    //try
//    //{
//    //    array.push_back(5);
//    //    array.push_back(3);
//    //    array.push_back(7);
//    //    //array.push_back(71);
//    //    auto iter = FixedArray<int, 3>::Iterator(array.begin());
//    //    //std::cout << array[-1] << std::endl;
//    //    std::cout << array[2] << std::endl;
//
//    //    std::cout << array;
//    //    std::cout << std::endl;
//    //}
//    //catch (OutOfRangeException & ex)
//    //{
//    //    std::cout << ex.what();
//    //}
//    //catch (LimitException & ex)
//    //{
//    //    std::cout << ex.what();
//    //}
