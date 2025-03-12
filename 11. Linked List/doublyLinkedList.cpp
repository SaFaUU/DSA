#include <iostream>
using namespace std;

struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
  struct Node *t, *last;

  first = new Node;
  first->prev = NULL;
  first->data = A[0];
  first->next = NULL;
  last = first;

  for (int i = 1; i < n; i++)
  {
    t = new Node;
    t->prev = last;
    t->data = A[i];
    t->next = NULL;
    last->next = t;
    last = t;
  }
}

void display(struct Node *p)
{
  while (p != NULL)
  {
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

int Length(struct Node *p)
{
  int len = 0;
  while (p != NULL)
  {
    len++;
    p = p->next;
  }
  return len;
}

void insert(struct Node *p, int index, int x)
{
  struct Node *t;

  if (index < 0 || index > Length(first))
  {
    return;
  }

  t = new Node;
  if (index == 0)
  {
    t->prev = NULL;
    t->data = x;
    t->next = first;
    first->prev = t;
    first = t;
  }
  else
  {
    for (int i = 1; i < index - 1; i++)
    {
      p = p->next;
    }
    t->prev = p;
    t->data = x;
    t->next = p->next;
    p->next->prev = t;
    p->next = t;
  }
}

void deleteNode(struct Node *p, int index)
{
  if (index == 0)
  {
    first = first->next;
    first->prev = NULL;
    delete p;
  }
  else
  {
    for (int i = 1; i <= index; i++)
    {
      p = p->next;
    }
    cout << p->data << endl;
    if (p->next == NULL)
    {
      p->prev->next = NULL;
    }
    else
    {

      if (p->prev)
      {
        p->prev->next = p->next;
        p->next->prev = p->prev;
      }
    }
    delete p;
  }
}

int main()
{
  int A[] = {10, 20, 30, 40, 50};
  create(A, 5);
  display(first);
  cout << "Length: " << Length(first) << endl;

  insert(first, 3, 100);
  insert(first, 0, 5);
  display(first);

  cout << "After Deletion: " << endl;
  deleteNode(first, 2);
  display(first);
  return 0;
}