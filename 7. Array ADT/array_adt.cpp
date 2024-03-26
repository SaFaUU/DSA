#include <iostream>
using namespace std;

struct Array
{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("Elements are \n");
    for (int i = 0; i < arr.length; i++)
    {
        /* code */
        printf("%d ", arr.A[i]);
    }
}

int main()
{
    struct Array arr;
    int n;
    printf("Enter Size of an Array \n");
    scanf("%d", &arr.size);
    arr.A = new int[arr.size];
    arr.length = 0;
    printf("Enter number of numbers \n");
    scanf("%d", &n);
    arr.length = n;

    printf("Enter all Elements \n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr.A[i]);
    }

    Display(arr);

    delete[] arr.A;

    return 0;
}