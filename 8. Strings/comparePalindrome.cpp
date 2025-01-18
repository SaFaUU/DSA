#include <iostream>
#include <cstring>
using namespace std;

void compareString(char a[], char b[])
{
  for (int i = 0; i < strlen(a); i++)
  {
    if (a[i] == b[i])
    {
      continue;
    }
    else
    {
      cout << "Do not Match" << endl;
      return;
    }
  }
  cout << "The Strings match" << endl;
}

void palindromeCheck(char a[], char b[])
{
  int i = 0, j = strlen(b) - 1;
  for (i = 0; i < j; i++, j--)
  {
    if (a[i] == b[j])
    {
      continue;
    }
    else
    {
      cout << "Not a Palindrome" << endl;
      return;
    }
  }
  cout << "Is a Palindrome" << endl;
}

int main()
{
  char a[] = "abcde";
  char b[] = "edcba";

  char c[] = "madam";
  char d[] = "madam";

  compareString(a, b);
  palindromeCheck(c, d);
  return 0;
}