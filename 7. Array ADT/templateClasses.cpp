#include <iostream>

using namespace std;

template <class T>
class Array
{
private:
  T *A;
  int size;
  int length;

public:
  Array()
  {
    size = 10;
    A = new T[10];
    length = 0;
  }
  Array(int sz)
  {
    size = sz;
    length = 0;
    A = new T[size];
  }
  ~Array()
  {
    delete[] A;
  }
  void Display();
  void Insert(int index, T x);
  T Delete(int index);
};

template <class T>
void Array<T>::Insert(int index, T x)
{
  if (index >= 0 && index <= length)
  {
    for (int i = length - 1; i >= index; i--)
      A[i + 1] = A[i];
    A[index] = x;
    length++;
  }
}

template <class T>
T Array<T>::Delete(int index)
{
  T x = A[index];
  if (index >= 0 && index < length)
  {
    for (int i = index; i < length; i++)
      A[i] = A[i + 1];
    length--;
  }
  return x;
}

template <class T>
void Array<T>::Display()
{
  for (int i = 0; i < length; i++)
    cout << A[i] << " ";
  cout << endl;
}

int main()
{
  Array<int> arr(5);
  arr.Insert(0, 10);
  arr.Insert(1, 20);
  arr.Insert(2, 30);
  arr.Display();
  arr.Delete(1);
  arr.Display();
  return 0;
}
