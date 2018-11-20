#include<iostream>
#include"Node.h"
using namespace std;

template<typename T>
class CLL
{
    protected:
    Node<T> * tail;
    public:
    CLL()
    {
        tail = NULL;
    }

    ~CLL();
    CLL(CLL &obj);
    CLL& operator=(CLL &obj);
    void insertAtTail(T value);  
    void insertAtHead(T value); 
    void display();
    T removeFromHead();
    T removeFromTail();
};

template<typename T>
CLL<T> :: ~CLL()
{
    Node<T> *temp = tail -> next;
    Node<T> *temp2;
    do {
            temp2 = temp;
            temp = temp -> next;
            delete temp2;
        } while (temp != tail -> next);
}

template<typename T>
CLL<T> :: CLL(CLL<T> &obj)
{
    Node<T> *temp = obj.tail;
    tail = NULL;
    temp = temp -> next;
    while (temp != obj.tail)
    {
        insertAtTail(temp -> value);
        temp = temp -> next;
    }
    insertAtTail(temp -> value);
}

template<typename T>
CLL<T>& CLL<T> :: operator=(CLL<T> &obj)
{
    Node<T> *temp = obj.tail;
    tail = NULL;
    temp = temp -> next;
    while (temp != obj.tail)
    {
        insertAtTail(temp -> value);
        temp = temp -> next;
    }
    insertAtTail(temp -> value);
}

template<typename T>
void CLL<T> :: insertAtHead(T value)
{
    Node<T> *p = new Node<T> (value);
    if (tail == NULL)
    {
        tail = p;
        p -> next = tail;
    }
    else
    {
        p -> next = tail -> next;
        tail -> next = p;
    }
}

template<typename T>
void CLL<T> :: display()
{
    if (tail == NULL)
        cout << "Empty List";
    else
    {
        Node<T> *temp = tail -> next;
        do
        {
            cout << temp -> value << "  ";
            temp = temp -> next;
        } while (temp != tail -> next);
        cout << '\n';
    }
}

template<typename T>
void CLL<T> :: insertAtTail(T value)
{
    Node<T> *p = new Node<T> (value);
    if (tail == NULL)
    {
        tail = p;
        p -> next = tail;
    }
    else
    {
        p -> next = tail -> next;
        tail -> next = p;
        tail = p;
    }
}

template<typename T>
T CLL<T> :: removeFromHead()
{
    if (tail == NULL)
        cout << "Empty List";
    else
    {
        Node<T> *temp = tail -> next;
        tail -> next = temp -> next;
        delete temp;
    }
}

template<typename T>
T CLL<T> :: removeFromTail()
{
    if (tail == NULL)
        cout << "Empty List";
    else
    {
        Node<T> *temp = tail -> next;
        while (temp -> next != tail)
        {
            temp = temp -> next;
        }
        temp -> next = tail -> next;
        Node<T> *temp2 = tail;
        tail = temp;
        delete temp2;
    }
}

int main()
{
    CLL<int> cll;
    cll.insertAtHead(1);
    cll.insertAtHead(2);
    cll.insertAtHead(3);
    cll.insertAtHead(4);
    cll.insertAtHead(5);
    cll.insertAtTail(10);
    cll.removeFromHead();
    cll.removeFromTail();
    cll.removeFromTail();
    CLL<int> cll2;
    cll2 = cll;
    cll2.display();
    cll.display();
}