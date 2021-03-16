#include <iostream>

template<typename T>
struct ListNode // Структура которая описывает 1 ячейку в нашем листе.
{               // Она должна состоять из данных и указателя на следующий элемент.
    T m_data; // Сама ячейка
    ListNode* m_next = nullptr; // Указатель на следующую ячейку
};

template<typename T>
class linked_list // Сам linked_list состоит из этих ячеек
{  //<T> - Какого типа linked_list, такого же типа должен быть и ListNode
private:
    ListNode<T>* m_head = nullptr; // Указатель на ListNote. (начальный элемент)
    ListNode<T>* m_tail = nullptr; // Указатель на ListNote. (конечный элемент)
    size_t m_size = 0;
    int size = 10;
    //std::string sam[size];

public:

    linked_list() = default;

    // copy constructor
    linked_list(const linked_list<T>& other)
    {
        ListNode<T>* temp = other.m_head;
        while(temp) // До того как будет nullptr
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
        m_tail = other.m_tail;
        m_size = other.m_size;  // В момент вызова деструктора other.m_head может указывать на тот же объект что и m_head
        other.m_head = nullptr; // Когда m_head выходит из области видимости, то вызывается деструктор для уничтожения other.m_head
        other.m_tail = nullptr; // Если мы не сделаем nullptr для other.m_head, то мы получим неопределённое поведение
        /*std::swap(m_size, other.m_size);
        std::swap(m_head, other.m_head);
        std::swap(m_tail, other.m_tail);
        other.m_head = nullptr;
        other.m_tail = nullptr;*/
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
        m_tail = source.m_tail;
        m_size = source.m_size;
        source.m_head = nullptr;
        source.m_tail = nullptr;
        /*std::swap(m_size, source.m_size);
        std::swap(m_head, source.m_head);
        std::swap(m_tail, source.m_tail);
        source.m_head = nullptr;
        source.m_tail = nullptr;*/
        return *this;
    }

    // Добавление элемента
    void push_front(const T& element)
    {
        if (m_head == nullptr)
        {
            m_head = new ListNode<T>;
            m_tail = m_head; // m_tail указывает на тоже, на что и m_head
            m_head->m_data = element;
        }
        else
        // Теперь у нас всегда есть ссылка на последний элемент и мы после него добавляем новый элемент
        // И делаем так, чтобы ссылка указывала на новый последний элемент (во второй строчке)
        // и благодаря этомы, нам не нужно каждый раз проходить по всем элементам
        // m_tail всегда будет указывать на последний элемент
        {
            m_tail->m_next = new ListNode<T>; // Обращаемся в m_tail и в его m_next записываем указатель на новый элемент
            m_tail = m_tail->m_next; // А теперь m_tail указывает на этот новый элемент
            m_tail->m_data = element; // И наконец-то в m_tail (в конец) мы запихнули наш новый элемент
        }
        m_size++;

        // Этот вариант работает, но с каждым добавлением элемента работает медленее, 
        // так как сначала надо пройтись по массиву, а потом добавить элемент

        //if (m_head == nullptr)
        //{
        //    m_head = new ListNode<T>; // Создаём ListNode где-то в оперативной памяти
        //    m_head->m_data = element; // Передаётся число которое мы передаём из main
        //}
        //else
        //{
        //    // С помощью этого мы добираемся до последнего элемента в списке
        //    ListNode<T>* node = m_head; // head - указатель на самый первый node
        //    while(node->m_next!=nullptr) //Если следующий элемнт у node не nullptr, значит за этим элементом есть ещё элемент
        //    {
        //        // То тогда в node мы записываем следующий элемент
        //        node = node->m_next;
        //    }
        //    // А потом добавляем новый элемент
        //    node->m_next = new ListNode<T>;
        //    node->m_next->m_data = element;
        //}
        //m_size++;
        
    }

    // Добавляет элемент со значением value в позицию которая указана в position
    void insert(T data, int position = 0)
    {
        // Создаём новый элемент в оперативной памяти
        // Можно написать new ListNode<T>() - эти скобки это вызов конструктора по умолчанию, но тут без разницы, он вызывается и так
        ListNode<T>* new_node = new ListNode<T>; 
        // Вписываем в него передаваемое значение
        new_node->m_data = data;
        if (position == 0)
        {
            // Так как он будет являться первым элементом, то следующий элемент это прошлый первый элемент, то есть m_head
            new_node->m_next = m_head;
            // А потом m_head берёт значение new_done
            m_head = new_node;
        }
        else
        {
            // previous_node - указывает на предыдущий элемент
            ListNode<T>* previous_node = m_head; // head - указатель на самый первый node
            for (size_t i = 0; i < position - 1; i++)
            {
                previous_node = previous_node->m_next;
            // После цикла в previous_node будет сидеть ссылка на элемент до того места куда нам надо вставить передаваемый элемент
            // То есть циклом мы доходим до элемента который находится перед вставляемым 
            }
            // Создаём временный указатель и сохранить то на что указывал предыдущий элемент до вставляемого
            // next_node - указывает на следующий элемент
            ListNode<T>* next_node = previous_node->m_next;
            // Потом перезаписали (по сути делаем обычный swap)
            previous_node->m_next = new_node;
            new_node->m_next = next_node;
        }
        m_size++;
    }

    // Добавляет элемент со значением value после позиции которая указана в position
    void insert_after(T data, int position = 0)
    {
        // Создаём новый элемент в оперативной памяти
        ListNode<T>* new_node = new ListNode<T>();
        // Вписываем в него передаваемое значение
        new_node->m_data = data;

        ListNode<T>* previous_node = m_head; // head - указатель на самый первый node
        for (size_t i = 0; i < position; i++)
        {
            previous_node = previous_node->m_next;
            // После цикла в previous_node будет сидеть ссылка на элемент до того места куда мне надо вставить передаваемый элемент
        }
        // Создаём временный указатель и сохранить то на что указывал предыдущий элемент до вставляемого
        ListNode<T>* next_node = previous_node->m_next;
        // Потом перезаписали
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
        ListNode<T>* temp = m_head; // Записываем в temp значение нулевого элемента
        m_head = m_head->m_next; // Присваиваем m_head адрес следующего элемента
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
        std::swap(m_tail, other_stack.m_tail);
    }

//    T& operator[](size_t index)
//    {
//        return m_head[index];
//    }

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