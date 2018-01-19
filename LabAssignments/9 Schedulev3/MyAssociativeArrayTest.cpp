// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <iostream>
#include <string>
#include <queue>
using namespace std;

#include <cassert>

#include "MyAssociativeArray.h"
#include "MyAssociativeArray.h" // ifndef test

struct testType
{
  double num;
  testType(int a):num(a) {}
};

struct testKey
{
  string tKey;
  testKey(string s):tKey(s) {}
};

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  MyAssociativeArray<string, double> a;
  
  //AssociativeArray::AssociativeArray & size()
  cout << "MyAssociativeArray test\n"
  << "----------------------------\n"
  << "Testing MyAssociativeArray::MyAssociativeArray & size()\n";
  assert(a.size() == 0);
  cout << "Pass!\n\n";
  
  //AssociativeArray::operator [ ] setter
  cout << "Testing MyAssociativeArray::operator [ ] setter \n";
  a["A"];
  assert(a["A"] == double());
  assert(a.size() == 1);
  cout << "Pass!\n\n";
  a["A"] = 1.1;
  
  //AssociativeArray::copy constructor
  cout << "Tesing copy constructor\n";
  a["B"] = 2.2;
  MyAssociativeArray<string , double> b = a;
  assert(b.size() == a.size());
  assert(b["A"] == 1.1);
  assert(b["B"] == 2.2);
  assert(b.size() == 2);
  cout << "Pass!\n\n";
  
  //AssociativeArray::operator [ ] setter
  cout << "Testing operator [ ] getter\n";
  const MyAssociativeArray<string , double> c = a;
  assert(c["A"] == 1.1);
  assert(c["B"] == 2.2);
  cout << "Pass!\n\n";
  
  //assignment operator
  cout << "Testing assignment operator\n";
  MyAssociativeArray<string , double> d;
  d = a;
  assert(d.size() == a.size());
  assert(d["A"] == 1.1);
  assert(d["B"] == 2.2);
  cout << "Pass!\n\n";
  
  //AssociativeArray::containsKey
  cout << "Testing AssociativeArray::containsKey\n";
  assert(a.containsKey("A"));
  assert(!a.containsKey("D"));
  cout << "Pass!\n\n";
  
  //AssociativeArray::deleteKey
  cout << "Testing AssociativeArray::deleteKey\n";
  a.deleteKey("A");
  //a.deleteKey("s");
  assert(!a.containsKey("A"));
  cout << "Pass!\n\n";
  
  //AssociativeArray::isKey
  cout << "Testing AssociativeArray::isKey\n";
  queue<string> keys = d.keys();
  assert(keys.front() == "B");
  keys.pop();
  assert(keys.front() == "A");
  cout << "Pass!\n\n";
  
  //2D test
  cout << "Testing 2D array\n";
  MyAssociativeArray<string, MyAssociativeArray<string , bool> > e;
  e["A"]["B"] = true;
  e["A"]["C"] = false;
  assert(e["A"]["B"]);
  assert(!e["A"]["C"]);
  cout << "Pass!\n\n";
  
  //clear
  cout << "Testing AssociativeArray::clear\n";
  e.clear();
  assert(e.size() == 0);
  cout << "Pass!\n\n";
  
  return 0;
}
