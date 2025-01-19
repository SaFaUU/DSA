#include <iostream>
using namespace std;
int main()
{
  char A[] = "decimal";
  char B[] = "medical";

  int count[26] = {0};

  for (int i = 0; A[i] != '\0'; i++)
  {
    count[A[i] - 'a'] += 1;
  }

  for (int i = 0; B[i] != '\0'; i++)
  {
    count[B[i] - 'a'] -= 1;
  }

  for (int i = 0; i < 26; i++)
  {
    if (count[i] != 0)
    {
      cout << "Not Anagram" << endl;
      return 0;
    }
  }

  cout << "Anagram" << endl;
  return 0;
}