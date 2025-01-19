#include <iostream>
using namespace std;
int main()
{
  char string[] = "finding";
  int H = 0, X = 0;
  for (int i = 0; string[i] != '\0'; i++)
  {
    X = 1;
    X = X << (string[i] - 'a');
    if (H & X)
    {
      cout << string[i] << " is repeated" << endl;
    }
    else
    {
      H = H | X;
    }
  }
  return 0;
}