#include <iostream>
using namespace std;

struct Element
{
  int i;
  int j;
  int x;
};

struct Sparse
{
  int m;
  int n;
  int num;
  Element *element;
};

void create(struct Sparse *s)
{
  cout << "Enter number of rows and columns" << endl;
  cin >> s->m >> s->n;
  cout << "Enter number of non-zero elements" << endl;
  cin >> s->num;
  s->element = new Element[s->num];

  cout << "Enter non-zero elements" << endl;
  for (int i = 0; i < s->num; i++)
  {
    cin >> s->element[i].i >> s->element[i].j >> s->element[i].x;
  }
}

void display(struct Sparse s)
{
  cout << "The sparse matrix is" << endl;
  int k = 0;
  for (int i = 1; i <= s.m; i++)
  {
    for (int j = 1; j <= s.n; j++)
    {
      if (s.element[k].i == i && s.element[k].j == j)
      {
        cout << s.element[k].x << " ";
        k++;
      }
      else
      {
        cout << "0 ";
      }
    }
    cout << endl;
  }
}

int main()
{
  struct Sparse s;
  create(&s);
  display(s);
  return 0;
}