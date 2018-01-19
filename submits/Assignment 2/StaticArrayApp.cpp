// Programmer: Curtis Lee
// Programmer's ID: 1489029
// Static Array Application

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>

#include "MyStaticArray.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;

  MyStaticArray<double, 100> a;  //data values
  MyStaticArray<bool, 100> b;    //checking which indexes have been used

  string buffer = "";
  int index, counter = 0;
  double value = 0.0;

  cout << "Enter a pair of whole numbers in the same line\n";
  cout << "The first number is Index and the second number is value.\n";

  while(true)
  {
    cout << "\nInput an index and a value [Q to quit]: ";
    cin  >> buffer;
    index = atoi(buffer.c_str());
    if(buffer == "Q" || buffer == "q") break;
    cin  >> buffer;
    value = atof(buffer.c_str());
    if(buffer == "Q" || buffer == "q") break;

    a[index] = value;
    b[index] = true;
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
