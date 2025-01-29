#include <iostream>
using namespace std;

class upperTriangle
{
private:
  int n;  // Size of the matrix (n x n)
  int *A; // 1D array to store the upper triangular elements

public:
  upperTriangle(int n)
  {
    this->n = n;
    A = new int[n * (n + 1) / 2]; // Allocate memory for the upper triangular elements
  }

  ~upperTriangle()
  {
    delete[] A; // Release the allocated memory to avoid memory leak
  }

  // Set the value at (i, j) in the matrix
  void set(int i, int j, int x)
  {
    if (i <= j)
    { // Only store elements in the upper triangular part
      int index = (i - 1) * n - ((i - 1) * (i - 2)) / 2 + (j - i);
      A[index] = x;
    }
  }

  // Get the value at (i, j) in the matrix
  int get(int i, int j)
  {
    if (i <= j)
    { // Only retrieve elements from the upper triangular part
      int index = (i - 1) * n - ((i - 1) * (i - 2)) / 2 + (j - i);
      return A[index];
    }
    else
    {
      return 0; // Return 0 for lower triangular elements
    }
  }

  // Display the matrix
  void display()
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (i <= j)
        {
          cout << get(i, j) << " "; // Use the get method to retrieve values
        }
        else
        {
          cout << "0 "; // Print 0 for lower triangular elements
        }
      }
      cout << endl;
    }
  }
};

int main()
{
  int n = 3;
  upperTriangle d(n);

  cout << "Please enter the elements of the matrix (row by row): " << endl;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int x;
      cin >> x;
      if (i <= j)
      { // Only store elements in the upper triangular part
        d.set(i, j, x);
      }
    }
  }

  cout << "The matrix is: " << endl;
  d.display();

  return 0;
}