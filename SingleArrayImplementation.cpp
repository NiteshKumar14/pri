#include<iostream>
#include"Array1D.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int size, option;
    Array1D obj;
    do
    {
        cout << "1. Create an array\n2. Display an array\n3. Exit\n";
        cout << "Enter any option: ";
        cin >> option;
        switch (option)
        {
            case 1:
                cout << "Enter the size of array: ";
                cin >> size;
                obj.resize(size);
                cin >> obj;
                break;
            case 2:
                cout << obj << endl;
            default:
                break;
        }
    } while (option != 3);
    
}
