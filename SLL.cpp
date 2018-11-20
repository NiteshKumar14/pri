#include<iostream>
using namespace std;

template<typename T>
class Node
{
    public:
    T value;
    Node* next;
    Node(T value = 0, Node* n = NULL)
    {
        this -> value = value;
        next = n;
    }
};

template<typename T>
class SLL
{
    protected:
    Node<T> *head, *tail;
    public:
    SLL()
    {
        head = NULL;
        tail = NULL;
    }

    SLL(SLL& obj);
    ~SLL();
    void addToHead(T value);
    void addToTail(T value);
    void display();
    void insertAtPostion(T value, int position);
    int count();
    T removeFromHead();
    T removeFromTail();
    void deleteElement(T v);
    friend SLL &operator+(T value, SLL& obj)
    {
        obj.addToHead(value);
        return obj;
    }
    friend SLL &operator+(SLL& obj, T value)
    {
        obj.addToTail(value);
        return obj;
    }
    SLL& operator+(SLL& obj);
    SLL& operator=(SLL& obj);
    void reverse();
};

template<typename T>
SLL<T>::SLL(SLL &obj)
{
    Node<T> *temp = obj.head;
    head = NULL;
    tail = NULL;
    while (temp != NULL)
    {
        addToTail(temp -> value);
        temp = temp -> next;
    }
}

template<typename T>
SLL<T>::~SLL()
{
    Node<T> *temp;
    while (head != NULL)
    {
        temp = head;
        head = head -> next;
        delete temp;
    }
}

template<typename T>
void SLL<T>::addToHead(T value)
{
    Node<T> *p = new Node<T>(value, head);
    if (head == NULL)
        tail = p;
    head = p;
}

template<typename T>
void SLL<T>::addToTail(T value)
{
    Node<T> *p = new Node<T>(value);
    if (head == NULL)
    {
        head = p;
        tail = p;
    }
    else 
    {
        tail -> next = p;
        tail = p;
    }
}

template<typename T>
void SLL<T>::display()
{
    if (head == NULL)
        cout << "Empty List\n";
    else 
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp -> value << '\t';
            temp = temp -> next;
        }
        cout << '\n';
    }
}

template<typename T>
void SLL<T>::insertAtPostion(T value, int position)
{
    int curpos = 0;
    Node<T> *p = new Node<T>(value);
    if (head == NULL && position != 1)
        throw "invalid postion";
    if (head == NULL && position == 1)
    {
        head = p;
        tail = p;
    }
    else
    {
        Node<T> *temp = head;
        curpos++;
        while(temp != NULL)
        {
            if (curpos == position - 1)
                break;
            temp = temp -> next;
            curpos++;
        }
        if (temp -> next == NULL)
        {
            temp -> next = p;
            tail = p;
        }
        else 
        {
            p -> next = temp -> next;
            temp -> next = p;
        }
    }
}

template<typename T>
int SLL<T>::count()
{
    int counter = 0;
    if (head != NULL)
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            counter++;
            temp = temp -> next;
        }
    }
    return counter;
}

template<typename T>
T SLL<T>::removeFromHead()
{
    T value;
    if (head == NULL)
    {
        cout << "Empty List";
        value = -1;
    }
    else
    {
        Node<T> *temp = head;
        head = head -> next;
        value = temp -> value;
        delete temp;
    }

    if (head == NULL)
        tail = NULL;

    return value;
}

template<typename T>
T SLL<T>::removeFromTail()
{
    T value;
    if (head == NULL)
    {
        cout << "Empty List";
        value = -1;
    }
    else
    {
        Node<T> *temp = head;
        while(temp -> next != tail)
            temp = temp -> next;
        value = (temp -> next) -> value;
        tail = temp;
        temp = temp -> next;
        tail -> next = NULL;
        delete temp;
    }

    if (tail == NULL)
        head = NULL;

    return value;
}

template<typename T>
void SLL<T>::deleteElement(T v)
{
    //TODO: Some problem with 4, 1, 1, 2, 6
    if (head == NULL)
        cout << "Empty List\n";
    else
    {
        Node<T> *temp = head;
        Node<T> *prev = NULL;
        while (temp != NULL)
        {
            if (temp -> value == v)
            {
                if (temp == head)
                    removeFromHead();
                else
                {
                    prev -> next = temp -> next;
                    if (prev -> next == NULL)
                    {
                        tail = prev;
                        delete temp;
                        break;
                    }
                }
            }
            prev = temp;
            temp = temp -> next;
        }
    }
}

template<typename T>
SLL<T>& SLL<T>::operator+(SLL<T>& obj)
{
    Node<T> *temp = obj.head;
    while (temp != NULL)
    {
        addToTail(temp -> value);
        temp = temp -> next;
    }
    return *this;
}

template<typename T>
SLL<T>& SLL<T>:: operator=(SLL<T> &obj)
{
    Node<T> *temp = obj.head;
    head = NULL;
    tail = NULL;
    while (temp != NULL)
    {
        addToTail(temp -> value);
        temp = temp -> next;
    }
}

template<typename T>
void SLL<T>::reverse()
{
    if (head == NULL)
        cout << "Empty List.";
    else 
    {
        Node<T> *temp1 = head;
        Node<T> *temp2 = temp1 -> next;
        Node<T> *temp3 = temp2 -> next;
        while (temp3 != NULL)
        {
            temp2 -> next = temp1;
            temp1 = temp2;
            temp2 = temp3;
            temp3 = temp3 -> next;
        }
        temp2 -> next = temp1;
        head -> next = NULL;
        temp3 = head;
        head = tail;
        tail = temp3;
    }
}

template<typename T>
class SSLL : private SLL<T>
{
    public:
    SSLL()
    {
        this -> head = NULL;
        this -> tail = NULL;
    }
    SLL<T>:: display;
    void insert(T value);
};

template<typename T>
void SSLL<T>::insert(T value)
    {
        Node<T> *p = new Node<T>(value);
        p -> next = NULL;
        if (this -> head == NULL)
        {
            this -> head = p;
            this -> tail = p;
        }
        else if (this -> head -> value > value)
            this -> addToHead(value);

        else if (this -> tail -> value < value)
            this -> addToTail(value);
        else 
        {
            Node<T> *temp = this -> head;
            Node<T> *prev = NULL;
            while (temp != NULL)
            {
                if (temp -> value > value)
                    break;
                prev = temp;
                temp = temp -> next;
            }
            p -> next = prev -> next;
            prev -> next = p;
        }
    }

int main()
{
    SLL<int> obj;
    obj + 1;
    obj + 2;
    obj + 3;
    obj.display();
    SLL<int> cpy;
    cpy = obj;
    cpy.display();
}