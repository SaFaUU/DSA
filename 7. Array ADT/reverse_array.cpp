#include <iostream>
using namespace std;

struct Array
{
    int A[10];
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

void Reverse(struct Array *arr)
{
    int *B;
    B = new int[arr->length];

    for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
    {
        B[j] = arr->A[i];
    }

    for (int i = 0; i < arr->length; i++)
    {
        arr->A[i] = B[i];
    }
}

void Reverse2(struct Array *arr)
{
    for (int i = 0, j = arr->length - 1; i <= j; i++, j--)
    {
        swap(arr->A[i], arr->A[j]);
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};

    // Reverse(&arr);
    Reverse2(&arr);
    Display(arr);

    return 0;
}