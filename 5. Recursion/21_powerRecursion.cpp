#include <iostream>
#include <time.h>
using namespace std;

int power(int m, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return m * power(m, n - 1);
    }
};

int power1(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power1(m * m, n / 2);
    else
        return m * power1(m * m, (n - 1) / 2);
};
int main()
{
    clock_t tStart = clock();
    int r = power(2, 9);
    printf("%d \n", r);
    printf("Time taken: %.4fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
    return 0;
}