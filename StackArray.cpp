#include<iostream>
using namespace std;

template<typename T>
class Stack
{
    int top;
    T *data;
    int size;
    public:
    Stack(int s = 20)
    {
        if (s <= 0)
            throw "Invalid Size";
        data = new T[s];
        size = s;
        top = -1;
    }
    void push(T );
    T pop();
    bool isEmpty();
    bool isFull();
    void display();
    T stackTop();
};

template<typename T>
void Stack<T> :: push(T value)
{
    if (isFull())
        throw "Stack Overflow";
    data[++top] = value;
}

template<typename T>
T Stack<T> :: pop()
{
    if (isEmpty())
        throw "Stack Underflow";
    return data[top--];
}

template<typename T>
bool Stack<T> :: isEmpty()
{
    return top == -1;
}

template<typename T>
bool Stack<T> :: isFull()
{
    return top == size - 1;
}

template<typename T>
void Stack<T> :: display()
{
    if (isEmpty())
        throw "Stack Underflow";
    for (int i = 0; i <= top; i++)
        cout << data[i] << "  ";
    cout << '\n';
}

template<typename T>
T Stack<T> :: stackTop()
{
    if (top == -1)
        throw "Stack Underflow";
    return data[top];
}

int main()
{
    Stack<int> s(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.pop() << '\n';
    s.display();
    cout << s.stackTop() << '\n';
    return 0;
}