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

void Swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void leftRotate(struct Array *arr)
{
  int firstElement = arr->A[0];

  for (int i = 0; i < arr->length - 1; i++)
  {
    arr->A[i] = arr->A[i + 1];
  }

  arr->A[arr->length - 1] = firstElement;
}

void rightRotate(struct Array *arr)
{
  int lastElement = arr->A[arr->length - 1];

  for (int i = arr->length - 1; i > 0; i--)
  {
    arr->A[i] = arr->A[i - 1];
  }

  arr->A[0] = lastElement;
}

void leftShift(struct Array *arr)
{
  for (int i = 0; i < arr->length; i++)
  {
    Swap(&arr->A[i], &arr->A[i + 1]);
  }
  arr->A[arr->length - 1] = 0;
}

void rightShift(struct Array *arr)
{
  for (int i = arr->length - 1; i >= 0; i--)
  {
    Swap(&arr->A[i], &arr->A[i - 1]);
  }
  arr->A[0] = 0;
}

void InsertInSort(struct Array *arr, int x)
{
  if (arr->length > arr->size)
  {
    return;
  }

  int i;
  for (i = arr->length - 1; arr->A[i] > x; i--)
  {
    if (x < arr->A[i])
    {
      arr->A[i + 1] = arr->A[i];
    }
  }
  arr->A[i + 1] = x;
  arr->length++;
}

int IsSorted(struct Array arr)
{
  for (int i = 0; i < arr.length - 1; i++)
  {
    if (arr.A[i] > arr.A[i + 1])
    {
      return -1;
    }
  }
  return 1;
}

void ReArrange(struct Array *arr)
{
  int i = 0, j = arr->length - 1;
  while (i < j)
  {

    while (arr->A[i] < 0)
    {
      i++;
    }
    while (arr->A[j] >= 0)
    {
      j--;
    }

    if (i < j)
    {
      Swap(&arr->A[i], &arr->A[j]);
    }
  }
}

struct Array MergeSortedArray(struct Array arr1, struct Array arr2)
{

  struct Array arr3;

  arr3.size = arr1.size + arr2.size;
  arr3.length = arr1.length + arr2.length;

  int i, j, k;
  i = j = k = 0;

  while (i < arr1.length && j < arr2.length)
  {
    if (arr1.A[i] < arr2.A[j])
    {
      arr3.A[k] = arr1.A[i];
      i++;
    }
    else
    {
      arr3.A[k] = arr2.A[j];
      j++;
    }
    k++;
  }

  for (; i < arr1.length; i++)
  {
    arr3.A[k] = arr1.A[i];
    k++;
  }

  for (; j < arr2.length; j++)
  {
    arr3.A[k] = arr2.A[j];
    k++;
  }

  return arr3;
}

struct Array UnionArray(struct Array arr1, struct Array arr2)
{
  struct Array arr3;

  int length = 0;
  arr3.size = arr1.size + arr2.size;

  for (int i = 0; i < arr1.length; i++)
  {
    arr3.A[length++] = arr1.A[i];
  }

  for (int j = 0; j < arr2.length; j++)
  {
    bool found = false;
    for (int i = 0; i < length; i++)
    {
      if (arr3.A[i] == arr2.A[j])
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      arr3.A[length++] = arr2.A[j];
    }
  }

  arr3.length = length;
  return arr3;
}

struct Array IntersectionArray(struct Array arr1, struct Array arr2)
{
  struct Array arr3;

  int length = 0;
  arr3.size = arr1.size + arr2.size;

  for (int i = 0; i < arr1.length; i++)
  {
    for (int j = 0; j < arr2.length; j++)
    {
      if (arr1.A[i] == arr2.A[j])
      {
        arr3.A[length++] = arr1.A[i];
      }
    }
  }

  arr3.length = length;
  return arr3;
}

struct Array DifferenceArray(struct Array arr1, struct Array arr2)
{
  struct Array arr3;

  int length = 0;
  arr3.size = arr1.size + arr2.size;

  for (int i = 0; i < arr1.length; i++)
  {
    bool found = false;
    for (int j = 0; j < arr2.length; j++)
    {
      if (arr1.A[i] == arr2.A[j])
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      arr3.A[length++] = arr1.A[i];
    }
  }

  arr3.length = length;
  return arr3;
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

  // Left Rotate
  cout << "Left Rotate" << endl;
  Display(arr);
  leftRotate(&arr);
  Display(arr);

  // Right Rotate
  cout << "Right Rotate" << endl;
  Display(arr);
  rightRotate(&arr);
  Display(arr);

  // Left Shift
  cout << "Left Shift" << endl;
  Display(arr);
  leftShift(&arr);
  Display(arr);

  // Right Shift
  cout << "Right Shift" << endl;
  Display(arr);
  rightShift(&arr);
  Display(arr);

  // Reinitializing
  arr = {{2, 8, 12, 15, 16, 100}, 10, 6};

  // Is Sorted
  cout << "Is Sorted: " << IsSorted(arr) << endl;

  // Insert in Sorted
  Display(arr);
  InsertInSort(&arr, 10);
  Display(arr);

  // Reinitializing
  arr = {{2, 8, 12, -15, 16, -100}, 10, 6};

  // Rearrange
  Display(arr);
  ReArrange(&arr);
  Display(arr);

  // Merge Sorted Array
  struct Array arr1 = {{1, 3, 5, 7}, 10, 4};
  struct Array arr2 = {{2, 4, 6, 8}, 10, 4};
  struct Array arr3 = MergeSortedArray(arr1, arr2);
  Display(arr3);

  // Union Array
  struct Array setA = {{1, 3, 5, 7}, 10, 4};
  struct Array setB = {{3, 4, 5, 8}, 10, 4};
  struct Array setC = UnionArray(setA, setB);
  cout << "Union Array: " << endl;
  Display(setC);

  // Intersection Array
  struct Array setD = {{1, 3, 5, 7}, 10, 4};
  struct Array setE = {{3, 4, 5, 8}, 10, 4};
  struct Array setF = IntersectionArray(setD, setE);
  cout << "Intersection Array: " << endl;
  Display(setF);

  // Difference Array
  struct Array setG = {{1, 3, 5, 7}, 10, 4};
  struct Array setH = {{3, 4, 5, 8}, 10, 4};
  struct Array setI = DifferenceArray(setG, setH);
  cout << "Difference Array: " << endl;
  Display(setI);

  return 0;
}