#include<iostream>
#include"StackLL.h"
using namespace std;

bool isOperator(char s)
{
    if (s == '+' || s == '-' || s == '/' || s == '^' || s =='*')
        return true;
    return false;
}

int answer(int a, int b, char op)
{
    int result;
    if (op == '+')
        result = b + a;
    else if (op == '-')
        result = b - a;
    else if (op == '*')
        result = b * a;
    else if (op == '/')
        result = b / a;
    return result;
}

int evaluatePostfix(string s)
{
    StackLL<int> stck;
    int i = 0;
    while (s[i] != '\0')
    {
        if (isOperator(s[i]))
        {
            int result = answer(stck.pop() - '0', stck.pop() - '0', s[i]);
            stck.push(result);
        }
        else
            stck.push(s[i]);
        i++;    
    }
    return stck.pop();
}

int main()
{
    string s;
    cout << "Enter the postfix expression: ";
    cin >> s;
    int a = evaluatePostfix(s);
    cout << a << '\n';
}