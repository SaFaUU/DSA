#include <iostream>
using namespace std;

int fib(int n)
{
    int t0 = 0, t1 = 1;

    if (n <= 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
};

int fibOptRec(int n, int arr[])
{
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        if (arr[n - 2] == -1)
        {
            arr[n - 2] = fibOptRec(n - 2, arr);
        }

        if (arr[n - 1] == -1)
        {
            arr[n - 1] = fibOptRec(n - 1, arr);
        }
    }
    arr[n] = arr[n - 2] + arr[n - 1];
    return arr[n];
}

int fibIter(int n)
{
    int t0 = 0, t1 = 1;
    int r = 0;

    if (n <= 1)
    {
        return n;
    }

    for (int i = 2; i <= n; i++)
    {
        r = t0 + t1;
        t0 = t1;
        t1 = r;
    }
    return r;
}

int main()
{
    cout << fib(7) << endl;
    cout << fibIter(7) << endl;
    int arr[10];
    for (int i = 0; i <= 10; i++)
    {
        arr[i] = -1;
    }
    cout << fibOptRec(7, arr) << endl;
    return 0;
}