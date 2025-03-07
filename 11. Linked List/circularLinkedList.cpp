#include <iostream>
using namespace std;

struct Node
{
  int data;
  struct Node *next;
} *linkedListA;

void create(struct Node *first, int A[], int n)
{
  struct Node *last, *t;

  first = new Node;
  first->data = A[0];
  last = first;
  last->next = first;

  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->data = A[i];
    t->next = first;
    last->next = t;
    last = t;
    last->next = first;
  }

  linkedListA = first;
};

void display(struct Node *p)
{
  do
  {
    cout << p->data << " ";
    p = p->next;
  } while (p != linkedListA);
  cout << endl;
}

void RDisplay(struct Node *p)
{
  static int flag = 0;
  if (p != linkedListA || flag == 0)
  {
    flag = 1;
    cout << p->data << " ";
    RDisplay(p->next);
  }
}

void insert(struct Node *p, int pos, int x)
{
  struct Node *t = new Node;

  if (pos == 0)
  {
    t->data = x;
    t->next = p->next;
    linkedListA = t;
  }
  else
  {
    for (int i = 1; i < pos - 1; i++)
    {
      p = p->next;
    }
    t->data = x;
    t->next = p->next;
    p->next = t;
  }
}

void deleteNode(struct Node *p, int pos)
{
  struct Node *q;
  if (pos == 0)
  {
    struct Node *first = p;
    do
    {
      p = p->next;
    } while ((p->next) != first);

    linkedListA = linkedListA->next;
    p->next = first->next;
    delete first;
  }
  else
  {
    for (int i = 0; i < pos - 1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    delete p;
  }
}
int main()
{
  int A[] = {1, 2, 3, 4, 5};
  create(linkedListA, A, 5);
  display(linkedListA);
  insert(linkedListA, 3, 6);
  RDisplay(linkedListA);
  cout << endl;
  deleteNode(linkedListA, 0);
  display(linkedListA);
  return 0;
}