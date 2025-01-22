#include <iostream>
using namespace std;
class lowerTriangle
{
private:
  int n;
  int *A;

public:
  lowerTriangle(int n)
  {
    this->n = n;
    A = new int[n * (n + 1) / 2];
  };
  void set(int i, int j, int x);
  int get(int i, int j);
  void display();
};

void lowerTriangle::set(int i, int j, int x)
{
  // a11, a21, a22, a31, a32, a33
  A[i * (i - 1) / 2 + j - 1] = x;
}

int lowerTriangle::get(int i, int j)
{
  if (i >= j)
  {
    return A[i * (i - 1) / 2 + j - 1];
  }
  else
  {
    return 0;
  }
}

void lowerTriangle::display()
{
  int i, j;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (i >= j)
        cout << A[i * (i - 1) / 2 + j - 1] << " ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
  lowerTriangle d(3);
  cout << "Please enter the elements of the matrix: " << endl;
  for (int i = 1; i <= 3; i++)
  {
    for (int j = 1; j <= 3; j++)
    {
      int x;
      cin >> x;
      d.set(i, j, x);
    }
  }
  cout << "The matrix is: " << endl;
  d.display();
  return 0;
}