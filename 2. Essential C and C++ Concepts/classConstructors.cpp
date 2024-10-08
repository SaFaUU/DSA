#include <iostream>
using namespace std;
class Rectangle
{
private:
    int length;
    int breadth;

public:
    // constructors
    Rectangle()
    {
        length = breadth = 1;
    };
    // Constructor Definition
    Rectangle(int l, int b);

    // Functions
    int area();
    int perimeter();

    // Getters
    int getLength() { return length; };

    // Setters
    void setLength(int l) { length = l; };

    ~Rectangle();
};

Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}

int Rectangle::area()
{
    return length * breadth;
}

int Rectangle::perimeter()
{
    return 2 * (length + breadth);
}

Rectangle::~Rectangle() {};

int main()
{
    Rectangle r(10, 5);
    r.area();
    r.setLength(15);
    return 0;
}