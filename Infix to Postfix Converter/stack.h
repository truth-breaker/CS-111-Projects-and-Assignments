#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;
//class Stack
const int MAX = 5;


typedef string el_t; //define el_t to be int for now


class Stack{

 private:
  el_t el[MAX];//el is an array with 10 slots
 int top; //index to the top element
  void stackError(string msg)const;

 public:
  Stack(); //Constructor
 bool isEmpty(); //returns true if stack is empty or returns false if not
 bool  isFull(); // returns true if stack is full or returns false if not
  void push(el_t e); //if full, calls stackError(errorMsg)
//if not full, enters an element at the top
  el_t pop(); //if empty calls stackError(errorMsg)
 //if not empty, removes an element from the top
  void clearIt();
  void displayAll();
  el_t topElem();
//int top; //index to the top element
};
#endif
