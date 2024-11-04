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
    B[0] = new int[4]{1, 2, 3, 4};
    B[1] = new int[4]{4, 5, 6, 7};
    B[2] = new int[4]{7, 8, 9, 10};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    };

    int **C;
    C = new int *[3];

    C[0] = new int[4]{1, 2, 3, 4};
    C[1] = new int[4]{4, 5, 6, 7};
    C[2] = new int[4]{7, 8, 9, 10};

    cout << "Matrix 3:" << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    };

    return 0;
}