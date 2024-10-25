#include <iostream>
using namespace std;

double taylorIterative(int x, int n)
{
    double r = 1;
    double p = 1;
    double f = 1;
    for (int i = 1; i <= n; i++)
    {
        p = p * x;
        f = f * i;
        r += p / f;
    }
    return r;
}

int main()
{
    cout << taylorIterative(1, 10) << endl;
    return 0;
}