#include<iostream>
using namespace std;

// 2-Dimensional array implementation using double pointer.
class Array2D
{
    int row, cols;
    int **data;

    public:
    Array2D(int r = 0, int c = 0)
    {
        if (r < 0 || c < 0)
            throw "Invalid Size";
        row = r;
        cols = c;
        data = new int*[row];
        for (int i = 0; i < row; i++)
            data[i] = new int[cols];
    }
    
    // Copy constructor in order to prevent shallow copy.
    // Note - Ref. is passed so that it don't keep on calling the copy constructor.
    Array2D(Array2D& obj)
    {
        row = obj.row;
        cols = obj.cols;
        data = new int*[row];
        for (int i = 0; i < row; i++)
            data[i] = new int[cols];
    }

    // We cannot use [] for passing 2 parameter so we used () instead.
    int& operator()(int i, int j)
    {
        if (i < 0 || i >= row || j < 0 || j >= cols)
            throw "Invalid index";
        return data[i][j];
    }

    /*  Deletes the older 2-D array if no. of rows and cols are not equal
        and makes the no of cols and rows equal and assigns memory.
    */
    Array2D& operator=(Array2D &obj)
    {
        if ((row != obj.row) || (cols != obj.cols))
        {
            for (int i = 0; i < row; i++)
            {
                delete[] data[i];
            }
            delete[] data;
            row = obj.row;
            cols = obj.cols;    
        }
        data = new int*[row];
        for (int i = 0; i < row; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = obj.data[i][j];
            }
        }
        return *this;
    }

    ~Array2D()
    {
        for (int i = 0; i < row; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }

    Array2D& operator+(Array2D& obj)
    {
        if (obj.row != row || obj.cols != cols)
            throw "Not same size";
        Array2D *temp = new Array2D(row, cols);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < cols; j++)
                (*temp)(i, j) = (*this) (i, j) + obj(i,j);
        return *temp;
    }

    Array2D& operator-(Array2D& obj)
    {
        if (obj.row != row || obj.cols != cols)
            throw "Not same size";
        Array2D *temp = new Array2D(row, cols);
        for (int i = 0; i < row; i++)
            for (int j = 0; j < cols; j++)
                (*temp)(i, j) = (*this) (i, j) - obj(i,j);
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
        {
            os << obj.data[i][j] << '\t';
        }
        os << '\n';
    }
    return os;
}

istream& operator>>(istream& is, Array2D& obj)
{
    for (int i = 0; i < obj.row; i++)
    {
        for (int j = 0; j < obj.cols; j++)
        {
            is >> obj.data[i][j];
        }
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