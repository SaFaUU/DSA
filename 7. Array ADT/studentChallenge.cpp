#include <iostream>
using namespace std;

struct Array
{
  int *A;
  int size;
  int length;
};

void getDuplicates(struct Array arr)
{
  int lastDuplicate = 0;

  cout << "The duplicate elements are: ";

  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] == arr.A[i + 1] && arr.A[i] != lastDuplicate)
    {
      cout << arr.A[i] << " ";
      lastDuplicate = arr.A[i];
    }
  }

  cout << endl;
}

void getDuplicateCounts(struct Array arr)
{
  int lastDuplicate = 0;

  cout << "The duplicate elements with Counts: " << endl;

  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] == arr.A[i + 1] && arr.A[i] != lastDuplicate)
    {
      // cout << arr.A[i] << " ";
      // lastDuplicate = arr.A[i];
      int j = i + 1;
      while (arr.A[j] == arr.A[i])
      {
        j++;
      };
      cout << arr.A[i] << " " << "Element is found" << " " << j - i << " times" << endl;
      i = j - 1;
    }
  }

  cout << endl;
}

void getDuplicateCounts2(struct Array arr)
{
  int max = arr.A[arr.length - 1];

  int newArray[max];

  for (int i = 0; i < max; i++)
  {
    newArray[i] = 0;
  }

  for (int i = 0; i < arr.length; i++)
  {
    newArray[arr.A[i]] += 1;
  }

  cout << "The duplicate elements with Counts: " << endl;
  for (int i = 0; i < max; i++)
  {
    if (newArray[i] > 1)
    {
      cout << i << " " << "Element is found" << " " << newArray[i] << " times" << endl;
    }
  }
}

void getDuplicatesInUnsorted(struct Array arr)
{

  for (int i = 0; i < arr.length - 1; i++)
  {
    int count = 1;
    if (arr.A[i] == -1)
    {
      continue;
    }
    for (int j = i + 1; j < arr.length; j++)
    {
      if (arr.A[i] == arr.A[j])
      {
        count++;
        arr.A[j] = -1;
      }
    }
    if (count > 1)
    {
      cout << arr.A[i] << " " << "Element is found" << " " << count << " times" << endl;
    }
  }
}

void findingSumOfElements(struct Array arr, int sum)
{
  for (int i = 0; i < arr.length - 1; i++)
  {
    for (int j = i + 1; j < arr.length; j++)
    {
      if ((sum - arr.A[i]) == arr.A[j])
      {
        cout << arr.A[i] << "+" << arr.A[j] << "=" << arr.A[i] + arr.A[j] << endl;
      }
    }
  }
}

void findingSumOfElements2(struct Array arr, int sum)
{
  int i = 0, j = arr.length - 1;

  while (i < j)
  {
    if (arr.A[i] + arr.A[j] == sum)
    {
      cout << arr.A[i] << "+" << arr.A[j] << "=" << arr.A[i] + arr.A[j] << endl;
      i++;
      j--;
    }
    else if (arr.A[i] + arr.A[j] > sum)
    {
      j--;
    }
    else if (arr.A[i] + arr.A[j] < sum)
    {
      i++;
    }
  }
}

int main()
{
  // int A[] = {1, 2, 3, 3, 5, 6, 6, 6, 8};
  // struct Array arr = {A, 10, 9};

  // getDuplicates(arr);
  // getDuplicateCounts(arr);
  // getDuplicateCounts2(arr);

  // cout << "Unsorted Array" << endl;
  // int B[] = {3, 5, 3, 6, 7, 9, 10, 4, 7, 9};

  // struct Array arr2 = {B, 10, 10};
  // getDuplicatesInUnsorted(arr2);

  int C[] = {2, 3, 4, 5, 6, 7, 8, 9};

  struct Array arr3 = {C, 10, 8};
  cout << "Finding Sum of Elements using Method 1" << endl;
  findingSumOfElements(arr3, 10);

  cout << "Finding Sum of Elements using Method 2" << endl;
  findingSumOfElements2(arr3, 10);

  return 0;
}