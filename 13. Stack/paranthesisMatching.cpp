#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class Node
{
public:
  T data;
  Node<T> *next;

  Node(T data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

template <class T>
class Stack
{
private:
  Node<T> *top;

public:
  Stack()
  {
    top = nullptr;
  }

  ~Stack()
  {
    while (!isEmpty())
    {
      pop();
    }
  }

  void push(T data)
  {
    Node<T> *t = new Node<T>(data);
    if (t == nullptr)
    {
      cout << "Stack Overflow" << endl;
      return;
    }
    t->next = top;
    top = t;
  }

  T pop()
  {
    if (isEmpty())
    {
      cout << "Stack Underflow" << endl;
      return T(); // Return default constructed value
    }
    T x = top->data;
    Node<T> *temp = top;
    top = top->next;
    delete temp;
    return x;
  }

  T peek() const
  {
    if (isEmpty())
    {
      cout << "Stack is empty" << endl;
      return T();
    }
    return top->data;
  }

  bool isEmpty() const
  {
    return top == nullptr;
  }

  bool isFull() const
  {
    Node<T> *t = new (nothrow) Node<T>(0);
    if (t == nullptr)
      return true;
    delete t;
    return false;
  }

  void display() const
  {
    Node<T> *p = top;
    while (p != nullptr)
    {
      cout << p->data << " ";
      p = p->next;
    }
    cout << endl;
  }
};

template <class T>
bool areParanthesisMatched(char *exp, Stack<T> s)
{
  for (int i = 0; i < strlen(exp); i++)
  {
    if (exp[i] == '(')
    {
      s.push(exp[i]);
    }
    else if (exp[i] == ')')
    {
      if (s.isEmpty())
      {
        return false;
      }
      s.pop();
    }
  }

  return s.isEmpty();
};

int main()
{
  char *exp = "((a+b)*(c-d))";
  Stack<char> s;

  if (areParanthesisMatched(exp, s))
  {
    cout << "Balanced" << endl;
  }
  else
  {
    cout << "Not Balanced" << endl;
  }

  return 0;
}
