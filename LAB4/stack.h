#include <iostream>
#define MAX_SIZE 20
using namespace std;
#include <stdexcept>
template <typename T>
class stack
{
  private:
    T data [MAX_SIZE];
    int size;

  public:
    stack();
    void push(T val);
    void pop();
    void pop_two();
    T top();
    bool empty ();
};

template <typename T>
stack<T>::stack()
{
  size = 0;
}

template <typename T>
void stack<T>::push(T val)
{
  //check if size is less than MAX_SIZE, if yes push value
  if(size==MAX_SIZE)
  {
  throw overflow_error("Called push on full stack.");

  }
  data[size]=val;
  size++;
}

template <typename T>
void stack<T>::pop()
{
  //check if stack empty, if yes throw out_of_range
  if (size == 0)
  {
    throw out_of_range("Called pop on empty stack.");
  }
  size--;
}

template <typename T>
void stack<T>::pop_two()
{
  //if size == 0, size == 1 throw two different error messages
  if (this -> size == 0)
  {
    throw out_of_range("Called pop_two on empty stack."); 
  }
  if (this -> size == 1)
    {
      throw out_of_range ("Called pop_two on a stack of size 1.");
    }
this -> size-=2;
  //same as pop() but decrease size by 2
}

template <typename T>
T stack<T>::top()
{
  //if stack is empty throw underflow_error
  if(this -> size==0)
  {
    throw underflow_error("Called top on empty stack.");
  }
  return this -> data[this -> size-1];
}

template <typename T>
bool stack<T>::empty ()
{
  return this -> size == 0;
}