#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

void print(ULListStr &list){

  for (size_t i = 0; i < list.size(); i++)
  {
    cout << list.get(i) << " ";
  }

  cout << endl;
}

int main(int argc, char* argv[])
{

  ULListStr test;

  //empty
  print(test);
  
  //push_back
  cout << "test push_back: " << endl;
  test.push_back("1");
  test.push_back("2");
  test.push_back("3");
  test.push_back("4");
  print(test);

  //push_front
  cout << "test push_front: " << endl;
  test.push_front("0");
  print(test);

  //pop_back
  cout << "test pop_back: " << endl;
  test.pop_back();
  print(test);

  //pop_front
  cout << "test pop_front: " << endl;
  test.pop_front();
  print(test);

  //back
  cout << "back: " << test.back() << endl;

  //first
  cout << "front: " << test.front() << endl;

  //testing getValAtLoc through get
  cout << "get loc 1: " << test.get(1) << endl;

}
