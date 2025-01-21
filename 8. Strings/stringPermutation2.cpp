#include <iostream>
using namespace std;

void Swap(char *a, char *b)
{
  char temp = *a;
  *a = *b;
  *b = temp;
}

void permutation(char name[], int l, int h)
{
  if (l == h)
  {
    cout << name << endl;
  }
  else
  {
    for (int i = l; i <= h; i++)
    {
      Swap(&name[l], &name[i]);
      permutation(name, l + 1, h);
      Swap(&name[l], &name[i]);
    }
  }
}

int main()
{
  char name[] = "ABC";

  int i = 0;

  permutation(name, 0, 2);

  return 0;
}