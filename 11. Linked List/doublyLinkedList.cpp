#include <iostream>
using namespace std;

struct Node
{
  struct Node *prev;
  int data;
  struct Node *next;
} *first = NULL, *second = NULL;

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

void reverseDoublyLinkedList(struct Node *p)
{

  while (p)
  {
    struct Node *temp = p->next;
    p->next = p->prev;
    p->prev = temp;
    p = p->prev;

    if (p && p->next == NULL)
    {
      first = p;
    }
  }
}

int middleNode(struct Node *p)
{

  struct Node *q = p;

  while (q != NULL && q->next != NULL)
  {
    {
      q = q->next;
      if (q != NULL && q->next != NULL)
      {
        q = q->next;
        p = p->next;
      }
    }
  }

  return p->data;
}

class Stack
{
  struct Node *arr;
  int top;
  int capacity;

public:
  Stack(int size)
  {
    arr = new struct Node[size];
    capacity = size;
    top = -1;
  }
  // Add element to stack
  void push(struct Node element)
  {
    if (top == capacity - 1)
    {
      cout << "Stack Overflow\n";
      return;
    }
    arr[++top] = element;
  }
  // Remove top element
  struct Node pop()
  {
    return arr[top--];
  }
  // Check top element
  struct Node peek()
  {
    return arr[top];
  }
  // Check if stack is empty
  bool isEmpty()
  {
    return top == -1;
  }
};

int findIntersection(struct Node *first, struct Node *second)
{
  Stack s1(Length(first));
  Stack s2(Length(second));

  while (first != NULL)
  {
    s1.push(*first);
    first = first->next;
  }

  while (second != NULL)
  {
    s2.push(*second);
    second = second->next;
  }

  while (s1.peek().data == s2.peek().data)
  {
    s1.pop();
    s2.pop();
  }

  return s1.peek().data;
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

  cout << "Reversed Linked List: " << endl;
  display(first);
  reverseDoublyLinkedList(first);
  display(first);

  cout << "Middle Node: " << middleNode(first) << endl;

  return 0;
}