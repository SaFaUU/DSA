#include <iostream>
using namespace std;

// Passing by value
void SwapbyValue(int x, int y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void SwapbyAdress(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void SwapbyReference(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    // Passing by value
    int a = 10, b = 20;
    SwapbyValue(a, b);
    printf("Passing by Value %d %d \n", a, b);

    // Pass by Address
    int c = 10, d = 20;
    SwapbyAdress(&c, &d);
    printf("Passing by Adress %d %d \n", c, d);

    // Pass by Reference
    int e = 10, f = 20;
    SwapbyReference(e, f);
    printf("Passing by Reference %d %d \n", e, f);

    return 0;
}