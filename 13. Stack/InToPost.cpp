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
    if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
    {
      s.push(exp[i]);
    }
    else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
    {
      if (s.isEmpty())
      {
        return false;
      }
      if (exp[i] == ')' && s.peek() == '(')
        s.pop();
      else if (exp[i] == '}' && s.peek() == '{')
        s.pop();
      else if (exp[i] == ']' && s.peek() == '[')
        s.pop();
    }
  }

  return s.isEmpty();
};

int precendence(char ch)
{
  if (ch == '^')
    return 3;
  else if (ch == '*' || ch == '/')
    return 2;
  else if (ch == '+' || ch == '-')
    return 1;
  else
    return -1;
};

bool isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
};

char *InToPost(char *infix)
{
  int i = 0, j = 0;

  Stack<char> s;
  char *postfix;

  postfix = new char[strlen(infix) + 1];

  while (infix[i] != '\0')
  {
    if (isOperator(infix[i]))
    {
      if (precendence(infix[i]) < precendence(s.peek()) || !s.isEmpty())
      {
        postfix[j++] = s.pop();
      }
      else
      {
        s.push(infix[i++]);
      }
    }
    else
    {
      postfix[j++] = infix[i++];
    }
  }

  while (!s.isEmpty())
  {
    postfix[j++] = s.pop();
  }
  return postfix;
}

int main()
{
  char *infix = "a+b*c-d/e";
  char *postfix = InToPost(infix);

  cout << "Infix Expression: " << infix << endl;
  cout << "Postfix Expression: " << postfix << endl;

  return 0;
}
