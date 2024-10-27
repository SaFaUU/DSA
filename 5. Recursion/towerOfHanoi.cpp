#include <iostream>
using namespace std;

void TOH(int n, int src, int aux, int dest)
{
    if (n >= 1)
    {
        TOH(n - 1, src, dest, aux);
        printf("from %d to %d using %d \n", src, dest, aux);
        TOH(n - 1, aux, src, dest);
    };
}

int main()
{
    TOH(4, 1, 2, 3);
    return 0;
}