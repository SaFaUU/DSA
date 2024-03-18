#include <iostream>
using namespace std;
int main()
{
    // int A[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // int *B[3];
    // B[0] = new int[4];
    // B[1] = new int[4];
    // B[2] = new int[4];

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << B[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // Creating array with double pointer

    int **C;
    C = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        C[i] = new int[4];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            C[i][j] = 5;
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}