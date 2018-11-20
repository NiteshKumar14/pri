#include<iostream>
using namespace std;

template<typename T>
class Queue
{
    T *a;
    int rear, front;
    int size;
    public:
    Queue(int s)
    {
        if (s <= 0)
            throw "Invalid Size";
        size = s;
        front = -1;
        rear = -1;
        a = new T[size];
    }
    void enqueue(T value);
    T dequeue();
    bool isFull();
    bool isEmpty();
};

template<typename T>
void Queue<T> :: enqueue(T value)
{
    if (isFull())
        throw "Queue Full";
    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    a[rear] = value;
}

template<typename T>
T Queue<T> :: dequeue()
{
    if (isEmpty())
        throw "Queue Empty";
    int value;
    value = a[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;
    return value;
}

template<typename T>
bool Queue<T> :: isFull()
{
    bool flag = false;
    if ((rear + 1) % size == front)
        flag = true;
    return flag;
}

template<typename T>
bool Queue<T> :: isEmpty()
{
    bool flag = false;
    if (rear == -1 && front == -1)
        flag = true;
    return flag;
}

int main()
{
    Queue<int> q(5);
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