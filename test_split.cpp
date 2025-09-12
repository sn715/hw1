/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

void print(Node* list) {
  Node* curr = list;

  while (curr != NULL) {
    cout << curr->value << "";
    Node* temp = curr;
    curr = curr->next;

    delete temp;
  }

  cout << endl;
}

int main(int argc, char* argv[])
{
  //case 1: empty
  Node* in = NULL;
  Node* odds = NULL;
  Node* evens = NULL;

  split(in, odds, evens);

  cout << "case 1: empty" << endl;
  print(odds);
  print(evens);

  cout << endl;

  //case 2: mixed
  in = new Node(1, new Node(2, new Node(3, new Node(4, NULL))));
  odds = NULL;
  evens = NULL;

  split(in, odds, evens);

  cout << "case 2: mixed" << endl;
  print(odds);
  print(evens);

  //case 3: odds 
  in = new Node(1, new Node(3, new Node(5, new Node(7, NULL))));
  odds = NULL;
  evens = NULL;

  split(in, odds, evens);

  cout << "case 3: odds" << endl;
  print(odds);
  print(evens);

  //case 4: evens
  in = new Node(2, new Node(4, new Node(6, new Node(8, NULL))));
  odds = NULL;
  evens = NULL;

  split(in, odds, evens);

  cout << "case 4: evens" << endl;
  print(odds);
  print(evens);

  //case 5: duplicates
  in = new Node(1, new Node(1, new Node(2, new Node(2, NULL))));
  odds = NULL;
  evens = NULL;

  split(in, odds, evens);

  cout << "case 5: duplicates" << endl;
  print(odds);
  print(evens);
}
