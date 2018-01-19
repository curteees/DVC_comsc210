// Programmer: Curtis Lee
// Programmer's ID: 1489029
// Test Static Array Template

#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "MyStaticArray.h"
#include "MyStaticArray.h"  //ifndef test

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;

  MyStaticArray<double, 10> a;  //testing for double

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

  // const object test
  cout << "\nconst object test\n";
  const MyStaticArray<double, 10> c = a;
  cout << " expect 88.8\n";
  cout << " actual " << c[8] << endl;
  assert(88.8 == c[8]);

  MyStaticArray<string, 10> s;  //testing for string

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
  const MyStaticArray<string, 10> b = s;
  cout << " expect 88.8\n";
  cout << " actual " << b[8] << endl;
  assert("88.8" == b[8]);

  return 0;
}
