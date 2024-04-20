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

struct Array *Merge(struct Array arr1, struct Array arr2)
{

    struct Array *arr3 = new struct Array;

    int i = 0,
        j = 0, k = 0;

    while (i < arr1.length & j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
        }
        else
        {
            arr3->A[k++] = arr2.A[j++];
        }
    }

    while (i < arr1.length)
    {
        arr3->A[k++] = arr1.A[i++];
    }

    while (j < arr2.length)
    {
        arr3->A[k++] = arr2.A[j++];
    }
    arr3->length = arr1.length + arr2.length;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1 = {{2, 6, 10, 15, 25}, 10, 5};
    struct Array arr2 = {{3, 4, 7, 18, 20}, 10, 5};
    struct Array *arr3;

    arr3 = Merge(arr1, arr2);

    Display(*arr3);

    return 0;
}