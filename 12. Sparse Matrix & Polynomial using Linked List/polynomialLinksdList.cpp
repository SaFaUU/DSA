#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
  int coeff;
  int pow;
  Node *next;
};

int evaluate(int x, struct Node *p)
{
  int sum = 0;
  while (p != NULL)
  {
    sum += p->coeff * pow(x, p->pow);
    p = p->next;
  }
  return sum;
}

// Adding Two Polynomials

int main()
{
  struct Node *head = new Node();
  head->coeff = 2;
  head->pow = 3;
  head->next = new Node();
  head->next->coeff = 3;
  head->next->pow = 2;
  head->next->next = NULL;

  cout << "The result is " << evaluate(2, head) << endl;
  return 0;
}