#include<iostream>
using namespace std;

// Upper Triangular matrix stored column wise in 1D matrix.
class Umatrix
{
    int size, *arr;
    public:
    Umatrix(int s = 0)
    {
        if (s < 0)
            throw "Invalid size";
        size = s;
        arr = new int[s * (s + 1) / 2];
    }

    void set(int i, int j, int value)
    {
        if (i <= 0 || j <= 0 || i > size || j > size)
            throw "Invalid Index";
        if (i > j && value != 0)
            throw "Invalid Index";
        if (i <= j)
        {    
            int k = (i - 1) + (j * (j - 1) / 2);
            arr[k] = value;
        }
    }

    int get(int i, int j)
    {
        if (i <= 0 || j <= 0 || i > size || j > size)
            throw "Invalid Index";
        int data = 0;
        if (i <= j)
            data = arr[(i - 1) + (j * (j - 1) / 2)];
        return data;
    }

    ~Umatrix()
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
        Umatrix obj(size);
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