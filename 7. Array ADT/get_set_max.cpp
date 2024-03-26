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
    printf("Elements are ");
    for (int i = 0; i < arr.length; i++)
    {
        /* code */
        printf("%d ", arr.A[i]);
    }
    printf("\n");
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

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};

    Display(arr);
    cout << "Element 2 Found in index " << Get(arr, 2) << "\n"
         << endl;
    Set(&arr, 2, 4);
    Display(arr);
    cout << "Max Element is " << Max(arr) << "\n"
         << endl;

    cout << "Min Element is " << Min(arr) << "\n"
         << endl;

    printf("Sum is %d \n", Sum(arr));

    printf("Avg is %f \n", avg(arr));

    return 0;
}