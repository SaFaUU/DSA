#include <iostream>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};
void changeLength(struct Rectangle *p, int l)
{
    p->length = l;
}
int main()
{

    struct Rectangle r = {10, 5};

    changeLength(&r, 20);
    cout << r.length * r.breadth;

    return 0;
}