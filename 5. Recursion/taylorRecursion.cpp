#include <iostream>
using namespace std;

double taylor(int x, int n)
{
    static double p = 1, f = 1;
    double r = 1;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        r = taylor(x, n - 1);
        p = p * x;
        f = f * n;
        return r + (p / f);
    }
}

int main()
{
    printf("%lf ", taylor(1, 10));
    return 0;
}