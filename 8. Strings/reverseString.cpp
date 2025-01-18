#include <iostream>
using namespace std;

void reverseString(char str[])
{
  int i = 0, j;
  for (j = 0; str[j] != '\0'; j++)
  {
  }

  char B[j];
  B[j] = '\0';
  j = j - 1;

  for (i = 0; j >= 0; i++, j--)
  {
    B[i] = str[j];
  }

  cout << B << endl;
}

void reverseString2(char str[])
{
  char t;
  int i, j;
  for (j = 0; str[j] != '\0'; j++)
  {
  };

  j = j - 1;

  for (i = 0; i < j; i++, j--)
  {
    t = str[i];
    str[i] = str[j];
    str[j] = t;
  }

  cout << str << endl;
}

int main()
{
  char str[] = "Welcome to C++ World";

  reverseString(str);

  reverseString2(str);
  return 0;
}