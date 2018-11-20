// Reverse element of stack using two additional stack

#include<iostream>
#include"StackLL.h"
using namespace std;

Stack<int>& reverse(Stack<int> )
int main()
{
    StackLL<int> original;
    int size, temp;
    cout << "Enter no of elements: ";
    cin >> size;
    cout << "Enter elements: ";
    while (size--)
    {
        cin >> temp;
        original.push(temp);
    }
    original.display();
    cout << "After Reverse: \n";
    original = reverse(original);
    original.display();
    return 0;
}