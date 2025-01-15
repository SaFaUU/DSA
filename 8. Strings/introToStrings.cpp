#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
  char tmp = 'a';
  cout << tmp << endl;
  char tmp2[] = {'a', 'b', 'c', '\0'};
  cout << tmp2 << endl;
  char tmp3[10] = {'a', 'b', 'c', '\0'};
  cout << tmp3 << endl;
  char *name = "John";
  cout << name << endl;

  char name2[100];
  cout << "Please Enter your name2" << endl;
  fgets(name2, 100, stdin);
  cout << name2 << endl;
  return 0;
}