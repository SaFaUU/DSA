#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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
  cout << endl;
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

int checkForLoop(struct Node *p)
{
  struct Node *slow = p, *fast = p;

  while (slow && fast && slow != fast)
  {
    slow = slow->next;
    fast = fast->next ? fast->next->next : NULL;

    if (slow == fast)
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  struct Node *t1, *t2;
  int A[] = {3, 5, 7, 10, 25};
  create(A, 6);

  t1 = first->next->next;
  t2 = first->next->next->next->next->next;

  t2->next = t1;

  if (checkForLoop(first))
  {
    cout << "Loop Found" << endl;
  }
  else
  {
    cout << "No Loop" << endl;
  }

  return 0;
}