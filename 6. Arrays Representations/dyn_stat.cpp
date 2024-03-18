#include <iostream>
using namespace std;
int main()
{

    int A[10];
    int *p;
    p = new int[5];
    for (int i = 0; i < 5; i++)
    {
        printf("%d \n", p[i]);
    }
    delete[] p;

    return 0;
}