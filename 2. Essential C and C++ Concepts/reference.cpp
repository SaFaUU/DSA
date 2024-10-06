#include <iostream>
using namespace std;
int main()
{
    int a = 10;
    int &r = a;

    printf("%d \n", r);
    return 0;
}