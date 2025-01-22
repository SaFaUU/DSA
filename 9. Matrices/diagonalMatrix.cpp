#include <iostream>
using namespace std;

struct Matrix
{
  int m[10];
  int n;
};

void set(struct Matrix *A, int i, int j, int x)
{
  if (i == j)
    A->m[i - 1] = x;
}
void get(struct Matrix A, int i, int j)
{
  if (i == j)
    cout << A.m[i - 1];
}

void display(struct Matrix A)
{
  int i, j;
  for (i = 1; i <= A.n; i++)
  {
    for (j = 1; j <= A.n; j++)
    {
      if (i == j)
        cout << A.m[i - 1] << " ";
      else
        cout << "0 ";
    }
    cout << endl;
  }
}

main()
{
  struct Matrix A;
  A.n = 3;
  set(&A, 1, 1, 1);
  set(&A, 2, 2, 2);
  set(&A, 3, 3, 3);
  display(A);
  return 0;
}