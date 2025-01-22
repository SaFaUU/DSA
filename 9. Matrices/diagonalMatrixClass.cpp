#include <iostream>
using namespace std;
class DiagonalMatrix
{
private:
  int n;
  int *A;

public:
  DiagonalMatrix(int n)
  {
    this->n = n;
    A = new int[n];
  };
  void set(int i, int j, int x);
  int get(int i, int j);
  void display();
};

void DiagonalMatrix::set(int i, int j, int x)
{
  if (i == j)
    A[i - 1] = x;
}

int DiagonalMatrix::get(int i, int j)
{
  if (i == j)
    return A[i - 1];
}

void DiagonalMatrix::display()
{
  int i, j;
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
    {
      if (i == j)
        cout << A[i - 1] << " ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
}

int main()
{
  DiagonalMatrix d(3);
  d.set(1, 1, 1);
  d.set(2, 2, 2);
  d.set(3, 3, 3);
  d.display();
  return 0;
}