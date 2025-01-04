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
  void InsertInSort(int x);
  int IsSorted();
  void ReArrange();
  Array MergeSortedArray(const Array &arr1, struct Array &arr2);
  Array UnionArray(const Array &arr1, struct Array &arr2);
  Array IntersectionArray(const Array &arr1, struct Array &arr2);
  Array DifferenceArray(const Array &arr1, struct Array &arr2);
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

  if (highIndex == -1)
  {
    highIndex = length - 1;
  }

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

void Array::InsertInSort(int x)
{
  if (length > size)
  {
    return;
  }

  int i;
  for (i = length - 1; A[i] > x; i--)
  {
    if (x < A[i])
    {
      A[i + 1] = A[i];
    }
  }
  A[i + 1] = x;
  length++;
}

int Array::IsSorted()
{
  for (int i = 0; i < length - 1; i++)
  {
    if (A[i] > A[i + 1])
    {
      return -1;
    }
  }
  return 1;
}

void Array::ReArrange()
{
  int i = 0, j = length - 1;
  while (i < j)
  {

    while (A[i] < 0)
    {
      i++;
    }
    while (A[j] >= 0)
    {
      j--;
    }

    if (i < j)
    {
      Swap(&A[i], &A[j]);
    }
  }
}

Array Array::MergeSortedArray(const Array &arr1, struct Array &arr2)
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

Array Array::UnionArray(const Array &arr1, struct Array &arr2)
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

Array Array::IntersectionArray(const Array &arr1, struct Array &arr2)
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

Array Array::DifferenceArray(const Array &arr1, struct Array &arr2)
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
  Array arr;

  arr.Insert(100, 0);
  arr.Insert(200, 1);
  arr.Insert(300, 2);
  arr.Insert(400, 3);
  arr.Insert(500, 4);
  arr.Insert(600, 5);
  arr.Insert(700, 6);
  arr.Insert(800, 7);
  arr.Insert(900, 8);
  arr.Insert(1000, 9);

  arr.Display();

  // Linear Search
  int index = arr.LinearSearch(100);
  cout << "Element Found using Linear Search at Index: " << index << endl;

  // Binary Search
  index = arr.BinarySearch(100);
  cout << "Element Found using Binary Search at Index: " << index << endl;

  // Binary Search
  index = arr.BinarySearchRecursive(0, -1, 100);
  cout << "Element Found using Binary Search Recursive at Index: " << index << endl;

  // Getting an Element
  arr.Append(2);
  cout << "Element at Index 2: " << arr.Get(2) << endl;

  // Setting an Element
  arr.Set(2, 99);
  arr.Display();
  cout << "Element at Index 2: " << arr.Get(2) << endl;

  // Max Element
  cout << "Max Element: " << arr.Max() << endl;

  // Sum of Elements
  cout << "Sum of Elements: " << arr.Sum() << endl;

  // Average of Elements
  cout << "Average of Elements: " << arr.Avg() << endl;

  // Reversing the Array
  cout << "Reversing the Array" << endl;
  arr.Display();
  arr.ReverseArray();
  arr.Display();

  // Reversing the Array with Swap
  cout << "Reversing the Array with Swap" << endl;
  arr.Display();
  arr.ReverseArraySwap();
  arr.Display();

  // Left Rotate
  cout << "Left Rotate" << endl;
  arr.Display();
  arr.leftRotate();
  arr.Display();

  // Right Rotate
  cout << "Right Rotate" << endl;
  arr.Display();
  arr.rightRotate();
  arr.Display();

  // Left Shift
  cout << "Left Shift" << endl;
  arr.Display();
  arr.leftShift();
  arr.Display();

  // Right Shift
  cout << "Right Shift" << endl;
  arr.Display();
  arr.rightShift();
  arr.Display();

  // Reinitializing
  // arr = {{2, 8, 12, 15, 16, 100}, 10, 6};
  Array arrSorted;
  arrSorted.Append(2);
  arrSorted.Append(8);
  arrSorted.Append(12);
  arrSorted.Append(15);
  arrSorted.Append(16);
  arrSorted.Append(100);

  // Is Sorted
  cout << "Is Sorted: " << arrSorted.IsSorted() << endl;

  // Insert in Sorted
  arrSorted.Display();
  arrSorted.InsertInSort(10);
  arrSorted.Display();

  // Reinitializing
  Array arrRearrange;
  arrRearrange.Append(2);
  arrRearrange.Append(8);
  arrRearrange.Append(12);
  arrRearrange.Append(-15);
  arrRearrange.Append(16);
  arrRearrange.Append(-100);

  // Rearrange
  arrRearrange.Display();
  arrRearrange.ReArrange();
  arrRearrange.Display();

  // Merge Sorted Array
  // struct Array arr1 = {{1, 3, 5, 7}, 10, 4};
  // struct Array arr2 = {{2, 4, 6, 8}, 10, 4};
  Array arrMergeArray1;
  arrMergeArray1.Append(1);
  arrMergeArray1.Append(3);
  arrMergeArray1.Append(5);
  arrMergeArray1.Append(7);

  Array arrMergeArray2;
  arrMergeArray2.Append(2);
  arrMergeArray2.Append(4);
  arrMergeArray2.Append(6);
  arrMergeArray2.Append(8);

  Array arrMergedArray = arrMergedArray.MergeSortedArray(arrMergeArray1, arrMergeArray2);
  arrMergedArray.Display();

  // Union Array
  // struct Array setA = {{1, 3, 5, 7}, 10, 4};
  // struct Array setB = {{3, 4, 5, 8}, 10, 4};
  Array setA;
  setA.Append(1);
  setA.Append(3);
  setA.Append(5);
  setA.Append(7);

  Array setB;
  setB.Append(3);
  setB.Append(4);
  setB.Append(5);
  setB.Append(8);

  struct Array setC = arr.UnionArray(setA, setB);
  cout << "Union Array: " << endl;
  setC.Display();

  // Intersection Array
  // struct Array setD = {{1, 3, 5, 7}, 10, 4};
  // struct Array setE = {{3, 4, 5, 8}, 10, 4};
  Array setD;
  setD.Append(1);
  setD.Append(3);
  setD.Append(5);
  setD.Append(7);

  Array setE;
  setE.Append(3);
  setE.Append(4);
  setE.Append(5);
  setE.Append(8);

  Array setF = arr.IntersectionArray(setD, setE);
  cout << "Intersection Array: " << endl;
  setF.Display();

  // Difference Array
  // struct Array setG = {{1, 3, 5, 7}, 10, 4};
  // struct Array setH = {{3, 4, 5, 8}, 10, 4};
  Array setG;
  setG.Append(1);
  setG.Append(3);
  setG.Append(5);
  setG.Append(7);

  Array setH;
  setH.Append(3);
  setH.Append(4);
  setH.Append(5);
  setH.Append(8);

  struct Array setI = arr.DifferenceArray(setG, setH);
  cout << "Difference Array: " << endl;
  setI.Display();

  return 0;
}