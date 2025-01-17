#include <iostream>
using namespace std;

int validateString(char *s)
{
  for (int i = 0; s[i] != '\0'; i++)
  {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
      continue;
    else
    {
      return 0;
    }
  }
  return 1;
};
int main()
{
  char *s = "Ani?123";

  if (validateString(s) == 1)
  {
    cout << "Valid String" << endl;
  }
  else
  {
    cout << "Invalid String" << endl;
  }
  return 0;
}