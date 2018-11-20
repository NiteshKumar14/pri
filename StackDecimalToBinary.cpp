#include<iostream>
#include"StackLL.h"
using namespace std;

void converToBinary(int number)
{
    int rem;
    StackLL<int> stack;
    while (number)
    {
        rem = number % 2;
        number = number / 2;
        stack.push(rem);
    }
    stack.display();
}
int main()
{
    int number;
    cout << "Enter the decimal no: ";
    cin >>  number;
    converToBinary(number);
}
