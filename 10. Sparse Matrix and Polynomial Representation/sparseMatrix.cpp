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

struct Sparse *add(struct Sparse s1, struct Sparse s2)
{
  int i = 0, j = 0, k = 0;

  struct Sparse *s3 = new Sparse;
  s3->m = s1.m;
  s3->n = s1.n;
  s3->element = new Element[s1.num + s2.num];

  while (i < s1.num || k < s2.num)
  {
    if (s1.element[i].i < s2.element[j].i)
    {
      s3->element[k] = s1.element[i];
      i++;
      k++;
    }
    else if (s1.element[i].i > s2.element[j].i)
    {
      s3->element[k] = s2.element[j];
      j++;
      k++;
    }
    else
    {
      if (s1.element[i].j < s2.element[j].j)
      {
        s3->element[k] = s1.element[i];
        i++;
        k++;
      }
      else if (s1.element[i].j > s2.element[j].j)
      {
        s3->element[k] = s2.element[j];
        j++;
        k++;
      }
      else
      {
        s3->element[k] = s1.element[i];
        s3->element[k].x = s1.element[i].x + s2.element[j].x;
        i++;
        j++;
        k++;
      }
    }
  }

  s3->num = k;
  return s3;
}

int main()
{
  struct Sparse s1, s2, *s;
  create(&s1);
  create(&s2);
  s = add(s1, s2);
  display(*s);
  return 0;
}