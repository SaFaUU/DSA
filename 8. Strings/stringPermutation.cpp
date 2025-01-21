#include <iostream>
using namespace std;

char res[3];
int A[3] = {0};
void permutation(char name[], int n)
{
  if (name[n] == '\0')
  {
    cout << res << endl;
    return;
  }
  for (int i = 0; name[i] != '\0'; i++)
  {
    if (A[i] == 0)
    {
      res[n] = name[i];
      A[i] = 1;
      permutation(name, n + 1);
      A[i] = 0;
    }
  }
}

int main()
{
  char name[] = "ABC";

  int n = 0;

  permutation(name, 0);

  return 0;
}