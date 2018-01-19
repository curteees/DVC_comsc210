// Programmer: Curtis Lee
// Programmer's ID: 1489029
// Test File Dynamic Array Template

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "MyDynamicArray.h"
#include "MyDynamicArray.h" //ifndef test

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;

  MyDynamicArray<double> a(10);  //testing for double

  // testing capacity
  cout << "\ntesting capacity\n";
  cout << " expect 10\n";
  cout << " actual " << a.capacity() << endl;
  assert(10 == a.capacity());

  // operator[] setter and getter test
  cout << "\noperator[] setter test\n";
  cout << " expect 0\n";
  cout << " actual " << a[8] << endl;
  a[8] = 88.8;
  cout << " expect 88.8\n";
  cout << " actual " << a[8] << endl;
  assert(88.8 == a[8]);

  //initial size test
  MyDynamicArray<int> x;
  cout << "\nInitial Size Test\n";
  cout << " expect 2\n";
  cout << " actual " << x.capacity() << endl;
  assert(x.capacity() == 2);

  // const object test
  cout << "\nconst object test\n";
  const MyDynamicArray<double> c = a;
  cout << " expect 88.8\n";
  cout << " actual " << c[8] << endl;
  assert(88.8 == c[8]);

  MyDynamicArray<string> s(10);  //testing for string
  cout << "\nTesting for string\n";

  // testing capacity
  cout << "\ntesting capacity\n";
  cout << " expect 10\n";
  cout << " actual " << s.capacity() << endl;
  assert(10 == s.capacity());

  // operator[] setter and getter test
  cout << "\noperator[] setter test\n";
  cout << " expect \n";
  cout << " actual " << s[8] << endl;
  s[8] = "88.8";
  cout << " expect 88.8\n";
  cout << " actual " << s[8] << endl;
  assert("88.8" == s[8]);

  // const object test
  cout << "\nconst object test\n";
  const MyDynamicArray<string> b = s;
  cout << " expect 88.8\n";
  cout << " actual " << b[8] << endl;
  assert("88.8" == b[8]);

  // object copy test
  cout << "\nObject copy test\n";
  MyDynamicArray<double>d = a;
  assert(a.capacity() == d.capacity());
  for (int i = 0; i < a.capacity(); i++)
    assert(a[i] == d[i]);
  cout << "Copied\n";

  // object assignment test
  cout << "\nObject assignment test\n";
  MyDynamicArray<double> e;
  e = a;
  assert(a.capacity( ) == e.capacity( ));
  for (int i = 0; i < a.capacity( ); i++)
    assert(a[i] == e[i]);
  cout << "Passed\n";

  return 0;
}
