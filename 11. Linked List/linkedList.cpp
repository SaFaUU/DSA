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

void create2(int A[], int n)
{
  Node *t, *last;
  second = new Node;
  second->data = A[0];
  second->next = NULL;
  last = second;

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

void removeDuplicates(struct Node *p)
{
  struct Node *q = p->next;

  while (q != NULL)
  {
    if (p->data != q->data)
    {
      p = q;
      q = q->next;
    }
    else
    {
      p->next = q->next;
      delete q;
      q = p->next;
    }
  }
}

void reverseWithArray(struct Node *p)
{
  int linkListCount = count(p);

  int A[linkListCount];
  int i = 0;
  while (p != NULL)
  {
    A[i++] = p->data;
    p = p->next;
  }

  p = first;
  linkListCount = count(p);
  while (p != NULL)
  {
    p->data = A[--linkListCount];
    p = p->next;
  }
}

void reverseWithLink(struct Node *p)
{
  struct Node *q, *r;

  q = NULL;
  r = NULL;

  while (p != NULL)
  {
    r = q;
    q = p;
    p = p->next;

    q->next = r;
  }

  first = q;
}

void reverseWithRecursion(struct Node *q, struct Node *p)
{
  if (p != NULL)
  {
    reverseWithRecursion(p, p->next);
    p->next = q;
  }
  else
  {
    first = q;
  }
}

void concetation(struct Node *p, struct Node *q)
{
  while (p->next != NULL)
  {
    p = p->next;
  }

  p->next = q;
}

void MergeList(struct Node *p, struct Node *q)
{
  struct Node *last = NULL;

  if (p->data > q->data)
  {
    third = last = q;
    q = q->next;
    last->next = NULL;
  }
  else
  {
    third = last = p;
    p = p->next;
    last->next = NULL;
  }

  while (p != NULL && q != NULL)
  {
    if (p->data < q->data)
    {
      last->next = p;
      last = p;
      p = p->next;
      last->next = NULL;
    }
    else
    {
      last->next = q;
      last = q;
      q = q->next;
      last->next = NULL;
    }
  }
  if (p != NULL)
  {
    last->next = p;
  }
  else
  {
    last->next = q;
  }
}

int main()
{
  int A[] = {3, 5, 5, 7, 10, 25};

  create(A, 6);

  cout << "Removing Duplicates" << endl;
  display(first);
  removeDuplicates(first);
  display(first);
  if (checkIfSorted(first))
  {
    cout << "Sorted" << endl;
  }
  else
  {
    cout << "Not Sorted" << endl;
  }

  cout << endl;
  // int B[] = {97, 98, 99};
  // create2(B, 3);

  // cout << "concetation of the Linked Lists " << endl;
  // concetation(first, second);
  // display(first);
  // Rdisplay(first);

  cout << "Merge of the Linked Lists " << endl;
  int B[] = {4, 6, 11};
  create2(B, 3);
  MergeList(first, second);
  display(first);

  cout << "Inserting in Linked List" << endl;
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

  cout << endl;
  cout << "Reversing the Linked List " << endl;
  reverseWithArray(first);
  display(first);

  cout << endl;
  cout << "Reversing the Linked List(Reverse with Link) " << endl;
  reverseWithLink(first);
  display(first);

  cout << endl;
  cout << "Reversing the Linked List(Reverse with Recursion) " << endl;
  reverseWithRecursion(NULL, first);
  display(first);

  return 0;
}