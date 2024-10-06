#include <iostream>
using namespace std;
int main()
{
    // Pointer Basics
    // int a = 10;
    // int *p;
    // p = &a;
    // printf("%d \n", a);
    // printf("%d \n", p);
    // printf("%d \n", *p);

    // Allocating Heap Memory in C++
    int *p;
    p = new int[5];
    printf("%d \n", p);

    return 0;
}