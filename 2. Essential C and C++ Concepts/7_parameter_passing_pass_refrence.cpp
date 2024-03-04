#include <iostream>
using namespace std;

void Swap(int &x, int &y)
{
    printf("%d %d", x, y);
    int temp;
    temp = x;
    x = y;
    y = temp;
}
int main()
{
    int a, b;
    a = 10;
    b = 20;
    Swap(a, b);
    cout << "In main, a = " << a << " n = " << b;
}