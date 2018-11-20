#include<iostream>
using namespace std;

class Tridimensional
{
    int size, *arr;
    public:
    Tridimensional(int s)
    {
        if (s < 0)
            throw "Invalid Size";
        size = s;
        arr = new int[size + 2 * (size - 1)];
    }

    void set(int i, int j, int value)
    {
        if (i <= 0 || j <= 0 || i > size || j > size)
            throw "Invalid Index";
        if (i != j || i != j - 1 || j != i - 1 && value != 0)
            throw "Invalid Index";
        if (i == j || i == j - 1 || j == i - 1)
        {
            int k = 2 + 3 * (i - 2) + (j - i - 1);
            arr[k] = value;
        }
    }

    int get(int i, int j)
    {
        if (i <= 0 || j <= 0 || i > size || j > size)
            throw "Invalid Index";
        int data = 0;
        if (i == j || i == j - 1 || j == i - 1)
            data = arr[2 + 3 * (i - 2) + (j - i - 1)];
        return data;
    }

    ~Tridimensional()
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
        Tridimensional obj(size);
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