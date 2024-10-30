#include <iostream>
using namespace std;
int main()
{
    int A[5];
    int *p;

    p = new int[5];
    // p = A;
    cout << p << " "; // Corrected printing method
    p[0] = 5;         // This should work fine
    cout << p[0];     // Optional: print the value to confirm
    delete[] p;
    p = nullptr;
}
