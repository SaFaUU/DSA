#include <iostream>
using namespace std;

double taylorHorner(double x, double n)
{
    static double f = 1;
    static double r = 1;

    if (n == 0)
    {
        return r;
    }
    r = 1 + ((x / n) * r);
    return taylorHorner(x, n - 1);
}

int main()
{
    printf("%lf ", taylorHorner(1, 10));
    return 0;
}
