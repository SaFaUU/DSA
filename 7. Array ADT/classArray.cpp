#include <iostream>
#include <cmath>

using namespace std;

class Array
{
private:
  int *A;
  int size;
  int length;
  void Swap(int *a, int *b);

public:
  Array()
  {
    size = 10;
    length = 0;
    A = new int[size];
  }
  Array(int sz)
  {
    size = sz;
    length = 0;
    A = new int[size];
  }
  void Display();
  void Append(int item);
  void Insert(int item, int index);
  void Delete(int index);
  int LinearSearch(int key);
  int BinarySearch(int key);
  int BinarySearchRecursive(int lowIndex, int highIndex, int key);
  int Get(int index);
  int Set(int index, int value);
  int Max();
  int Sum();
  float Avg();
  void ReverseArray();
  void ReverseArraySwap();
  void leftRotate();
  void rightRotate();
  void leftShift();
  void rightShift();

  ~Array()
  {
    delete[] A;
  }
};

void Array::Display()
{
  cout << "The Elements are: ";
  for (int i = 0; i < length; i++)
  {
    cout << A[i] << " ";
  }
  cout << endl;
}

void Array::Append(int item)
{
  A[length] = item;
  length += 1;
};

void Array::Insert(int item, int index)
{
  for (int i = length; i >= index; i--)
  {
    A[i] = A[i - 1];
  }
  A[index] = item;
  length += 1;
}

void Array::Delete(int index)
{
  if (index > length)
  {
    return;
  }

  for (int i = index; i < length; i++)
  {
    A[i] = A[i + 1];
  }

  length--;
}

int Array::LinearSearch(int key)
{
  for (int i = 0; i < length; i++)
  {
    if (A[i] == key)
    {
      return i;
    }
  }
  return -1;
}

int Array::BinarySearch(int key)
{
  int lowIndex = 0;
  int highIndex = length - 1;

  while (lowIndex <= highIndex)
  {
    int midIndex = floor((lowIndex + highIndex) / 2);

    if (key == A[midIndex])
    {
      return midIndex;
    }

    if (key < A[midIndex])
    {
      highIndex = midIndex - 1;
    }

    if (key > A[midIndex])
    {
      lowIndex = midIndex + 1;
    }
  }

  return -1;
}

int Array::BinarySearchRecursive(int lowIndex, int highIndex, int key)
{
  if (lowIndex <= highIndex)
  {

    int midIndex = floor((lowIndex + highIndex) / 2);

    if (key == A[midIndex])
    {
      return midIndex;
    }

    if (key < A[midIndex])
    {
      return BinarySearchRecursive(lowIndex, highIndex - 1, key);
    }

    if (key > A[midIndex])
    {
      return BinarySearchRecursive(lowIndex + 1, highIndex, key);
    }
  }
  return -1;
}

int Array::Get(int index)
{
  if (index <= 0 || index >= length)
  {
    return -1;
  }
  else
  {
    return A[index];
  }
}
int Array::Set(int index, int value)
{
  if (index <= 0 || index >= length)
  {
    return -1;
  }
  else
  {
    A[index] = value;
    return 0;
  }
}

int Array::Max()
{
  int max = A[0];
  for (int i = 0; i < length; i++)
  {
    if (A[i] > max)
    {
      max = A[i];
    }
  }
  return max;
}

int Array::Sum()
{
  int total = 0;
  for (int i = 0; i < length; i++)
  {
    total += A[i];
  }
  return total;
}

float Array::Avg()
{
  return float(Sum()) / length;
}

void Array::ReverseArray()
{
  int SArray[length];

  for (int i = length - 1, j = 0; i >= 0; i--, j++)
  {
    SArray[j] = A[i];
  }

  for (int k = 0; k <= length; k++)
  {
    A[k] = SArray[k];
  }
}

void Array::ReverseArraySwap()
{
  for (int i = 0, j = length - 1; i < j; i++, j--)
  {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}

void Array::Swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Array::leftRotate()
{
  int firstElement = A[0];

  for (int i = 0; i < length - 1; i++)
  {
    A[i] = A[i + 1];
  }

  A[length - 1] = firstElement;
}

void Array::rightRotate()
{
  int lastElement = A[length - 1];

  for (int i = length - 1; i > 0; i--)
  {
    A[i] = A[i - 1];
  }

  A[0] = lastElement;
}

void Array::leftShift()
{
  for (int i = 0; i < length; i++)
  {
    Swap(&A[i], &A[i + 1]);
  }
  A[length - 1] = 0;
}

void Array::rightShift()
{
  for (int i = length - 1; i >= 0; i--)
  {
    Swap(&A[i], &A[i - 1]);
  }
  A[0] = 0;
}

void Array::InsertInSort(struct Array *arr, int x)
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

int Array::IsSorted(struct Array arr)
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

void Array::ReArrange(struct Array *arr)
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

struct Array Array::MergeSortedArray(struct Array arr1, struct Array arr2)
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

struct Array Array::UnionArray(struct Array arr1, struct Array arr2)
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

struct Array Array::IntersectionArray(struct Array arr1, struct Array arr2)
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

struct Array Array::DifferenceArray(struct Array arr1, struct Array arr2)
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