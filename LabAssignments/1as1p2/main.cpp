// Programmer: Curtis Lee
// Programmer's ID: 1489029
// Array Application

#include <iostream>
#include <string>
using namespace std;

#include <cassert>
#include <cstdlib>

class Array
{
  int data[100];
  int dummy;

  public:
  Array();
  int& operator[](int); // setter
  int operator[](int) const; // getter

  int capacity() const {return 100;}
};

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;

  Array a;
  Array b; //uses same index, but inputs 1 for the value to indicate its in use
  string buffer = "";
  int index, value, counter = 0;

  cout << "Enter a pair of whole numbers in the same line\n";
  cout << "The first number is Index and the second number is value.\n";

  while(true)
  {
    cout << "\nInput an index and a value [Q to quit]: ";
    cin  >> buffer;
    index = atoi(buffer.c_str());
    if(buffer == "Q" || buffer == "q") break;
    cin  >> buffer;
    value = atoi(buffer.c_str());
    if(buffer == "Q" || buffer == "q") break;

    a[index] = value;
    b[index] = 1;
  }

  for(int i=0; i<b.capacity(); i++)
  {
    counter += b[i];
  }
  cout << "\nYou stored this many values: " << counter << endl;

  cout << "\nThe index-value pairs are:\n";
  for(int i=0; i<a.capacity(); i++)
  {
    if(b[i] == 1)
      cout << i << " => " << a[i] << endl;
  }

  while(true)
  {
    cout << "\nInput an index for me to look up [Q to quit]: ";
    cin  >> buffer;
    index = atoi(buffer.c_str());
    if(buffer == "Q" || buffer == "q") break;
    if(index >= 0 && index < 100 && b[index] == 1)
      cout << "Found it -- the value stored at " << index << " is " << a[index] << endl;
    else
      cout << "Sorry, I didn't find it\n";
  }
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
