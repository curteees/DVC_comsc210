// Programmer: Curtis Lee
// Programmer's ID: 1489029
// Array Class

#include <iostream>
using namespace std;

#include <cassert>

class Array
{
  int data[100];
  int dummy;

  public:
  Array();
  int& operator[](int); // setter
  int operator[](int)const; // getter

  int capacity()const {return 100;}
};

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;

  Array a;

  // testing capacity
  cout << "\ntesting capacity\n";
  cout << " expect 100\n";
  cout << " actual " << a.capacity() << endl;
  assert(100 == a.capacity());

  // operator[] setter and getter test
  cout << "\noperator[] setter test\n";
  cout << " expect 0\n";
  cout << " actual " << a[8] << endl;
  a[8] = 888;
  cout << " expect 888\n";
  cout << " actual " << a[8] << endl;
  assert(888 == a[8]);

  // const object test
  cout << "\nconst object test\n";
  const Array c = a;
  cout << c[8] << endl;
  assert(888 == c[8]);

  return 0;
}

Array::Array()
{
  for(int i = 0; i < 100; i++)
    data[i] = 0;
}

int& Array::operator[](int index)
{
  if(index >= 0 && index < 100)
    return data[index];
  return dummy;
}

int Array::operator[](int index) const
{
  if(index >= 0 && index < 100)
    return data[index];
  return dummy;
}
