#include<iostream>
using namespace std;

template<typename T>
class Dequeue
{
    T *arr;
    int size;
    int front, rear;
    public:
    Dequeue(int s)
    {
        if (s <= 0)
            throw "Invalid Size";
        size = s;
        arr = new T[size];
        front = -1;
        rear = -1;
    }
    ~Dequeue();
    void insertFront(T value);
    T deleteRear();
    void insertRear(T value);
    T deleteFront();
    bool isFull();
    bool isEmpty();
};

template<typename T>
Dequeue<T> :: ~Dequeue()
{
    delete[] arr;
}

template<typename T>
void Dequeue<T> :: insertFront(T value)
{
    if (isFull())
        throw "Stack is full cannot insert";
    if (isEmpty())
    {
        front = 0;
        rear = 0;
        arr[front] = value;
    }
    else
    {
        if (front == 0)
        {
            front = size - 1;
            a[front] = value;
        }
        else
            a[--front] = value;
    }
}

template<typename T>
T Dequeue<T> :: deleteRear()
{
    if (isEmpty())
        throw "Queue Empty cannot delete";
    else if (rear == 0)
        rear = size - 1;
    else
        rear--;
    int value = arr[rear];
    if (front == rear)
        rear = front = -1;
    return value;
}

template<typename T>
void Dequeue<T> :: insertRear(T value)
{
    if (isFull())
        throw "Queue Full";
    if (front == -1)
        front = 0;
    rear = (rear + 1) % size;
    a[rear] = value;
}

template<typename T>
T Dequeue<T> :: deleteFront()
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
bool Dequeue<T> :: isFull()
{
    bool flag = false;
    if ((rear + 1) % size == front)
        flag = true;
    return flag;
}

template<typename T>
bool Dequeue<T> :: isEmpty()
{
    bool flag = false;
    if (rear == -1 && front == -1)
        flag = true;
    return flag;
}