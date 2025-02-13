#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
} *first = NULL;

void create(int A[], int n)
{
  Node *t, *last;
  first = new Node;
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
};

void display(Node *p)
{
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
}

void Rdisplay(struct Node *p)
{
  if (p != NULL)
  {
    cout << p->data << " ";
    Rdisplay(p->next);
  }
}

int count(struct Node *p)
{
  int c = 0;
  while (p != NULL)
  {
    p = p->next;
    c++;
  }
  return c;
}

int countRecursive(struct Node *p)
{
  if (p == NULL)
    return 0;
  return 1 + countRecursive(p->next);
}

int max(struct Node *p)
{
  int max = p->data;
  while (p != NULL)
  {
    if (p->data > max)
    {
      max = p->data;
    }
    p = p->next;
  }
  return max;
}

int main()
{
  int A[] = {3, 5, 7, 10, 25};
  create(A, 5);
  display(first);
  cout << endl;
  Rdisplay(first);
  cout << endl;
  cout << "The count is " << count(first) << endl;
  cout << "The count from Recursive call is " << countRecursive(first) << endl;
  cout << "The max is " << max(first) << endl;

  return 0;
}