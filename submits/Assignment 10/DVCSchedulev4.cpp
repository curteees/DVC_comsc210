// Programmer: Curtis Lee
// Programmer's ID: 1489029

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <vector>
using namespace std;

#include <cstring>

#include "MyHashMap.h"

int hashCode(const string&);

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
  
  MyHashMap<string, bool, 90000> alreadySeen(hashCode);
  MyHashMap<string, int, 150> record(hashCode);
  
  int duplicates = 0;
  
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
    
    string key = term + "," +  section;
    if (alreadySeen.containsKey(key))
    {
      duplicates++;
    }
    else
    {
      alreadySeen[key] = true;
      record[subjectCode]++;
    }
  }
  fin.close();
  
  // sort
  set<string> sKeys;
  queue<string> qs = record.keys();
  while(!qs.empty())
  {
    sKeys.insert(qs.front());
    qs.pop();
  }
  
  cout  << "\nNumber of duplicates: " << duplicates << endl;
  
  for(auto& i : sKeys)
  {
    cout << i << ": " << record[i] << endl;
  }
  
}

int hashCode(const string& key)
{
  int index = 0;
  for (int i = 0; i < key.size(); i++)
    index += i * i * i * key[i];
  return index;
}
