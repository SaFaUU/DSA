#include <iostream>
using namespace std;

int *fun(int n)
{

    int *p;
    p = (int *)malloc(n * sizeof(int));
    return (p);
}
int main()
{
    int *a;
    a = fun(5);

    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}