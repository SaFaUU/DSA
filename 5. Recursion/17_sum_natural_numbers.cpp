#include <iostream>
using namespace std;

int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + sum(n - 1);
    }
}
int main()
{
    int r;
    r = sum(5);
    printf("%d", r);
    return 0;
}