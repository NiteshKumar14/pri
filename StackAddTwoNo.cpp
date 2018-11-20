#include<iostream>
#include"StackLL.h"
using namespace std;

int main()
{
    string s1, s2;
    StackLL<int> stack1, stack2, result;
    cout << "Enter first no: ";
    cin >> s1;
    cout << "Enter second no: ";
    cin >> s2;
    for (int i = 0; s1[i] != '\0'; i++)
        stack1.push(s1[i] - '0');
    for (int j = 0; s2[j] != '\0'; j++)
        stack2.push(s2[j] - '0');
    int carry = 0;
    int res;
    int a, b;
    while (!stack1.isEmpty() && !stack2.isEmpty())
    {
        a = stack1.pop();
        b = stack2.pop();
        res = a + b + carry;
        carry = res / 10;
        result.push(res % 10);
    }
    while (!stack1.isEmpty())
    {
        a = stack1.pop();
        res = a + carry;
        carry = res / 10;
        result.push(res % 10);
    }
    while (!stack2.isEmpty())
    {
        b = stack2.pop();
        res = b + carry;
        carry = res / 10;
        result.push(res % 10);
    }
    if (carry != 0)
        result.push(carry);
    result.display();
}