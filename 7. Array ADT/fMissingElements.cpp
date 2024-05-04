#include <iostream>
using namespace std;
int main()
{
    int A[] = {1, 2, 4, 5, 6, 7, 9, 10};
    int diff = A[0] - 0;

    int i = 0;
    while (i < sizeof(A) / sizeof(A[0]))
    {
        if (A[i] != diff + i)
        {
            cout << diff + i << " ";
            diff++;
        }
        i++;
    }

    return 0;
}