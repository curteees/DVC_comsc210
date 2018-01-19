// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

#include <cstring>

int termSeason(const string);

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
  map<string, set<int> > data;
  
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
    if (course.find('-') == string::npos) continue;
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    data[course].insert(termSeason(term));
  }
  fin.close();
  
  string courseIn;
  cout << "Enter a course to see when it was last offered\n";
  cout << "Input must be in this format: COURSE-#\n";
  cout << "Example: COMSC-210\n";
  cout << "Press x to exit\n";
  while(true)
  {
    cout << "\nEnter a course or x to exit: ";
    getline(cin, courseIn);
    if(courseIn == "X" || courseIn == "x") break;
    
    if(!data[courseIn].empty())
    {
      cout << courseIn << " was last offered in ";
      if(*data[courseIn].rbegin() % 10 == 3) cout << "Fall ";
      else if(*data[courseIn].rbegin() % 10 == 2) cout << "Summer ";
      else if(*data[courseIn].rbegin() % 10 == 1) cout << "Spring";
      cout << *data[courseIn].rbegin() / 10 << endl;
    }
    else
      cout << "Sorry, I couldn't find " << courseIn << endl;
  }
  return 0;
}

int termSeason(const string t)
{
  string term = t.substr(0, t.find(" "));
  size_t pos = t.find(" ");
  string year = t.substr(pos);
  
  if(term == "Spring") return stoi(year) * 10 + 1;
  else if(term == "Summer") return stoi(year) * 10 + 2;
  else if(term == "Fall") return stoi(year) * 10 + 3;
  else return 0;
}
