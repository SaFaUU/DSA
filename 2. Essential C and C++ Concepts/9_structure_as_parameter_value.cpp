#include <iostream>
using namespace std;
int area(struct Rectangle r)
{
    return r.length * r.breadth;
}
struct Rectangle
{
    int length;
    int breadth;
};
int main()
{

    struct Rectangle r = {10, 5};
    cout << area(r);
    return 0;
}