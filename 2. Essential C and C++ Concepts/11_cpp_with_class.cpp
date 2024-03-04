#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle()
    {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area();
    void changeLength(int l)
    {
        length = l;
    }
    ~Rectangle()
    {
        cout << "Destructor called" << endl;
    }
};
int Rectangle::area()
{
    return length * breadth;
}
int main()
{
    Rectangle r(10, 5);
    cout << r.area() << endl;
    r.changeLength(15);
    cout << r.area() << endl;
    return 0;
}