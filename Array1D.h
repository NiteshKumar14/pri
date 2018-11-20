using namespace std;

class Array1D
{
    int *a;
    int size;
    public:
    Array1D (int s = 0)
    {
        if (s < 0)
            throw "Invalid Size";
        size = s;
        a = new int[size];
    }

    Array1D (Array1D& obj)
    {
        size = obj.size;
        a = new int[size];
        for (int i = 0; i < size; i++)
        {
            a[i] = obj.a[i];
        }
    }

    int& operator[](int index)
    {
        if (index >= size || index < 0)
           throw "Invalid index to access.";
        return a[index];
    }

    Array1D& operator=(Array1D &obj)
    {
        // If size is not same delete the old array and reallocate size.
        if (size != obj.size)
        {
            delete []a;
            size = obj.size;
            a = new int[size];
        }

        // Copying the data.
        for (int i = 0; i < size; i++)
            a[i] = obj.a[i];

        // *this represents the invoking object.
        return *this;
    }

    ~Array1D()
    {
        delete[] a;
    }

    void resize (int newsize);
    friend ostream& operator<<(ostream &os, Array1D& obj);
    friend istream& operator>>(istream &is, Array1D& obj);
};

void Array1D :: resize(int newsize)
{
    if (size < 0) throw "Invalid Size";
    delete[] a;
    size = newsize;
    a = new int[size];
}

ostream& operator<<(ostream& os, Array1D& obj)
{
    for (int i = 0; i < obj.size; i++)
        os << obj.a[i] << '\t';
    return os;
}

istream& operator>>(istream& is, Array1D& obj)
{
    for (int i = 0; i < obj.size; i++)
        is >> obj.a[i];
    return is;
}