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

  return 0;
}