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
    printf("\n");
}

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
    if (index == arr->length)
    {
        arr->A[index] = 0;
        arr->length--;
        return;
    }

    if (index > 0 && index <= arr->length)
    {
        for (int i = arr->length; i > index; i--)
        {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

void Delete(struct Array *arr, int index)
{

    if (index > 0 && index < arr->length)
    {
        for (int i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
    }
}

int checkSorted(struct Array arr)
{
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < arr.A[i - 1])
        {
            return false;
        }
    }
    return true;
}

void InsertSort(struct Array *arr, int num)
{
    int i = arr->length - 1; // 5
    printf("Array Last Index is: %d \n", i);
    while (arr->A[i] > num && i >= 0)
    {
        arr->A[i + 1] = arr->A[i];
        printf("Moving Element %d from index %d to index %d \n", arr->A[i], i, i + 1);
        i--;
    }
    arr->A[i + 1] = num;
    arr->length++;
}

// void Swap(int *a, int *b)
// {
//     int temp = *b;
//     b = a;
//     a = &temp;
// }

void SortVE(struct Array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] > 0)
        {
            j--;
        }
        if (i < j)
        {
            printf("Swapping between %d and %d \n", arr->A[i], arr->A[j]);
            swap(arr->A[i], arr->A[j]);
            Display(*arr);
        }
    }
}

int main()
{
    // struct Array arr = {{1, 2, 4, 5, 6}, 10, 5};
    struct Array arr = {{-1, 2, 4, -5, -6}, 10, 5};
    // cout << "Array Sort Status: " << checkSorted(arr) << endl;
    // InsertSort(&arr, 3);
    SortVE(&arr);
    Display(arr);

    return 0;
}