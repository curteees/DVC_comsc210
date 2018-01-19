// Programmer: Curtis Lee
// Programmer's ID: 1489029
// Stack Test File

#include <iostream>
using namespace std;

#include <cassert>

#include "MyStack.h"
#include "MyStack.h"  //ifndef test

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;

  MyStack<int> a;

  cout << "Testing constructor, size, and pop\n";
  for(int i = 0; i < a.size(); i++)
  {
    assert(a.peek() == 0);
    a.pop();
  }
  cout << "Passed\n";

  cout << "\nTesting push, pop, peek\n";
  a.push(1);
  a.push(2);
  cout << "EXPECTED: 2 for 2nd push\n";
  int add2 = a.peek();
  a.pop();
  cout << "ACTUAL: " << add2 << endl;
  assert(2 == add2);
  cout << "EXPECTED: 1 for 1st push\n";
  int add1 = a.peek();
  a.pop();
  cout << "ACTUAL: " << add1 << endl;
  assert(1 == add1);

  cout << "\nTesting empty\n";
  cout << "EXPECTED: 1 \n";
  cout << "ACTUAL: " << a.empty() << endl;

  a.push(11);
  a.push(22);
  cout << "\nTesting clear\n";
  a.clear();
  cout << "EXPECTED: 0\n";
  cout << "ACTUAL: " << a.size() << endl;

  cout << "\nConst object test" << endl;
  const MyStack<int> b;
  assert(b.size() == 0);
  assert(b.empty());
  cout << "Passed\n";

  cout << "\nObject copy test\n";
  a.push(111);
  a.push(222);
  MyStack<int> c(a); // making a copy
  assert(a.size() == c.size());
  for(int i = 0; i < a.size(); i++)
  {
    assert(a.peek() == c.peek());
    a.pop();
    c.pop();
  }
  cout << "Passed\n";

  cout << "\nObject assignment test\n";
  a.push(1111);
  a.push(2222);
  MyStack<int> d;
  d = a;
  assert(a.size() == d.size());
  for(int i = 0; i < 10; i++)
  {
    assert(a.size() == d.size());
    a.pop();
    d.pop();
  }
  cout << "Passed\n";

  return 0;
}
