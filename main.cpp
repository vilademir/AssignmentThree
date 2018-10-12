#include <iostream>
#include <fstream>
#include "CheckSyntax.h"


using namespace std;

string input;

//http://users.cis.fiu.edu/~weiss/Deltoid/vcstl/templates#T9
//http://www.cplusplus.com/doc/tutorial/files/

int main(int argc, char ** argv)
{
    if(argc > 1)
    {
      string fileName = argv[1];

      ifstream doesFileExist(fileName);

      if(doesFileExist.good())
      {
        CheckSyntax eh;
        eh.checkDelimiters(fileName);
      }else{
        std::cout << "File doesn't exist. Please try again." << '\n';
      }
    return 0;
    }
  }
