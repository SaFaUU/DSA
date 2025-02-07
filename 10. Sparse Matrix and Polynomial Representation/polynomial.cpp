#include <iostream>
using namespace std;

struct Element
{
  int coeff;
  int exp;
};

struct Polynomial
{
  int num;
  struct Element *element;
};

void create(struct Polynomial *poly)
{
  cout << "Please Enter the number of Polynomials" << endl;
  cin >> poly->num;
  poly->element = new Element[poly->num];

  for (int i = 0; i < poly->num; i++)
  {
    cout << "Enter the coefficient and exponent" << endl;
    cin >> poly->element[i].coeff >> poly->element[i].exp;
  }
}

void display(struct Polynomial poly)
{
  cout << "The Polynomial is" << endl;
  for (int i = 0; i < poly.num; i++)
  {
    cout << poly.element[i].coeff << "x^" << poly.element[i].exp << " + ";
  }
}

struct Polynomial *add(struct Polynomial p1, struct Polynomial p2)
{
  struct Polynomial *p3 = new Polynomial;
  p3->num = p1.num + p2.num;
  p3->element = new Element[p3->num];

  int i = 0, j = 0, k = 0;
  while (i < p1.num && j < p2.num)
  {
    if (p1.element[i].exp > p2.element[j].exp)
    {
      p3->element[k++] = p1.element[i++];
    }
    else if (p1.element[i].exp < p2.element[j].exp)
    {
      p3->element[k++] = p2.element[j++];
    }
    else
    {
      p3->element[k].coeff = p1.element[i].coeff + p2.element[j].coeff;
      p3->element[k].exp = p1.element[i].exp;
      i++;
      j++;
      k++;
    }
  }

  for (; i < p1.num; i++)
  {
    p3->element[k++] = p1.element[i];
  }
  for (; j < p2.num; j++)
  {
    p3->element[k++] = p2.element[j];
  }

  p3->num = k;

  return p3;
}

int main()
{
  struct Polynomial p1, p2, *p3;
  create(&p1);
  create(&p2);
  cout << "The first polynomial is" << endl;
  display(p1);
  cout << "The second polynomial is" << endl;
  display(p2);
  p3 = add(p1, p2);
  cout << "The sum of the polynomials is" << endl;
  display(*p3);
  return 0;
}