// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

#include <cstring>

#include "MyAssociativeArray.h"

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
  
  MyAssociativeArray<string, MyAssociativeArray<string, bool> > alreadySeen;
  MyAssociativeArray<string, MyAssociativeArray<string, int> > record;
  
  int duplicates = 0;
  int c = 0;
  int t = 0;           //for progress dots
  
  // read the input file
  while (fin.good())
  {
    //progress bar
    if(c == 1000*t)
    {
      cout << '.'; cout.flush();
      t++;
    }
    c++;
    
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
    
    if (alreadySeen[term].containsKey(section))
    {
      duplicates++;
    }
    else
    {
      alreadySeen[term][section] = true;
      record[subjectCode][course]++;
    }
  }
  fin.close();
  
  // sort
  MyAssociativeArray<int, string> sKeys;
  queue<string> qs = record.keys();
  for(unsigned int i = 0; !qs.empty(); i++)
  {
    sKeys[i] = qs.front();
    qs.pop();
  }
  
  for(int i = 0; i < sKeys.size(); i++)
  {
    for(int j = i + 1; j < sKeys.size(); j++)
    {
      if(sKeys[i] > sKeys[j])
      {
        swap(sKeys[i], sKeys[j]);
      }
    }
  }
  
  for(int i = 0; i < record.size(); i++)
  {
    MyAssociativeArray<int, string> cKeys;
    queue<string> qc = record[sKeys[i]].keys();
    for(unsigned int i = 0; !qc.empty(); i++)
    {
      cKeys[i] = qc.front();
      qc.pop();
    }
    
    for(int x = 0; x < record[sKeys[i]].size(); x++)
    {
      for(int y = x + 1; y < record[sKeys[i]].size(); y++)
      {
        if(cKeys[x] > cKeys[y])
        {
          swap(cKeys[x], cKeys[y]);
        }
      }
    }
    
    MyAssociativeArray<int, string> out;
    
    for(int j = 0; j < record[sKeys[i]].size(); j++)
    {
      string s = "  " + cKeys[j] + ", " + to_string(record[sKeys[i]][cKeys[j]]) + " section(s)";
      out[j] = s;
    }
    
    if(sKeys[i] != "" && (record[sKeys[i]].size()) > 0)
    {
      cout << sKeys[i] << ", " << record[sKeys[i]].size() << " course(s)" << endl;
    }
    for(int z = 0; z < out.size(); z++)
    {
      cout << out[z] << endl;
    }
  }
  cout  << "Number of duplicates: " << duplicates << endl;
}
