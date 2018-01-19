// Programmer: Curtis Lee
// Programmer's ID: 1489029
// RNP Calculator

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "MyStack.h"

int main()
{
  // programmer's identification
  cout << "Programmer: Curtis Lee\n";
  cout << "Programmer's ID: 1489029\n";
  cout << "File: " << __FILE__ << endl << endl;

  MyStack<string> mainStack;
  string input = "";
  MyStack<string> dupStack;

  while(true)
  {
    if(mainStack.empty())
      cout << "Enter: ";
    else
    {
      string prompt = "Enter: ";
      while(!dupStack.empty())
      {
        prompt += dupStack.peek() + " ";
        dupStack.pop();
      }
      cout << prompt;
    }
    cin >> input;

    if(input == "Q" || input == "q")
      break;

    if(mainStack.size() < 2 && (input == "+" || input == "*" || input == "/" || input == "-"))
    {} //empty if statement to do nothing when stack doesn't have enough values
    else
    {
      if(mainStack.size() >= 2 && (input == "+" || input == "*" || input == "/" || input == "-"))
      {
        double val1 = atof(mainStack.peek().c_str());
        mainStack.pop();
        double val2 = atof(mainStack.peek().c_str());
        mainStack.pop();
        double result = 0.0;

        if(input == "+")
          result = val1 + val2;
        else if(input == "*")
          result = val1 * val2;
        else if(input == "-")
          result = val2 - val1;
        else if(input == "/")
          result = val2 / val1;

        ostringstream strs;
        strs << result;
        mainStack.push(strs.str());
      }
      else
        mainStack.push(input);
    }
    dupStack = mainStack;
  }

  return 0;
}
