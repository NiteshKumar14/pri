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