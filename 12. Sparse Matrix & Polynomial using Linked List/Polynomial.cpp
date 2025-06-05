#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
  int coeff;
  int pow;
  Node *next;
};

void create(struct Node *&p, int n)
{
  struct Node *last = NULL;
  printf("Enter the coefficients and powers of the polynomial\n");
  for (int i = 0; i < n; i++)
  {
    struct Node *t = new Node();
    cin >> t->coeff >> t->pow;
    t->next = NULL;
    if (p == NULL)
    {
      p = t;
      last = t;
    }
    else
    {
      last->next = t;
      last = t;
    }
  }
}
void display(struct Node *p)
{
  while (p != NULL)
  {
    cout << p->coeff << "x^" << p->pow << " + ";
    p = p->next;
  }
  cout << endl;
};

void evaluate(struct Node *p, int x)
{
  int sum = 0;
  while (p != NULL)
  {
    sum += p->coeff * pow(x, p->pow);
    p = p->next;
  }
  cout << "The result is " << sum << endl;
};

int main()
{
  struct Node *head = NULL;
  create(head, 3);
  display(head);
  evaluate(head, 2);
  return 0;
}