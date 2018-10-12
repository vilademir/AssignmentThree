#include <iostream>
#include <fstream>
#include "CheckSyntax.h"


using namespace std;

//constructor
CheckSyntax::CheckSyntax(){}

//destructor
CheckSyntax::~CheckSyntax()
{
    delete newStackObject;
}

//this function reverses the first half of the delimiter in order to compare it the second half
char CheckSyntax::reverseDelimiter(char reverse)
{

  if(reverse == '(')
  {
    return ')';
  }else if(reverse == ')')
  {
    return '(';
  }else if(reverse == '[')
  {
    return ']';
  }else if(reverse == ']')
  {
    return '[';
  }else if(reverse == '{')
  {
    return '}';
  }else if(reverse == '}')
  {
    return '{';
  }
}

//this function checks to see if the delimiters are complete and not missing anything
void CheckSyntax::checkDelimiters(string nameOfFile)
{

  newStackObject = new GenStack<char>();
  char delimiter;
  int lineCounter = 0;

  ifstream fileReader(nameOfFile);

  if (fileReader.is_open())
    {
      string fileLine;

      while (getline(fileReader, fileLine))
      {
        lineCounter++;
        for (int x = 0; x < fileLine.length(); x++)
        {
          if(fileLine[x] == '(' || fileLine[x] == '[' || fileLine[x] == '{')
          {
            delimiter = reverseDelimiter(fileLine[x]);
            newStackObject->push(delimiter);
          }else if(fileLine[x] == ')' || fileLine[x] == ']' || fileLine[x] == '}'){
            if(fileLine[x] == newStackObject->peek())
            {
              newStackObject->pop();

            }else{
            std::cout << "Syntax Error on line " << lineCounter << "." << '\n';
            exit(1);
            }
          }
          if(fileLine[x] == '/' && fileLine[x + 1])
          {
            continue;
          }
        }
      }
    if(newStackObject->isEmpty())
    {
      std::cout << "File is good" << '\n';
    }else{
      std::cout << "Syntax Error. Missing closing delimiter for delimiter on line " << lineCounter << "." << '\n';
      std::cout << "Reached the end of file." << '\n';
    }
  }
  fileReader.close();
}
