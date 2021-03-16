#include <iostream>

template<typename T>
struct ListNode 
{
    T m_data; 
    ListNode* m_next = nullptr; 
};

template<typename T>
class linked_list 
{  
private:
    ListNode<T>* m_head = nullptr; 
    //ListNode<T>* m_tail = nullptr;
    size_t m_size = 0;

public:

    linked_list() = default;

    // copy constructor
    linked_list(const linked_list<T>& other)
    {
        ListNode<T>* temp = other.m_head;
        while (temp)
        {
            push_front(temp->m_data);
            temp = temp->m_next;
        }
        m_size = other.m_size;
    }

    // move constructor
    linked_list(linked_list<T>&& other)
    {
        m_head = other.m_head;
        //m_tail = other.m_tail;
        m_size = other.m_size;
        other.m_head = nullptr; 
        //other.m_tail = nullptr; 
    }

    // copy assignment operator
    linked_list<T>& operator = (const linked_list<T>& source)
    {
        ListNode<T>* temp = source.m_head;
        while (temp)
        {
            push_front(temp->m_data);
            temp = temp->m_next;
        }
        m_size = source.m_size;
        return *this;
    }

    // move assignment operator
    linked_list<T>& operator = (linked_list<T>&& source)
    {
        m_head = source.m_head;
        //m_tail = source.m_tail;
        m_size = source.m_size;
        source.m_head = nullptr;
        //source.m_tail = nullptr;
        return *this;
    }

    // Добавление элемента
    void push_front(const T& element)
    {
        //if (m_head == nullptr)
        //{
        //    m_head = new ListNode<T>;
        //    m_tail = m_head;
        //    m_head->m_data = element;
        //}
        //else
        //{
        //    m_tail->m_next = new ListNode<T>; 
        //    m_tail = m_tail->m_next; 
        //    m_tail->m_data = element;
        //}
        //m_size++;

        if (m_head == nullptr)
        {
            m_head = new ListNode<T>;
            m_head->m_data = element; 
        }
        else
        {
            ListNode<T>* node = m_head; 
            while (node->m_next != nullptr) 
            {
                node = node->m_next;
            }
            node->m_next = new ListNode<T>;
            node->m_next->m_data = element;
        }
        m_size++;
    }

    // Добавляет элемент со значением value в позицию которая указана в position
    void insert(T data, int position = 0)
    {
        ListNode<T>* new_node = new ListNode<T>;
        new_node->m_data = data;
        if (position == 0)
        {            new_node->m_next = m_head;
            m_head = new_node;
        }
        else
        {
            ListNode<T>* previous_node = m_head; 
            for (size_t i = 0; i < position - 1; i++)
            {
                previous_node = previous_node->m_next;
            }
            ListNode<T>* next_node = previous_node->m_next;
            previous_node->m_next = new_node;
            new_node->m_next = next_node;
        }
        m_size++;
    }

    // Добавляет элемент со значением value после позиции которая указана в position
    void insert_after(T data, int position = 0) // data &
    {

        ListNode<T>* new_node = new ListNode<T>();
        new_node->m_data = data;

        ListNode<T>* previous_node = m_head;
        for (size_t i = 0; i < position; i++)
        {
            previous_node = previous_node->m_next;
        }
        ListNode<T>* next_node = previous_node->m_next;
        previous_node->m_next = new_node;
        new_node->m_next = next_node;
        m_size++;
    }

    T& front()
    {
        return m_head->m_data;
    }

    // Уничтожает первый элемент
    void pop_front()
    {
        ListNode<T>* temp = m_head; 
        m_head = m_head->m_next; 
        delete temp;
        m_size--;
    }

    // Уничтожает последний элемент
    void pop_back()
    {
        remove(m_size - 1);
    }

    void clear()
    {
        while (m_size)
        {
            pop_front();
        }
    }

