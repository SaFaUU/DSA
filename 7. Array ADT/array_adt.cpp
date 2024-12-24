#include <iostream>
#include <cmath>

using namespace std;

struct Array
{
  int A[10];
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
  for (int i = arr->length; i >= index; i--)
  {
    arr->A[i] = arr->A[i - 1];
  }
  arr->A[index] = item;
  arr->length += 1;
}

void Delete(struct Array *arr, int index)
{
  if (index > arr->length)
  {
    return;
  }

  for (int i = index; i < arr->length; i++)
  {
    arr->A[i] = arr->A[i + 1];
  }

  arr->length--;
}

int LinearSearch(struct Array arr, int key)
{
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] == key)
    {
      return i;
    }
  }
  return -1;
}

int BinarySearch(struct Array arr, int key)
{
  int lowIndex = 0;
  int highIndex = arr.length - 1;

  while (lowIndex <= highIndex)
  {
    int midIndex = floor((lowIndex + highIndex) / 2);

    if (key == arr.A[midIndex])
    {
      return midIndex;
    }

    if (key < arr.A[midIndex])
    {
      highIndex = midIndex - 1;
    }

    if (key > arr.A[midIndex])
    {
      lowIndex = midIndex + 1;
    }
  }

  return -1;
}

int BinarySearchRecursive(struct Array arr, int lowIndex, int highIndex, int key)
{
  if (lowIndex <= highIndex)
  {

    int midIndex = floor((lowIndex + highIndex) / 2);

    if (key == arr.A[midIndex])
    {
      return midIndex;
    }

    if (key < arr.A[midIndex])
    {
      return BinarySearchRecursive(arr, lowIndex, highIndex - 1, key);
    }

    if (key > arr.A[midIndex])
    {
      return BinarySearchRecursive(arr, lowIndex + 1, highIndex, key);
    }
  }
  return -1;
}

int Get(struct Array arr, int index)
{
  if (index <= 0 || index >= arr.length)
  {
    return -1;
  }
  else
  {
    return arr.A[index];
  }
}
int Set(struct Array *arr, int index, int value)
{
  if (index <= 0 || index >= arr->length)
  {
    return -1;
  }
  else
  {
    arr->A[index] = value;
    return 0;
  }
}

int Max(struct Array arr)
{
  int max = arr.A[0];
  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] > max)
    {
      max = arr.A[i];
    }
  }
  return max;
}

int Sum(struct Array arr)
{
  int total = 0;
  for (int i = 0; i < arr.length; i++)
  {
    total += arr.A[i];
  }
  return total;
}

float Avg(struct Array arr)
{
  return float(Sum(arr)) / arr.length;
}

void ReverseArray(struct Array *arr)
{
  int SArray[arr->length];

  for (int i = arr->length - 1, j = 0; i >= 0; i--, j++)
  {
    SArray[j] = arr->A[i];
  }

  for (int k = 0; k <= arr->length; k++)
  {
    arr->A[k] = SArray[k];
  }
}

void ReverseArraySwap(struct Array *arr)
{
  for (int i = 0, j = arr->length - 1; i < j; i++, j--)
  {
    int temp = arr->A[i];
    arr->A[i] = arr->A[j];
    arr->A[j] = temp;
  }
}

int main()
{
  struct Array arr = {{2, 3, 4, 5, 6, 100}, 10, 6};
  Display(arr);

  // Linear Search
  int index = LinearSearch(arr, 100);
  cout << "Element Found using Linear Search at Index: " << index << endl;

  // Binary Search
  index = BinarySearch(arr, 100);
  cout << "Element Found using Binary Search at Index: " << index << endl;

  // Binary Search
  index = BinarySearchRecursive(arr, 0, arr.length - 1, 100);
  cout << "Element Found using Binary Search Recursive at Index: " << index << endl;

  // Getting an Element
  Display(arr);
  cout << "Element at Index 2: " << Get(arr, 2) << endl;

  // Setting an Element
  Set(&arr, 2, 99);
  Display(arr);
  cout << "Element at Index 2: " << Get(arr, 2) << endl;

  // Max Element
  cout << "Max Element: " << Max(arr) << endl;

  // Sum of Elements
  cout << "Sum of Elements: " << Sum(arr) << endl;

  // Average of Elements
  cout << "Average of Elements: " << Avg(arr) << endl;

  // Reversing the Array
  cout << "Reversing the Array" << endl;
  Display(arr);
  ReverseArray(&arr);
  Display(arr);

  // Reversing the Array with Swap
  cout << "Reversing the Array with Swap" << endl;
  Display(arr);
  ReverseArraySwap(&arr);
  Display(arr);

  return 0;
}