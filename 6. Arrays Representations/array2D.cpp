#include <iostream>
using namespace std;
int main()
{
    cout << "Matrix 1:" << endl;
    int A[3][4] = {{1, 2, 3, 4}, {4, 5, 6, 7}, {7, 8, 9, 10}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix 2:" << endl;

    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    B[0] = {1, 2, 3, 4};

    return 0;
}