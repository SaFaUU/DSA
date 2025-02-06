#include <iostream>
using namespace std;

class Element
{
public:
  int i;
  int j;
  int x;
};

class Sparse
{
private:
  int m;
  int n;
  int num;
  Element *element;

public:
  Sparse(int m, int n, int num)
  {
    this->m = m;
    this->n = n;
    this->num = num;
    element = new Element[num];
  }

  ~Sparse()
  {
    delete[] element;
  };

  Sparse operator+(Sparse &s);

  friend istream &operator>>(istream &in, Sparse &s);
  friend ostream &operator<<(ostream &out, Sparse &s);
};

istream &operator>>(istream &in, Sparse &s)
{
  cout << "Enter non-zero elements" << endl;
  for (int i = 0; i < s.num; i++)
  {
    cin >> s.element[i].i >> s.element[i].j >> s.element[i].x;
  }

  return in;
}

ostream &operator<<(ostream &out, Sparse &s)
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
  return out;
};

Sparse Sparse::operator+(Sparse &s)
{
  int i = 0, j = 0, k = 0;

  // struct Sparse *s3 = new Sparse(s1.m, s1.n, s1.num + s2.num);
  Sparse *s3 = new Sparse(m, n, num + s.num);

  while (i < num || k < s.num)
  {
    if (element[i].i < s.element[j].i)
    {
      s3->element[k] = element[i];
      i++;
      k++;
    }
    else if (element[i].i > s.element[j].i)
    {
      s3->element[k] = s.element[j];
      j++;
      k++;
    }
    else
    {
      if (element[i].j < s.element[j].j)
      {
        s3->element[k] = element[i];
        i++;
        k++;
      }
      else if (element[i].j > s.element[j].j)
      {
        s3->element[k] = s.element[j];
        j++;
        k++;
      }
      else
      {
        s3->element[k] = element[i];
        s3->element[k].x = element[i].x + s.element[j].x;
        i++;
        j++;
        k++;
      }
    }
  }

  s3->num = k;
  return *s3;
}

int main()
{
  Sparse s1(4, 4, 4);
  Sparse s2(4, 4, 4);
  cin >> s1 >> s2;

  Sparse s3 = s1 + s2;

  cout << s3;

  return 0;
}