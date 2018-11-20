#include<iostream>
#include" Node.h"
using namespace std;

template<typename T>
class QueueLL
{
    protected:
    Node<T> *head, *tail;
    public:
    QueueLL()
    {
        head = NULL;
        tail = NULL;
    }

    QueueLL(QueueLL& obj);
    ~QueueLL();
    void enqueue(T value);
    T dequeue();
    bool isEmpty();
};

template<typename T>
QueueLL<T>::QueueLL(QueueLL &obj)
{
    Node<T> *temp = obj.head;
    head = NULL;
    tail = NULL;
    while (temp != NULL)
    {
        enqueue(temp -> value);
        temp = temp -> next;
    }
}

template<typename T>
QueueLL<T>::~QueueLL()
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
void QueueLL<T>::enqueue(T value)
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
T QueueLL<T>::dequeue()
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
bool QueueLL<T> :: isEmpty()
{
    bool flag = false;
    if (head == NULL && tail == NULL)
        flag = true;
    return flag;
}

int main()
{
    QueueLL<int> q;
    try
    {
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.enqueue(4);
        q.enqueue(5);
        cout << q.dequeue() << '\n';
        cout << q.dequeue() << '\n';
        cout << q.dequeue() << '\n';
        cout << q.dequeue() << '\n';
        cout << q.dequeue() << '\n';
    } catch (const char *str)
    {
        cout << str << '\n';
    }
    return 0;
}
