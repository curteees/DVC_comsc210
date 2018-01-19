// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

#include <cstring>

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;
  
  // parse file
  char *token;
  char buf[1000];
  const char *const tab = "\t";
  
  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  // store classes
  map<string, set<string> > data;
  
  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue; // skip blank lines
    
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    const string key = term + "-" + section;
    data[key].insert(course);
  }
  fin.close();
  
  // output
  cout << "Duplicate entries will be displayed, \nNothing will print if there are no duplicates\n\n";
  map<string, set<string> >::iterator it;
  for(it = data.begin(); it != data.end(); it++)
  {
    if(it->second.size() > 1)
    {
      set<string>::iterator it2;
      cout << "Multiple entrance found for - " << it->first << ": \n";
      for(it2 = it->second.begin(); it2 != it->second.end(); it2++)
      {
        cout << *it2 << endl;
      }
    }
  }
  return 0;
}
