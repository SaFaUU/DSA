#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
int main()
{
    // Accessing Elements from Pointer Adress of Structures
    // struct Rectangle r = {10, 5};
    // struct Rectangle *p = &r;
    // printf("%d \n", (*p).length);
    // printf("%d \n", p->breadth);

    // Creating a structure in heap dynamically
    struct Rectangle *p;
    p = new struct Rectangle;
    p->length = 15;
    p->breadth = 5;
    printf("%d \n", p->length);
    printf("%d \n", p->breadth);

    return 0;
}