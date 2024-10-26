#include <iostream>
using namespace std;

int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

int c(int n, int r)
{
    int nominator = fact(n);
    int denominator = fact(r);
    int denominator2 = fact(n - r);

    return nominator / (denominator * denominator2);
}

int pascalsTriangle(int n, int r)
{
    if (r == 0 || n == r)
        return 1;
    return pascalsTriangle((n - 1), (r - 1)) + pascalsTriangle((n - 1), r);
}

int main()
{
    cout << c(4, 2) << endl;
    cout << pascalsTriangle(4, 2) << endl;
    return 0;
}