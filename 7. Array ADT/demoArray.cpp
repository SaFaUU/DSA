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
    cout << "The Elements are: ";
    for (int i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void Append(struct Array *arr, int item)
{
    arr->A[arr->length] = item;
    arr->length += 1;
};

void Insert(struct Array *arr, int item, int index)
{
    for (int i = arr->length - 1; i >= index; i--)
    {
        arr->A[i + 1] = arr->A[i];
    }
    arr->A[index] = item;
    arr->length += 1;
}

int main()
{
    struct Array arr;
    cout << "Please Enter the Array Size" << endl;
    cin >> arr.size;

    arr.A = new int[arr.size];
    arr.length = 0;

    cout << "Please Enter the Array Length" << endl;
    cin >> arr.length;

    cout << "Please Enter the Elements of the Array" << endl;
    for (int i = 0; i < arr.length; i++)
    {
        cin >> arr.A[i];
    }

    Append(&arr, 6);
    Insert(&arr, 100, 0);
    cout << "Array Length: " << arr.length << endl;

    Display(arr);

    return 0;
}