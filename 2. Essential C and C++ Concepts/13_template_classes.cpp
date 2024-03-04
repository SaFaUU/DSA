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
Arithmetic<T>::Arithmetic(T a, T b)
{
    this->a = a;
    this->b = b;
};
template <class T>
T Arithmetic<T>::add()
{
    return a + b;
};
template <class T>
T Arithmetic<T>::sub()
{
    return a - b;
};
main()
{
    Arithmetic<int> obj(10, 20);
    cout << obj.add() << endl;
    cout << obj.sub() << endl;
    return 0;
}