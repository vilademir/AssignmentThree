#include <iostream>

using namespace std;

template <class S>

class GenStack
{
public:
  GenStack();
  GenStack(int maxSize);
  ~GenStack();

  void push(S d);
  S pop();
  S peek();

  bool isFull();
  bool isEmpty();

  int size;
  int top;

  S *myArray; //pointer to char 'myArray'
};

//http://www.cplusplus.com/doc/oldtutorial/templates/
template <class S>
GenStack<S>::GenStack()  //initialize variables to default values
{
  myArray = new S[10];
  size = 10;
  top = -1;
}

template <class S>
GenStack<S>::GenStack(int maxSize) //overload constructor
{
  myArray = new S[maxSize];
  size = maxSize;
  top = -1;

}

template <class S>
GenStack<S>::~GenStack()
{
  delete myArray;
  cout << "stack destroyed" << endl;
}

template <class S>
void GenStack<S>::push(S d)
{
  //check if not full
  //you are responsible for error/bound checking

  myArray[++top] = d;

}

template <class S>
S GenStack<S>::pop()
{
  //check if empty
  //you are responsible for error/bound checking

  return myArray[top--];
}

template <class S>
S GenStack<S>::peek()
{
  return myArray[top];
}

template <class S>
bool GenStack<S>::isFull()
{
  return (top == size - 1);
}

template <class S>
bool GenStack<S>::isEmpty()
{
  return (top == -1);
}
