#include<iostream>
#include"StackLL.h"
using namespace std;

bool match(char compare1, char compare2)
{
    bool flag = false;
    if (compare1 == ')' && compare2 == '(')
        flag = true;
    else if (compare1 == '}' && compare2 == '{')
        flag = true;
    else if (compare1 == '>' && compare2 == '<')
        flag = true;
    else if (compare1 == ']' && compare2 == '[')
        flag = true;
    return flag;
}

bool checkBrackets(string expression)
{
    StackLL<char> stack;
    bool valid = true;
    int i = 0;
    while (expression[i] != '\0' && valid)
    {
        if (expression[i] == '(' || expression[i] == '{' || expression[i] == '<' || expression[i] == '[')
        {
            stack.push(expression[i]);
        }
        if (expression[i] == ')' || expression[i] == '}' || expression[i] == '>' || expression[i] == ']')
        {
            if (stack.isEmpty())
            {
                valid = false;
                break;
            }
            else if (match(expression[i], stack.topOfStack()))
            {
                stack.pop();
            }
            else 
            {
                valid = false;
                break;
            }
        }
        i++;
    }
    if (!stack.isEmpty())
        valid = false;
    return valid;
}
int main()
{
    string expression;
    cout << "Enter the expression: ";
    cin >> expression;
    bool valid = checkBrackets(expression);
    if (valid)
        cout << "Balanced\n";
    else
        cout << "Unbalanced\n";
}