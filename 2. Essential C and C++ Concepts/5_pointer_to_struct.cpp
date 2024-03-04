#include <iostream>
using namespace std;
int main()
{
    struct Rectangle
    {
        int length;
        int breadth;
    };

    // struct Rectangle r = {10, 5};
    // struct Rectangle *p = &r;

    // p->length = 20;
    // p->breadth = 20;
    // cout << p->length * p->breadth << endl;

    // To create memory in heap
    struct Rectangle *p;
    p = (struct Rectangle *)malloc(sizeof(struct Rectangle));

    p->length = 10;
    p->breadth = 5;

    cout << p->length * p->breadth << endl;

    return 0;
}