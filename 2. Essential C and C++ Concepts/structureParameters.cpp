#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int area(struct Rectangle r1)
{
    return r1.length * r1.breadth;
}

int areaByReference(struct Rectangle &r1)
{
    return r1.length * r1.breadth;
}

int areaByAddress(struct Rectangle *r1)
{
    return r1->length * r1->breadth;
}

main()
{

    // Pass by value
    struct Rectangle r = {10, 5};
    printf("%d \n", area(r));

    // Pass by reference
    struct Rectangle q = {10, 5};
    printf("%d \n", areaByReference(q));

    // Pass by address
    struct Rectangle p = {10, 5};
    printf("%d \n", areaByAddress(&p));

    return 0;
}