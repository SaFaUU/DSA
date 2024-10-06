#include <iostream>
using namespace std;

void func(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = A[i] + 1;
        cout << A[i] << " ";
    }
    printf("\n");
}

int *funcReturn(int n)
{
    int *p;

    p = new int[n];

    return p;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};
    int *B;

    func(A, 5);

    B = funcReturn(5);
    for (int i = 0; i < 5; i++)
    {
        cout << B[i] << " ";
    }
    printf("\n");

    delete[] B;

    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}