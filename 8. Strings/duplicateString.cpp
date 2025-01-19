#include <iostream>
#include <cstring>
using namespace std;

void findDuplicates(char string[])
{
  int array[26];
  int i;

  for (i = 0; i < 26; i++)
  {
    array[i] = 0;
  }

  for (i = 0; i < strlen(string); i++)
  {
    array[string[i] - 'a'] += 1;
  }

  for (int j = 0; j < 26; j++)
  {
    if (array[j] > 1)
    {
      cout << char(j + 'a') << " is repeated " << array[j] << " times" << endl;
    }
  }
}
int main()
{
  char string[] = "finding";

  findDuplicates(string);

  return 0;
}