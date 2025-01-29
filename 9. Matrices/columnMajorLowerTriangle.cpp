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
  // a11(0), a21(1), a31(2), a41(3), || a22(4), a32(5), a42(6), || a33(7), a43(8), || a44(9)
  // A[n * (j - 1) - ((j - 1) * (j - 2) / 2) + i - j] = x;
  A[n * (j - 1) - ((j - 1) * (j - 2) / 2) + i - j] = x;
}

int lowerTriangle::get(int i, int j)
{
  if (i >= j)
  {
    return A[n * (j - 1) - ((j - 1) * (j - 2) / 2) + i - j];
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
        cout << A[n * (j - 1) - ((j - 1) * (j - 2) / 2) + i - j] << " ";
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