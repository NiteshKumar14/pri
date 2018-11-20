#include<iostream>
using namespace std;

class DiagonalMatrix
{
    int size, *arr;
    public:
    DiagonalMatrix(int s)
    {
        if (size < 0)
            throw "Invalid size";
        size = s;
        arr = new int[s];
    }

    void set(int i, int j, int value)
    {
        if (i <= 0 || j <= 0 || i > size || j > size)
            throw "Invalid Index";
        if (i != j && value != 0)
            throw "Invalid postion to assign";
        if (i == j)
        {
            int k = i - 1;
            arr[k] = value;
        }
    }

    int get(int i, int j)
    {
        if (i <= 0 || j <= 0 || i > size || j > size)
            throw "Invalid Index";
        int data = 0;
        if (i == j)
            data = arr[i - 1];
        return data;
    }

    ~DiagonalMatrix()
    {
        delete[] arr;
    }
};
int main()
{
    int size, value;
    cout << "Enter the size of matrix: ";
    cin >> size;
    try
    {
        DiagonalMatrix obj(size);
        for (int i = 1; i <= size; i++)
            for (int j = 1; j <= size; j++)
            {
                cout << "Enter " << i << ", " << j << " : ";
                cin >> value;
                obj.set(i, j, value);
            }
        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
                cout << obj.get(i, j) << "  ";
            cout << '\n';
        }
    } catch(const char* str)
    {
        cout << str << '\n';
    }
}