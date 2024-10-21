#include <iostream>
using namespace std;

int pow(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return m * pow(m, n - 1);
}

int pow2(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return pow2(m * m, n / 2);
    }
    else
    {
        return m * pow2(m * m, (n - 1) / 2);
    }
}

int main()
{
    int p = pow(2, 9);
    printf("%d ", p);

    printf("\n");

    int q = pow2(2, 9);
    printf("%d ", q);
    return 0;
}