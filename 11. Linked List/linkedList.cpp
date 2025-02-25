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

Node *search(struct Node *p, int key)
{
  while (p != NULL)
  {
    if (p->data == key)
      return p;
    p = p->next;
  }
  return NULL;
}

void insert(struct Node *p, int pos, int x)
{
  Node *t = new Node;

  if (pos == 0)
  {
    t->data = x;
    t->next = first;
    first = t;
  }
  else if (pos > 0 && pos <= count(first))
  {
    for (int i = 0; i < pos - 2; i++)
    {
      p = p->next;
    }
    t->data = x;
    t->next = p->next;
    p->next = t;
  }
}

void insertInSortedList(struct Node *p, int x)
{
  struct Node *t = new Node;
  struct Node *q = NULL;

  while (p && p->data < x)
  {
    q = p;
    p = p->next;
  }

  t->data = x;
  t->next = p;
  q->next = t;
}

int deleteFromLinkedList(struct Node *p, int index)
{
  struct Node *q = NULL;
  int x = -1;

  if (index < 1 && index > count(p))
  {
    return -1;
  }

  if (index == 1)
  {
    x = first->data;
    q = first;
    first = first->next;
    delete q;
    return x;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
    {
      q = p;
      p = p->next;
    }

    x = p->data;
    q->next = p->next;
    delete p;
    return x;
  }
};

int checkIfSorted(struct Node *p)
{
  int x = -2147483648;

  while (p != NULL)
  {
    if (p->data < x)
    {
      return 0;
    }
    x = p->data;
    p = p->next;
  }
  return 1;
}

int main()
{
  int A[] = {3, 5, 7, 10, 25};

  cout << endl;

  if (checkIfSorted(first))
  {
    cout << "Sorted" << endl;
  }
  else
  {
    cout << "Not Sorted" << endl;
  }

  create(A, 5);
  display(first);
  cout << endl;
  Rdisplay(first);

  cout << endl;
  insertInSortedList(first, 15);
  display(first);
  cout << endl;

  deleteFromLinkedList(first, 5);
  display(first);

  cout << endl;
  cout << "The count is " << count(first) << endl;
  cout << "The count from Recursive call is " << countRecursive(first) << endl;
  cout << "The max is " << max(first) << endl;
  Node *res = search(first, 25);
  if (res == NULL)
    cout << "Element 25 " << "Not found" << endl;
  else
    cout << "Element 25 " << "Found" << endl;

  insert(first, 3, 15);
  insert(first, 0, 10);
  display(first);

  return 0;
}