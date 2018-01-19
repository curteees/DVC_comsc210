// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 14890129\n";
  cout << "File: " << __FILE__ << endl;
    
  string buf;
  int ans;
  cout << "What is 2+2?\n";
  cin >> buf;
  ans = atoi(buf.c_str( ));
  if(ans == 4)
    cout << "correct!";
  else
    cout << "incorrect";
  return 0;
}
