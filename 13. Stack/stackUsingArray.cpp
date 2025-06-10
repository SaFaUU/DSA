#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
  int top;
  int size;
  T *arr;

  Stack(int size);
  void push(int element);
  T pop();
  void display();
  T peek(int index);
  bool isEmpty();
  bool isFull();
};

template <class T>
Stack<T>::Stack(int size)
{
  this->size = size;
  top = -1;
  arr = new T[size];
};

template <class T>
void Stack<T>::push(int element)
{
  if (top == size - 1)
  {
    cout << "Stack Overflow" << endl;
  }
  else
  {
    top++;
    arr[top] = element;
  }
}

template <class T>
T Stack<T>::pop()
{
  T x = -1;
  if (top == -1)
  {
    cout << "Stack Underflow" << endl;
    return x;
  }
  else
  {
    x = arr[top];
    top--;
    return x;
  }
}

template <class T>
void Stack<T>::display()
{
  for (int i = top; i >= 0; i--)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

template <class T>
T Stack<T>::peek(int index)
{
  T x = -1;
  if (top - index + 1 < 0)
  {
    cout << "Invalid Index" << endl;
    return x;
  }
  else
  {
    return arr[top - index + 1];
  }
}

template <class T>
bool Stack<T>::isEmpty()
{
  if (top == -1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <class T>
bool Stack<T>::isFull()
{
  if (top == size - 1)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  Stack<int> s(5);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  cout << "The Full Stack is: " << endl;
  s.display();

  printf("The Top Element is: %d\n", s.peek(1));

  cout << "The Popped Element is: " << s.pop() << endl;

  cout << "The Full Stack is: " << endl;
  s.display();

  cout << "Empty Stack: " << s.isEmpty() << endl;
  cout << "Full Stack: " << s.isFull() << endl;

  return 0;
}