#include <iostream>
using namespace std;

void fun(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[5] = {2, 4, 6, 8, 10};
    fun(a, 5);
    return 0;
}