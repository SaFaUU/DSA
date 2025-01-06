#include <iostream>
using namespace std;

struct Array
{
  int *A;
  int size;
  int length;
};

int getSumOfArray(struct Array arr)
{
  int sum = 0;

  for (int i = 0; i < arr.length; i++)
  {
    sum += arr.A[i];
  }

  return sum;
}

int getSumOfNaturals(struct Array arr)
{
  return (arr.A[arr.length - 1] * (arr.A[arr.length - 1] + 1)) / 2;
}

int findMissingleSingleSorted(struct Array arr)
{
  return getSumOfNaturals(arr) - getSumOfArray(arr);
}

void findMultipleMissingElementSorted(struct Array arr)
{
  int difference = arr.A[0] - 0;

  for (int i = 0; i < arr.length; i++)
  {
    if (arr.A[i] != difference + i)
    {
      while (arr.A[i] != difference + i)
      {
        cout << difference + i << " ";
        difference++;
      }
    }
  }
}

void findMultipleMissingElementSorted2(struct Array arr)
{
  int max = arr.A[0];

  for (int i = 1; i < arr.length; i++)
  {
    if (arr.A[i] > max)
    {
      max = arr.A[i];
    }
  }

  int newArray[max];

  for (int i = 0; i < max; i++)
  {
    newArray[i] = 0;
  }

  for (int i = 0; i < arr.length; i++)
  {
    newArray[arr.A[i]] += 1;
  };

  for (int i = arr.A[0]; i < max; i++)
  {
    if (newArray[i] == 0)
    {
      cout << i << " ";
    }
  }
}

int main()
{
  int A[] = {1, 2, 3, 5, 6};
  struct Array arr = {A, 10, 5};

  cout << findMissingleSingleSorted(arr) << endl;

  int B[] = {6, 7, 9, 10, 11, 15};
  struct Array arr2 = {B, 10, 6};

  cout << "The missing elements are: ";
  findMultipleMissingElementSorted(arr2);
  cout << endl;

  cout << "The missing elements are: ";
  findMultipleMissingElementSorted2(arr2);
  cout << endl;

  return 0;
}