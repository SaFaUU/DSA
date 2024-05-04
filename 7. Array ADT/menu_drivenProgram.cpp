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

void Append(struct Array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

void Insert(struct Array *arr, int index, int x)
{
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

void Swap(int *a, int *b)
{
    int temp = *b;
    b = a;
    a = &temp;
}

int BinarySearch(struct Array arr, int key)
{
    int l = 0;
    int h = arr.length - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr.A[mid] == key)
        {
            return mid;
        }
        else if (arr.A[mid] < key)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    return -1;
}

int Get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
    {
        return arr.A[index];
    };
    return -1;
}

void Set(struct Array *arr, int index, int value)
{
    if (index >= 0 && index < arr->length)
    {
        arr->A[index] = value;
    }
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] > max)
        {
            max = arr.A[i];
        }
    };
    return max;
}

int Min(struct Array arr)
{
    int min = arr.A[0];
    for (int i = 1; i < arr.length; i++)
    {
        if (arr.A[i] < min)
        {
            min = arr.A[i];
        }
    };
    return min;
}

int Sum(struct Array arr)
{

    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        /* code */
        sum += arr.A[i];
    }
    return sum;
}

float avg(struct Array arr)
{
    int sum = 0;
    for (int i = 0; i < arr.length; i++)
    {
        /* code */
        sum += arr.A[i];
    }
    return sum / arr.length;
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

struct Array *Union(struct Array arr1, struct Array arr2)
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
        else if (arr2.A[j] < arr1.A[i])
        {
            arr3->A[k++] = arr2.A[j++];
        }
        else
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
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
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Isect(Array arr1, struct Array arr2)
{

    struct Array *arr3 = new struct Array;

    int i = 0,
        j = 0, k = 0;

    while (i < arr1.length & j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
        {
            i++;
        }
        else if (arr2.A[j] < arr1.A[i])
        {
            j++;
        }
        else if (arr1.A[i] == arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

struct Array *Difference(Array arr1, struct Array arr2)
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
        else if (arr2.A[j] < arr1.A[i])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while (i < arr1.length)
    {
        arr3->A[k++] = arr1.A[i++];
    }

    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

int main()
{
    struct Array arr1;
    printf("Enter Size of Array");
    scanf("%d", &arr1.size);
    arr1.A = new int[arr1.size];

    printf("Enter Length of Array");
    scanf("%d", &arr1.length);
    printf("Enter Elements of Array");
    for (int i = 0; i < arr1.length; i++)
    {
        scanf("%d", &arr1.A[i]);
    }

    printf("Menu");

    printf("\n1. Insert");
    printf("\n2. Display");
    printf("\n3. Binary Search");
    printf("\n4. Sum");
    printf("\n8. Exit");

    int choice;
    int sum;
    do
    {
        printf("\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an element and index");
            scanf("%d%d", &arr1.A[arr1.length], &arr1.length);
            Insert(&arr1, arr1.length, arr1.A[arr1.length - 1]);
            break;
        case 2:
            Display(arr1);
            break;
        case 3:
            printf("Enter an element to search");
            scanf("%d", &arr1.length);
            BinarySearch(arr1, arr1.length);
            break;
        case 4:
            sum = Sum(arr1);
            printf("Sum = %d", sum);
            break;
        case 8:
            exit(0);
        }
    } while (choice != 8);

    return 0;
}