    void remove(int position)
    {
        if (position == 0)
        {
            pop_front();
        }
        else
        {
            ListNode<T>* previous = m_head;
            for (size_t i = 0; i < position - 1; i++)
            {
                previous = previous->m_next;
            }

            ListNode<T>* pos_delete = previous->m_next;
            previous->m_next = pos_delete->m_next;
            delete pos_delete;
            m_size--;
        }
    }

    // обменивает содержимым два стека
    void swap(linked_list& other_stack)
    {
        std::swap(m_size, other_stack.m_size);
        std::swap(m_head, other_stack.m_head);
        //std::swap(m_tail, other_stack.m_tail);
    }

    T& operator[](size_t index)
    {
        return m_head[index];
    }

    T back()
    {
        ListNode<T>* node = m_head; 
        while (node->m_next != nullptr)
        {
            node = node->m_next;
        }
        return node->m_data;
    }

    void push_back(T element)
    {
        ListNode<T>* new_node = new ListNode<T>;
        new_node->m_data = element;
        ListNode<T>* previous_node = m_head;
        for (size_t i = 0; i < m_size - 1; i++)
        {
            previous_node = previous_node->m_next;
        }
        ListNode<T>* next_node = previous_node->m_next;

        previous_node->m_next = new_node;
        //m_tail = m_tail->m_next;
        new_node->m_next = next_node;
        m_size++;
    }

    bool search(T value)
    {
        ListNode<T>* my_value = new ListNode<T>;
        my_value->m_data = value;
        ListNode<T>* node = m_head; 
        while (node->m_next != nullptr) 
        {
            if (node->m_data == my_value->m_data)
            {
                return true;
            }
            node = node->m_next;
        }
        if (node->m_data == my_value->m_data)
        {
            return true;
        }
        return false;
    }

    T take_front()
    {
        int result = front();
        pop_front();
        return result;

    }

    T take_back()
    {
        int result = back();
        pop_back();
        return result;

    }

    bool empty()
    {
        return m_size == 0;
    }

    size_t get_size()
    {
        return m_size;
    }

    ~linked_list()
    {
        clear();
    }

    friend std::ostream& operator << (std::ostream& os, const linked_list& l)
    {
        ListNode<T>* current = l.m_head;
        while (current)
        {
            os << current->m_data << " | ";
            current = current->m_next;
        }
        return os;
    }
};

int main()
{
    std::cout << std::boolalpha;
    linked_list<int> list;

    list.push_front(11);
    list.push_front(22);
    list.push_front(33);
    std::cout << list << std::endl;
    int number3 = 44;
    std::cout << "Add element " << number3 << " to the end of the list." << std::endl;
    list.push_back(number3);
    std::cout << list << std::endl;
    std::cout << "Last element: " << list.back() << std::endl;
    std::cout << "Add new elements to the list " << std::endl;
    list.push_front(55);
    list.push_front(66);
    list.push_front(77);
    std::cout << list << std::endl;

    int result = list.take_front();
    std::cout << "First element copy and delete it from list: " << result << std::endl;
    std::cout << list << std::endl;

    int result2 = list.take_back();
    std::cout << "Last element copy and delete it from list: " << result2 << std::endl;
    std::cout << list << std::endl;
    std::cout << "Delete last element" << std::endl;
    list.pop_back();
    std::cout << list << std::endl;
    int number1 = 7;
    std::cout << "Is element " << number1 << " on the list?\n" << list.search(number1) << std::endl;
    int number2 = 44;
    std::cout << "Is element " << number2 << " on the list?\n" << list.search(number2) << std::endl;

    linked_list<int> list2(list);
    std::cout << list2 << std::endl;

    /*
        ДОМАШНЕЕ ЗАДАНИЕ:
        + back() возвращает ссылку на последний элемент
        + push_back(element) добавляет элемент в конец списка
        + pop_back() уничтожает последний элемент
        + search(value) возвращает true если элемент со значением value
          есть в списке и false в противном случае
        + take_front() возвращает копию первого элемента (и удаляет оригинал)
        + take_back() возвращает копию последнего элемента (и удаляет оригинал)
    */
}