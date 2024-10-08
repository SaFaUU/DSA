#include <iostream>
using namespace std;

template <class T>
class Arithmetic
{
private:
    T a, b;

public:
    Arithmetic(T x, T y);
    T add();
    T sub();
};

template <class T>
Arithmetic<T>::Arithmetic(T x, T y)
{
    this->a = x;
    this->b = y;
};

template <class T>
T Arithmetic<T>::add()
{
    return this->a + this->b;
};

template <class T>
T Arithmetic<T>::sub()
{
    return this->a - this->b;
};

int main()
{
    Arithmetic<int> a(10, 5);
    cout << a.add() << endl;
    cout << a.sub() << endl;
    return 0;
}