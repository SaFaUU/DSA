#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};

struct Student
{
    int roll;
    char name[25];
    char dept[10];
};

struct Card
{
    int face;
    int shape;
    int color;
};

main()
{
    struct Card deck[52];
    // struct Card deck[52] = {{1,0,0}, {2,0,0}};
    // struct Rectangle r;
    struct Rectangle r = {10, 5};
    printf("Area of Rectangle is %d", r.breadth * r.length);
    return 0;
}