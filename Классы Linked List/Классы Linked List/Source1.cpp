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
        while(temp)
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
        other.m_size = nullptr; //!!!!!!!!!!!!!!!!!!!!
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
        source.m_size = nullptr;
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
            while(node->m_next!=nullptr)
            {
                node = node->m_next;
            }
            node->m_next= new ListNode<T>;
            node->m_next->m_data = element;
        }
        m_size++;
    }

    // Добавляет элемент со значением value после позиции которая указана в position
    void insert_after(T data, int position = 0)
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

    void pop_front()
    {
        ListNode<T>* temp = m_head;
        m_head = m_head->m_next;
        delete temp;
        m_size--;
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
    std::cout << "Linked list empty: " << list.empty() << std::endl;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    std::cout << list << std::endl;
    list.insert_after(5, 0);
    list.insert_after(6, 2);
    std::cout << list << std::endl;
    list.remove(2);
    std::cout << "First list" << std::endl;
    std::cout << list << std::endl;

    linked_list<int> list2;
    list2.push_front(4);
    list2.push_front(5);
    std::cout << "Second list" << std::endl;
    std::cout << list2 << std::endl;
    std::cout << "*******Swap magic*******" << std::endl;
    list2.swap(list);
    std::cout << list << std::endl;
    std::cout << list2 << std::endl;

    list2.pop_front();
    std::cout << "Delete first element from second list" << std::endl;
    std::cout << list2 << std::endl;
    std::cout << "Linked list empty: " << list2.empty() << std::endl;
    std::cout << "*******Clear magic*******" << std::endl;
    list2.clear();
    std::cout << list2 << std::endl;
    std::cout << "Linked list empty: " << list2.empty() << std::endl;
    /*
        Задание 1: Дополнить односвязный список
        Реализуйте следующие методы:
        + pop_front() уничтожает первый элемент
        + clear() очищает список
        + empty() возвращает true если список пуст и false в противном случае
        + swap(other_list) обменивает два списка значениями
        + insert_after(value, position) добавляет элемент со значением value
          после позиции которая указана в position
        + remove(position) удаляет элемент в позиции position
        + конструктор копирования/перемещения (и соответствующие операторы)
    */
}