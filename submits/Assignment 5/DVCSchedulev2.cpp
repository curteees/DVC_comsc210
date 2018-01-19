// Programmer: Curtis Lee
// Programmer's ID: 1489029
// DVC Schedule v2

#define _CRT_SECURE_NO_WARNINGS

// C++ libraries code block
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

// C libraries code block
#include <cstring> // for strtok and strcpy

//Header Files
#include "MyDynamicArray.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;

  //Dynamic Arrays
  MyDynamicArray<string> code;        //Array to hold subject codes
  MyDynamicArray<int> num;            //Array to count codes
  
  //for duplicate checking
  MyDynamicArray< MyDynamicArray<string> > alreadySeen; //alreadySeen[i] is list of sections
  MyDynamicArray<string> terms;      //terms[i] = "Fall 2012", alreadySeen[i]
  MyDynamicArray<int> nSections;     //number of sections

  int n = 0;           //number of subject codes
  int c = 0;
  int t = 0;           //for progress dots
  int duplicates = 0;  //counts number of duplicates
  int m = 0;           //index for alreadySeen

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

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

    //duplicate checking
    bool found = false;
    int index = m;
    for (int i = 0; i < m; i++)
    {
      if (terms[i] == term)
      {
        found = true;
        index = i;
        break;
    	}
    }

    //if not found, append to array
    if(found == false)
    {
      terms[m++] = term;
    }
    
    found = false;
    for (int i = 0; i < nSections[index]; i++)
    {
      if (alreadySeen[index][i] == section)
      {
        found = true;
        break;
      }
    }
    
    if(found)
    {
      duplicates++;
      continue;
    }
    else
    {
      alreadySeen[index][nSections[index]] = section;
      nSections[index]++;
    }
    
    //check if subject code exists
    bool exist = false;

    //count sections
    for(int i = 0; i < n; i++)
    {
      if(subjectCode == code[i])
      {
        num[i]++;
        exist = true;
      }
    }
    if(exist == false)
    {
      code[n] = subjectCode;
      num[n]++;
      n++;
      exist = true;
    }
  }
  fin.close();

  //sort
  for(int i = 0; i < n; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      if(code[j] < code[i])
      {
        swap(code[i], code[j]);  //swapping both the subject code and number of sections
        swap(num[i], num[j]);
      }
    }
  }

  //output
  cout << "\nNumber of duplicates = " << duplicates << endl << endl;
  for(int i = 0; i < n; i++)
  {
    cout << code[i] << ", " << num[i] << " sections\n";
  }
}
