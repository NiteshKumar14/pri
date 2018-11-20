#include<iostream>
#include"Node.h"
using namespace std;

template<typename T>
class StackLL
{
    protected:
    Node<T> *head, *tail;
    void addToTail(T value);
    public:
    StackLL()
    {
        head = NULL;
        tail = NULL;
    }
    StackLL(StackLL& obj);
    ~StackLL();
    void push(T value);
    void display();
    bool isEmpty();
    T topOfStack();
    T pop();
    friend StackLL &operator+(T value, StackLL& obj)
    {
        obj.addToHead(value);
        return obj;
    }
    StackLL& operator+(StackLL& obj);
    StackLL& operator=(StackLL& obj);
};

template<typename T>
StackLL<T>::StackLL(StackLL &obj)
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
StackLL<T>::~StackLL()
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
void StackLL<T>::push(T value)
{
    Node<T> *p = new Node<T>(value, head);
    if (head == NULL)
        tail = p;
    head = p;
}

template<typename T>
void StackLL<T>::addToTail(T value)
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
void StackLL<T>::display()
{
    // StackLL<T> temp;
    if (head == NULL)
        cout << "Empty List\n";
    else 
    {
        Node<T> *temp1 = head;
        while (temp1 != NULL)
        {
            // temp.push(temp1 -> value);
            cout << temp1 -> value;
            temp1 = temp1 -> next;
        }
        // temp1 = temp.head;
        // while (temp1 != NULL)
        // {
        //     cout << temp1 -> value;
        //     temp1 = temp1 -> next;
        // }
        cout << '\n';
    }
}

template<typename T>
bool StackLL<T> :: isEmpty()
{
    return head == NULL;
}

template<typename T>
T StackLL<T> :: topOfStack()
{
    return head -> value;
}

template<typename T>
T StackLL<T>::pop()
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
StackLL<T>& StackLL<T>::operator+(StackLL<T>& obj)
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
StackLL<T>& StackLL<T>:: operator=(StackLL<T> &obj)
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


