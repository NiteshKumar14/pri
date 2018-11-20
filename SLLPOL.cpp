#include<iostream>
using namespace std;

template<typename T>
class Node
{
    public:
    Node *next;
    T coeff;
    int expo;
    Node(T c, int e, Node* n = NULL)
    {
        coeff = c;
        expo = e;
        next = n;
    }
};
template<typename T>
class SLLPOL
{
    Node<T> *head;
    Node<T> *tail;
    public:
    SLLPOL()
    {
        head = NULL;
        tail = NULL;
    }
    SLLPOL(SLLPOL &obj);
    void insert(T coeff, int expo);
    void display();
    void addToTail(Node<T> *p);
    SLLPOL& operator+(SLLPOL& obj);
    SLLPOL& operator=(SLLPOL& obj);
};

template<typename T>
SLLPOL<T> :: SLLPOL(SLLPOL &obj)
{
    head = NULL;
    tail = NULL;
    Node<T> *temp = obj.head;
    while (temp != NULL)
    {
        insert(temp -> coeff, temp -> expo);
        temp = temp -> next;
    }
}

template<typename T>
void SLLPOL<T> :: insert(T coeff, int expo)
{
    Node<T> *p = new Node<T>(coeff, expo);
    if (head == NULL)
    {
        head = p;
        tail = p;
    }
    else if (head -> expo < expo)
    {
        p -> next = head;
        head = p;
    }
    else
    {
        Node<T>* temp = head;
        Node<T>* prev = NULL;
        while (temp != NULL)
        {
            if (temp -> expo < expo)
            {
                p -> next = temp;
                prev -> next = p;
                break;
            }
            prev = temp;
            temp = temp -> next;
        }
        if (temp == NULL)
            addToTail(p);
    }
}

template<typename T>
void SLLPOL<T> :: display()
{
    if (head == NULL)
        cout << "Empty List\t";
    else
    {
        Node<T> *temp = head;
        while(temp != NULL)
        {
            cout << temp -> coeff << " x^" << temp -> expo << "  ";
            temp = temp -> next;
        }
        cout << "\t";
    }
}

template<typename T>
void SLLPOL<T> :: addToTail(Node<T> *p)
{
    tail -> next = p;
    tail = p;
}

template<typename T>
SLLPOL<T>& SLLPOL<T> :: operator+(SLLPOL<T> &obj)
{
    SLLPOL<T> *temp = new SLLPOL<T>();
    Node<T> *temp1 = NULL;
    Node<T> *temp2 = NULL;
    if (head -> expo > obj.head -> expo)
    {
        temp1 = head;
        temp2 = obj.head;
    }
    else
    {
        temp1 = obj.head;
        temp2 = head;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1 -> expo == temp2 -> expo)
        {
            temp -> insert(temp1 ->coeff + temp2 -> coeff, temp1 -> expo);
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        else if (temp1 -> expo > temp2 -> expo)
        {
            temp -> insert(temp1 -> coeff, temp1 -> expo);
            temp1 = temp1 -> next;
        }
        else if (temp1 -> expo < temp2 -> expo)
        {
            temp -> insert(temp2 -> coeff, temp2 -> expo);
            temp2 = temp2 -> next;
        }
    }
    while (temp1 != NULL)
    {
        temp -> insert(temp1 -> coeff, temp1 -> expo);
        temp1 = temp1 -> next;
    }
    while (temp2 != NULL)
    {
        temp -> insert(temp2 -> coeff, temp2 -> expo);
        temp2 = temp2 -> next;
    }
    return *temp;
}

template<typename T>
SLLPOL<T>& SLLPOL<T> :: operator=(SLLPOL<T>& obj)
{
    if (obj.head == NULL)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        Node<T> *temp = obj.head;
        while (temp != NULL)
        {
            insert(temp -> coeff, temp -> expo);
            temp = temp -> next;
        }
    }
    return *this;
}

int main()
{
    SLLPOL<int> obj;
    obj.insert(10, 2);
    obj.insert(5, 1);
    obj.insert(2, 0);
    obj.display();
    SLLPOL<int> obj2;
    obj2.insert(10, 500);
    obj2.insert(20, 2);
    obj2.insert(10, 1);
    obj2.display();
    SLLPOL<int> obj3 = obj + obj2;
    obj3.display();
    return 0;
}