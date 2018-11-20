#include<iostream>
using namespace std;

template<typename T>
class Node
{
    public:
    T value;
    int priority;
    Node* next;
    Node(T value = 0, int p = 0, Node* n = NULL)
    {
        this -> value = value;
        priority = p;
        next = n;
    }
};

template<typename T>
class PQueue
{
    protected:
    Node<T> *head, *tail;
    public:
    PQueue()
    {
        head = NULL;
        tail = NULL;
    }

    // SLL(SLL& obj);
    // ~SLL();
    void addToHead(T value, int priority);
    void addToTail(T value, int priority);
    T dequeue();
    void enqueue(T value, int priority);
    void display();
};

template<typename T>
void PQueue<T> :: enqueue(T value, int priority)
{
    Node<T> *p = new Node<T>(value, priority);
    p -> next = NULL;
    if (this -> head == NULL)
    {
        this -> head = p;
        this -> tail = p;
    }
    else if (this -> head -> value > value)
        this -> addToHead(value, priority);

    else if (this -> tail -> value < value)
        this -> addToTail(value, priority);
    else 
    {
        Node<T> *temp = this -> head;
        Node<T> *prev = NULL;
        while (temp != NULL)
        {
            if (temp -> priority > priority)
                break;
            prev = temp;
            temp = temp -> next;
        }
        p -> next = prev -> next;
        prev -> next = p;
    }
}

template<typename T>
T PQueue<T> :: dequeue()
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
void PQueue<T>::addToHead(T value, int priority)
{
    Node<T> *p = new Node<T>(value, priority, head);
    if (head == NULL)
        tail = p;
    head = p;
}

template<typename T>
void PQueue<T>::addToTail(T value, int priority)
{
    Node<T> *p = new Node<T>(value, priority);
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
void PQueue<T>::display()
{
    if (head == NULL)
        cout << "Empty List\n";
    else 
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << "Value: " << temp -> value << '\t' << "Priority: " << temp -> priority << '\n';
            temp = temp -> next;
        }
        cout << '\n';
    }
}

int main()
{
    PQueue<int> pq;
    pq.enqueue(10, 1);
    pq.enqueue(9, 2);
    pq.enqueue(4, 5);
    pq.display();
}