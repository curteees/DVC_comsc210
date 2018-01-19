// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <iostream>
using namespace std;

#include<cassert>

#include "MyQueue.h"
#include "MyQueue.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  cout << "-------------------------------------\n";
  cout << "Testing constructor and size with int\n";
  MyQueue<int> a;
  assert(a.size()==0);
  cout << "Passed\n";
  
  cout << "\nTesting push, front, and pop\n";
  a.push(1);
  a.push(2);
  cout << "EXPECTED: 1 for 1st element\n";
  int addA = a.front();
  cout << "ACTUAL: " << addA << endl;
  cout << "EXPECTED: 2 for 2nd element\n";
  int addB = a.back();
  cout << "ACTUAL: " << addB << endl << endl;
  a.pop();
  a.pop();
  cout << "Testing Queue empty()\n";
  cout << "EXPECTED: true (1) \n";
  cout << "ACTUAL: " << a.empty() << endl << endl;
  
  a.push(11);
  a.push(22);
  cout << "Testing clear\n";
  a.clear();
  cout << "EXPECTED size = 0\n";
  cout << "ACTUAL: " << a.size() << endl;
  
  cout << "\nConst object test" << endl;
  const MyQueue<int> c;
  assert(c.size() == 0);
  assert(c.empty());
  cout << "Passed\n";
  
  a.push(111);
  a.push(222);
  cout << "\nObject copy test\n";
  MyQueue<int> d(a); // making a copy
  assert(a.size() == d.size());
  for (int i = 0; i < a.size(); i++)
  {
    assert(a.front() == a.front());
    a.pop();
    d.pop();
  }
  cout << "Passed\n";
  
  a.push(1111);
  a.push(2222);
  // object assignment test
  cout << "\nObject assignment test\n";
  MyQueue<int> e;
  e = a;
  assert(a.size() == e.size());
  for (int i = 0; i < 10; i++)
  {
    assert(a.size() == e.size());
    a.pop();
    e.pop();
  }
  cout << "Passed\n\n";

  
  cout << "----------------------------------------\n";
  cout << "Testing constructor and size with string\n";
  MyQueue<string> s;
  assert(s.size()==0);
  cout << "Passed\n";
  
  cout << "\nTesting push, front, and pop\n";
  s.push("1");
  s.push("2");
  cout << "EXPECTED: 1 for 1st element\n";
  string addA1 = s.front();
  cout << "ACTUAL: " << addA << endl;
  cout << "EXPECTED: 2 for 2nd element\n";
  string addB2 = s.back();
  cout << "ACTUAL: " << addB << endl << endl;
  s.pop();
  s.pop();
  cout << "Testing Queue empty()\n";
  cout << "EXPECTED: true (1) \n";
  cout << "ACTUAL: " << s.empty() << endl << endl;
  
  s.push("11");
  s.push("22");
  cout << "Testing clear\n";
  s.clear();
  cout << "EXPECTED size = 0\n";
  cout << "ACTUAL: " << s.size() << endl;

  cout << "\nConst object test" << endl;
  const MyQueue<string> s2;
  assert(s2.size() == 0);
  assert(s2.empty());
  cout << "Passed\n";
  
  s.push("111");
  s.push("222");
  cout << "\nObject copy test\n";
  MyQueue<string> d2(s); // making a copy
  assert(s.size() == d2.size());
  for (int i = 0; i < s.size(); i++)
  {
    assert(s.front() == s.front());
    s.pop();
    d2.pop();
  }
  cout << "Passed\n";
  
  s.push("1111");
  s.push("2222");
  // object assignment test
  cout << "\nObject assignment test\n";
  MyQueue<string> e2;
  e2 = s;
  assert(s.size() == e2.size());
  for (int i = 0; i < 10; i++)
  {
    assert(s.size() == e2.size());
    s.pop();
    e2.pop();
  }
  cout << "Passed\n";
}
