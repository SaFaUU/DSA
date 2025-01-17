#include <iostream>
using namespace std;
int main()
{
  int word = 1, vowel = 0, consonant = 0;
  char A[] = "Welcome to C++ World";

  for (int i = 0; A[i] != '\0'; i++)
  {
    if (A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u' || A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U')
    {
      vowel++;
    }
    else if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z'))
    {
      consonant++;
    }
    else if (A[i] == ' ')
    {
      word++;
    }
  }
  cout << "Word : " << word << " Vowel : " << vowel << " Consonant : " << consonant << endl;
  return 0;
}