#include <iostream>
using namespace std;

void move(int n, int a, int b, int c)
{
    if (n > 0)
    {
        move(n - 1, a, c, b);
        printf("Move from %d to %d \n", a, c);
        move(n - 1, b, a, c);
    }
}

int main()
{
    move(3, 1, 2, 3);
    return 0;
}