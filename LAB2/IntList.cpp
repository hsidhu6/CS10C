#include "IntList.h"
using namespace std;

IntList::IntList():dummyHead(new IntNode(0)),dummyTail(new IntNode(0))
{
  dummyHead -> next = dummyTail;
  // set the previous pointer of tail 
  dummyTail -> prev = dummyHead;
}
IntList::~IntList()
{
  //iterate and delete every node 
  IntNode* current = dummyHead;
    IntNode* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

}
void IntList::push_front (int val)
{
  // create the new node 
  IntNode* newNode = new IntNode(val);
  //save the current next node in a temp value 
  
  // step 1: set the next value of new to saved node
  newNode -> next = dummyHead -> next;
  // step 2: set the prev value to dummyHead
  newNode -> prev = dummyHead;
  // step 3: set the prev value of saved node to new node 
  newNode -> next -> prev = newNode;
  // step 4: set the next value of dummyHead to new
  dummyHead -> next = newNode;
}
void IntList::pop_front()
{
  // first check whether list is empty or not 
  if (this -> empty())
  {
    return;
  };
  IntNode* first = dummyHead -> next;
  // set the next pointer of dummyHead to firstnodes next
  dummyHead -> next = dummyHead -> next -> next;
  // set the prev pointer of 2nd node to dummyHead
  dummyHead -> next -> prev = dummyHead;
  // delete firstnode 
  delete first;
}

void IntList::push_back(int val)
{
  // create new node
  IntNode* newNode = new IntNode(val);
  // save the prev node of dummyTail in a temp 
  // step 1: set the new nodes next to dummyTail
  newNode -> next = dummyTail;
  // step 2: set prev pointer of tail to new node
  newNode -> prev = dummyTail -> prev;
  // step 3: set next of saved node to new
  newNode -> prev -> next = newNode;
  // step 4: set prev of new node to saved node 
  dummyTail -> prev = newNode;
}

void IntList::pop_back()
{
  if (this -> empty())
  {
    return;
  }
  IntNode* last = dummyTail -> prev;
  dummyTail -> prev = dummyTail -> prev -> prev;
  dummyTail -> prev -> next = dummyTail;
  delete last;
}
bool IntList::empty() const
{
  // if dummyHead's next is dummyTail (list is empty) return true
  if (dummyHead -> next == dummyTail)
  {
    return true;
  };
  return false;
}
ostream & operator<<(ostream &out, const IntList &rhs)
{
  //iterate the linked list
  IntNode* current = rhs.dummyHead -> next; 
    while (current != rhs.dummyTail)
    {
        out<< current -> data;
        if (current != rhs.dummyTail -> prev)
        {
          out << " ";
        }
        current = current -> next;
    }
  // out << 
  return out;
}
void IntList::printReverse() const
{
  // iterate the linked list from the end
  IntNode* current = dummyTail -> prev;
 
    while (current != dummyHead)
    {
        cout << current -> data;
        if (current != dummyHead -> next)
        {
          cout << " ";
        }
        current = current -> prev;
    }
  // print 

}