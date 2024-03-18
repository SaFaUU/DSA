#include <iostream>
using namespace std;
int main()
{
    int *p, *q;
    p = new int[5];
    q = new int[10];
    p[0] = 3;
    p[1] = 5;
    p[2] = 2;
    p[3] = 4;
    p[4] = 1;

    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    delete[] p;
    p = q;
    q = nullptr;

    for (int i = 0; i < 10; i++)
    {
        printf("%d \n", p[i]);
    }

    delete[] p;

    return 0;
}