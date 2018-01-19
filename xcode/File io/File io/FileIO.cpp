// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 14890129\n";
  cout << "File: " << __FILE__ << endl;
    
  ofstream fout;
  fout.open("data.xls");
  fout << "Name\tAge\tGPA\n"; // column headings
  fout << "Bob" << '\t' << "21" << '\t' << "2.5" << '\n';
  fout << "Rob" << '\t' << "20" << '\t' << "3.0" << '\n';
  fout.close();
  return 0;
}
