#include<iostream>
#include"Array1D.h"
using namespace std;

// 2-D array using the single dimensional array class.
class Array2D
{
    int row, cols;
    Array1D *arr;

    public:
    Array2D(int r = 0, int c = 0)
    {
        if (r < 0 || c < 0) throw "Invalid size";
        row = r;
        cols = c;
        // Array of objects of the one dimensional class
        arr = new Array1D[row];
        for (int i = 0; i < row; i++)
        {
            /*  Resize methods makes the size of individual array as required
                because initially while creating array of objects the size
                is initialized to 0.
            */
            arr[i].resize(cols);
        }
    }

    Array2D(Array2D& obj)
    {
        row = obj.row;
        cols = obj.cols;
        // Same work as that of the parameterized constructor.
        arr = new Array1D[row];
        for (int i = 0; i < row; i++)
        {
            arr[i].resize(cols);
        }
        // Copies the value of one array into another one.
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                (*this) [i][j] = obj[i][j];
            }
        }
    }

    ~Array2D()
    {
        delete[] arr;
    }

    // Returns a reference of Array1D class (ref. is returned to make it use as lvalue)
    Array1D& operator[](int index)
    {
        if (index >= (row * cols))
            throw "Invalid index";
        return arr[index];
    }

    // Returns ref. so if we are using obj1 = obj2 = obj3 would not give any error.
    Array2D& operator=(Array2D& obj)
    {
        /*  If rows and columns of one is diff from the other we have to
            delete the older array and create a new array with the required
            no of rows and cols.
        */
        if ((row != obj.row) || (cols != obj.cols))
        {
            delete[] arr;
            row = obj.row;
            cols = obj.cols;
            arr = new Array1D[row];
        }
        for (int i = 0; i < row; i++)
                arr[i].resize(cols);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < cols; j++)
                (*this)[i][j] = obj[i][j];
        }
        return (*this);
    }

    Array2D& operator+(Array2D &obj)
    {
        if (obj.row != row || obj.cols != cols)
            throw "size not same";
        /*  Using dynamic memory allocation so that it doesn't get deleted 
            when function is off the stack.
        */
        Array2D *temp = new Array2D(row, cols);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < cols; j++)
                (*temp)[i][j] = obj[i][j] + (*this) [i][j];
        return *temp;
    }

    Array2D& operator-(Array2D &obj)
    {
        if (obj.row != row || obj.cols != cols)
            throw "size not same";
        
        Array2D *temp = new Array2D(row, cols);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < cols; j++)
                (*temp)[i][j] = obj[i][j] - (*this) [i][j];
        return *temp;
    }

    friend ostream& operator<<(ostream& os, Array2D& obj);
    friend istream& operator>>(istream& is, Array2D& obj);
};

ostream& operator<<(ostream& os, Array2D& obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.cols; j++)
            os << obj[i][j] << '\t';
        os << '\n';
    }
    return os;
}

istream& operator>>(istream& is, Array2D& obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.cols; j++)
            is >> obj[i][j];
    }
    return is;
}
int main()
{
    int row, cols, option;
    char ans;
    try
    {
        do
        {
            cout << "1. To create a new matrix\n2. Add 2 matrices\n3. Subtract 2 matrices\n4. Exit\n";
            cout << "Enter any option: ";
            cin >> option;
            switch(option)
            {
                case 1:
                {
                    cout << "Enter the no of rows: ";
                    cin >> row;
                    cout << "Enter the no of cols: ";
                    cin >> cols;
                    Array2D obj(row, cols);
                    cin >> obj;
                    cout << "Do you want to display the array? (y- yes / n- no)? ";
                    cin >> ans;
                    if (ans == 'y')
                        cout << obj;
                    break;
                }
                case 2:
                    {
                        cout << "Enter the no of rows of 1st matrix: ";
                        cin >> row;
                        cout << "Enter the no of cols of 1st matrix: ";
                        cin >> cols;
                        Array2D obj1(row, cols);
                        cin >> obj1;
                        cout << "Enter the no of rows of 2nd matrix: ";
                        cin >> row;
                        cout << "Enter the no of cols of 2nd matrix: ";
                        cin >> cols;
                        Array2D obj2(row, cols);
                        cin >> obj2;
                        Array2D obj3(row , cols);
                        obj3 = obj1 + obj2;
                        cout << obj3;
                        break;
                    }
                case 3:
                    {
                        cout << "Enter the no of rows of 1st matrix: ";
                        cin >> row;
                        cout << "Enter the no of cols of 1st matrix: ";
                        cin >> cols;
                        Array2D obj1(row, cols);
                        cin >> obj1;
                        cout << "Enter the no of rows of 2nd matrix: ";
                        cin >> row;
                        cout << "Enter the no of cols of 2nd matrix: ";
                        cin >> cols;
                        Array2D obj2(row, cols);
                        cin >> obj2;
                        Array2D obj3(row , cols);
                        obj3 = obj2 - obj1;
                        cout << obj3;
                        break;
                    }
                case 4:
                    break;
                default:
                    break;
            }
        } while (option != 4);
    } 
    catch(const char* str)
    {
        cout << str << endl;
    }
}