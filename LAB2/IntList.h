#include <iostream>
using namespace std; //dummyHead -> dummyTail
#ifndef INT_LIST_H
#define INT_LIST_H
//IntList.h
struct IntNode 
{
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList
{
  private: 
    IntNode* dummyHead;
    IntNode* dummyTail;
  public: 
    IntList();
    ~IntList();
    void push_front (int val);
    void pop_front();
    void push_back(int value);
    void pop_back();
    bool empty() const;
    friend ostream & operator<<(ostream &out, const IntList &rhs);
    void printReverse() const;
};
#endif