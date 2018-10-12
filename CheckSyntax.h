#include <iostream>
#include "GenStack.h"

using namespace std;

class CheckSyntax
{
public:
  GenStack<char>* newStackObject;
  CheckSyntax();
  ~CheckSyntax();
  char reverseDelimiter(char reverse);
  void checkDelimiters(string nameOfFile);
};
