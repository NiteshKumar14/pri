#include<iostream>
using namespace std;

template<typename T>
class Node 
{
    public:
    Node* next;
    Node* prev;
    T value;
    Node(T value, Node *next = NULL, Node *prev = NULL)
    {
        this -> value = value;
        this -> next = next;
        this -> prev = prev;
    }
};

template<typename T>
class DLL 
{
    Node<T> *head, *tail;
    public:
    DLL()
    {
        head = NULL;
        tail = NULL;
    }
    DLL(DLL &);
    ~DLL();
    void addToHead(T );
    void addToTail(T );
    void addToPosition(int , T );
    T removeFromHead();
    T removeFromTail();
    T removeFromPosition(int );
    void display();
    T middle();
    void sort();
    int count();
    void displayReverse();
    void reverse();
    DLL& operator=(DLL& );
};

template<typename T>
DLL<T> :: DLL(DLL<T> &obj)
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
DLL<T> :: ~DLL()
{
    Node<T> *temp = head;
    Node<T> *deleteNode = NULL;
    while (temp != NULL)
    {
        deleteNode = temp;
        temp = temp -> next;
        delete deleteNode;
    }
}

template<typename T>
void DLL<T> :: addToHead(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }
}

template<typename T>
void DLL<T> :: addToTail(T value)
{
    Node<T> *newNode = new Node<T>(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}

template<typename T>
void DLL<T> :: addToPosition(int position, T value)
{
    position--;
    Node<T> *newNode = new Node<T>(value);
    if (head == NULL && position == 0)
    {
        head = newNode;
        tail = newNode;
    }
    else if (head == NULL && position != 0)
        throw "Invalid position";
    else
    {
        int currentPosition = 0;
        Node<T> *temp = head;
        while (temp != NULL && position != currentPosition++)
            temp = temp -> next;
        if (temp == NULL)
            throw "Invalid Position";
        newNode -> next = temp;
        newNode -> prev = temp -> prev;
        (temp -> prev) -> next = newNode;
        temp -> prev = newNode;
    }
}

template<typename T>
T DLL<T> :: removeFromHead()
{
    T value;
    if (head == NULL)
        throw "Empty List";
    value = head -> value;
    Node<T> *temp = head;
    head = head -> next;
    if (head != NULL)
        head -> prev = NULL;
    delete temp;
    return value;
}

template<typename T>
T DLL<T> :: removeFromTail()
{
    T value;
    if (head == NULL)
        throw "Empty List";
    value = tail -> value;
    Node<T> *temp = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    delete temp;
    return value;
}

template<typename T>
T DLL<T> :: removeFromPosition(int position)
{
    T value;
    position--;
    if (head == NULL)
        throw "Invalid index";
    else if (position == 0)
        value = removeFromHead();
    else
    {
        int currentPosition = 0;
        Node<T> *temp = head;
        while (temp != NULL && position != currentPosition++)
            temp = temp ->next;
        if (temp == NULL)
            throw "Invalid index";
        if (temp == tail)
            value = removeFromTail();
        else 
        {
            (temp -> prev) -> next = temp -> next;
            (temp -> next) -> prev = temp -> prev;
            value = temp -> value;
            delete temp;
        }
    }
    return value;
}

template<typename T>
void DLL<T> :: display()
{
    if (head == NULL)
        throw "Empty List";
    Node<T> *temp = head;
    while (temp != NULL)
    {
        cout << temp -> value << "  ";
        temp = temp -> next;
    }
    cout << "\n";
}
template<typename T>
T DLL<T> :: middle()
{
    if (head == NULL)
        throw "Empty List";
    Node<T> *start, *end;
    start = head;
    end = tail;
    while (start != end && start -> next != end)
    {
        start = start -> next;
        end = end -> prev;
    }
    return start -> value;
}

template<typename T>
void DLL<T> :: sort()
{
    if (head == NULL)
        throw "Empty List";
    int noOfElements = count();
    T tempValue;
    bool isSwapped = false;
    Node<T> *temp1, *temp2;
    temp1 = head;
    temp2 = tail;
    for (int i = 0; i < noOfElements; i++)
    {
        isSwapped = false;
        while (temp1 != temp2)
        {
            if (temp1 -> value > (temp1 -> next) -> value)
            {
                tempValue = temp1 -> value;
                temp1 -> value = (temp1 -> next) -> value;
                (temp1 -> next) -> value = tempValue;
                isSwapped = true;
            }
            temp1 = temp1 -> next;
        }
        if (isSwapped == false)
            break;
        temp2 = temp2 -> prev;
        temp1 = head;
    }
}

template<typename T>
int DLL<T> :: count()
{
    int noOfElements = 0;
    if (head != NULL)
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            noOfElements++;
            temp = temp -> next;
        }
    }
    return noOfElements;
}

template<typename T>
void DLL<T> :: displayReverse()
{
    if (head == NULL)
        throw "Empty List";
    Node<T> *temp = tail;
    while (temp != NULL)
    {
        cout << temp -> value << "  "; 
        temp = temp -> prev;
    }
    cout << '\n';
}

template<typename T>
void DLL<T> :: reverse()
{
    if (head == NULL)
        throw "Empty List";
    Node<T> *temp1 = head;
    Node<T> *temp2 = NULL;
    while (temp1 != NULL)
    {
        temp2 = temp1 -> next;
        temp1 -> next = temp1 -> prev;
        temp1 -> prev = temp2;
        temp1 = temp2;
    }
    temp1 = head;
    head = tail;
    tail = head;
}

template<typename T>
DLL<T>& DLL<T> :: operator=(DLL<T> &obj)
{
    Node<T> *temp = obj.head;
    head = NULL;
    tail = NULL;
    while (temp != NULL)
    {
        addToTail(temp -> value);
        temp = temp -> next;
    }
    return *this;
}

int main()
{
    DLL<int> obj;
    obj.addToTail(1);
    obj.addToTail(2);
    obj.addToTail(4);
    obj.addToTail(5);
    obj.addToTail(3);
    obj.addToPosition(3, 7);
    obj.display();
    obj.sort();
    obj.display();
    obj.reverse();
    obj.display();
    DLL<int> obj2;
    obj2 = obj;
    obj2.display();
    return 0;
}

