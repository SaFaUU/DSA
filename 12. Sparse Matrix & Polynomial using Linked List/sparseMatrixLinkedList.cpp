#include <iostream>
using namespace std;

struct Node
{
  int col;
  int value;
  Node *next;
};

void display(struct Node *A[5])
{

  for (int i = 0; i < 5; i++)
  {
    Node *temp = A[i];
    for (int j = 0; j < 6; j++)
    {
      if (temp && temp->col == j)
      {
        cout << temp->value << " ";
        temp = temp->next;
      }
      else
      {
        cout << "0 ";
      }
    }
    cout << endl;
  }
}

int main()
{
  Node *A[5];

  A[0] = new Node();
  A[1] = new Node();
  A[2] = new Node();
  A[3] = new Node();
  A[4] = new Node();

  A[0]->col = 4;
  A[0]->value = 8;

  A[1]->col = 3;
  A[1]->value = 7;

  A[2]->col = 0;
  A[2]->value = 5;
  A[2]->next = new Node();
  A[2]->next->col = 4;
  A[2]->next->value = 9;

  A[3]->col = 5;
  A[3]->value = 3;

  A[4]->col = 0;
  A[4]->value = 6;
  A[4]->next = new Node();
  A[4]->next->col = 3;
  A[4]->next->value = 4;

  display(A);

  return 0;
}